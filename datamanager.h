#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <jsoncpp/json/json.h>


class DataManager
{  
public:
    Json::Value DataJson;

    DataManager();

    virtual std::string getUrl() const = 0;
    virtual std::vector<std::pair<std::string, std::string>> getVariables() const = 0;

    void loadDataMenu();
    void handleVariableSelections(std::vector<std::pair<std::string, std::string>>);
    void handleModelSelections(std::vector<std::pair<std::string, std::string>>);

    void getData();
    void printSavedLocation();
    void idkk();
    void displayData(std::string hourlyOrDaily);
    void setHourlyOrDaily();

    void handleSolar(std::vector<std::pair<std::string, std::string>> solarVariables);
    void handleWeatherModels(std::vector<std::pair<std::string, std::string>> weatherModels);
    void handlePressure();
    void handleReanalysisModels(std::vector<std::pair<std::string, std::string>> reanalysisModels);






private:
    struct Variables
    {
        std::vector<std::pair<std::string, std::string>> solarVariables {
            {"Shortwave Radiation", "shortwave_radiation"},
            {"Direct Radiation", "direct_radiation"},
            {"Diffuse Radiation", "diffuse_radiation"},
            {"Direct Normal Irradiance", "direct_normal_irradiance"},
            {"Global Tilted Irradiance", "global_tilted_irradiance"},
            {"Terrestrial Radiation", "terrestrial_radiation"},
            {"Instant Shortwave Radiation", "shortwave_radiation_instant"},
            {"Instant Direct Radiation", "direct_radiation_instant"},
            {"Instant Diffuse Radiation", "diffuse_radiation_instant"},
            {"Instant Direct Normal Irradiance", "direct_normal_irradiance_instant"},
            {"Instant Global Tilted Irradiance", "global_tilted_irradiance_instant"},
            {"Instant Terrestrial Radiation", "terrestrial_radiation_instant"}
        };

        std::vector<std::pair<std::string, std::string>> reanalysisModels {
            {"ECMWF IFS (9 km, Global, 2017 onwards)", "ecmwf_ifs"},
            {"ERA5-Seamless (ERA5 & ERA5-Land combined)", "era5_seamless"},
            {"ERA5 (25 km, Global)", "era5"},
            {"ERA5-Land (10 km, Global)", "era5_land"},
            {"CERRA (5 km, Europe, 1985 to June 2021)", "cerra"}
        };

        std::vector<std::pair<std::string, std::string>> WeatherModels {
            {"ECMWF IFS 0.4°", "ecmwf_ifs04"},
            {"ECMWF IFS 0.25°", "ecmwf_ifs025"},
            {"ECMWF AIFS 0.25°", "ecmwf_aifs025"},
            {"CMA GRAPES Global", "cma_grapes_global"},
            {"BOM ACCESS Global", "bom_access_global"},
            {"MET Norway Nordic", "metno_nordic"},
            {"GFS Seamless", "gfs_seamless"},
            {"GFS Global", "gfs_global"},
            {"GFS HRRR", "gfs_hrrr"},
            {"JMA Seamless", "jma_seamless"},
            {"JMA MSM", "jma_msm"},
            {"JMA GSM", "jma_gsm"},
            {"DWD ICON Seamless", "icon_seamless"},
            {"DWD ICON Global", "icon_global"},
            {"DWD ICON EU", "icon_eu"},
            {"DWD ICON D2", "icon_d2"},
            {"GEM Seamless", "gem_seamless"},
            {"GEM Global", "gem_global"},
            {"GEM Regional", "gem_regional"},
            {"GEM HRDPS Continental", "gem_hrdps_continental"},
            {"Météo-France Seamless", "meteofrance_seamless"},
            {"Météo-France ARPEGE World", "meteofrance_arpege_world"},
            {"Météo-France ARPEGE Europe", "meteofrance_arpege_europe"},
            {"Météo-France AROME France", "meteofrance_arome_france"},
            {"Météo-France AROME France HD", "meteofrance_arome_france_hd"},
            {"ARPAE Seamless", "arpae_cosmo_seamless"},
            {"ARPAE COSMO 2I", "arpae_cosmo_2i"},
            {"ARPAE COSMO 2I RUC", "arpae_cosmo_2i_ruc"},
            {"ARPAE COSMO 5M", "arpae_cosmo_5m"}
        };
    };

};

#endif // DATAMANAGER_H
