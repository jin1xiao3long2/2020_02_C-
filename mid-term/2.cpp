#include <iostream>

const double Pi = 3.1415926;

class SodaCan final{

private:

    double radius = 0;
    double height = 0;

public:

    SodaCan() = delete;
    SodaCan(double r, double h): radius(r), height(h) {};
    ~SodaCan() = default;

    double get_surface_area()
    {
        double circle_area = Pi * radius * radius;
        double c_area = 2 * radius * Pi * height;
        return circle_area * 2 + c_area;
    }

    double get_volume()
    {
        return Pi * radius * radius * height;
    }
};


int main(){
    SodaCan MySodaCan(3.2, 6.5);
    std::cout << "SodaCan's surface_area: " << MySodaCan.get_surface_area() << "cm * cm" << std::endl;
    std::cout << "SodaCan's volume: " << MySodaCan.get_volume() << "cm * cm * cm" << std::endl;
    return 0;
}