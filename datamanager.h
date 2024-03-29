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
    void getData();
    void idk();
    void idkk();
    void displayData();

};

#endif // DATAMANAGER_H
