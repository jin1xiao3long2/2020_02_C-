#include "account.hpp"
#include <map>

void check_money(long long money)
{
    if(money < 0)
    {
        throw std::logic_error("wrong value");
    }
}

void create_account(int &num, Account account[])
{
    if(num >= 10)
    {
        throw std::logic_error("sorry, account not available");
    }
    std::cout << "please enter your account name" << std::endl;
    std::string name;
    std::cin >> name;
    getchar();
    account[num].Active_account(name);
    std::cout << "your account number is  " << num << "\ncreate succeed" << std::endl;
    num++;
}

Account &login_account(Account account[])
{
    std::cout << "please enter your account number" << std::endl;
    int Number;
    std::cin >> Number;
    getchar();
    if(Number >= 10 || Number < 0)
    {
        throw std::logic_error("no such account number");
    }
    if(!account[Number].is_active())
    {
        throw std::logic_error("haven't active yet");
    }
    return account[Number];
}

void show_account(Account account[], int num)
{
    for(int i = 0; i < 10; i++)
    {
        show_normal_information(account[i]);
        if(num == i)
        {
            std::cout << "Rest of account " << num << " to 9 haven't active yet" << std::endl; 
            break;
        }
    }
}

int main()
{
    Account _account[10]; //上限为10
    int num = 0;
    bool _run = true;
    char _command = '\0';
    Account::set_rate(0.043);
    do{
        std::cout << "Account system" << std::endl;
        std::cout << "1: create account" << std::endl;
        std::cout << "2: deposit" << std::endl;
        std::cout << "3: withdraw" << std::endl;
        std::cout << "4: show information" << std::endl;
        std::cout << "5: exit" << std::endl;
        do{
        _command = getchar();
        while(std::cin.get() != '\n');
        if(_command != '1' && _command != '2' && _command != '3' && _command != '4' && _command != '5')
            std::cout << "Please enter '1' to '5'" << std::endl;
        }while(_command != '1' && _command != '2' && _command != '3' && _command != '4' && _command != '5');
        switch (_command)
        {
        case '1':
            try{
                create_account(num, _account);
            }catch(const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case '2':
            try{
                Account& temp_account = login_account(_account);
                std::cout << "How much..." << std::endl; //应该是工作人员输入总金额
                long long temp_money = 0;
                std::cin >> temp_money;
                getchar();
                check_money(temp_money);
                temp_account.deposit(temp_money);
                std::cout << "Deposit successfully, your balance is now   " << temp_account.get_balance() << std::endl;
            }catch(const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case '3':
            try{
                Account& temp_account = login_account(_account);
                std::cout << "How much..." << std::endl; //应该是工作人员输入总金额
                long long temp_money = 0;
                std::cin >> temp_money;
                getchar();
                check_money(temp_money);
                temp_account.withdraw(temp_money);
                std::cout << "WithDraw successfully, your balance is now   " << temp_account.get_balance() << std::endl;
            }catch(const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case '4':
            try{
                Account temp_account = login_account(_account);
                show_information(temp_account);
            }catch(const std::logic_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case '5':
            break;
        default:
            break;
        }
        std::cout << "-------------------------------------------------------------------------\n\n\n" << std::endl;
    }while(_command != '5');
    show_account(_account, num);
    system("pause");

    return 0;
}