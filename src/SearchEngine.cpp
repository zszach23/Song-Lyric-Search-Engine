// Zach Sally
// 5/14/2024
//
// ======================
// |  SearchEngine.cpp  |
// ======================
//
// Class that acts as a menu for the user to interact with playlist database

#include "SearchEngine.h"

#include "SongDatabase.h"
#include "WebAPIHandler.h"

#include <iostream>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

// Search Engine Initialization:
// - Database
// - API Tokens
//-----------------------------//
void SearchEngine::initialize()
//-----------------------------//
{
    SongDatabase::initialize();
    WebAPIHandler::initialize();
}