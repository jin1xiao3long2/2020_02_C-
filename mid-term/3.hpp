#include <string>

class Country final{

private:

    std::string Country_name = "";
    double _area = 0; //km2
    long long int _population = 0; 
    double _density = 0;

public:

    Country() = delete;
    Country(std::string name, double area, int population, double density):
            Country_name(name), _area(area), _population(population), _density(density){}; 
    ~Country() = default;

    std::string get_name() const
    {
        return Country_name;
    }

    double get_area() const
    {
        return _area;
    }

    long long int get_population() const
    {
        return _population;
    }

    double get_density() const
    {
        return _density;
    }
};