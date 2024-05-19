// Zach Sally
// 5/14/2024
//
// ==============================
// |  AuthorizationHandler.cpp  |
// ==============================
//
// Class that handles authorization for Spotify and Genius APIs

#include "AuthorizationHandler.h"

#include "SearchEngineConfig.h"

#include <json.hpp>

using namespace std;
using json = nlohmann::json;

const string GENIUS_CLIENT_ID_KEY = "GENIUS_CLIENT_ID";
const string GENIUS_CLIENT_SECRET_KEY = "GENIUS_CLIENT_SECRET";
const string SPOTIFY_CLIENT_ID_KEY = "SPOTIFY_CLIENT_ID";
const string SPOTIFY_CLIENT_SECRET_KEY = "SPOTIFY_CLIENT_SECRET";

string AuthorizationHandler::getGeniusToken()
{
    json geniusKeys = SearchEngineConfig::getGeniusAPIKeys();

    string geniusClientID = geniusKeys[GENIUS_CLIENT_ID_KEY];
    string geniusClientSecret = geniusKeys[GENIUS_CLIENT_SECRET_KEY];

    return getToken(geniusClientID, geniusClientSecret);
}

string AuthorizationHandler::getSpotifyToken()
{
    json spotifyKeys = SearchEngineConfig::getSpotifyAPIKeys();

    string spotifyClientID = spotifyKeys[SPOTIFY_CLIENT_ID_KEY];
    string spotifyClientSecret = spotifyKeys[SPOTIFY_CLIENT_SECRET_KEY];

    return getToken(spotifyClientID, spotifyClientSecret);
}

string AuthorizationHandler::getToken(const string& id, const string& secret)
{
    // Dummy implementation for demonstration purposes
    return id + secret;
}