#ifndef APICONTROLLER_H
#define APICONTROLLER_H

#include <string>
#include <jsoncpp/json/json.h>



// Forward declaration for CURL type
typedef void CURL;

class APIController {
public:
    APIController();
    Json::Value fetchJsonData(std::string url);
    void fetchDataToDownload(std::string url);

    // Public member function for writing data callback
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer);

private:
    // Private member variable for cURL handle
    CURL *curlHandle;
};

#endif // APICONTROLLER_H
