// Zach Sally
// 5/14/2024
//
// ====================================
// |  GeniusAuthorizationHandler.cpp  |
// ====================================
//
// Class that handles authorization for Spotify and Genius APIs

#include "GeniusAuthorizationHandler.h"

#include "HttpServerHandler.h"
#include "SearchEngineConfig.h"

#include <curl/curl.h>
#include <httplib.h>
#include <iostream>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

void handleAuthorizationCallback(const httplib::Request &req, httplib::Response &res);

const string REDIRECT_URI = "http://localhost:8080/callback";
const string RESPONSE_TYPE = "code";

const string GENIUS_AUTH_URL = "https://api.genius.com/oauth/authorize?";
const string GENIUS_TOKEN_URL = "https://api.genius.com/oauth/token";

const string GENIUS_CLIENT_ID_KEY = "GENIUS_CLIENT_ID";
const string GENIUS_CLIENT_SECRET_KEY = "GENIUS_CLIENT_SECRET";

//-----------------------------------------------//
string GeniusAuthorizationHandler::getGeniusToken()
//-----------------------------------------------//
{
    json geniusKeys = SearchEngineConfig::getGeniusAPIKeys();

    string geniusClientId = geniusKeys[GENIUS_CLIENT_ID_KEY];
    string geniusClientSecret = geniusKeys[GENIUS_CLIENT_SECRET_KEY];

    string query = "client_id=" + geniusClientId +
                "&redirect_uri=" + REDIRECT_URI +
                "&scope=\"\"" +
                "&state=" + "1" +
                "&response_type=" + RESPONSE_TYPE;

    HttpServerHandler::addGetCallback("/callback", handleAuthorizationCallback);

    GeniusAuthorizationHandler::redirectUserToAuthorizationPage(GENIUS_AUTH_URL, query);
    
    return getToken(geniusClientId, geniusClientSecret, GENIUS_AUTH_URL);
}

//----------------------------------------------------------------------------------------------------------//
string GeniusAuthorizationHandler::redirectUserToAuthorizationPage(const string& authURL, const string& query)
//----------------------------------------------------------------------------------------------------------//
{
    string url = authURL + query;

    cout << "Redirecting user to: " << url << endl;

#if defined(_WIN32)
    std::system(("start " + url).c_str());
#elif defined(__APPLE__)
    std::system(("open " + url).c_str());
#else
    std::system(("xdg-open " + url).c_str());
#endif

    return url;
}

//------------------------------------------------------------------------------------------------------//
string GeniusAuthorizationHandler::getToken(const string& id, const string& secret, const string& authURL)
//------------------------------------------------------------------------------------------------------//
{
    cout << "Getting token" << endl;
}

//---------------------------------------------------------------------------------//
void handleAuthorizationCallback(const httplib::Request &req, httplib::Response &res)
//---------------------------------------------------------------------------------//
{
    cout << "Callback received" << endl;
}