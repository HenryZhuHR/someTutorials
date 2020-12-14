/**
 * @file struct-inter-ptr.c
 * @author Zhu Heran
 * @compile gcc struct-inter-ptr.c -o struct-inter-ptr && ./struct-inter-ptr
 */

#include <stdio.h>
#include <string.h>

typedef struct _NODE
{
  int           data;
  struct _NODE* next;
} Node;

int main(int argc, char const* argv[])
{
  Node node0, node1, node2;
  node0.data = 0;
  node1.data = 1;
  node2.data = 2;
  node0.next = &node1;
  node1.next = &node2;

  Node* p = &node0;
  while (p != NULL)
  {
    printf("p->data\t%d\n", p->data);
    p = p->next;
  }
  return 0;
}