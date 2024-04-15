#ifndef WEATHERDATAMANAGER_H
#define WEATHERDATAMANAGER_H

#include "datamanager.h"

class WeatherDataManager : public DataManager
{
public:



    WeatherDataManager();
    std::string getUrl() const override;
    std::vector<std::pair<std::string, std::string>> getVariables() const override;
    void handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables) const override;
    void handleSolar() const;





private:
    void handleAdditionalVariables() const;
    void handlePressure() const;
    void handleWeatherModels() const ;

    struct variables{
        std::vector<std::pair<std::string, std::string>> hourlyVariables {
            {"Temperature","temperature_2m"},
            {"Relative Humidity","relative_humidity_2m"},
            {"Dew Point","dew_point_2m"},
            {"Apparent Temperature","apparent_temperature"},
            {"Precipitation Probability","precipitation_probability"},
            {"Precipitation","precipitation"},
            {"Rain","rain"},
            {"Showers","showers"},
            {"Snowfall","snowfall"},
            {"Snow Depth","snow_depth"},
            {"Weather Code","weather_code"},
            {"Pressure MSL","pressure_msl"},
            {"Surface Pressure","surface_pressure"},
            {"Cloud Cover","cloud_cover"},
            {"Low Cloud Cover","cloud_cover_low"},
            {"Mid Cloud Cover","cloud_cover_mid"},
            {"High Cloud Cover","cloud_cover_high"},
            {"Visibility","visibility"},
            {"Evapotranspiration","evapotranspiration"},
            {"ET0 FAO Evapotranspiration","et0_fao_evapotranspiration"},
            {"Vapour Pressure Deficit","vapour_pressure_deficit"},
            {"Wind Speed (10 m)","wind_speed_10m"},
            {"Wind Speed (80 m)","wind_speed_80m"},
            {"Wind Speed (120 m)","wind_speed_120m"},
            {"Wind Speed (180 m)","wind_speed_180m"},
            {"Wind Direction (10 m)","wind_direction_10m"},
            {"Wind Direction (80 m)","wind_direction_80m"},
            {"Wind Direction (120 m)","wind_direction_120m"},
            {"Wind Direction (180 m)","wind_direction_180m"},
            {"Wind Gusts (10 m)","wind_gusts_10m"},
            {"Temperature (80 m)","temperature_80m"},
            {"Temperature (120 m)","temperature_120m"},
            {"Temperature (180 m)","temperature_180m"},
            {"Soil Temperature (0 cm)","soil_temperature_0cm"},
            {"Soil Temperature (6 cm)","soil_temperature_6cm"},
            {"Soil Temperature (18 cm)","soil_temperature_18cm"},
            {"Soil Temperature (54 cm)","soil_temperature_54cm"},
            {"Soil Moisture (0-1 cm)","soil_moisture_0_to_1cm"},
            {"Soil Moisture (1-3 cm)","soil_moisture_1_to_3cm"},
            {"Soil Moisture (3-9 cm)","soil_moisture_3_to_9cm"},
            {"Soil Moisture (9-27 cm)","soil_moisture_9_to_27cm"},
            {"Soil Moisture (27-81 cm)","soil_moisture_27_to_81cm"},

            ///special Variables with extra selections
            {"Additional Variables","Special Variable with Extra selection"},
            {"Solar Radiaton Variables","Special Variable with Extra selection"},
            {"Pressure Variables","Special Variable with Extra selection"},
            {"Weather Models","Special Variable with Extra selection"}
        };

        std::vector<std::pair<std::string, std::string>> dailyVariables {
            {"Weather Code", "weather_code"},
            {"Temperature 2m Max", "temperature_2m_max"},
            {"Temperature 2m Min", "temperature_2m_min"},
            {"Apparent Temperature Max", "apparent_temperature_max"},
            {"Apparent Temperature Min", "apparent_temperature_min"},
            {"Sunrise", "sunrise"},
            {"Sunset", "sunset"},
            {"Daylight Duration", "daylight_duration"},
            {"Sunshine Duration", "sunshine_duration"},
            {"UV Index Max", "uv_index_max"},
            {"UV Index Clear Sky Max", "uv_index_clear_sky_max"},
            {"Precipitation Sum", "precipitation_sum"},
            {"Rain Sum", "rain_sum"},
            {"Showers Sum", "showers_sum"},
            {"Snowfall Sum", "snowfall_sum"},
            {"Precipitation Hours", "precipitation_hours"},
            {"Precipitation Probability Max", "precipitation_probability_max"},
            {"Wind Speed 10m Max", "wind_speed_10m_max"},
            {"Wind Gusts 10m Max", "wind_gusts_10m_max"},
            {"Wind Direction 10m Dominant", "wind_direction_10m_dominant"},
            {"Shortwave Radiation Sum", "shortwave_radiation_sum"},
            {"ET0 FAO Evapotranspiration", "et0_fao_evapotranspiration"}
        };

        std::vector<std::pair<std::string, std::string>> additionalVariables {
             {"UV Index", "uv_index"},
             {"UV Index Clear Sky", "uv_index_clear_sky"},
             {"Is Day or Night", "is_day"},
             {"CAPE", "cape"},
             {"Freezing Level Height", "freezing_level_height"},
             {"Sunshine Duration", "sunshine_duration"}
        };
        std::vector<std::pair<std::string, std::string>> weatherModels {
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

        std::vector<std::pair<std::string, std::string>> solarVariables {
            {"Shortwave Solar Radiation GHI", "shortwave_radiation"},
            {"Direct Solar Radiation", "direct_radiation"},
            {"Diffuse Solar Radiation DHI", "diffuse_radiation"},
            {"Direct Normal Irradiance DNI", "direct_normal_irradiance"},
            {"Global Tilted Radiation GTI", "global_tilted_irradiance"},
            {"Terrestrial Solar Radiation", "terrestrial_radiation"},
            {"Shortwave Solar Radiation GHI (Instant)", "shortwave_radiation_instant"},
            {"Direct Solar Radiation (Instant)", "direct_radiation_instant"},
            {"Diffuse Solar Radiation DHI (Instant)", "diffuse_radiation_instant"},
            {"Direct Normal Irradiance DNI (Instant)", "direct_normal_irradiance_instant"},
            {"Global Tilted Radiation GTI (Instant)", "global_tilted_irradiance_instant"},
            {"Terrestrial Solar Radiation (Instant)", "terrestrial_radiation_instant"}
        };


        std::vector<std::pair<std::string, std::string>> pressureLevelDomain {
            {"Temperature", "temperature_"},
            {"Relative Humidity", "relative_humidity_"},
            {"Cloud cover","cloud_cover_"},
            {"Wind speed","wind_speed_"},
            {"Wind Direction", "wind_direction_"},
            {"Geopontential Height","geopotential_height_"}
        };

        std::vector<std::pair<std::string, std::string>> pressureLevel {
        {"1000 hPa (110 m)", "1000hPa"},
        {"975 hPa (320 m)", "975hPa"},
        {"950 hPa (500 m)", "950hPa"},
        {"925 hPa (800 m)", "925hPa"},
        {"900 hPa (1000 m)", "900hPa"},
        {"850 hPa (1500 m)", "850hPa"},
        {"800 hPa (1900 m)", "800hPa"},
        {"700 hPa (3 km)", "700hPa"},
        {"600 hPa (4.2 km)", "600hPa"},
        {"500 hPa (5.6 km)", "500hPa"},
        {"400 hPa (7.2 km)", "400hPa"},
        {"300 hPa (9.2 km)", "300hPa"},
        {"250 hPa (10.4 km)", "250hPa"},
        {"200 hPa (11.8 km)", "200hPa"},
        {"150 hPa (13.5 km)", "150hPa"},
        {"100 hPa (15.8 km)", "100hPa"},
        {"70 hPa (17.7 km)", "70hPa"},
        {"50 hPa (19.3 km)", "50hPa"},
        {"30 hPa (22 km)", "30hPa"}
        };
    };
    variables weatherVariables;

}; // Add a closing brace to close the class declaration

#endif // WEATHERDATAMANAGER_H
