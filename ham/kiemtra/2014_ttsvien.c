#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.them mot sinh vien vao he thong.\n");
  printf("2.in danh sach sinh vien.\n");
  printf("3.xoa sinh vien.\n");
  printf("4.ghi vao file va ve menu dau.\n");
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	break;
      }
    case 2:
      {
	break;
      }
    case 3:
      {
	break;
      }
    case 4:
      {
	break;
      }
    }
}
void switch_case1(int *n)
{
  printf("-----menu-----\n");
  printf("1.dang nhap.\n");
  printf("2.thoat.");
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	break;
      }
    case 2:
      {
	break;
      }
    }
}

int main()
{
  int *n,i=1;
  n=&i;
  while(i!=5)
    {
      if((i<=5)&&(i>=1))
	{
	  switch_case(n);
	}
      else
	{
	  printf("nhap lai.\n");
	  switch_case(n);
	}
    }
  return 0;
}
