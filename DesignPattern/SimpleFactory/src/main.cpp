// g++ main.cpp -o main
// ./main

#include <iostream>
#include "SimpleFactory.h"

int main()
{
  printf("SimpleFactory\n");

  //定义工厂类对象
  Factory*              fac     = new Factory();
  AbstractSportProduct* product = NULL;

  product = fac->getSportProduct("Basketball");
  if (product)
  {
    delete product;
  }

  product = fac->getSportProduct("Football");
  if (product)
  {
    delete product;
  }

  product = fac->getSportProduct("Volleyball");
  if (product)
  {
    delete product;
  }

  delete fac;
  return 0;
}