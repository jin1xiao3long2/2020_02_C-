#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(std::vector<int> &list, int low, int high)
{
    int num = list[high];
    int i = low - 1;
    for(int j = low; j < high; j++)  //put the number less than num(list[high]) to someplace's left and the number bigger than someplace's to its right
    {
        if(list[j] <= num)
        {
            i++;
            Swap(list[i], list[j]);
        }
    }   
    Swap(list[i+1], list[high]);   // put the number to the middle so that list is like this-> [ a1,a2,a3... num b1,b2,b3 ] all the a is less than num and b is bigger than num
    return i+1; //return the position of num
}


int RandomizedPartition(std::vector<int> &list, int low, int high)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int i = (rand() % (high - low + 1)) + low;   //random number i;
    Swap(list[i], list[high]);   //change the  place of list[i] and list[high]
    return Partition(list, low, high);          //return the position of middle num
}



int RandomizedSelect(std::vector<int> &list, int low, int high, int k)
{
    if(low == high)
        return list[low];
    int i = RandomizedPartition(list, low, high);
    int j = i - low + 1;
    if(k == j) return list[i];
    else if(k < j)  return RandomizedSelect(list, low, i-1, k);
    else return RandomizedSelect(list, i+1, high, k-j);
}


int main()
{

    int i = 0, k = 0;
    std::cin >> i >> k;       //M  N
    std::vector<int> v;
    for(int j = 0; j < i; j++)
    {
        int m;
        std::cin >> m;    // for every element
        v.push_back(m);
    }
    //for(int m = 0; m < 100; m++)
    std::cout << RandomizedSelect(v, 0, i-1, i-k+1) << std::endl;
    for(auto z = 0; z < v.size(); z++)
    {
        std::cout << v.at(z) << " ";
    }
    return 0;
}