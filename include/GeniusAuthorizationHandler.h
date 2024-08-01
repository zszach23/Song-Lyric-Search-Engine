// Zach Sally
// 5/14/2024
//
// ==================================
// |  GeniusAuthorizationHandler.h  |
// ==================================
//
// Header file for handling authorization for Genius API

#pragma once

#include <string>

class GeniusAuthorizationHandler
{
public:
    static std::string getGeniusToken();

private:
    static std::string geniusToken;

    static std::string redirectUserToAuthorizationPage(const std::string& authURL, const std::string& query);
    static std::string getToken(const std::string& id, const std::string& secret, const std::string& authURL);
};