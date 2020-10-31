#include <iostream>
#include <vector>
#include <algorithm>

std::ostream& operator<<(std::ostream &out, std::vector<long long> v)
{
    for(auto const &c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return out;
}

void qzh(std::vector<long long> V1, std::vector<long long> V2, int low, int high)
{
    for(int i = low; i < high; i++)
    {   
        V2.push_back(V1.at(i));
        std::cout << V2;
        qzh(V1, V2, i+1, high);
        V2.pop_back();
    }   
}

int main()
{
    int num;
    std::cin >> num;
    std::vector<long long> v1;
    for(int i = 0; i < num; i++)
    {
        long long n;
        std::cin >> n;
        v1.push_back(n);
    }
    std::sort(v1.begin(), v1.end());
    std::vector<long long> v2;
    qzh(v1, v2, 0, num);

    return 0;
}