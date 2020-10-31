#pragma once

#include <iostream>
#include <string>

class Date final
{

private:

    unsigned _year = 2000;
    short _month = 1;
    short _day = 1;
    bool _dataRight = true;

private:

    void _throw_error(const char* e)
    {
        throw std::logic_error(e);
    }

    bool _is_LeapYear(unsigned year)
    {
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return true;
        return false;
    }

    void _check_Date(unsigned year, short month, short day)
    {
        //if(year > 2020 || year < 1900)
        //    _dataRight = false;
        if(month < 1 || month > 12)
            _dataRight = false;
        if(day < 1)
            _dataRight = false;
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day > 31)
                _dataRight = false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day > 30)
                _dataRight = false;
        case 2:
            if(_is_LeapYear(year))
                if(day > 29)
                _dataRight = false;
            else
                if(day > 28)
                _dataRight = false;
        default:
            break;
        }

        if(!_dataRight)
            _throw_error("incorrect date");
        
    }
public:
    Date(unsigned year, short month, short day): _year(year), _month(month), _day(day) 
    {   
        _check_Date(_year, _month, _day);
    }

    Date(unsigned year, const Date& date): _year(year), _month(date._month), _day(date._day)
    {
        _check_Date(_year, _month, _day);
    }

    Date(const Date& date): _year(date._year), _month(date._month), _day(date._day){};

    Date& operator=(const Date& date)
    {
        if(this != &date)
        {
            this->_year = date._year;
            this->_month = date._month;
            this->_day = date._day;
        }
        return *this;
    }

    ~Date() = default;

public:

    inline unsigned _get_Year() const
    {
        return this->_year;
    }

    inline short _get_Month() const
    {
        return this->_month;
    }

    inline short _get_Day() const
    {
        return this->_day;
    }

    inline bool _is_Same_Day(const Date& date) const//only judge month and day
    {
        if(this->_month == date._month && this->_day == date._day)
            return true;
        return false;
    }

    inline bool _is_Same_Day(const Date* date) const//only judge month and day
    {
        return _is_Same_Day(*date);
    }

    inline bool _is_Same_Date(const Date& date) const//add year comparing with _is_Same Day
    {
        if(this->_year == date._year && this->_month == date._month && this->_day == date._day)
            return true;
        return false;
    }

    inline bool _is_Same_Date(const Date* date) const//add year comparing with _is_Same Day
    {
        return _is_Same_Date(*date);
    }

    std::string _get_Date() const // "year-month-day"
    {
        return std::to_string(this->_year) + "-" + std::to_string(this->_month) + "-" + std::to_string(this->_day); 
    }

    void _show_Date() const
    {
        std::cout << std::to_string(this->_year) + "-" + std::to_string(this->_month) + "-" + std::to_string(this->_day) << std::endl; 
    }    
};

inline bool _is_Same_Day(const Date& dl, const Date& dr)
{
    return dl._is_Same_Day(dr);
}

inline bool _is_Same_Date(const Date& dl, const Date& dr)
{
    return dl._is_Same_Date(dr);
}

inline bool _is_Same_Day(const Date* dl, const Date* dr)
{
    return _is_Same_Day(*dl, *dr);
}

inline bool _is_Same_Date(const Date* dl, const Date* dr)
{
    return _is_Same_Date(*dl, *dr);
}

enum Sex{male, female};

class People {

private:

    unsigned long long* _number = nullptr;

    Sex* _sex = nullptr;

    Date* _birthday = nullptr;

    unsigned long* _id = nullptr;

//    bool _set_data = false;

private:

    bool _is_Set_Data() const//to ensure person has their data
    {
        if(!_number || !_sex || !_birthday || !_id)
            return false;
        return true;
    }

public:

    People() = default;
    
    People(unsigned long long number, Sex sex, Date birthday, unsigned long id): //number, sex, birthday, id 
         _number(new unsigned long long(number)), _sex(new Sex(sex)), _birthday(new Date(birthday)), _id(new unsigned long(id)){};

    People(const People&) = delete; //no two persons has same data

    People& operator=(const People&) = delete;

    virtual ~People()
    {
        _destroy_Data();
    }

public:
    
    inline void _destroy_Data()
    {
        if(_number)
            delete _number;
        if(_sex)
            delete _sex;
        if(_birthday)
            delete _birthday;
        if(_id)
            delete _id;
    }

    void _set_Number(unsigned long long number)   //no demand
    {   
        _number = new unsigned long long(number);
    }

    unsigned long long _get_Number() const
    {
        return *_number;
    }

    void _set_Sex(Sex sex) // 'male' or 'female' 
    {
        _sex = new Sex(sex);
    }

    Sex _get_Sex() const
    {
        return *_sex;
    }

    void _set_birthday(const Date& date) 
    {
        _birthday = new Date(date);
    }

    Date _get_Birthday() const
    {
        return *_birthday;
    }

    void _set_Id(unsigned long id)
    {
        _id = new unsigned long(id);
    }

    unsigned long _get_Id() const
    {
        return *_id;
    }

    void _show_Information() const
    {
        if(!this->_is_Set_Data())
            throw std::logic_error("no data");
        std::cout << "Number : " << *_number << std::endl;
        std::cout << "Sex : ";
        if(*_sex == 0)
            std::cout << "male" << std::endl;
        else
            std::cout << "female" << std::endl;
        std::cout << "Birthday : " << _birthday->_get_Date() << std::endl;
        std::cout << "Id : " << *_id << std::endl;
    }


    virtual short _compare_Behavior(const People& people) const  //no certain behavior
    {
        if(!this->_is_Set_Data() || !people._is_Set_Data())
            throw std::logic_error("no data");
        //to do
        //for example -> to know who is elder
        //1 -> this is elder ; -1-> another is elder; 0 -> the same
        if(this->_get_Birthday()._get_Year() < people._get_Birthday()._get_Year())
            return 1;
        else if(this->_get_Birthday()._get_Year() > people._get_Birthday()._get_Year())
            return -1;
        else
        {
            if(this->_get_Birthday()._get_Month() < people._get_Birthday()._get_Month())
                return 1;
            else if(this->_get_Birthday()._get_Month() > people._get_Birthday()._get_Month())
                return -1;
            else
            {
                if(this->_get_Birthday()._get_Day() < people._get_Birthday()._get_Day())
                    return 1;
                else if(this->_get_Birthday()._get_Day() > people._get_Birthday()._get_Day())
                    return -1;
                else
                    return 0;
            }   
        }
    }
};

short _compare_Behavior(const People& pl, const People& pr)
{
    return pl._compare_Behavior(pr);
}

short _compare_Behavior(const People* pl, const People* pr)
{
    return pl->_compare_Behavior(*pr);
}