#include "Display.hpp"

Display::Display() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

void Display::Start() {
    Wire.begin(SDA_PIN, SCL_PIN);
    
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("Falha ao inicializar o display!");
        for (;;);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();
    display.setCursor(0, 0);
    display.println("Iniciando...");
    display.display();
    delay(2000);
}

void Display::PrintLine(uint8_t line, const char* texto) 
{
    if (line > 3) return; // Evita acessar linha inválida
    
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, line * 16);
    
    // Limpa a linha antes de desenhar o novo texto
    display.fillRect(0, line * 16, 128, 16, SSD1306_BLACK);
    
    display.print(texto);
    display.display();
}

void Display::Clear()
{
    display.clearDisplay();
    display.display();
}