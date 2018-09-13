#include<stdio.h>
#include "stack.h"

initialize(stacktype stack)
{
  top=0;
}
empty(stacktype stack)
{
  return top ==0;
}
full(stacktype stack)
{
  return top == max;
}
push(eltype el,stacktype stack)
{
  if(full(*stack))
    printf("stack overflow");
  else stack[top++]=el;
}
eltype pop (stacktype stack)
{
  if(empty(stack))
    printf("stack underflow");
  else return stack[--top];
}
