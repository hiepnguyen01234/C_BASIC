#include<stdio.h>
#include<stdlib.h>

#define max 50
int top;
void khoitao(char *stack){top=0;}
int empty(char *stack){return top==0;}
int full(char *stack){return top==max;}
void push(char new,char *stack)
{
  if(full(stack))
    printf("stack overflow.\n");
  else stack[top++]=new;
};
char pop (char *stack)
{
  if(empty(stack))
    printf("stack underflow.\n");
  else return stack[--top];
}

typedef struct queue
{
  int rear,front,sft;
  char qu[max];
}queue;
void khoitao1(queue *q)
{
  q->front=0;
  q->sft=0;
  q->rear=-1;
}
int empty1(queue *q)
{
    return (q->sft==0);
}
int full1(queue *q)
{
    return (q->sft==max);
}
void push1(queue *q,char x)
{
  if(full1(q)) printf("day.\n");
  else 
    {
      q->qu[++q->rear]=x;
      q->sft++;
    }
}
char pop1(queue *q)
{
  char x;
  int i;
  if(empty1(q)) printf("rong.\n");
  x=q->qu[q->front];
  for(i=q->front;i<q->rear;i++)
    q->qu[i]=q->qu[i+1];
  q->rear--;
  q->sft--;
  return x;
}


int main()
{
  char xau[20];
  queue *q;
  q=(queue*)malloc(sizeof(queue));
  char mang[20];
  int i=0;
  khoitao1(q);
  printf("nhap xau ky tu:\n");
  gets(xau);
  while(xau[i]!='\0')
    {     
      push(xau[i],mang);
      push1(q,xau[i]);
      i++;
    }
  // push(0,mang);
  puts(mang);
  puts(q->qu);
  while(!empty1(q))
    {
      printf("%c/%c\n",pop(mang),pop1(q));
      if(pop(mang)!=pop1(q))
	{
	  printf("khong doi xung.\n");
	  return 0;
	}
    }
  printf("doi xung.\n"); 
  return 0;
}
