#ifndef SENSORTEMP1_HPP
#define SENSORTEMP1_HPP

#include <Arduino.h>

class SensorTemp1
{
    public:
        SensorTemp1();
        float ReadTemperature();
    
    private:
       float temperature; 
};
    
#endif