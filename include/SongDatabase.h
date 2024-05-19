// Zach Sally
// 5/14/2024
//
// ====================
// |  SongDatabase.h  |
// ====================
//
// Header file for class that handles song database interactions

#pragma once

#include <string>

class SongDatabase
{
public:
    static void initialize();

    // Database Operations
    static bool addPlaylistToDatabase(const std::string& playlistID);
    static bool removePlaylistFromDatabase(const std::string& playlistID);
    static void displayPlaylistsInDatabase();
    static void displaySongsInPlaylist(const std::string& playlistID);
};