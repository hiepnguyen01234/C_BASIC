#include<stdio.h>
#include<stdlib.h>

#define max 50
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
  if (q->sft==0)
  return 0;
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
  khoitao1(q);
  int i=0;
  printf("nhap xau ky tu:\n");
  gets(xau);
  while(xau[i]!='\0')
    {     
      push1(q,xau[i]);
      i++;
    }
  puts(q->qu);

  return 0;
}
