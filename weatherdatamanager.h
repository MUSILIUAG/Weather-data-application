#ifndef WEATHERDATAMANAGER_H
#define WEATHERDATAMANAGER_H

#include "datamanager.h"

class WeatherDataManager : public DataManager
{
public:



    WeatherDataManager();
    std::string getUrl() const override;
    std::vector<std::string> getVariables() const override;


private:
    struct Variables{
    std::vector<std::string> varibles{"temperature_2m", "relative_humidity_2m", "dew_point_2m", "apparent_temperature"
        , "precipitation_probability", "precipitation", "rain", "showers", "snowfall", "snow_depth"
        , "weather_code", "pressure_msl", "surface_pressure", "cloud_cover", "cloud_cover_low"
        , "cloud_cover_mid", "cloud_cover_high"};
    };

}; // Add a closing brace to close the class declaration

#endif // WEATHERDATAMANAGER_H
