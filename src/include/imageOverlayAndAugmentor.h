//
// Created by harshvardhan on 19/06/20.
//

#ifndef OPENCVDATASETCREATOR_IMAGEOVERLAYANDAUGMENTOR_H
#define OPENCVDATASETCREATOR_IMAGEOVERLAYANDAUGMENTOR_H
#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<opencv2/opencv.hpp>

#include <fstream>
#include <random>
#include <sstream>


class imageOverlayAndAugmentor {
    public:
        void imageController(std::string &analysisCustom, std::string &analysis, const long analysisLineNumbers,const long analysisCustomLineNumbers);
        

private:
        cv::Mat imageBrightnessAndContrastControl(cv::Mat image,int brightnessRandom,int contrastRandom);
        cv::Mat imageOverlay(cv::Mat customImage,cv::Mat randomImage,int x,int y,std::string imageName);
        cv::Mat imageRotater(cv::Mat customImage, cv::Mat randomImage, int x, int y, std::string imageName);
        void boundingBox(int XMid,int YMid,int h,int w,std::string name);
        void imageSaver(std::string imgName,cv::Mat image);


};


#endif //OPENCVDATASETCREATOR_IMAGEOVERLAYANDAUGMENTOR_H
