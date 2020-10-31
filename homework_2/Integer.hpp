#include <iostream>

class Integer final{

private:

    int _value = 0;

public:

    Integer() = default;
    Integer(int num): _value(num){};
    Integer(const Integer &Int): _value(Int._value){};
    ~Integer() = default;
    Integer operator=(const Integer &Int)
    {
        this->_value = Int._value;
        return *this;
    }

public:
    void Show_Value()
    {
        std::cout << this->_value << std::endl;
    }

    void add(const Integer &Int)
    {
        this->_value += Int._value;
    }


};