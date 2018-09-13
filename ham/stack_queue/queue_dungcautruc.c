#define max 50
typedef struct queue
{
  int rear,front,sft;
  char qu[max];
}queue;
void makenullqueue(queue *q)
{
  q->front=0;
  q->sft=0;
  q->rear=-1;
}
int emptyqueue(queue *q)
{
    return (q->sft==0);
}
int fullqueue(queue *q)
{
    return (q->sft==max);
}
void enqueue(queue *q,char x)
{
  if(full1(q)) printf("day.\n");
  else 
    {
      q->qu[++q->rear]=x;
      q->sft++;
    }
}
char dequeue(queue *q)
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

