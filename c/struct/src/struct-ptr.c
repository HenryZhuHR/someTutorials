/**
 * @file struct-ptr.c
 * @author Zhu Heran
 * @compile gcc struct-ptr.c -o struct-ptr && ./struct-ptr
 */

#include <stdio.h>
#include <string.h>

typedef struct _Book
{
  int id;
} Book;

int main(int argc, char const* argv[])
{
  Book* p_mathBook;
  Book  mathBook;
  p_mathBook = &mathBook;

  mathBook.id = 0;
  printf("p_mathBook->id\t%d\n", p_mathBook->id);
  mathBook.id = 1;
  printf("p_mathBook->id\t%d\n", p_mathBook->id);

  Book sciBook[4];
  for (int i = 0; i < 4; i++)
  {
    sciBook[i].id = i;
    printf("sciBook[i].id\t%d\n", sciBook[i].id);
  }

  Book* p = sciBook;
  for (int i = 0; i < 4; i++)
  {
    printf("p-> ? id : %d\n", (p+i)->id);
  }

  return 0;
}