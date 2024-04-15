#ifndef DATAEXPORTER_H
#define DATAEXPORTER_H
#include "iostream"


class DataExporter
{
public:
    DataExporter(std::string url);


    void loadDataExporterMenu();
    void exportData();

private:
    void navToExporter();
};

#endif // DATAEXPORTER_H
