// Zach Sally
// 5/14/2024
//
// ==============
// |  main.cpp  |
// ==============
//
// Driver program for search engine

#include "SearchEngineConfig.h"
#include "GeniusAuthorizationHandler.h"
#include "HttpServerHandler.h"

#include <iostream>

using namespace std;

//------//
int main()
//------//
{
    SearchEngineConfig::initialize();
    HttpServerHandler::initialize();

    // cout << "Genius API Keys: " << SearchEngineConfig::getGeniusAPIKeys().dump(2) << endl;
    // cout << "Spotify API Keys: " << SearchEngineConfig::getSpotifyAPIKeys().dump(2) << endl;

    cout << "Genius Authorization Token: " << GeniusAuthorizationHandler::getGeniusToken() << endl;
    // cout << "Spotify Authorization Token: " << AuthorizationHandler::getSpotifyToken() << endl;


}