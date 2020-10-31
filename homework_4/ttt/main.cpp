#include "Point.h"
#include <iostream>

int main()
{
    Point a(4,5);
    std::cout << "Point A : " << a.GetX() << "," << a.GetY() << std::endl;
    Point::showCount();
    Point b(a);
    std::cout << "Point B : " << b.GetX() << "," << b.GetY() << std::endl;
    Point::showCount();
    return 0;
}