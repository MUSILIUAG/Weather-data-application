#ifndef DATAEXPORTER_H
#define DATAEXPORTER_H
#include "iostream"


class DataExporter
{
public:
    DataExporter(std::string url);


    void loadDataExporterMenu();
    void navToExporter();
    void exportData();

};

#endif // DATAEXPORTER_H
