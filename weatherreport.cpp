#include <assert.h>
#include <string>
#include <iostream>
#include "SensorStub.h"
using namespace std;

namespace WeatherSpace {

// This is a function to predict the weather, based on readings
// from a sensor


    bool isSunnyDay(const IWeatherSensor& s)
    {
        return (s.Precipitation() < 20);
    }

    bool iscloudy(const IWeatherSensor& s)
    {
        auto precip = s.Precipitation();
        return ((s.TemperatureInC() > 25) && (precip >= 20 && precip < 60));
    }

    bool isStormy(const IWeatherSensor& s)
    {
        auto precip = s.Precipitation();
        return ((s.TemperatureInC() > 25) && (precip < 20 || precip > 60) && s.WindSpeedKMPH() > 50);
    }

string Report(const IWeatherSensor& sensor) {
    string report;
    // precipitation < 20 is a sunny day
    if (isSunnyDay(sensor))
    {
        report = "Sunny day";
    }
     
    if (iscloudy(sensor))
    {
        report = "Partly cloudy";
    }

    if (isStormy(sensor))
    {
        report = "Alert, Stormy with heavy rain";
    }
    return report;
}

// Test a rainy day

void TestRainy() {
    SensorStub sensor;
    string report = Report(sensor);
    cout << "TestRainy testing"<<report << endl;
    assert(report.find("rain") != string::npos);
}

// Test another rainy day

void TestHighPrecipitationAndLowWindspeed() {
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    SensorStub sensor;

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    string report = Report(sensor);
    cout << "TestHighPrecipitationAndLowWindspeed"<<report << endl;
    assert(report.length() > 0);
}
}  // namespace WeatherSpace

int main() {
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitationAndLowWindspeed();
    cout << "All is well (maybe)\n";
    return 0;
}
