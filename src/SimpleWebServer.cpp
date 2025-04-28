#include "SimpleWebServer.hpp"

SimpleWebServer::SimpleWebServer() : server(80) 
{
    Serial.println("Construtor do servidor web chamado...");
}

void SimpleWebServer::handleClient() {
    server.handleClient();
}

void SimpleWebServer::sendData(const int &temp1, const int &temp2) {
    currentTemp1 = temp1;
    currentTemp2 = temp2;
}

void SimpleWebServer::setupRoutes() {
    
    // Endpoints
    server.on("/getMacAddress", HTTP_GET, [this]() 
    {
        server.send(200, "text/plain", WiFi.macAddress());
        Serial.println("MAC Address: " + WiFi.macAddress());
    });

    server.on("/getTemp1", HTTP_GET, [this]() 
    {
        server.send(200, "text/plain", String(currentTemp1));
        Serial.println("Temp1: " + String(currentTemp1));
    });

    server.on("/getTemp2", HTTP_GET, [this]() 
    {
        server.send(200, "text/plain", String(currentTemp2));
        Serial.println("Temp2: " + String(currentTemp2));
    });

    server.begin();
}