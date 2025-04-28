#ifndef SENSORTEMP2_HPP
#define SENSORTEMP2_HPP

#include <Arduino.h>

class SensorTemp2
{
    public:
        SensorTemp2();
        float ReadTemperature();
    
    private:
       float temperature; 
};
    
#endif