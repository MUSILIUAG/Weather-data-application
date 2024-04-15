#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <jsoncpp/json/json.h>


class DataManager
{  
public:

    DataManager();
    void loadDataMenu();


    virtual std::string getUrl() const = 0;
    virtual std::vector<std::pair<std::string, std::string>> getVariables() const = 0;
    virtual void handleVariableSelections(std::vector<std::pair<std::string, std::string>>) const = 0 ;

    std::vector<std::string> handleKeySelection(std::vector<std::pair<std::string, std::string>> allVariables) const;
    std::string setHourlyOrDaily() const;

private:
    Json::Value DataJson;

    void locationSelectionHandler();
    void selectDerivedClassAddress();
    void getData();
    void getWeatherVariables();
    void displayData();

    DataManager* ptr;

};

#endif // DATAMANAGER_H
