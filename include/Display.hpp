#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C  // Endereço I2C padrão para SSD1306
#define SDA_PIN 21
#define SCL_PIN 22

class Display 
{
    public:
        Display();
        void Start();
        void PrintLine(uint8_t line, const char* texto);
        void Clear();

    private:
        Adafruit_SSD1306 display;
};

#endif