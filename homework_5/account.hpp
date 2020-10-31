#pragma once

#include <iostream>
#include <time.h>
#include <string>
#include <vector>

struct record{
    long long before_money = 0;
    bool _type = false; //取钱类型为true ,  存钱类型为false
    long long after_money = 0;
    tm *_date;
};


class Account final{

private:
    std::string _name;
    long long _balance = 0;
    std::vector<record> _record;
    bool _active = false;
    tm *create_time = nullptr;
    static double _rate;

tm *get_date()
{
    time_t _time;
    tm *tm_info;
    time(&_time);
    tm_info = localtime(&_time);
    tm_info->tm_year += 1900;
    tm_info->tm_mon += 1;
    return tm_info;
}

public:

    Account() = default;

    ~Account() = default;

    void Active_account(std::string name)
    {
        _name = name;
        _active = true;
        create_time = get_date();
    }

    void deposit(long long money)
    {
        if(!_active)
            throw std::logic_error("Haven't active yet");
        record n_record;
        n_record._type = false;
        n_record.before_money = this->_balance;
        n_record._date = get_date();
        n_record.after_money = this->_balance + money;
        _record.push_back(n_record);
        _balance += money;
    }

    void withdraw(long long money)
    {
        if(!_active)
            throw std::logic_error("Haven't active yet");
        if(money > _balance)
            throw std::logic_error("Not enough balance");
        record n_record;
        n_record._type = false;
        n_record.before_money = this->_balance;
        n_record._date = get_date();
        n_record.after_money = this->_balance - money;
        _record.push_back(n_record);
        _balance -= money;
    }

    bool is_active() const
    {
        return _active;
    }

    long long get_balance() const
    {
        return this->_balance;
    }

    friend std::string get_my_time(tm *);
    friend void show_information(const Account &);
    friend void show_normal_information(const Account &);
    

    static std::string get_rate()
    {
        return std::to_string(Account::_rate * 100) + "%";
    }

    static void set_rate(double rate)
    {
        Account::_rate = rate;
    }
};

double Account::_rate = 3.2;

std::string get_my_time(tm *Time)
{
    std::string year = std::to_string(Time->tm_year);
    std::string month = std::to_string(Time->tm_mon);
    std::string day = std::to_string(Time->tm_mday);
    std::string hour = std::to_string(Time->tm_hour);
    std::string min = std::to_string(Time->tm_min);
    std::string sec = std::to_string(Time->tm_sec);
    return year + "/" + month + "/" + day + "  " 
            + hour + ":" + min + ":" + sec;
}

void show_information(const Account &_account)
{
    if(!_account._active)
            throw std::logic_error("Haven't active yet");
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "Your account :     " << _account._name << std::endl;
    std::cout << "Balance :          " << _account._balance << std::endl;
    std::cout << "Record num :       " << _account._record.size() << std::endl;
    std::cout << "Rate :             " << Account::get_rate() << std::endl;
    std::cout << "Create time :      " << get_my_time(_account.create_time) << std::endl;
    std::cout << std::endl;
    std::cout << "Wanna see details about record? (Y / N)" << std::endl;
    char _command = '\0';
    do{
    _command = getchar();
    _command = tolower(_command);
    while(std::cin.get() != '\n');
    if(_command != 'y' && _command != 'n')
        std::cout << "Please enter 'y'(es) of 'n'(o)" << std::endl;
    }while(_command != 'y' && _command != 'n');
    if(_command == 'y')
    {
        std::cout << "\n\n" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        for(auto const r : _account._record)
        {
            std::cout << "|Time:     " << get_my_time(r._date);
            std::string type = r._type ? "withdraw" : "deposit";
            std::cout << "          " << type << " " << r.before_money-r.after_money << "yuan,  balance"
            << r.before_money << std::endl;
            std::cout << "------------------------------------------------------------------" << std::endl;
        }
    }
    std::cout << "\n-------------------------------------------------------------------------" << std::endl;
}

void show_normal_information(const Account& _account)
{
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    if(_account.is_active())
    {
        std::cout << "|  Account name :   " << _account._name << std::endl;
        std::cout << "|  Record       :   " << _account._record.size() << std::endl;
        std::cout << "|  Create time  :   " << get_my_time(_account.create_time) << std::endl;
    }
    std::cout << "-------------------------------------------------------------------------" << std::endl;
}

