# 目录
- [目录](#目录)
- [简介](#简介)
- [vector 的初始化](#vector-的初始化)
  - [头文件引入](#头文件引入)
  - [初始化](#初始化)
- [vector 的成员函数](#vector-的成员函数)
  - [构造函数](#构造函数)
  - [增加函数](#增加函数)
  - [删除](#删除)
  - [遍历函数](#遍历函数)
  - [判断函数](#判断函数)
  - [大小函数](#大小函数)
  - [其他函数](#其他函数)
- [vector 与 迭代器](#vector-与-迭代器)
- [打印一个vector的n种方式](#打印一个vector的n种方式)
  - [for range](#for-range)
  - [传统for](#传统for)
  - [迭代器](#迭代器)
  - [template function](#template-function)
  - [template function 2](#template-function-2)
  - [for_each + lambda](#for_each--lambda)
  - [for_each + functor](#for_each--functor)
  - [ostream_iterator](#ostream_iterator)



# 简介
**vector** 容器是 `STL` 中最常用的容器之一，它和 array 容器非常类似，都可以看做是对 C++ 普通数组的“升级版”。

不同之处在于，array 实现的是静态数组（容量固定的数组），而 vector 实现的是一个动态数组，即可以进行元素的插入和删除，在此过程中，vector 会动态调整所占用的内存空间，整个过程无需人工干预。

vector 常被称为 `向量容器`，因为该容器擅长在尾部插入或删除元素，在常量时间内就可以完成，时间复杂度为O(1)；而对于在容器头部或者中部插入或删除元素，则花费时间要长一些（移动元素需要耗费时间），时间复杂度为线性阶O(n)。


# vector 的初始化
## 头文件引入
vector 容器以类模板 ``vector<T>``（ ``T`` 表示存储元素的类型）的形式定义在 `stl_vector.h` 头文件中，并位于 ``std`` 命名空间中
```cpp
#include <vector>
using namespace std;
```
## 初始化
```cpp
std::vector<double> values;
```

# vector 的成员函数
## 构造函数
```cpp
// 创建一个空 vector
vector();

// 创建一个 vector ,元素个数为 nSize
vector(int nSize);

// 创建一个 vector ，元素个数为 nSize,且值均为t
vector(int nSize,const t& t);

// 复制构造函数
vector(const vector&);

// 复制[begin,end)区间内另一个数组的元素到vector中
vector(begin,end);
```

## 增加函数
```cpp
// 向量尾部增加一个元素X
void push_back(const T& x);

// 向量中迭代器指向元素前增加一个元素x
iterator insert(iterator it,const T& x);

// 向量中迭代器指向元素前增加n个相同的元素x
iterator insert(iterator it,int n,const T& x);

// 向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据
iterator insert(iterator it,const_iterator first,const_iterator last);
```

## 删除
```cpp
// 删除向量中迭代器指向元素
iterator erase(iterator it);

// 删除向量中[first,last)中元素
iterator erase(iterator first,iterator last);

// 删除向量中最后一个元素
void pop_back();

// 清空向量中所有元素
void clear();
```


## 遍历函数
```cpp
// 返回pos位置元素的引用
reference at(int pos);

// 返回首元素的引用
reference front();

// 返回尾元素的引用
reference back();

// 返回向量头指针，指向第一个元素
iterator begin();

// 返回向量尾指针，指向向量最后一个元素的下一个位置
iterator end();

// 反向迭代器，指向最后一个元素
reverse_iterator rbegin();

// 反向迭代器，指向第一个元素之前的位置
reverse_iterator rend();
```

## 判断函数
```cpp
// 判断向量是否为空，若为空，则向量中无元素
bool empty() const;
```

## 大小函数
```cpp
// 返回向量中元素的个数
int size() const;

// 返回当前向量所能容纳的最大元素值
int capacity() const;

// 返回最大可允许的vector元素数量值
int max_size() const;
```

## 其他函数
```cpp
// 交换两个同类型向量的数据
void swap(vector&);

// 清空 vector ，设置 vector 中前n个元素的值为x
void assign(int n,const T& x);

// 向量中[first,last)中元素设置成当前向量元素
void assign(const_iterator first,const_iterator last);
```

# vector 与 迭代器
迭代器是一个`可遍历 STL 容器内全部或部分元素`的对象。一个迭代器用来指出容器中的一个特定位置。

迭代器是个所谓的 smart pointers，具有遍历复杂数据结构的能力。

运用 `start`、`finish`、`end_of_storage` 三个迭代器便可轻易操作vector 容器。

# 打印一个vector的n种方式
## for range
```cpp
vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

for (const auto &c : ivec) cout << c << " ";
```
用 const auto & 只是告诉我这里只是在读元素。

## 传统for
```cpp
for (auto i = 0; i != ivec.size(); ++i) cout << ivec[i] << " ";
```
auto当然也可以换成别的，比如 delctype 之类.

## 迭代器
```cpp
for (auto it = ivec.cbegin(); it != ivec.cend() ; ++it) cout << *it << " ";
```
这里的 auto 是 vector::const_iterator.当然还可以方向迭代器。

## template function
```cpp
template <typename T>
void display(const vector<T>& vec) {
  for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    cout << *it << " ";
}

...
display(ivec);
```
## template function 2
```cpp
template <typename T>
void display(const T& container) {
  for (auto it = container.cbegin(); it != container.cend(); ++it)
    cout << *it << " ";
}

...
display(ivec);
```
这个针对别的container也行，比如list等.

## for_each + lambda
```cpp
for_each(ivec.cbegin(), ivec.cend(), [](const int& c){cout << c << " "; });
```
## for_each + functor
```cpp
template <typename elementType>
struct Display {
  void operator() (const elementType& element) const {
    cout << element << " ";
  }
};

...
for_each(ivec.cbegin(), ivec.cend(), Display<int>());
```
## ostream_iterator
```cpp
ostream_iterator<int> out_iter(cout, " ");
copy(ivec.cbegin(), ivec.cend(), out_iter);
```