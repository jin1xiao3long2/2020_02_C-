class Point{

public:

    Point(int x = 0, int y = 0): x(x), y(y){}
    Point(const Point &p);
    ~Point(){count--;}
    int GetX() const {return x;}
    int GetY() const {return y;}
    static void showCount();

private:

    int x;
    int y;
    static int count;
};