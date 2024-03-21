#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <jsoncpp/json/json.h>


class DataManager
{  
public:
    Json::Value DataJson;
    std::vector<std::string>weatherVariables{"temperature_2m","relative_humidity_2m","dew_point_2m"};
    std::string url = "1";



    DataManager();

    void loadDataMenu();
    void displayData();
    void getData();
    void handleVariableSelections(std::vector<std::string>);
};

#endif // DATAMANAGER_H
