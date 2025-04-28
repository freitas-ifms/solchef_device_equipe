#include "SensorTemp2.hpp"

SensorTemp2::SensorTemp2()
{
    Serial.println("SensorTemp1 constructor called");
}

float SensorTemp2::ReadTemperature() 
{
   // Simula sensor ou usa leitura real
  return random(200, 300) / 10.0;  // Exemplo: 20.0 a 30.0 °C
}