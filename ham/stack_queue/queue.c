typedef struct queue
{
  node *front,*rear;
}queue;
void makenullqueue(queue *q)
{
  q->front=NULL;
  q->rear=NULL;
}
int emptyqueue(queue *q)
{
  return q->front==NULL;
}
void enqueue(int x,queue *q)
{
  node* new=(node*)malloc(sizeof(node));
  new->data=x;
  new->next=NULL;
  if(emptyqueue(q))
    {
      q->front=q->rear=new;
    }
  else
    {
      q->rear->next=new;
      q->rear=new;
    }
}
void dequeue(queue *q,int *x)
{
  if(!emptyqueue(q))
    {
      node *empty;
      empty=q->front;
      *x=q->front->data;
      q->front=q->front->next;
      free(empty);
    }
  else printf("loi.\n");
}
