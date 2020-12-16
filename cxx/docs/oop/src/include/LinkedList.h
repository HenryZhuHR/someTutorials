/*****************************************************************************
 *  OpenST Basic tool library
 *  Copyright (C) 2014 Henry.Wen  renhuabest@163.com.
 *
 *  This file is part of OST.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with OST. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @file        LinkedList.h
 * @brief       对文件的简述
 * Details.
 *
 * @author      Henry.Zhu
 * @email       2017301200136@whu.edu.cn
 * @version     1.0.0.1
 * @date        renhuabest@163.com
 * @license     GNU General Public License (GPL)
 * @code        utf-8
 *
 *----------------------------------------------------------------------------*
 *  Remark         : Description
 *----------------------------------------------------------------------------*
 *  Change History :
 *  <Date>     | <Version> | <Author>       | <Description>
 *----------------------------------------------------------------------------*
 *  2020/12/15 | 1.0.0.1   | Henry.Zhu      | Create File
 *----------------------------------------------------------------------------*
 *
 *****************************************************************************/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include "stdio.h"

/**
 * @brief 链表的结点
 * @note 没有定义构造函数
 * @todo 是否要定义构造函数和其他成员函数？
 */
template <class T> class LinkedNode
{
  protected:
    T data;

  public:
    LinkedNode(/* args */);
    ~LinkedNode();
};

/** @brief 链表
 */
template <class T> class LinkedList
{
  protected:
    LinkedNode<T>* head;

  public:
    LinkedList();
    LinkedList(const T& data);
    // LinkedList(LinkNode<T>* ptr = NULL);
    // LinkedList(const T& data, LinkNode<T>* ptr = NULL);
    ~LinkedList();

  public:
    T getHeaddata() const;
};

class Test
{
private:
  /* data */
public:
  Test(/* args */){
  std::cout<<"hello my";
};

};



#endif