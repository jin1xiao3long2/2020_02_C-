#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream &out, std::vector<int> v)
{
    for(auto const &c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return out;
}

int main()
{
    std::vector<std::vector<int>> v1;
    std::vector<int>  v = {3, 4, 5, 6, 7};
    v.push_back(4);

    if(std::find(v.begin(), v.end(), 8) != v.end() )
        std::cout << "here" ;
    else 
        std::cout << "there";

    std::cout << *(v.begin()) ;


    std::cout << v;
    std::vector<int> a;
    for(int i = 0; i < 5; i++)
    {
        v1.push_back(a);
    }    
    v1[0].push_back(2);
    std::cout << v1[1];

    return 0;
}