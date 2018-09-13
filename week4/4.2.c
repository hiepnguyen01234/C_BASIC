#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

typedef struct sinhvien
{
  int mssv;
  char hoten[80];
  float diemthi;
}sv;
typedef struct node
{
  sv ttsv;
  struct node *next;
}nd;
typedef struct stack
{
  nd *top;
}stack;

int main()
{
  void init(stack s)
  {
    s.top=NULL;
  }
  int isempty(stack s)
  {
    return (s.top ==NULL);
  }

  int len (stack s)
  {
    nd *p =s.top;
    int i=0;
    while (p!=NULL)
      {
	i++;
	p=p->next;
      }
    return  i;
  }
  return 0;
}
