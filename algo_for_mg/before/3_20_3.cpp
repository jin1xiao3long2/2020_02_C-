#include <iostream>
#include <vector>
#include <numeric>

std::ostream& operator<<(std::ostream& out, const std::vector<int> &v) 
{
    for(auto const &c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return out;
}


void give(std::vector<int> v, int low, int high)
{
    for(int i = low; ; i++) 
    {
        if(v[low] > v[high])
        {
            v[low]--;
            v[high]++;
            if(v[low] >= v[high])
            std::cout << v;
        }

        if(high < v.size() - 1)
        {
            if(v[high] - v[high+1] > 1)
                give(v, low+1, high+1);
        }       
        int sum = std::accumulate(v.begin() + low, v.end(), 0);
        int num = v.size() - low ;
        int end = sum / num;
        if(sum % num != 0)
            end += 1;
        std::cout << "sum & num & end   " << sum << "  " << num << "  " << end << std::endl;
        if(v[low] == end)
            break;
    }
}


int main()
{
    int all = 0;
    int num = 0;
    std::cin >> all >> num;

    std::vector<int> v;
    for(int i = 0; i < num; i++) // set 
    {
        if(!i)
            v.push_back(all);
        else
            v.push_back(0);
    }

    give(v, 0, 1);


    return 0;
}