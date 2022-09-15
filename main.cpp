#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "test.h"
using namespace std;//标准命名空间

namespace A{//A是空间的名字。1：命名空间只能写在全局 2：命名空间可以嵌套命名空间 3:命名空间是开放的随时可以加入新成员，但是新成员只能在加入后使用
    int a=200;
    int b=300;
    int c=400;

}

void test03(){
    using A::a;//using申明是让命名空间中某个标识符可以直接使用
    cout<<a<<endl;
    //int a=100;//注意：在使用using申明了某个变量，在该作用域内不能定义同名的变量
}

void test04(){
    using namespace A;//让某个命名空间的标识符都可以直接使用
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    int a=500;//这里就可以重新定义
    cout<<a<<endl;
}

namespace Maker{
    int a=60;
    namespace B{
        int b=40;
    }
}

/*void test(){
    cout<<Maker::c<<endl;//这里会报错，此时命名空间Maker还没有添加新成员c
}*/

namespace Maker{
    int c=30;
}


//注意4：匿名空间
namespace {//类似于static
    int d=50;
}

//命名空间可以取别名

void test01(){
    namespace nameMaker = Maker;
    cout<<nameMaker::a<<endl;
}

//注意6：分文件编写代码时，如果.h中有两个命名空间，但是里面的成员函数或成员变量同名时，在.cpp中实现函数时，需要加上命名空间

//全局变量
int mya=10;
int main() {
    //cout是标准输出流对象
    //endl是刷新缓冲区，并换行
    int mya=20;
    //就近原则
    std::cout<<""<<mya << std::endl;
    std::cout<<""<<::mya <<std::endl;
    std::cout<<""<<Maker::c <<std::endl;//::是作用域运算符，前面什么都没写是全局变量
    std::cout<<""<<Maker::B::b <<std::endl;
    std::cout<<d<<endl;//匿名空间的输出
    test01();
    myMaker1::func1();
    test03();
    test04();
    return EXIT_SUCCESS;
}
