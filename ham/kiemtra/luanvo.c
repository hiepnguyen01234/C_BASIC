#include<stdio.h>

typedef struct vosy
{
  char biethieu[31];
  int nhanhnhen;
  int mau;
  int phongthu;
}sv;

void switch_case(int *n)
{
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

int main()
{
  int j=1,*n;
  n=&j;
  while(j!=4)
    {
      printf("-----menu-----\n");
      printf("1.\n");
      printf("2.\n");
      printf("3.\n");
      printf("4.\n"); 
      switch_case(n);
      if((j!=1)&&(j!=2)&&(j!=3)&&(j!=4))
	{
	  printf("nhap lai:\n");
	}
    }
  char meo[30];
  printf("nhap day ky tu:");
  scanf("%s",meo);
  j=atoi(meo);
  if(j==0)
    {
      printf("so sanh kieu fuck.\n");
      return 0;
    }
  printf("chay sai roi.\n");
  return 0;
}
