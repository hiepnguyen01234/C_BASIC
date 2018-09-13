#include<stdio.h>
#include "stack.h"

int main()
{
  int i;
  stacktype s;
  char c;

  initialize(s);
  printf("kiem tra rong:%d\n",empty(s));
  printf("kiem tra tran:%d\n",full(s));
  do{
    c=getchar();
    push(c,s);
  }while(c!='\n');
  do{
    printf("%c",pop(s));
  }while(!empty(s));
  printf("\n");
return 0;
}
