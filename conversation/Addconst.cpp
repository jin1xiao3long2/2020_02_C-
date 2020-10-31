#include <iostream>

class Foo{

private:

    int i = 0;

public:

    Foo(int j): i(j) {};
    ~Foo() = default;

    bool operator <(const Foo &rhs) const
    {
        return this->i < rhs.i;
    }
};


int main()
{
    Foo a(1);
    Foo b(2);
    std::cout << (a<b) << std::endl; 
}