// Zach Sally
// 5/14/2024
//
// ==============
// |  main.cpp  |
// ==============
//
// Header file for declaring Search Engine class

#pragma once

#include <json.hpp>
#include <string>

class SearchEngine
{
public:

    static void initialize();

    // Menu Options
    static void search(const std::string& query);
    static nlohmann::json getTrackList(const std::string& playlistID);
    static nlohmann::json getLyrics(const std::string& songName);
    static void addNewPlaylist(const std::string& playlistID);
    static void removePlaylist(const std::string& playlistID);
    static void addSongToPlaylist(const std::string& playlistID, const std::string& songName);
    static void removeSongFromPlaylist(const std::string& playlistID, const std::string& songName);
};