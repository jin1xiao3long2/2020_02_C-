#include "people.hpp"

int main()
{

    People _person_A(13312345678, male, Date(2000, 5, 9), 1);
    People _person_B(13387654321, female, Date(2000, 7, 21), 2);
    if(_compare_Behavior(_person_A, _person_B) == 1)
        std::cout << "A is elder" << std::endl;
    else if(_compare_Behavior(_person_A, _person_B) == -1)
        std::cout << "B is elder" << std::endl;
    else
        std::cout << "They are the same" << std::endl;
    _person_A._show_Information();
    _person_A._set_Number(13322222222);
    std::cout << "Information changed" << std::endl;
    _person_A._show_Information();
    
    return 0;
}