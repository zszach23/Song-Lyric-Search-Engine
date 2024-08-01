// Zach Sally
// 5/14/2024
//
// =====================================
// |  SpotifyAuthorizationHandler.cpp  |
// =====================================
//
// Class that handles authorization for Spotify and Genius APIs

#include "SpotifyAuthorizationHandler.h"

#include "SearchEngineConfig.h"

#include <curl/curl.h>
#include <httplib.h>
#include <iostream>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

size_t writeCallback(void *contents, size_t size, size_t nmemb, string* s);

const string REDIRECT_URI = "http://localhost:8080/callback";
const string RESPONSE_TYPE = "code";

const string SPOTIFY_AUTH_URL = "https://accounts.spotify.com/authorize?";

const string SPOTIFY_CLIENT_ID_KEY = "SPOTIFY_CLIENT_ID";
const string SPOTIFY_CLIENT_SECRET_KEY = "SPOTIFY_CLIENT_SECRET";

//------------------------------------------//
string SpotifyAuthorizationHandler::getSpotifyToken()
//------------------------------------------//
{
    json spotifyKeys = SearchEngineConfig::getSpotifyAPIKeys();

    string spotifyClientID = spotifyKeys[SPOTIFY_CLIENT_ID_KEY];
    string spotifyClientSecret = spotifyKeys[SPOTIFY_CLIENT_SECRET_KEY];

    return getToken(spotifyClientID, spotifyClientSecret, SPOTIFY_AUTH_URL);
}

//-------------------------------------------------------------------------------------------------------//
string SpotifyAuthorizationHandler::getToken(const string& id, const string& secret, const string& authURL)
//-------------------------------------------------------------------------------------------------------//
{
    CURL* curl = curl_easy_init();
    CURLcode res;
    string readBuffer;

    if (curl)
    {
        string query = "client_id=" + id +
                       "&redirect_uri=" + REDIRECT_URI +
                       "&scope=\"\""
                       "&response_type=" + RESPONSE_TYPE;
                       "&state=1";

        string url = authURL + query;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

//----------------------------------------------------------------------//
size_t writeCallback(void *contents, size_t size, size_t nmemb, string* s)
//----------------------------------------------------------------------//
{
    size_t newLength = size * nmemb;

    try
    {
        s->append((char*)contents, newLength);
    }
    catch (bad_alloc &e)
    {
        return 0;
    }

    return newLength;
}

//---------------------------------------------------------------------------------//
void handleAuthorizationCallback(const httplib::Request &req, httplib::Response &res)
//---------------------------------------------------------------------------------//
{
    cout << "Callback received" << endl;
}