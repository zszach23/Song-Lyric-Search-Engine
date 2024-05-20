// Zach Sally
// 5/15/2024
//
// ====================
// |  testcase01.cpp  |
// ====================
//
// Test case to ensure that the SearchEngineConfig class is functioning correctly

#include "SearchEngineConfig.h"

#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

json getConfig();

class SearchEngineConfigTest : public ::testing::Test
{
protected:

    void SetUp() override
    {
        SearchEngineConfig::initialize();
    }

    json config = getConfig();
};

// Test SearchEngineConfig::getSpotifyAPIKeys()
//---------------------------------------------//
TEST_F(SearchEngineConfigTest, GetSpotifyAPIKeys)
//---------------------------------------------//
{
    json spotifyKeys = SearchEngineConfig::getSpotifyAPIKeys();

    EXPECT_EQ(spotifyKeys["SPOTIFY_CLIENT_ID"], config["SPOTIFY_CLIENT_ID"]);
    EXPECT_EQ(spotifyKeys["SPOTIFY_CLIENT_SECRET"], config["SPOTIFY_CLIENT_SECRET"]);
}

// Test SearchEngineConfig::getGeniusAPIKeys()
//--------------------------------------------//
TEST_F(SearchEngineConfigTest, GetGeniusAPIKeys)
//--------------------------------------------//
{
    json geniusKeys = SearchEngineConfig::getGeniusAPIKeys();

    EXPECT_EQ(geniusKeys["GENIUS_CLIENT_ID"], config["GENIUS_CLIENT_ID"]);
    EXPECT_EQ(geniusKeys["GENIUS_CLIENT_SECRET"], config["GENIUS_CLIENT_SECRET"]);
}

//--------------//
json getConfig()
//--------------//
{
    // Hardcoded path to config file to ensure environment variable is not needed
    ifstream file("../config.json");
    json config;
    file >> config;
    return config;
}