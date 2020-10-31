#include <iostream>

struct TimeStruct{
    unsigned int Year;
    unsigned int Month;
    unsigned int Day;

    unsigned int Hour;
    unsigned int Minute;
    unsigned int Second;
};


int main()
{
    TimeStruct myTime = {2020, 3, 3, 15, 15, 00};

    bool is_leap_year = false;
    bool effective_data = false;
    std::cout << "Please enter the year" << std::endl;
    std::cin << myTime.Year;
    if(myTime % 100 == 0)
    {
        if(myTime % 400 == 0)
            is_leap_year = true;
        else 
            ;
    }
    else if(myTime % 4 == 0)
    {
        is_leap_year = true;
    }
    std::cout << "Please enter the month" << std::endl;
    do
    {
        std::cin << myTime.Month;
        if(myTime.Month > 0 && myTime.Month < 13)
            effective_data = true;
    } while (!effective_data);

    
}