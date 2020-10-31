#include <vector>
#include <iostream>

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


std::ostream& operator<<(std::ostream& out, std::vector<int> v)
{
    for(auto const c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return out;
}

int main()
{

    std::vector<int> v = {1, 3, 5};
    std::cout << v;
    Swap(v[1], v[0]);
    std::cout << v;
}