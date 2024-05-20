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
    /**************************************************************************
    * @brief Get the Genius API Client ID and Client Secret in a JSON format
    * 
    * @param None
    * @return nlohmann::json - JSON object containing the Genius API Client ID
    *                          and Client Secret
    **************************************************************************/
    static nlohmann::json getGeniusAPIKeys();

    /**************************************************************************
    * @brief Get the Spotify API Client ID and Client Secret in a JSON format
    * 
    * @param None
    * @return nlohmann::json - JSON object containing the Spotify API Client ID
    *                          and Client Secret
    **************************************************************************/
    static nlohmann::json getSpotifyAPIKeys();

private:

    const static std::string CONFIG_FILE_ENV_VARIABLE;

    const static std::string GENIUS_CLIENT_ID_KEY;
    const static std::string GENIUS_CLIENT_SECRET_KEY;
    const static std::string SPOTIFY_CLIENT_ID_KEY;
    const static std::string SPOTIFY_CLIENT_SECRET_KEY;

    /**************************************************************************
    * @brief Get the Client ID and Client Secret from a JSON object
    * 
    * @param idKey - The key for the Client ID
    * @param secretKey - The key for the Client Secret
    * 
    * @return nlohmann::json - JSON object containing the Client ID and Client Secret
    **************************************************************************/
    static nlohmann::json getKeys(const std::string& idKey, const std::string& secretKey);

    /**************************************************************************
    * @brief Create a JSON object from a JSON file
    * 
    * @param file - The file to create the JSON object from
    * 
    * @return nlohmann::json - JSON object created from the file
    **************************************************************************/
    static nlohmann::json createJSONObjectFromFile(const std::string& file);
};