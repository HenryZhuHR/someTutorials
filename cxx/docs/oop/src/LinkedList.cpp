#include "LinkedList.h"

/**
 * 构造函数、析构函数部分
 */
template <class T> LinkedList<T>::LinkedList()
{
    this->head       = new LinkedList<T>();
    this->head->data = 0;
}

template <class T> LinkedList<T>::LinkedList(const T& data)
{
    this->head       = new LinkedList<T>();
    this->head->data = data;
}

template <class T> LinkedList<T>::~LinkedList()
{
    printf("[INFO]\t delete list");
}

/**
 * 成员函数部分
 */
template <class T> T LinkedList<T>::getHeaddata() const
{
    return this->head->data;
}