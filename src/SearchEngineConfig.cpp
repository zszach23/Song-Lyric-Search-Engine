// Zach Sally
// 5/14/2024
//
// ============================
// |  SearchEngineConfig.cpp  |
// ============================
//
// Helper class to configure Search Engine by providing Genius and Spotify API keys and secrets

#include "SearchEngineConfig.h"

#include <fstream>

using namespace std;
using json = nlohmann::json;

const string CONFIG_FILE_ENV_VARIABLE = "CONFIG_FILE";

const string GENIUS_CLIENT_ID_KEY = "GENIUS_CLIENT_ID";
const string GENIUS_CLIENT_SECRET_KEY = "GENIUS_CLIENT_SECRET";
const string SPOTIFY_CLIENT_ID_KEY = "SPOTIFY_CLIENT_ID";
const string SPOTIFY_CLIENT_SECRET_KEY = "SPOTIFY_CLIENT_SECRET";

// Returns the Genius API keys and secrets as a JSON object
//-----------------------------------------//
json SearchEngineConfig::getGeniusAPIKeys()
//-----------------------------------------//
{
    return getKeys(GENIUS_CLIENT_ID_KEY, GENIUS_CLIENT_SECRET_KEY);
}

// Returns the Spotify API keys and secrets as a JSON object
//------------------------------------------//
json SearchEngineConfig::getSpotifyAPIKeys()
//------------------------------------------//
{
    return getKeys(SPOTIFY_CLIENT_ID_KEY, SPOTIFY_CLIENT_SECRET_KEY);
}

// Returns the keys and secrets corresponding to the given id and secret keys
// as a JSON object
//----------------------------------------------------------------------------//
json SearchEngineConfig::getKeys(const string& idKey, const string& secretKey)
//----------------------------------------------------------------------------//
{
    const string CONFIG_FILE = std::getenv(CONFIG_FILE_ENV_VARIABLE.c_str());

    json keys = SearchEngineConfig::createJSONObjectFromFile(CONFIG_FILE);

    string id = keys[idKey];
    string secret = keys[secretKey];

    json apiKeys = 
    {
        {idKey, id},
        {secretKey, secret}
    };

    return apiKeys;
}

// Creates a JSON object from a file
//-------------------------------------------------------------------//
json SearchEngineConfig::createJSONObjectFromFile(const string& file)
//-------------------------------------------------------------------//
{
    ifstream configFile(file);

    if (!configFile.is_open())
    {
        throw invalid_argument("Could Not Open File: " + file);
    }

    return json::parse(configFile);
}