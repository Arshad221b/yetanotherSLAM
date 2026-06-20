//
// Created by Arshad K on 20/06/26.
//

#include <iostream>
#include <cmath>

int main()
{
    double x = 1.0;
    double y = 5.0;
    double distance_before_rotation = std::sqrt(x*x + y*y);
    double pi = 3.14159265358979;
    double degree = 30.0;
    double radian = degree * pi / 180;

    double x_new = x * cos(radian) - y * sin(radian);
    double y_new = x * sin(radian) + y * cos(radian);
    double distance_after_rotation = std::sqrt(x_new*x_new + y_new*y_new);

    std:: cout << "After rotating 90deg: " << x_new << "\n\n";
    std:: cout << "After rotating 90deg: " << y_new << "\n\n";

    std:: cout << "before rotation distance: " << distance_before_rotation << "\n\n";
    std:: cout << "after rotation distance: " << distance_after_rotation << "\n\n";
    return 0;

}
