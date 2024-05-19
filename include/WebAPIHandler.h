// Zach Sally
// 5/14/2024
//
// =====================
// |  WebAPIHandler.h  |
// =====================
//
// Header file for handling web API interactions

#pragma once

#include <json.hpp>
#include <string>

class WebAPIHandler
{
public:
    static void initialize();

    static nlohmann::json getTrackList(const std::string& playlistID);
    static nlohmann::json getLyrics(const std::string& songName);
};