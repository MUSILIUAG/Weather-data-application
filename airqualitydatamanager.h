#ifndef AIRQUALITYDATAMANAGER_H
#define AIRQUALITYDATAMANAGER_H
#include "datamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;

class AirQualityDataManager:public DataManager
{
public:
    std::string getUrl() const override;
    std::vector<std::pair<std::string, std::string>> getVariables() const override;


    AirQualityDataManager();


private:
    struct hourlyVariables {
        std::vector<std::pair<std::string, std::string>> variables {
            {"Particulate Matter PM10", "pm10"},
            {"Particulate Matter PM2.5", "pm2_5"},
            {"Carbon Monoxide CO", "carbon_monoxide"},
            {"Nitrogen Dioxide NO2", "nitrogen_dioxide"},
            {"Sulphur Dioxide SO2", "sulphur_dioxide"},
            {"Ozone O3", "ozone"},
            {"Aerosol Optical Depth", "aerosol_optical_depth"},
            {"Dust", "dust"},
            {"UV Index", "uv_index"},
            {"UV Index Clear Sky", "uv_index_clear_sky"},
            {"Ammonia NH3 (*)", "ammonia"},
            {"Alder Pollen (*)", "alder_pollen"},
            {"Birch Pollen (*)", "birch_pollen"},
            {"Grass Pollen (*)", "grass_pollen"},
            {"Mugwort Pollen (*)", "mugwort_pollen"},
            {"Olive Pollen (*)", "olive_pollen"},
            {"Ragweed Pollen (*)", "ragweed_pollen"}
        };

    };


};

#endif // AIRQUALITYDATAMANAGER_H
