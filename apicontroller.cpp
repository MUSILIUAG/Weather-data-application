#include "apicontroller.h"
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "usersettings.h"
#include <firebase/app.h>
#include <firebase/firestore.h>
#include "datamanager.h"





extern UserSettings userSettings;

APIController::APIController(){}

size_t APIController::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

Json::Value APIController::fetchWeatherData(std::pair<double, double> geocoordinates) {
    CURL *curl;
    CURLcode res;
    std::string apiResponse;
<<<<<<< HEAD
    std::string latitudeAsString = std::to_string(geocoordinates.first);
    std::string longitudeAsString = std::to_string(geocoordinates.second);
    std::string url;
=======
    std::string latitudeAsString = std::to_string(credentials.first);
    std::string longitudeAsString = std::to_string(credentials.second);
    std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + latitudeAsString +
                      "&longitude=" + longitudeAsString +
                      "&hourly=temperature_2m,relative_humidity_2m,precipitation_probability,is_day" +
                      "&daily=&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                      "&precipitation_unit="+userSettings.currentPercipitationUnit;

>>>>>>> b9ef956ed2f28bf2688b9187f845c0c48dc1ae7b

    // uses the users settings to make to specify if to use days to specify or if to use range for historical data
    if(userSettings.startDate == "")//checks if the user has any saved range settings
    {
<<<<<<< HEAD
        url = "https://api.open-meteo.com/v1/forecast?latitude=" + latitudeAsString + "&longitude=" + longitudeAsString +
                "&hourly="+userSettings.userSelections +
                "&daily=&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days="+userSettings.dayRange;
    }
    else{
        url = "https://archive-api.open-meteo.com/v1/archive?latitude=" + latitudeAsString + "&longitude=" + longitudeAsString +
                "&start_date="+userSettings.startDate+"&end_date="+userSettings.endDate +
                "&hourly="+ userSettings.userSelections + ",is_day" +
                "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit;
=======
        url += "&forecast_days="+userSettings.dayRange;
    }
    else{
        url += "&start_date="+userSettings.startDate+"&end_date="+userSettings.endDate;
>>>>>>> b9ef956ed2f28bf2688b9187f845c0c48dc1ae7b
    }


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


