#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <jsoncpp/json/json.h>


class DataManager
{  
public:
    Json::Value DataJson;
    std::vector<std::string>weatherVariables{"temperature_2m","relative_humidity_2m","dew_point_2m"};



    DataManager();

    void loadDataMenu();
    void displayData();
    void setData(std::pair<double, double> geocoordinates);
    void handleVariableSelections(std::vector<std::string>);
};

#endif // DATAMANAGER_H
