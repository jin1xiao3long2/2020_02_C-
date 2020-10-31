#include <iostream>
#include <string>
enum _Sex{male, female};

class people{

protected:
    std::string name;
    int age;
    _Sex sex; 
public:
    people() = delete;

    people(std::string Name, int Age, _Sex Sex): name(Name), age(Age), sex(Sex){};

    virtual ~people() = default;

protected:

    virtual void info()
    {
        std::cout << "Name : " << name << std::endl;
        std::cout << "Age : " << age << std::endl;
        std::cout << "Sex : " << sex << std::endl;
    }

public:

    virtual void show()
    {
        std::cout << "Person Information " << std::endl;
        this->info();
    }
};

class student : virtual public people{
protected:
    std::string classNo;

public:
    student() = delete;

    student(std::string Name, int Age, _Sex Sex, std::string ClassNo):
    people(Name, Age, Sex), classNo(ClassNo){};

    virtual ~student() = default;

protected:

    virtual void info() override
    {
        std::cout << "ClassNumber : " << classNo << std::endl;
    }

public:

    virtual void show()
    {
        std::cout << "Student Information " << std::endl;
        people::info();
        this->info();
    }
};

class teacher : virtual public people{

protected:

    std::string principalship;
    std::string department;

public:
    teacher(std::string Name, int Age, _Sex Sex, std::string _principalship, std::string _department)
    : people(Name, Age, Sex), principalship(_principalship), department(_department){};

    teacher() = delete;

    virtual ~teacher() = default;

protected:

    virtual void info() override
    {
        std::cout << "Principalship : " << principalship << std::endl;
        std::cout << "Department : " << department << std::endl;
    }

public:
    virtual void show() override
    {
        std::cout << "Teacher Information " << std::endl;
        people::info();
        this->info();
    }
};

class graduate : public student {

protected:

    std::string subject;
    std::string adviser;

public:

    graduate() = delete;

    graduate(std::string Name, int Age, _Sex Sex, std::string ClassNo, std::string Subject, std::string Adviser):
    student(Name, Age, Sex, ClassNo), people(Name, Age, Sex), subject(Subject), adviser(Adviser){};

    virtual ~graduate() = default;

protected:

    virtual void info() override
    {
        std::cout << "Subject : " << subject << std::endl;
        std::cout << "Adviser : " << adviser << std::endl;
    }

public:

    virtual void show() override
    {
        std::cout << "Graduate Information " << std::endl;
        people::info();
        student::info();
        this->info();
    }
};

class TA final : public teacher, public graduate{

protected:

    std::string any;

public:

    TA() = delete;

    TA(std::string Name, int Age, _Sex Sex, std::string ClassNo, std::string Subject, 
    std::string Adviser, std::string _principalship, std::string _department, std::string Any):
    graduate(Name, Age, Sex, ClassNo, Subject, Adviser), teacher(Name, Age, Sex, _principalship, _department), 
    people(Name, Age, Sex), any(Any){};

    virtual ~TA() = default;

protected:

    void info() override
    {
        std::cout << "Some other info: " << any << std::endl;
    }

public:

    void show() override
    {
        std::cout << "TA information " << std::endl;
        people::info();
        student::info();
        graduate::info();
        teacher::info();
        this->info();
    }

};
