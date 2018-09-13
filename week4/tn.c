#include<stdio.h>
#include<stdlib.h>

typedef struct sv
{
  int mssv;
  char name[31];
  float diemthi;
  struct sv *next;
}sv;
typedef struct stack
{
  sv *top;
}stack;

#define max 50
typedef sv eltype; 
//typedef eltype stacktype[max];

void *initialize();
int empty(const stack *s);
int full();
int push(eltype *new,stack *s);
eltype pop (stack *s);

void *initialize ()
{
  stack *s;
  s= (stack*)malloc(sizeof(stack));
  if(s==NULL){return NULL;}
  s->top=NULL;
  return s;
}
int empty(const stack *s)
{
  return(s->top==NULL);
}
int full()
{
  printf("\nfull stack.\n");
  getchar();
  return 1;
}
int push(eltype *new,stack *s)
{
  new=(eltype*)malloc(sizeof(eltype));
  if(new==NULL)
    {
      full();
      return 1;
    }
  new->next=s->top;
  s->top=new;
  return 0;
}
eltype pop(stack *s)
{
  sv *new,*cur;
  // if(empty(s))return NULL;
  new=s->top;
  s->top=new->next;
  cur=new;
  free(new);
  printf("\nxoa thanh cong.\n");
  return *cur;
}

int main()
{
  return 0;
}
