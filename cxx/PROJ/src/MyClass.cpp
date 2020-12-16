#include "MyClass.h"

#include <iostream>


MyClass::MyClass(/* args */)
{
    std::cout<<"[INFO] ";
    std::cout<<"call default no-argument constructor";
    std::cout<<std::endl;
}

MyClass::~MyClass()
{
}