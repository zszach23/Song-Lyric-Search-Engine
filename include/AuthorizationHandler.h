// Zach Sally
// 5/14/2024
//
// ============================
// |  AuthorizationHandler.h  |
// ============================
//
// Header file for handling authorization for Spotify and Genius APIs

#pragma once

#include <string>

class AuthorizationHandler
{
public:
    static std::string getGeniusToken();
    static std::string getSpotifyToken();

private:
    static std::string geniusToken;
    static std::string spotifyToken;

    static std::string getToken(const std::string& id, const std::string& secret);
};