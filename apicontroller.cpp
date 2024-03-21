#include "apicontroller.h"
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "usersettings.h"
#include "datamanager.h"



APIController::APIController(){}

size_t APIController::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

Json::Value APIController::fetchWeatherData(std::string url) {
    CURL *curl;
    CURLcode res;
    std::string apiResponse;

    std::cout<<url.size()<<url<<std::endl;

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
                if (jsonRoot.isObject()) return jsonRoot;
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


//void APIController::test() {
//    // Initialize Firebase
//    firebase::AppOptions options;
//    options.set_database_url("https://your-project-id.firebaseio.com");
//    firebase::App::Create(options);

//    // Access the Firestore instance
//    firebase::firestore::Firestore* firestore = firebase::firestore::Firestore::GetInstance();

//    // Parse the JSON data from weatherData.weatherDataJson
//    Json::Value jsonData = weatherData.weatherDataJson; // Assuming weatherData is an instance of WeatherDataManager

//    // Create a map to hold the weather data
//    firebase::firestore::MapFieldValue weatherDataFirestore;

//    // Assuming the JSON structure contains temperature and humidity fields
//    weatherDataFirestore["temperature"] = firebase::firestore::FieldValue::Double(jsonData["temperature_2m"].asDouble());
//    weatherDataFirestore["humidity"] = firebase::firestore::FieldValue::Double(jsonData["relative_humidity_2m"].asDouble());

//    // Add the weather data to the Firestore collection
//    firestore->Collection("weather_collection").Add(weatherDataFirestore).OnCompletion(
//        [](const firebase::Future<firebase::firestore::DocumentReference>& future) {
//            if (future.error() == firebase::firestore::kErrorNone) {
//                std::cout << "Data added successfully" << std::endl;
//            } else {
//                std::cerr << "Error adding data to Firestore: " << future.error_message() << std::endl;
//            }
//        }
//    );

//    // Cleanup
//    // No need to delete Firestore and App objects immediately. Let them live until the operation is complete.
//    // delete firestore;
//    // delete app;
//}


