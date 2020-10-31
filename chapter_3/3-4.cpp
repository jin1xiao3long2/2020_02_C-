#include <iostream>

bool symm(unsigned n)
{
    unsigned i = n;
    unsigned m = 0;
    int times = 0;
    while(i > 0)
    {
        times++;
        m = m * 10 + i % 10;
        i /= 10;    
        std::cout << "times = " << times << std::endl;
    }
    return m == n;
}

class Clock{
    int hour, minute, second;

public:
    Clock(int a, int b, int c);
    void show()
    {
        std::cout << hour << minute << second;
    }
};

int main()
{
    symm(233);
    Clock c;
    c.show();
    return 0;
}