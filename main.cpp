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

//自定义的数据类型
struct Maker1{
    char name[64];
    int age;
};

struct Maker3{
    int a;
    void func05(){//结构体内可以写函数
        cout<<"wm\n";
    }
};

void test05(){
     Maker1 a;//可以不加struct就可以定义变量
}

void test06(){
    Maker3 v;
    v.func05();
}

/*void test07(){
    int a=10;
    int b=20;
    printf("%d\n",a>b ? a:b);//在c中三目运算符返回的是右值，不能被修改（a>b?a:b）=100;这句语句就是错的
    *(a>b?&a:&b)=100;
    printf("%d\n",b);
}*/

void test08(){
    int a=10;
    int b=20;
    (a>b?a:b)=100;//在c++中三目运算符返回的是左值
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}

const int aa=10;//没有内存，在编译阶段编译器会把这行代码改成cout<<"aa="<<10<<endl;

void test09(){
    //发生了常量折叠
    cout<<"aa="<<aa<<endl;//在编译阶段编译器会把这行代码改成cout<<"aa="<<10<<endl;
    //volatile表示禁止编译器优化
    volatile const int bb=20;
    int* p =(int*)&bb;
    *p=200;
    cout<<"bb="<<bb<<endl;//这里c++的编译器会写成cout<<"bb=="<<20<<endl;所以输出还是20！！！
    cout<<"*p="<<*p<<endl;
    cout<<"bb的地址："<<(long int)&bb<<endl;//如果不转换，& 返回的是bool类型
    cout<<"p所指向的地址："<<(long int)p<<endl;//其实指向的地址是相同的
}

void test10(){
    int a=10;
    const int b=a;//如果用变量给const修饰的局部变量赋值，那么编译器不会优化
    int* pp=(int*)&b;
    *pp=100;
    cout<<"b="<<b<<endl;
    cout<<"*p="<<*pp<<endl;
}

//自定义数据类型编译器不会优化
struct mm{
    mm(){
        aaa=100;
    }
    int aaa;
};

void test11(){
    const mm mmm;
    mm* pt=(mm*)&mmm;
    cout<<mmm.aaa<<endl;
    pt->aaa=200;
    cout<<mmm.aaa<<endl;//没有优化，因为是自定义数据

}

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
    test05();
    test06();
    //c++不能进行隐形转换，只能显示转换
    char* p=(char*)malloc(64);
    test08();
    test09();
    //extern const int c;
    extern const int dd;
    //cout<<"c="<<c<<endl;//c++中const修饰的变量具有内部链接属性，别的文件不能使用,test.cpp中的全局常量别的文件不能用
    cout<<"dd="<<dd<<endl;//test中的dd加了extern后，别的文件就可以使用了，c中只需要一个文件加上extern；
    test10();
    test11();
    return EXIT_SUCCESS;
}
