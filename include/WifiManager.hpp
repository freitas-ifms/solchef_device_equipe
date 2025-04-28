#ifndef WIFIMANAGER_HPP
#define WIFIMANAGER_HPP

#include <Arduino.h>
#include <WiFi.h>

class WifiManager 
{
    public:
        WifiManager();  
        void connect(const char* ssid, const char* key);
        bool isConnected();
        std::string getIPAddress();
    
    private:
        const char* _ssid;
        const char* _key;
};
    
#endif