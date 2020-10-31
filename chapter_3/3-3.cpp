#include <iostream>

double arctan(double x)
{
    double sqr = x * x; 
    double e = x;
    double r = 0;
    int i = 1;
    while(e / i > 1e-15)
    {
        double f = e / i;
        r = (i % 4 == 1)? r + f : r - f;
        e = e * sqr;
        i += 2;
        std::cout << "the value of i is " << i << std::endl;
    }
    return r;
}

int main()
{
    arctan(1/5.0);
    return 0;
}