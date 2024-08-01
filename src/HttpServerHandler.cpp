// Zach Sally
// 5/14/2024
//
// ===========================
// |  HttpServerHandler.cpp  |
// ===========================
//
// Class that handles local HTTP server interactions

#include "HttpServerHandler.h"

httplib::Server HttpServerHandler::server;

//--------------------------------//
void HttpServerHandler::initialize()
//--------------------------------//
{
    std::thread serverthread([&]() {
        server.listen("localhost", 8080);
    });

    serverthread.detach();
}

//-------------------------------------------//
httplib::Server& HttpServerHandler::getServer()
//-------------------------------------------//
{
    return server;
}

//----------------------------------------------------------------------------------------------------//
void HttpServerHandler::addGetCallback(const std::string& path, const httplib::Server::Handler& handler)
//----------------------------------------------------------------------------------------------------//
{
    server.Get(path.c_str(), handler);
}