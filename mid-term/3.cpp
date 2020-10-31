#include <iostream>
#include <vector>
#include "3.hpp"

void show_info(Country country)
{
    std::cout << "Country name:  " << country.get_name() << std::endl;
    std::cout << "area:  " << country.get_area() << "km2" << std::endl;
    std::cout << "population:  " << country.get_population() << std::endl;
    std::cout << "density:  " << country.get_density() << " person/km2\n" << std::endl;
}

Country get_max_area(const std::vector<Country> &v)
{
    double area_max = 0;
    int i = 0;
    int temp = 0;
    for(auto const e : v)
    {
        if(e.get_area() > area_max)
        {
            //std::cout << e.get_name() << "   " << e.get_population() << "   " << pop_max << std::endl;
            area_max = e.get_area();
            temp = i;
        }
        i++;
    }
    return v[temp];
}

Country get_max_population(const std::vector<Country> &v)
{
    long long int pop_max = 0;
    int i = 0;
    int temp = 0;
    for(auto const e : v)
    {
        if(e.get_population() > pop_max)
        {
            //std::cout << e.get_name() << "   " << e.get_population() << "   " << pop_max << std::endl;
            pop_max = e.get_population();
            temp = i;
        }
        i++;
    }
    return v[temp];
}

Country get_max_density(const std::vector<Country> &v)
{
    double den_max = 0;
    int i = 0;
    int temp = 0;
    for(auto const e : v)
    {
        if(e.get_density() > den_max)
        {
            //std::cout << e.get_name() << "   " << e.get_population() << "   " << pop_max << std::endl;
            den_max = e.get_density();
            temp = i;
        }
        i++;
    }
    return v[temp];
}

int main()
{
    std::vector<Country> v;
    Country China("China", 9634057, 1400050000, 144.3);
    v.push_back(China);
    Country Korea("Korea", 100210, 51635256, 529.7);
    v.push_back(Korea);
    Country Japan("Japan", 377972.28, 124776364, 347.8);
    v.push_back(Japan);
    Country America("America", 9370000, 330000000, 35.6);
    v.push_back(America);
    Country Fake_country("jo", 11111111, 22222222,2);
    v.push_back(Fake_country);
    show_info(China);
    std::cout << "max area country: " << std::endl;
    show_info(get_max_area(v));
    std::cout << "max population country: " << std::endl;
    show_info(get_max_population(v));
    std::cout << "max density country: " << std::endl;
    show_info(get_max_density(v));
    
    return 0;
}