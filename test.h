//
// Created by 王梦 on 2022/9/16.
//
#include<iostream>

using namespace std;

namespace myMaker1{
    //int ma;tong
    void func1();//这是函数申明！加上{}就是定义了！那么test.cpp中myMaker::func1(){}就会现实重定义！！！
    //int ma;同理，这里是定义，编译时main.cpp就会报错！
}

namespace myMaker2{
    void func1();
}

