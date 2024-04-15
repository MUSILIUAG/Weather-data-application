#include "apicontroller.h"
#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "userpreferences.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include "utility.h"
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



void APIController::fetchDataToDownload(std::string url) {
    CURL *curl;
    CURLcode res;
    FILE *file;
    // Initialize curl session
    curl = curl_easy_init();
    if (curl) {
        // Set the URL to download
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Open a file to write the downloaded data
        std::string file_ext = Utility::getExtensionFromUrl(url);
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
            std::string content_type = Utility::getExtensionFromUrl(url);
            Utility::toLower(content_type);
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

