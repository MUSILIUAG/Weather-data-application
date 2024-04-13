#include "apicontroller.h"
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "userpreferences.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include "datamanager.h"



APIController::APIController(){}

size_t APIController::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

Json::Value APIController::fetchJsonData(std::string url) {
    CURL *curl;
    CURLcode res;
    std::string apiResponse;
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







// Callback function to write data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Convert string to lowercase
void to_lower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Get file extension from URL
std::string get_extension_from_url(const std::string &url) {
    size_t dot_pos = url.find_last_of("=");
    if (dot_pos != std::string::npos) {
        std::string ext = url.substr(dot_pos + 1);
        to_lower(ext);
        return ext;
    }
    return "";
}

void testing(std::string url) {
    CURL *curl;
    CURLcode res;
    FILE *file;
    // Initialize curl session
    curl = curl_easy_init();
    if (curl) {
        // Set the URL to download
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Open a file to write the downloaded data
        std::string file_ext = get_extension_from_url(url);
        std::string file_name = "downloaded_file." + file_ext;
        file = fopen(file_name.c_str(), "wb");
        if (!file) {
            std::cerr << "Error opening file for writing" << std::endl;
        }

        // Set the callback function to write data to the file
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Check the content type to determine the file extension
            std::string content_type = get_extension_from_url(url);
            to_lower(content_type);
            if (file_ext == "csv")
            {
                // File is CSV
                std::cout << "File downloaded successfully as CSV!" << std::endl;
            }
            else if (content_type.find("json") != std::string::npos)
            {
                // File is JSON
                std::cout << "File downloaded successfully as JSON!" << std::endl;
            }
            else if (file_ext == "xlsx")
            {
                // File is XLSX
                std::cout << "File downloaded successfully as XLSX!" << std::endl;
            }
            else {

                std::cerr << "Unknown file format" << std::endl;
            }
        }

        // Clean up curl resources
        curl_easy_cleanup(curl);

        // Close the file
        fclose(file);
    } else {
        std::cerr << "Error initializing curl" << std::endl;
    }
}

void APIController::test(std::string url)
{
    testing(url);
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


