# 第一章 迈向现代C++

## 1.1 被弃用的特性

弃用并不是彻底不能用，而是这些特性即将从未来的标准中消失，应该尽量避免使用。弃用的特性处于兼容性的考虑，依然是标准库的一部分(这里是C++的原则，一直向前兼容，我感觉有点偶像包袱了)。

1.不再允许字符串字面值常量赋值给一个 char \* 。如果需要用字符串字面值常量复制和初始化一个 char \*，应该使用const char * 或者 auto 。(这里挺关键的)

2.C++98异常说明、unexpected_handler、set_unexpected()等相关特性将被弃用，应该使用noexcept。(我是UE4的程序员，这个东西用的比较少，不太了解)

3.auto_ptr被弃用，应该使用unique_ptr。(智能指针)

4.register关键字被弃用，可以使用但不再具备任何实际意义。(对寄存器操作)

5.bool类型的++操作被弃用。(从来没用过好吗)

6.如果一个类有析构函数，为其生成拷贝构造函数和拷贝赋值运算符的特性被弃用了。(面试可以装杯了)

7.C语言风格的类型转换被弃用(就是使用convert_type)，应该使用static_cast、reinterpret_cast、const_cast来进行类型转换。(早就应该这么做了)

8.最新的C++17标准中弃用了一些C的标准库，比如\<ccomplex>、\<cstdalign>、\<cstdbool>、\<ctgmath>。(呃，表示一个没用过)

9.诸如参数绑定(C++11的std::bind和std::function)、export等特性页均被弃用。

如果有些你从未使用过或者听说过，就算了，别费那个时间去了解它们，人要向前看。

## 1.2 与C的兼容性

C++不是C的一个超集，从一开始就不是。有许多的程序员说C++是对C的升级，从根上就错了，一个面向过程，一个面向对象，未来的发展方向也不一样。尽管传统C++和C语言的风格很像，也只能说两个物种长得比较像了。这就像人类和猴子，像不像，甚至远古的时候还有血缘关系，但是人类是高级动物。

编写C++时，要避免使用void*之类的C语言的程序风格。在不得不使用C时，注意使用 extern "C" 这种特性。将C语言的代码与C++代码进行分离编译，再统一链接。如以下代码：

```c++
//foo.h
#ifdef __cplusplus
extern "C"
{
#endif
    int add(int x, int y);
#ifdef __cplusplus
}
#enfif

//foo.c
int add(int x, int y)
{
    return x + y;
}

//1.1.cpp
#include "foo.h"
#include <iostream>
#include <functional>
int main()
{
    [out = std::ref(std::cout << add(1, 2))]()
    {
        out.get() << ".\n";
    }();  //Lambda表达式
    return 0;
}
```

上面的代码是直接从书上抄来的，也不多解释了，不难。主要是个人不太满意这种代码风格，本来挺简单的东西，要弄这么复杂，可能作者是为了展示现代C++吧。
