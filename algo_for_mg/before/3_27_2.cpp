#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int min,int max)
{
	time_t t; 
	srand((unsigned) time(&t)); 
	int i=int(rand()%(max-min+1))+min;
    return i;
}

int partition(vector<int>& vi,int start,int end)
{
	int key = vi[end];
	int i = start -1;
	for(int j = start;j < end;++j)
	{
		if(vi[j] < key)
		{
			++i;
			std::swap(vi[i], vi[j]);
		}
	}
	std::swap(vi[i+1], vi[end]);
	return i+1;
}

int randomized_partition(vector<int>& vi,int start,int end)
{
	int i = random(start,end);
	std::swap(vi[i], vi[end]);
	return partition(vi,start,end);

}

inline int randomized_select(vector<int>& vi,int start,int end,int i)
{
	if(start == end) return vi[start];
	
	int q = randomized_partition(vi,start,end);
	int k = q - start + 1;
	if(i == k)	return vi[q];
	else if(i < k)
		return randomized_select(vi,start,q-1,i);
	else
		return randomized_select(vi,q+1,end,i-k);
		
}

int main(int argc,char **argv)
{

	vector<int> vi;

    int all = 0, num = 0;
    std::cin >> all >> num;
    for(int i = 0; i < all; i++)
    {
        int c = 0;
        std::cin >> c;
        vi.push_back(c);
    }

    std::cout << randomized_select(vi, 0, vi.size() - 1, vi.size() - num + 1);
	return 0;

}

 
