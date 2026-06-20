//
// Created by Arshad K on 20/06/26.
//

#include <iostream>
#include <cmath>

class Point3D
{
public:
    double x;
    double y;
    double z;
    double degree;




    double distanceFromOrigin()
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    void rotationFromZaxis(double degrees)
    {
        double pi = 3.14;
        double r = degrees * pi / 180 ;
        double x_new = x * cos(r) - y * sin(r);
        double y_new = x * sin(r) + y * cos(r);

        x = x_new;
        y = y_new;
    }

    void rotationFromXaxis(double degrees)
    {
        double pi = 3.14;
        double r = degrees * pi / 180 ;
        double y_new = y * cos(r) - z * sin(r);
        double z_new = y * sin(r) + z * cos(r);

        z = z_new;
        y = y_new;
    }

    void rotationFromYaxis(double degrees)
    {
        double pi = 3.14;
        double r = degrees * pi / 180 ;
        double x_new = x * cos(r) + z * sin(r);
        double z_new = z * cos(r) - x * sin(r);

        x = x_new;
        z = z_new;
    }



};

int main()
{
    Point3D p;
    p.x = 1.0;
    p.y = 5.0;
    p.z = 5.0;
    p.degree = 30;

    std:: cout << "Points before the rotation: " << p.x << " " << p.y << " " << p.z << "\n";
    p.rotationFromXaxis(p.degree);
    std:: cout << "Points before the Y rotation: " << p.x << " " << p.y << " " << p.z << "\n";
    p.rotationFromYaxis(p.degree);
    std:: cout << "Points before the Z rotation: " << p.x << " " << p.y << " " << p.z << "\n";
    p.rotationFromZaxis(p.degree);
    std:: cout << "Points before the Z rotation: " << p.x << " " << p.y << " " << p.z << "\n";

}