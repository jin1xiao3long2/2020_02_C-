#include "head.hpp"


int main()
{
    Foo* a = new Foo();
    std::cout << "a" << std::endl;
    Foo* b = new Foo(3);
    delete a;
    delete b;

    return 0;
}
