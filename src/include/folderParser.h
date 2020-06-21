//
// Created by harshvardhan on 19/06/20.
//

#ifndef OPENCVDATASETCREATOR_FOLDERPARSER_H
#define OPENCVDATASETCREATOR_FOLDERPARSER_H
#include<filesystem>
#include<iostream>
#include<fstream>
#include<vector>
#include <opencv2/opencv.hpp>
class folderParser {
public:
    void FolderParser(std::string &pathToDirectory,bool custom);
    void imageIntegrityCheckerAndPropertyRetriver( std::string &pathToImage,bool custom,int n);
    int lineNumbersCustom;
    int lineNumbersReady;


};


#endif //OPENCVDATASETCREATOR_FOLDERPARSER_H
