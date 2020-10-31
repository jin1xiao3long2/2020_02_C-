#include "head.hpp"

Foo::Foo()
{
    std::cout << "cons" << std::endl;
}

Foo::~Foo()
{
    std::cout << "des" << std::endl;
}

Foo::Foo(int b)
{
    c = b;
    std::cout << "conscopy" << std::endl;
}
