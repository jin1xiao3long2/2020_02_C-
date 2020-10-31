#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class file_exception : public std::exception{

private:

std::string Err_Msg;

public:

file_exception(std::string e)
{
    this->Err_Msg = e;
}

virtual ~file_exception() = default;

virtual const char* what() const noexcept override
{
    return this->Err_Msg.c_str();
}

};

class students final{

private:

    std::string _name;
    unsigned int _score;

public:

    students(std::string Name, int Score): _name(Name), _score(Score){};

    ~students() = default;

    std::string get_name() const
    {
        return this->_name;
    }

    int get_score() const
    {
        return this->_score;
    }


};

void write_file(std::ofstream &out_file)
{
    out_file.open("./test.txt", std::ios_base::out | std::ios_base::binary);
    if(!out_file)
        throw(file_exception("Error: file open failed"));
    //write
    std::string info[10] = {"Stu0 88", "StuA 99", "StuB 68", "StuC 70", "StuD 85", 
                            "StuE 75", "StuF 72", "StuG 86", "StuH 62", "StuI 92"};
    for(int i = 0; i < 10; i++)
        out_file.write(info[i].c_str(), info[i].length());
    out_file.close();
}

void read_file(std::ifstream &in_file, std::vector<students> &vec)
{
    in_file.open("./test.txt", std::ios_base::in | std::ios_base::binary);
    if(!in_file)
        throw(file_exception("Error: file open failed"));
    //write
    char a[7];
    for(int i = 0; i < 10; i++)
    {
    in_file.read(a, 7 * sizeof(char));
    std::stringstream s;
    s << a;
    std::string name, score;
    s >> name;
    s >> score;
    int i_score = std::atoi(score.c_str());
    vec.emplace_back(name, i_score);
    }
    in_file.close();
}

std::ostream& operator<<(std::ostream& out, const std::vector<students>& vec)
{
    for(auto const &e : vec)
    {
        std::cout << "Name: " << e.get_name() << ",  Score: " << e.get_score() << std::endl;
    }
    return out;
}

int main()
{
    std::ofstream OF;
    try{
        write_file(OF);
    }
    catch(const file_exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
    
    std::ifstream IF;
    std::vector<students> V;
    try{
        read_file(IF, V);
    }catch(const file_exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }

    std::cout << V << std::endl;
    return 0;
}