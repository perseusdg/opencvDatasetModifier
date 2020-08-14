//
// Created by harshvardhan on 19/06/20.
//

#include "folderParser.h"
using namespace cv;

using std::cin;
using std::cout;
using std::fstream;
using std::to_string;

#if __has_include(<filesystem>)
    #include <filesystem>
    namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#endif


void folderParser::FolderParser(std::string &pathToDirectory,bool custom)
{
    int n = 0;
    for(const auto & entry:fs::directory_iterator(pathToDirectory))
        {
            n = n+1;
            std::string path = (entry.path().string());
            imageIntegrityCheckerAndPropertyRetriver(path,custom,n);

        }
    if(custom)
    {
        folderParser::lineNumbersCustom = n;
    }
    else
     {
        folderParser::lineNumbersReady=n;
     }

}
void folderParser::imageIntegrityCheckerAndPropertyRetriver(std::string &pathToImage,bool custom,int n)
{
    std::string resultLocation;
    std::string analysisLocation;
    Mat image;
    std::string current_path = fs::current_path().string();
    if(custom)
    {
        resultLocation = current_path + "/corruptedCustomImages.txt";
        analysisLocation = current_path + "/analysisCustom.csv";
    }
    else
    {
        resultLocation = current_path + "/corruptedImages.txt";
        analysisLocation = current_path + "/analysis.csv";
    }
    image = imread(pathToImage,IMREAD_COLOR);
    //checking image integrity here
    if(!image.data)
        {
            if(fs::exists(resultLocation))
                {
                    fstream imgFile;
                    imgFile.open(resultLocation,std::ios::app);
                    imgFile<<pathToImage<<std::endl;
                    imgFile.close();


                }
            else
                {
                    fstream imgFile;
                    imgFile.open(resultLocation,std::ios::out|std::ios::in);
                    imgFile<<pathToImage<<std::endl;
                    imgFile.close();
                }

        }
    else
        {

            int i_height = image.cols;
            int i_width = image.rows;
            fstream fout;
            fout.open(analysisLocation,std::ios::out|std::ios::app);
            fout<<n-1<<","<<pathToImage<<","<<i_height<<","<<i_width<<std::endl;
            fout.close();
        }

}
