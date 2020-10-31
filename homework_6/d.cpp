
class A{
public:
    void setA(int);
private:
    int a;
};
class B{
public:
    void setB(int);
private:
    int b;
};
class C:public A, private B{
public:
    void setC(int, int, int);
private:
    int c;
};
void A::setA(int x){
    a = x;
}
void B::setB(int x){
    b = x;
}
void C::setC(int x, int y, int z){
    setA(x);
    setB(y);
    c = z;
}
int main(int argc, const char * argv[]) {
    C obj;
    obj.setA(5); // A
    obj.setB(6); // B
    obj.setC(6, 7, 9); // C
    return 0;
}