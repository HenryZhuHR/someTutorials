# 目录
- [目录](#目录)
- [两数之和](#两数之和)
  - [题目](#题目)
  - [解法](#解法)
    - [暴力枚举](#暴力枚举)
    - [哈希表](#哈希表)
- [补充学习](#补充学习)
  - [Vector](#vector)
  - [打印一个vector的n种方式](#打印一个vector的n种方式)
    - [for range](#for-range)
    - [传统for](#传统for)
    - [迭代器](#迭代器)
    - [template function](#template-function)
    - [template function 2](#template-function-2)
    - [for_each + lambda](#for_each--lambda)
    - [for_each + functor](#for_each--functor)
    - [ostream_iterator](#ostream_iterator)
  - [map](#map)
  - [unordered_map](#unordered_map)



# 两数之和
## 题目
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:
```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
## 解法
最容易想到的方法是枚举数组中的每一个数 `x`，寻找数组中是否存在 `target - x`，即求和改为作差
### 暴力枚举
- [CXX 解法](./cpp/two-sum-enum.cpp)
### 哈希表
- [CXX 解法](./cpp/two-sum-hash.cpp)

# 补充学习
## Vector
vector是C++标准模板库中的部分内容，它是一个多功能的，能够操作多种数据结构和算法的模板类和函数库。          
vector之所以被认为是一个容器，是因为它能够像容器一样存放各种类型的对象。         
简单地说，vector是一个能够存放任意类型的动态数组，能够增加和压缩数据。         

- 头文件引入
```cpp
#include <vector>
```

## 打印一个vector的n种方式
### for range
```cpp
vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

for (const auto &c : ivec) cout << c << " ";
```
用 const auto & 只是告诉我这里只是在读元素。

### 传统for
```cpp
for (auto i = 0; i != ivec.size(); ++i) cout << ivec[i] << " ";
```
auto当然也可以换成别的，比如 delctype 之类.

### 迭代器
```cpp
for (auto it = ivec.cbegin(); it != ivec.cend() ; ++it) cout << *it << " ";
```
这里的 auto 是 vector::const_iterator.当然还可以方向迭代器。

### template function
```cpp
template <typename T>
void display(const vector<T>& vec) {
  for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    cout << *it << " ";
}

...
display(ivec);
```
### template function 2
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

### for_each + lambda
```cpp
for_each(ivec.cbegin(), ivec.cend(), [](const int& c){cout << c << " "; });
```
### for_each + functor
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
### ostream_iterator
```cpp
ostream_iterator<int> out_iter(cout, " ");
copy(ivec.cbegin(), ivec.cend(), out_iter);
```


## map
- 头文件引入
```cpp
#include <map>
```


## unordered_map
- 头文件引入
```cpp
#include <unordered_map>
```