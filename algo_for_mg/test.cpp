#include <iostream>
#include <vector>
#include <mozart/format>
class test
{
    private:
        std::vector<int> v;

    public:
        test(){
            v.push_back(2);
        }
        ~test(){};
        std::vector<int> &get_data()
        {
            return this->v;
        }
};


int main()
{
    test* a = new test();
    std::vector<int> &b = a->get_data();
    std::cout << b.size() << std::endl;
    b.push_back(3);
    std::cout << b.size() << std::endl;
    std::cout << a->get_data().size();
    return 0;
}