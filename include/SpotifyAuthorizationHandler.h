// Zach Sally
// 5/14/2024
//
// ===================================
// |  SpotifyAuthorizationHandler.h  |
// ===================================
//
// Header file for handling authorization for Spotify API

#pragma once

#include <string>

class SpotifyAuthorizationHandler
{
public:
    static std::string getSpotifyToken();

private:
    static std::string spotifyToken;

    static std::string getToken(const std::string& id, const std::string& secret, const std::string& authURL);
};