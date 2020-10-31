#include <iostream>

void reverse(int number)
{
    int reverse_number = 0;   
    int num = 0;
    while(true)
    {
        if(number == 0)
            break;
        reverse_number *= 10;
        num = number % 10;
        reverse_number += num;
        number /= 10;
    }
    std::cout << "整数翻转后为:   " << reverse_number << std::endl; 
    //return reverse_number;   // 若需要返回 添加即可
}

int main()
{
    int number = 0;
    std::cout << "请输入一个整数" << std::endl;
    std::cin >> number;
    reverse(number);   //反向并输出

    return 0;
    
}