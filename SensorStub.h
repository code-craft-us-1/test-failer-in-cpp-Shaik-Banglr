#pragma once
#include "WheatherSensorInterface.h"

class SensorStub : public IWeatherSensor {
public:
    SensorStub()
    :windspeed(52)
    ,temperature(26)
    ,precip(70)
    ,humidity(72)
    {

    }

    int Humidity() const override {
        return humidity;
    }

    int Precipitation() const override {
        return precip;
    }

    double TemperatureInC() const override {
        return temperature;
    }

    int WindSpeedKMPH() const override {
        return windspeed;
    }


private:
    int windspeed;
    double temperature;
    int precip;
    int humidity;
};

