#ifndef SIMPLE_WEB_SERVER_HPP
#define SIMPLE_WEB_SERVER_HPP

#include <WebServer.h>
#include <WiFi.h>

class SimpleWebServer {

    public:
        SimpleWebServer();
        void handleClient();
        void sendData(const int &temp1, const int &temp2);
        void setupRoutes();
        
    private:
        WebServer server;
        float currentTemp1;
        float currentTemp2;
};

#endif