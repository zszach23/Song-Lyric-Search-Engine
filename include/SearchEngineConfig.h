// Zach Sally
// 5/14/2024
//
// ==========================
// |  SearchEngineConfig.h  |
// ==========================
//
// Header file for configuring the search engine with Spotify and Genius client keys and secrets

#pragma once

#include <json.hpp>
#include <string>

class SearchEngineConfig
{
public:
    static nlohmann::json getGeniusAPIKeys();
    static nlohmann::json getSpotifyAPIKeys();

private:
    static nlohmann::json getKeys(const std::string& idKey, const std::string& secretKey);
    static nlohmann::json createJSONObjectFromFile(const std::string& file);
};