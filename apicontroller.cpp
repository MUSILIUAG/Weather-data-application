#include "apicontroller.h"
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

APIController::APIController(){}

size_t APIController::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

Json::Value APIController::fetchWeatherData(std::pair<double, double> credentials) {
    CURL *curl;
    CURLcode res;
    std::string apiResponse;
    std::string latitudeAsString = std::to_string(credentials.first);
    std::string longitudeAsString = std::to_string(credentials.second);
    std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + latitudeAsString + "&longitude=" + longitudeAsString + "&hourly=temperature_2m,relative_humidity_2m,precipitation_probability&forecast_days=1";


    // Initialize cURL session
    curl = curl_easy_init();
    if (curl) {
        // Set the URL to make the GET request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set the callback function to receive data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &APIController::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &apiResponse);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Request successful, parse the JSON response
            Json::Value jsonRoot;
            Json::Reader jsonReader;
            if (jsonReader.parse(apiResponse, jsonRoot)) {
                // Process JSON data as needed
                if (jsonRoot.isObject()) {
//                    // Example: Extract coordinates
//                    if (jsonRoot.isMember("latitude") && jsonRoot["latitude"].isDouble() &&
//                        jsonRoot.isMember("longitude") && jsonRoot["longitude"].isDouble()) {
//                        double latitude = jsonRoot["latitude"].asDouble();
//                        double longitude = jsonRoot["longitude"].asDouble();
//                        std::cout << "Coordinates: " << latitude << "°N, " << longitude << "°E" << std::endl;
//                    }

//                    // Example: Extract hourly temperature data
//                    if (jsonRoot.isMember("hourly") && jsonRoot["hourly"].isObject() &&
//                        jsonRoot["hourly"].isMember("temperature_2m") && jsonRoot["hourly"]["temperature_2m"].isArray()) {
//                        const auto& hourlyData = jsonRoot["hourly"]["temperature_2m"];
//                        for (const auto& entry : hourlyData) {
//                            if (entry.isDouble()) {
//                                double temperature = entry.asDouble();
//                                std::cout << "Hourly temperature: " << temperature << std::endl;
//                            }
//                        }
//                    }
                return jsonRoot;
                }
            }
            else
            {
                std::cerr << "Failed to parse JSON response" << std::endl;
            }
            curl_easy_cleanup(curl);
        }

        // Clean up cURL resources
        curl_easy_cleanup(curl);
    }
    return Json::Value();
}
