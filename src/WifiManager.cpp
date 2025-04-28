#include "WifiManager.hpp"

WifiManager::WifiManager() : _ssid(nullptr), _key(nullptr) {}

void WifiManager::connect(const char* ssid, const char* key) {
    _ssid = ssid;
    _key = key;

    Serial.print("SSID   ");
    Serial.println(_ssid);
    Serial.print("Key   ");
    Serial.println(_key);
    
    WiFi.begin(_ssid, _key);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
    // Exibir IP, Máscara de Rede, Gateway e Endereço MAC
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Subnet Mask: ");
    Serial.println(WiFi.subnetMask());
    Serial.print("Gateway IP: ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("MAC Address: ");
    Serial.println(WiFi.macAddress());

}

bool WifiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

std::string WifiManager::getIPAddress() {
    if (isConnected()) {
        return WiFi.localIP().toString().c_str();
    }
    return "0.0.0.0";
}