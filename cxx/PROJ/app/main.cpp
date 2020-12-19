#include <iostream>
#include <string>
#include <vector>
#include <memory>
// using namespace std;


#include "MyClass.h"
#include "Solution/Solution.h"

int main(int argc, char **argv)
{
  std::unique_ptr<int> uptr_i; //创建空智能指针
  uptr_i.reset(new int(6));    //绑定动态对象
  std::cout << *uptr_i << std::endl;

  Solution sln =Solution();
  sln.Hello();
  SolutionHello();


  return 0;
}
