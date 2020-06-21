#include <opencv2/opencv.hpp>
#include <iostream>
#include<string>
#include "imageOverlayAndAugmentor.h"
#include"folderParser.h"
using namespace cv;
namespace fs = std::filesystem;

int main()
{
    folderParser fParser;
    imageOverlayAndAugmentor img;
    std::string folder_custom,folder_readymade;

    std::cout<<"Enter the absolute path of dataset to be imposed on:";
    std::getline(std::cin,folder_readymade);
    std::cout<<std::endl;

    std::cout<<"Enter the absolute path of dataset that is to be imposed";
    std::getline(std::cin,folder_custom);
    std::cout<<std::endl;

    int choice;
    std::cout<<"Would you like to perform image augmentation on both datasets(0),on the your dataset(1),on the readymade dataset(2) :";
    std::cin>>choice;
    if(choice == 0)
    {
        std::cout<<"Image augmentation will be performed on both";
    }
    else if(choice == 1)
    {
        std::cout<<"Image augmentation will be performed on your dataset";
    }
    else if(choice == 2)
    {
        std::cout<<"Limited image augmentation will be performed on the ready made dataset only";
    }
    else
    {
        std::cout<<"Incorrect entry,exiting program!!";
        return -1;
    }
    fParser.FolderParser(folder_readymade,false);
    fParser.FolderParser(folder_custom,true);
    std::string current_path = fs::current_path();

    std::string analysisCustomLocation =current_path + "/analysisCustom.csv";
    std::string analysisLocation =current_path + "/analysis.csv";
    std::cout<<fParser.lineNumbersCustom<<std::endl;
    std::cout<<fParser.lineNumbersReady<<std::endl;

    img.imageController(analysisCustomLocation,analysisLocation,fParser.lineNumbersReady,fParser.lineNumbersCustom);



    std::cout<<fParser.lineNumbersCustom<<std::endl;
    std::cout<<fParser.lineNumbersReady<<std::endl;
    return 0;



}
