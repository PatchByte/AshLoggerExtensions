#include "AshLoggerExtensions/SimpleLokiExtension.h"
#include <nlohmann/json.hpp>
#include <ixwebsocket/IXHttpClient.h>
#include <fmt/format.h>

#include <iostream>
#include <vector>
#include <chrono>

namespace ash::passages
{
    static int64_t GetCurrentUnixEpochInNanoSeconds()
    {
        auto time = std::chrono::system_clock::now();
        auto since_epoch = time.time_since_epoch();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

        return millis.count();
    }

    static nlohmann::json CreateLokiPushPayload(std::string Label, AshLoggerTag Tag, std::string FormattedString)
    {
        nlohmann::json stream = nlohmann::json();

        nlohmann::json streamKey = nlohmann::json();
        streamKey[Label] = Tag.GetPrefix();

        std::vector<nlohmann::json> streamValues = {};
        std::vector<std::string> streamValue = {
            // We are adding 000000000 because of the documentation https://grafana.com/docs/loki/latest/api/#push-log-entries-to-loki
            fmt::format("{}000000", GetCurrentUnixEpochInNanoSeconds() ),
            FormattedString
        };

        std::vector<nlohmann::json> payloadStreams = { };
        nlohmann::json payload = nlohmann::json();

        streamValues.push_back(nlohmann::json(streamValue));

        stream["stream"] = streamKey;
        stream["values"] = streamValues;

        payloadStreams.push_back(stream);
        payload["streams"] = payloadStreams;

        return payload;
    }

    static ix::HttpClient* CreateHttpClient()
    {
        ix::HttpClient* client = new ix::HttpClient();

        return client;
    }

    void SimpleLokiExtension::DoPassthrough(AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString)
    {
        if(this->GetLoggerTagFilter().DoFilter(Tag.GetShortTag()) == false) { return; }

        auto httpClient = CreateHttpClient();
        auto payload = CreateLokiPushPayload(this->GetParent()->GetLoggerName(), Tag, FormattedString);

        ix::HttpRequestArgsPtr clientArgs = httpClient->createRequest();
        clientArgs->extraHeaders = {
            { "Content-Type", "application/json" }
        };
        std::string clientPayload = payload.dump(-1);
        ix::HttpResponsePtr response = httpClient->post(fmt::format("http://{}:{}/loki/api/v1/push", this->lokiEndpointHostname, this->lokiEndpointPort), clientPayload, clientArgs);
    }

}