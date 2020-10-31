#include <iostream>
#include <time.h>
#include <stdlib.h>

void aa()
{
    int j = rand();
    std::cout << "rand is  " << j << std::endl;
}


int main()
{
    srand((unsigned)(time(NULL)));
    for(int i = 0; i < 10; i++)
    {
        aa();
        
    }

    return 0;
}