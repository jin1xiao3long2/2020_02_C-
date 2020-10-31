#include "4.hpp"
#include <iostream>
#include <time.h>
int main()
{
    srand(time(0));
    Score Class1;
    student jola("jola", 60, Class1);
    student kiva("kiva", 100, Class1);
    student Lee("Lee", 101, Class1);
    for(int i = 0; i < 37; i++)
    {
        student stu("student"+std::to_string(i), rand() % 101, Class1);
    }
    std::cout << Class1.get_low().get_name() << " lowest score:  " << Class1.get_low().get_score() << std::endl;
    std::cout << Class1.get_high().get_name() << "  highest score:  " << Class1.get_high().get_score() << std::endl;
    std::cout <<  " Average score:  " << Class1.get_aver() << std::endl;
}