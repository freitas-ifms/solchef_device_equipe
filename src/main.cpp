#include <Arduino.h>
#include <Display.hpp>
#include <WifiManager.hpp>
#include <SimpleWebServer.hpp>
#include <SensorTemp1.hpp>
#include <SensorTemp2.hpp>

Display display;
SimpleWebServer webServer;
WifiManager wifiManager;
SensorTemp1 sensor1;
SensorTemp2 sensor2;

void setup() {
    Serial.begin(115200);
    display.Start();
    wifiManager.connect("Maker_WiFi", "Maker@2025");
    webServer.setupRoutes();
}

void loop() 
{
    webServer.sendData(sensor1.ReadTemperature(), sensor2.ReadTemperature());
    webServer.handleClient();
    //display.PrintLine(0, "Temperatura 1: ");
    //display.PrintLine(1, String(sensor1.ReadTemperature()).c_str());
    //display.PrintLine(2, "Temperatura 2: ");
    //display.PrintLine(3, String(sensor2.ReadTemperature()).c_str());
    display.PrintLine(0, "IP: ");
    display.PrintLine(1, wifiManager.getIPAddress().c_str());
    delay(5000);

    Serial.println("Loop principal executado...");
}