#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        value1 = 1;
    }

    Base(int value) : Base()  //委托构造函数
    {
        value2 = value;
    }

    int value1;
    int value2;
};

int main()
{
    Base b(2);
    cout << b.value1 << endl;
    cout << b.value2 << endl;
    return 0;
}