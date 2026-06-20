//
// Created by Arshad K on 20/06/26.
//
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>


int main()
{
    Eigen::Vector3d p(1.09, 5.0, 5.0);
    double angle = 30.0 * M_PI / 180.0;
    std:: cout << "angle: " << angle << "\n";

    // rotation about Z axis
    Eigen::AngleAxisd rotZ(angle, Eigen::Vector3d::UnitZ());
    std::cout << "rotation angle" << rotZ.angle() << "\n";
    std::cout << "rotation axis" << rotZ.axis().transpose() << "\n";
    Eigen::Matrix3d R = rotZ.toRotationMatrix();
    std:: cout << "R: \n" << R << "\n";

    Eigen::Vector3d p_rotated = R * p;


    std::cout << "Before: " << p.transpose() << "\n";
    std::cout << "After: " << p_rotated.transpose() << "\n";
    std::cout << "Before: " << p.norm() << "\n";
    std::cout << "Length after: " << p_rotated.norm() << "\n";


}