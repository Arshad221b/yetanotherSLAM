//
// Created by Arshad K on 05/07/26.
//

#include "../include/slam/main.h"
#include "../include/slam/dataset.h"
#include <opencv2/opencv.hpp>

int main()
{
    Dataset dataset("/Users/michelangelo/Coding/yetanotherSLAM/data/rgbd_dataset_freiburg1_desk");

    for (int i =1; i <= dataset.size() - 1; i ++)
    {
        cv:: Mat img = dataset.get_image(i);
        if (img.empty()) continue;
        cv::imshow("frames", img);
        cv::waitKey(30);
    }
    return 0;
}