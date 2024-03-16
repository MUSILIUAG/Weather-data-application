#include "apicontroller.h"
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "usersettings.h"
#include <firebase/app.h>
#include <firebase/firestore.h>




extern UserSettings userSettings;

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
    std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + latitudeAsString +
                      "&longitude=" + longitudeAsString +
                      "&hourly=temperature_2m,relative_humidity_2m,precipitation_probability" +
                      "&daily=&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                      "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days="+userSettings.dayRange;


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


void APIController::test()
{
// Initialize Firebase
firebase::AppOptions options;
options.set_database_url("https://your-project-id.firebaseio.com");
firebase::App* app = firebase::App::Create(options);

// Initialize Firestore
firebase::firestore::Firestore* firestore = firebase::firestore::Firestore::GetInstance(app);

// Create a document reference
firebase::firestore::CollectionReference collection = firestore->Collection("your_collection");

// Convert JSON data to a map
std::map<std::string, firebase::firestore::FieldValue> data;
data["key1"] = firebase::firestore::FieldValue::String("value1");
data["key2"] = firebase::firestore::FieldValue::String("value2");

// Add the data to Firestore
collection.Add(data).OnCompletion([](const firebase::Future<firebase::firestore::DocumentReference>& future) {
    if (future.error() == firebase::firestore::kErrorNone) {
        std::cout << "Data added successfully" << std::endl;
    } else {
        std::cerr << "Error adding data to Firestore: " << future.error_message() << std::endl;
    }
});

// Wait for the operation to complete
while (!collection.is_valid()) {
    // Handle other events while waiting
}

// Cleanup
delete firestore;
delete app;

}
