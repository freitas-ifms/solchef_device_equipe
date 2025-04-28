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

// Variáveis para armazenar as temperaturas
float temperatura1 = 0.0;
float temperatura2 = 0.0;

// Definições de handles para as tasks
TaskHandle_t TaskTemperaturaHandle = NULL;
TaskHandle_t TaskServidorHandle = NULL;
TaskHandle_t TaskDisplayHandle = NULL;

// Task para ler sensores de temperatura
void TaskTemperatura(void *pvParameters) {
    for (;;) {
        temperatura1 = sensor1.ReadTemperature();
        temperatura2 = sensor2.ReadTemperature();
        vTaskDelay(pdMS_TO_TICKS(2000)); // Atualiza a cada 2 segundos
    }
}

// Task para enviar dados via WebServer
void TaskServidor(void *pvParameters) {
    for (;;) {
        webServer.sendData(temperatura1, temperatura2);
        webServer.handleClient();
        vTaskDelay(pdMS_TO_TICKS(100)); // Frequência de resposta rápida
    }
}

// Task para atualizar Display
void TaskDisplay(void *pvParameters) {
    for (;;) {
        display.PrintLine(0, "IP:");
        display.PrintLine(1, wifiManager.getIPAddress().c_str());
        display.PrintLine(2, String("Temp1: " + String(temperatura1)).c_str());
        display.PrintLine(3, String("Temp2: " + String(temperatura2)).c_str());
        vTaskDelay(pdMS_TO_TICKS(5000)); // Atualiza display a cada 5 segundos
    }
}

void setup() {
    Serial.begin(115200);
    display.Start();
    wifiManager.connect("Maker_WiFi", "Maker@2025");
    webServer.setupRoutes();

    // Criar a task de leitura de temperatura no núcleo 0
    xTaskCreatePinnedToCore(
        TaskTemperatura,        // Função
        "TaskTemperatura",      // Nome
        2048,                   // Stack size (bytes)
        NULL,                   // Parâmetros
        1,                      // Prioridade
        &TaskTemperaturaHandle, // Handle
        0                       // Núcleo 0
    );

    // Criar a task do servidor web no núcleo 1
    xTaskCreatePinnedToCore(
        TaskServidor,
        "TaskServidor",
        4096,
        NULL,
        1,
        &TaskServidorHandle,
        1 // Núcleo 1
    );

    // Criar a task do Display no núcleo 1
    xTaskCreatePinnedToCore(
        TaskDisplay,
        "TaskDisplay",
        4096,
        NULL,
        1,
        &TaskDisplayHandle,
        1 // Núcleo 1
    );
}

void loop() {
    // O loop principal fica vazio porque as tasks estão rodando
    vTaskDelay(pdMS_TO_TICKS(1000)); 
}
