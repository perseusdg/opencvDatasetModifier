#include <opencv2/opencv.hpp>
#include <iostream>
#include<string>
#include "imageOverlayAndAugmentor.h"
#include"folderParser.h"
using namespace cv;

#if __has_include(<filesystem>)
    #include <filesystem>
    namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#endif

int main()
{
    folderParser *fParser = new folderParser;
    imageOverlayAndAugmentor *img = new imageOverlayAndAugmentor;
    std::string folder_custom,folder_readymade;

    std::cout<<"Enter the absolute path of dataset to be imposed on:";
    std::getline(std::cin,folder_readymade);
    std::cout<<std::endl;

    std::cout<<"Enter the absolute path of dataset that is to be imposed";
    std::getline(std::cin,folder_custom);
    std::cout<<std::endl;

   
    fParser->FolderParser(folder_readymade,false);
    fParser->FolderParser(folder_custom,true);
    std::string current_path = fs::current_path().string();

    std::string analysisCustomLocation =current_path + "/analysisCustom.csv";
    std::string analysisLocation =current_path + "/analysis.csv";
   

    img->imageController(analysisCustomLocation,analysisLocation,fParser->lineNumbersReady ,fParser->lineNumbersCustom );
   
   
    delete img;
    delete fParser;


}
