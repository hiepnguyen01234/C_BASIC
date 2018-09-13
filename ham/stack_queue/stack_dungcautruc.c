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
