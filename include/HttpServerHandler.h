// Zach Sally
// 5/14/2024
//
// =========================
// |  HttpServerHandler.h  |
// =========================
//
// Header file for handling local HTTP Server interactions

#pragma once

#include <httplib.h>

class HttpServerHandler
{
public:
    static void initialize();
    static httplib::Server& getServer();
    static void addGetCallback(const std::string& path, const httplib::Server::Handler& handler);

private:
    static httplib::Server server;
};