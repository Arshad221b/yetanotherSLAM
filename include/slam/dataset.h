//
// Created by Arshad K on 05/07/26.
//

#ifndef YETANOTHERSLAM_DATASET_H
#define YETANOTHERSLAM_DATASET_H


#pragma once              // prevents this header being included twice

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class Dataset {
public:
    // Constructor: takes the sequence folder, parses rgb.txt.
    Dataset(const std::string& sequence_folder);

    // How many frames were loaded.
    int size() const;

    // Load and return frame i from disk.
    cv::Mat get_image(int i) const;

private:
    std::string base_dir_;
    std::vector<double> timestamps_;
    std::vector<std::string> image_paths_;
};


#endif //YETANOTHERSLAM_DATASET_H
