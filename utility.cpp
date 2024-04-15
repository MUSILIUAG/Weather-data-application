#include "utility.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>
#include <regex>


Utility::Utility(){}

int Utility::getIntegerInput()
{
    int choice;
    while (true) {
        std::cout << "Enter: ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter an integer." << std::endl;
        }
        else
        {
            break;
        }
    }
    return choice;
}

double Utility::getDoubleInput()
{
// Function to validate double input
    double choice;
    // Loop until valid input is received
    while (true) {
        std::cout << "Enter: ";
        // Check if input is a double
        if (!(std::cin >> choice))
        {
            std::cin.clear(); // Clear the failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cerr << "Invalid input. Please enter a double." << std::endl;
        }
        else
        {
            // Input is valid, break out of the loop
            break;
        }
    }
    return choice;
}

bool Utility::isValidDateFormat(const std::string& date) {
       // Regular expression to match the format yyyy-mm-dd
       std::regex datePattern("\\d{4}-\\d{2}-\\d{2}");

       // Check if the input matches the pattern
       return std::regex_match(date, datePattern);
   }

bool Utility::isWithinRange(double value, double min, double max) {
    return (value >= min && value <= max);
}


bool Utility::isWithinRange(int value, int min, int max) {
    return (value >= min && value <= max);
}




std::string Utility::vectorToString(std::vector<std::string> vector)
{
    std::ostringstream oss;

    for (size_t i = 0; i < vector.size(); ++i) {
        if (i > 0) {
            oss << ",";
        }
        oss << vector[i]; // Adds only the  code
    }
    return oss.str(); // Returns the comma-separated string
}


std::vector<std::string> Utility::stringArrayToVec(std::string string){
    std::istringstream iss(string); //Gets the string array from the user

    std::string key;
    std::vector<std::string> keyToKeyVector;

    // adds the values to a vector
    while (std::getline(iss, key, ',')) {
        keyToKeyVector.push_back(key);
    }

    std::sort(keyToKeyVector.begin(), keyToKeyVector.end());
    return keyToKeyVector;

}

// Convert string to lowercase
void Utility::toLower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Get file extension from URL
std::string Utility::getExtensionFromUrl(const std::string &url) {
    size_t dot_pos = url.find_last_of("=");
    if (dot_pos != std::string::npos) {
        std::string ext = url.substr(dot_pos + 1);
        toLower(ext);
        return ext;
    }
    return "";
}
