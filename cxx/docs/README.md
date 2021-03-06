# 导航
- [导航](#导航)
- [STL (Standard Template Library)](#stl-standard-template-library)
- [容器 (Container)](#容器-container)
  - [序列容器](#序列容器)
    - [vector](#vector)
  - [容器适配器](#容器适配器)
  - [关联容器](#关联容器)
  - [无序关联容器](#无序关联容器)
  - [list](#list)
  - [set](#set)
  - [map](#map)
- [迭代器 (Iterator)](#迭代器-iterator)
- [算法 (Algorithm)](#算法-algorithm)
- [仿函数 (Function object)](#仿函数-function-object)
- [迭代适配器 (Adaptor)](#迭代适配器-adaptor)
- [空间配置器 (Allocator)](#空间配置器-allocator)



# STL (Standard Template Library)
STL（Standard Template Library），标准模板库，是一个具有工业强度的，高效的C++程序库。它被容纳于C++标准程序库（C++ Standard Library）中，是ANSI/ISO C++标准中最新的也是极具革命性的一部分。该库包含了诸多在计算机科学领域里所常用的基本数据结构和基本算法。为广大C++程序员们提供了一个可扩展的应用框架，高度体现了软件的可复用性。

STL的一个重要特点是数据结构和算法的分离。尽管这是个简单的概念，但这种分离确实使得STL变得非常通用。例如，由于STL的sort()函数是完全通用的，你可以用它来操作几乎任何数据集合，包括链表，容器和数组；

STL另一个重要特性是它不是面向对象的。为了具有足够通用性，STL主要依赖于模板而不是封装，继承和虚函数（多态性）——OOP的三个要素。你在STL中找不到任何明显的类继承关系。这好像是一种倒退，但这正好是使得STL的组件具有广泛通用性的底层特征。另外，由于STL是基于模板，内联函数的使用使得生成的代码短小高效；

从逻辑层次来看，在STL中体现了泛型化程序设计的思想，引入了诸多新的名词，比如像需求（requirements），概念（concept），模型（model），容器（container），算法（algorithmn），迭代子（iterator）等。与OOP（object-oriented programming）中的多态（polymorphism）一样，泛型也是一种软件的复用技术；从实现层次看，整个STL是以一种类型参数化的方式实现的，这种方式基于一个在早先C++标准中没有出现的语言特性--模板（template）。
# 容器 (Container)
## 序列容器
### vector
[vector 详细](STL/vector.md)
## 容器适配器
## 关联容器
## 无序关联容器
## list
## set
## map
# 迭代器 (Iterator)
# 算法 (Algorithm)
# 仿函数 (Function object)
# 迭代适配器 (Adaptor)
# 空间配置器 (Allocator)