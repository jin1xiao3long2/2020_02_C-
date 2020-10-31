#include <string>
#include <vector>
#include <algorithm>

class Score;

class student
{
private:

    std::string _name;
    int _score = 0;

public:
    student() = delete;
    student(std::string , int , Score&);
    ~student() = default;

    int get_score() const
    {
        return _score;
    }

    std::string get_name() const
    {
        return _name;
    }
};

bool cmp(const student &s1, const student &s2)
{
    return s1.get_score() < s2.get_score();
}

class Score{

private:
    std::vector<student> _students;
    int _num = 0;
    double average_score = 0;

public:
    Score() = default;
    ~Score() = default;
    Score(const Score &lhs) = default;

public:
    void add_student(student stu)
    {
        _students.push_back(stu);
        std::sort(_students.begin(), _students.end(), cmp);
        _num = _students.size();
        int sum = 0;
        for(auto const &e : _students)
        {
            sum += e.get_score();
        }
        average_score = sum * 1.0 / _num;
    }

    student get_low() const
    {
        return _students[0];
    }

    student get_high() const
    {
        return _students[_num-1];
    }

    double get_aver() const
    {
        return average_score;
    }

};

student::student(std::string name, int score, Score &Class): _name(name), _score(score)
{
    Class.add_student(*this);
};



