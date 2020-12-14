/**
 * @file struct.c
 * @author Zhu Heran
 * @compile gcc struct.c -o struct && ./struct
 */

#include <stdio.h>
#include <string.h>

struct Book
{
  char* title;
  char  author[60];
  int   id;
};

int main(int argc, char const* argv[])
{

  struct Book mathBook; /* Declare mathBook of type Book */

  /* book 1 specification */
  mathBook.title = "math book";
  strcpy(mathBook.author, "someone");
  mathBook.id = 6491807;

  /* print mathBook info */
  printf("----- mathBook -----\n");
  printf("title\t\t%s\n", mathBook.title);
  printf("author\t\t%s\n", mathBook.author);
  printf("id\t\t%d\n", mathBook.id);

  return 0;
}