node *push(node *top,int x)
{
  node *new=(node*)malloc(sizeof(node));
  new->data=x;
  new->link=top;
  return new;   
}
node *pop(node *top,int *x) 
{
  if(top==NULL) printf("loi\n");
  else 
    {
      node *temp;
      *x=top->data;
      temp=top->link;
      free(top);
      return temp;
    }
}

/* void push(node **top,int x)
{
node *new=(node*)malloc(sizeof(node));
new->data=x;
new->link=*top;
*top=new;
}
void pop(node **top,int *x)
{
if(*top==NULL) printf("loi.\n");
else 
{
node *temp;
*x=*top->data;
temp=*top->link;
free(*top);
*top=temp;
}
}
