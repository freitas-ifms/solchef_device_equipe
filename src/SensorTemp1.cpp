#include "SensorTemp1.hpp"

SensorTemp1::SensorTemp1()
{
    Serial.println("SensorTemp1 constructor called");
}

float SensorTemp1::ReadTemperature() 
{
   // Simula sensor ou usa leitura real
  return random(200, 300) / 10.0;  // Exemplo: 20.0 a 30.0 °C
}