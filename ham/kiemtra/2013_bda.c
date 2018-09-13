#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  char madb[30];
  int diem;
  struct node *left,*right;
}node;
typedef node *tree;

void insert(char madoibong[],int dim,tree *root)
{
  if((*root)==NULL)
    {
      (*root)=(node*)malloc(sizeof(node));
      strcpy((*root)->madb,madoibong);
      (*root)->diem=dim;
      (*root)->right=NULL;
      (*root)->left=NULL;
    }
  else if(strcmp(madoibong,(*root)->madb)>0) return insert(madoibong,dim,&(*root)->right);
  esle if(strcmp(madoibogn,(*root)->madb)<0) return insert(madoibong,dim,&(*root)->left);
}

void switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.tao cay.\n");
  printf("2.ket qua.\n");
  printf("3.tim kiem.\n");
  printf("4.xuong han.\n");
  printf("5.xuat file.\n");
  printf("6.thoat.\n");
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
    case 5:
      {
	break;
      }
    case 6:
      {
	break;
      }
    }
}

int main()
{
  int *n,i=1;
  n=&i;
  while(i!=6)
    {
      if((i<=6)&&(i>=1))
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
