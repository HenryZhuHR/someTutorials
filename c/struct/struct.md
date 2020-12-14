# 目录
- [目录](#目录)
- [结构体](#结构体)
- [声明和定义](#声明和定义)
- [初始化](#初始化)
- [结构体指针](#结构体指针)
  - [普通结构体指针](#普通结构体指针)
  - [结构体数组的指针](#结构体数组的指针)
  - [结构体内部的指针](#结构体内部的指针)



# 结构体
结构名（structure tag）
```c
struct [结构名] [对象名];   //“struct 结构名”就是结构体的数据类型名
```

```c
struct [structure tag] /*结构体的标签*/{
    /*零个或多个成员变量的定义*/
    member definition; 
    member definition;
    ...
    member definition;
} [one or more structure variables];  /*一个或多个结构体变量的定义*/
```
> 结构体标签(structure tag)是可选的，但是推荐还是写上，这样使得代码更加规范清晰

结构体是一种自定义的数据类型，创建数据类型的模板，不占用内存空间。结构体变量才占据空间。

上节所述的结构体类型本身并不会作为数据而被系统分配内存，如果一个结构体类型定义了变量则系统会分配内存空间，每一个结构体变量的所占内存大小，由结构体类型中的每个成员的总和决定。


# 声明和定义
- 先声明结构体类型，再定义该类型变量
```c
struct Book
{
    char*   title;
    int     id;
};

struct Book book1,book2;
```

- 在声明的同时定义变量（不推荐）
```c
struct Book
{
    char*   title;
    int     id;
}book1,book2;
```

- 不指定类型名直接定义结构体类型变量（不推荐）
```c
struct
{
    char*   title;
    int     id;
}book1,book2;
```
这种方式只能够定义一次，不能再以此定义其它变量。

- **推荐** : typedef 声明
```c
type struct _Book
{
    char*   title;
    int     id;
}Book;

Book book1,book2;
```

# 初始化
定义如下结构体
```c
struct Book {
  char* title;
  char  author[60];
  int   id;
};
```
- 方式一
```c
struct Book book = {"book", "some", 100};
```

- 方式二
```c
struct Book bookList[] ={
    {"book-1", "a", 0},
    {"book-2", "a", 1},
    {"book-3", "c", 2}
};
```

- 方式三
```c
struct Book book;
book.title="math";
strcpy(book.author, "one");
book.id=8;
```


# 结构体指针
定义如下结构体
```c
typedef struct _Book {
    int id;
} Book;
```
## 普通结构体指针
```c
Book* p_mathBook;
Book  mathBook;
p_mathBook = &mathBook;

mathBook.id = 0;
printf("p_mathBook->id\t%d\n", p_mathBook->id);
mathBook.id = 1;
printf("p_mathBook->id\t%d\n", p_mathBook->id);
```
输出
```c
p_mathBook->id  0
p_mathBook->id  1
```
## 结构体数组的指针
```c
Book sciBook[4];
for (int i = 0; i < 4; i++) {
    sciBook[i].id = i;
    printf("sciBook[i].id\t%d\n", sciBook[i].id);
}

Book* p = sciBook;
for (int i = 0; i < 4; i++) {
    printf("p-> ? id : %d\n", (p+i)->id);
}
```

```c
sciBook[i].id   0
sciBook[i].id   1
sciBook[i].id   2
sciBook[i].id   3

p-> ? id : 0
p-> ? id : 1
p-> ? id : 2
p-> ? id : 3
```

## 结构体内部的指针
```c
typedef struct _NODE {
  int           data;
  struct _NODE* next;
} Node;

int main(int argc, char const* argv[]) {
  Node node0, node1, node2;
  node0.data = 0;
  node1.data = 1;
  node2.data = 2;
  node0.next = &node1;
  node1.next = &node2;

  Node* p = &node0;
  while (p != NULL) {
    printf("p->data\t%d\n", p->data);
    p = p->next;
  }
  return 0;
}
```
