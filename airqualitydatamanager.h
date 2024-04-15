#ifndef AIRQUALITYDATAMANAGER_H
#define AIRQUALITYDATAMANAGER_H
#include "datamanager.h"
#include "userpreferences.h"

extern UserPreferences userSettings;

class AirQualityDataManager:public DataManager
{
public:
    std::string getUrl() const override;
    std::vector<std::pair<std::string, std::string>> getVariables() const override;
    void handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables) const override;



    AirQualityDataManager();


private:
    void handleEuropeanAirqualityVariables() const;

    struct variables {
        std::vector<std::pair<std::string, std::string>> hourlyVariables {
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
            {"Ragweed Pollen (*)", "ragweed_pollen"},

            ///special Varibles with extra selections
            {"European AirQuality Index","Special Variable with Extra selection"}

        };
        std::vector<std::pair<std::string, std::string>> europeanAirQualityVariables = {
            {"European AQI", "european_aqi"},
            {"European AQI PM2.5", "european_aqi_pm2_5"},
            {"European AQI PM10", "european_aqi_pm10"},
            {"European AQI NO2", "european_aqi_nitrogen_dioxide"},
            {"European AQI O3", "european_aqi_ozone"},
            {"European AQI SO2", "european_aqi_sulphur_dioxide"}
        };

    };
    variables airQualityVariables;


};

#endif // AIRQUALITYDATAMANAGER_H
