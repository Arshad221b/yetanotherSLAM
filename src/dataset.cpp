//
// Created by Arshad K on 05/07/26.
//

#include "../include/slam/dataset.h"
#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

Dataset:: Dataset(const std:: string& sequence_folder)
{
    base_dir_ = sequence_folder;
    std::string rgb_txt = base_dir_ + "/rgb.txt";
    std::ifstream file(rgb_txt);
    if (!file.is_open())
    {
        std:: cerr << "Could not open " << rgb_txt << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (line[0] == '#') continue;

        std::istringstream ss(line);
        double timestamp;
        std:: string path;

        ss >> timestamp >> path;
        timestamps_.push_back(timestamp);
        image_paths_.push_back(path);
    }
}

int Dataset::size() const{
    return image_paths_.size();
}

cv::Mat Dataset::get_image(int i) const
{
    std:: string full_path = base_dir_ + "/" + image_paths_[i];
    cv::Mat img = cv::imread(full_path);
    if (img.empty())
    {
        std:: cerr << "failed to load " << full_path << std::endl;
    }

    return img;
}
