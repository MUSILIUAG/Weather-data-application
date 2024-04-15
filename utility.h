#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <vector>


class Utility
{
public:
    Utility();

    static int getIntegerInput();
    static double getDoubleInput();
    static std::string vectorToString(std::vector<std::string> vector);
    static std::vector<std::string> stringArrayToVec(std::string string);
    static void toLower(std::string &str);
    static std::string getExtensionFromUrl(const std::string &url);
    static bool isValidDateFormat(const std::string& date);
    static bool isWithinRange(double value, double min, double max);
    static bool isWithinRange(int value, int min, int max);

};

#endif // UTILITY_H
