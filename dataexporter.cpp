#include "dataexporter.h"
#include "iostream"
#include <fstream>
#include "apicontroller.h"





APIController apiController;
std::string baseUrl;


DataExporter::DataExporter(std::string url)
{
   baseUrl = url;
}

void DataExporter::loadDataExporterMenu()
{

    std::cout<<"\n"<<"<<<<DATA EXPORTER>>>>"<<std::endl;

    std::cout<<"1 - Export Data "<<std::endl;
    std::cout<<"2 - Exit "<<std::endl;

    navToExporter();


}

void DataExporter::navToExporter( )
{
    std::cout <<"\n"<< "choose 1 - 2: ";
    int choice;
    std::cin>>choice;

    switch(choice)
    {
    case 1:
        exportData();
        break;
    case 2:
        //exit
        break;
    default:
        loadDataExporterMenu();
        break;


    }

}



void DataExporter::exportData()
{

std::cout<<"Formats csv, xlsx, json "<<std::endl;
std::string format;
std::cin>>format;


std::string completeUrl = baseUrl + "&format=" + format;

apiController.fetchDataToDownload(completeUrl);

}
















