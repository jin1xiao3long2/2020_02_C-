#include "Integer.hpp"

int main(int argc, char* argv[])
{
    Integer* A = new Integer(5);
    Integer* B = new Integer(7);
    A->Show_Value();
    B->Show_Value();
    A->add(*B);
    A->Show_Value();
    A->~Integer(); // can be cancelled
    B->~Integer(); // the same as above
    delete A;
    delete B;
    return 0;
}