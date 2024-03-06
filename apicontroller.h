#ifndef APICONTROLLER_H
#define APICONTROLLER_H

#include <string>

// Forward declaration for CURL type
typedef void CURL;

// Forward declaration for APIController class
class APIController {
public:
    // Constructor
    APIController();

    // Method to display weather data
    void fetchWeatherData();

    // Public member function for writing data callback
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer);

private:
    // Private member variable for cURL handle
    CURL *curlHandle;
};

#endif // APICONTROLLER_H
