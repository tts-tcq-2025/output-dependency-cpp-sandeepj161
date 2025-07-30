#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        double temperature;
        int precipitation;
        int humidity;
        int windSpeed;

        public:
            SensorStub(double temp, int precip, int hum, int wind) : temperature(temp), precipitation(precip), humidity(hum), windSpeed(wind) {}
        double TemperatureInC() const override {
            return temperature;
        }
        int Precipitation() const override {
            return precipitation;
        }
        int Humidity() const override {
            return humidity;
        }
        int WindSpeedKMPH() const override {
            return windSpeed;
        }
    };

    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    void TestRainy()
    {
        SensorStub sensor(26, 70, 72, 40); // temp, precipitation, humidity, wind
        std::string report = Report(sensor);
        assert(report.find("rain") != std::string::npos);
    }

    void TestHighPrecipitation()
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        SensorStub sensor(26, 70, 72, 52);

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        std::string report = Report(sensor);
        assert(report.length() > 0);
    }
}

void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}
