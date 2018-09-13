#include<stdio.h>
#include<stdlib.h>

typedef struct bistr
{
  int data;
  struct bistr *right,*left;
}bist;
typedef struct bistr *bst;

void makenull(bst *t)
{
  *t=NULL;
}
int empty(bst t)
{
  return t==NULL;
}
bst rightchild(bst t)
{
  if(t!=NULL) return t->right;
  else return NULL;
}
bst leftchild(bst t)
{
  if(t!=NULL) return t->left;
  else return NULL;
}
bist *creat(int data)
{
  bist *new;
  new=(bist*)malloc(sizeof(bist));
  if(new!=NULL)
    {
      new->right=NULL;
      new->left=NULL;
      new->data=data;
    }
  return new;
}
int isleaf(bst t)
{
  if(t!=NULL)
    return (rightchild(t)==NULL)&&(leftchild(t)==NULL);
  else return -1;
}
int slnode(bst t)
{
  if(empty(t)) return 0;
  else return 1+slnode(leftchild(t))+slnode(rightchild(t));
}
bst addleft(bst *t,int data)
{
  bist *new=creat(data);
  if(new==NULL) return new;
  if(*t==NULL)
    *t=new;
  else 
    {
      bist *lnode=*t;
      while(lnode->left!=NULL)
	{
	  lnode->left=new;
	  lnode=lnode->left;
	}
    }
  return new;
}
bst addright(bst *t,int data)
{
  bist *new=creat(data);
  if(new==NULL) return new;
  if(*t==NULL) *t=new;
  else
    {
      bist *lnode=*t;
      while(lnode->right!=NULL)
	{
	  lnode->right=new;
	  lnode=lnode->right;
	}
    }
  return new;
}

int main()
{
  bst t;
  int i,n,data;
  makenull(&t);
  empty(t);
  printf("nhap so nut trai can nhap:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("nhap gia tri cho nut:");
      scanf("%d",&data);
      addleft(&t,data);
    }
  printf("nhap so nut phai can nhap:");
  scanf("%d",&n);
    for(i=0;i<n;i++)
      {
	printf("nhap gia tri nut:");
	scanf("%d",&data);
	addright(&t,data);
      }
  return 0;
}
