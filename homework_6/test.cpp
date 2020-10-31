#include "people.hpp"

void CLEAR()
{
    std::cout << "----------------------------------------------------------------" << std::endl;
}

int main()
{
    people *ptr;
    CLEAR();
    ptr = new people("JinXiao", 20, male);
    ptr->show();
    delete ptr;
    CLEAR();
    ptr = new student("JinXiao", 20, male, "class 1");
    ptr->show();
    delete ptr;
    CLEAR();
    ptr = new teacher("Teacher Liu", 35, female, "professor", "1-1-2");
    ptr->show();
    delete ptr;
    CLEAR();
    ptr = new graduate("Jola", 24, male, "class 5", "Computer science", "Ye Qing");
    ptr->show();
    delete ptr;
    CLEAR();
    ptr = new TA("Dalao", 26, female, "class 2", "Music", "Teacher Liu", "assistant", "3-4-2", "good at LOL(XD)");
    ptr->show();
    delete ptr;
    CLEAR();
    return 0;
}