//
// Created by Arshad K on 20/06/26.
//

#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>


int main()
{
    Eigen::Vector3d p(1.0, 5.0, 5.0);
    double angle = 30.0 * M_PI / 180.0;


    Eigen::AngleAxisd rotZ(angle, Eigen::Vector3d::UnitZ());

    Eigen::Matrix3d R = rotZ.toRotationMatrix();
    std:: cout << "R: \n" << R << "\n";

    // applying extrinsic camera matrix to the p
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate(rotZ);
    T.pretranslate(Eigen::Vector3d(2, 2,2));




    std::cout << "T:\n" << T.matrix() << "\n";
    Eigen::Vector3d p_posed = T* p;
    std :: cout << "After full pose: " << p_posed.transpose() << "\n";
    std :: cout << "Length before: " << p.norm() << "\n";
    std :: cout << "Length after: " << p_posed.norm() << "\n";

    // apply p to the camera matrix (basis of SLAM)
    Eigen::Isometry3d T_inv  = T.inverse();
    std::cout << "T inverse \n" << T_inv.matrix() << "\n";

    Eigen::Vector3d p_back = T_inv * p_posed;
    std :: cout << "Original: \n" << p.transpose() << "\n";
    std :: cout << "Recoverd original: \n" << p_back.transpose() << "\n";

}