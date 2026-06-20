#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

int main() {
    Eigen::Matrix2d m;
    m << 1, 2,
         3, 4;
    std::cout << "Eigen works. Matrix:\n" << m << "\n";
    std::cout << "Determinant: " << m.determinant() << "\n\n";

    std::cout << "OpenCV version: " << CV_VERSION << "\n";
    cv::Mat img = cv::Mat::zeros(2, 2, CV_8UC1);
    std::cout << "Created a " << img.rows << "x" << img.cols << " OpenCV image.\n";
    return 0;
}