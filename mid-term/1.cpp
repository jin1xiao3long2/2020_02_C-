#include <iostream>
class A {
private:
    int i;
public:
    A(int x) { i = x; }
    ~A(){std::cout << i << std::endl;}
};
int main() {
    A a(1);
    A * pa = new A(2);
    delete pa;
    return 0;
}