#include<stdio.h>
#include "stack.h"

typedef struct node
{
  int data;
}node;
typedef struct stack
{
  node sv;
struct  stack *next;
}stack;

int main()
{
  int i,n;
  stack *root,*cur;
  root=(stack*)malloc(sizeof(stack));
  cur=(stack*)malloc(sizeof(stack));
  root->next=NULL;
  cur=root;

  printf("nhap so luong:\n");scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      stack *new;
      new=(stack*)malloc(sizeof(stack));
      printf("enter your data:\n");
      scanf("%d",&(new->sv).data);
      new->next=NULL;
      cur->next=new;
      cur=new;
    }
  cur=root;
  while(cur->next!=NULL)
    {
      cur=cur->next;
      printf("\n%d\n",(cur->sv).data);
    }
  free(root);
  free(cur);
  return 0;
}
