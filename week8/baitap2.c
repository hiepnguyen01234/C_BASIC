#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  int data;
  struct node *left,*right;
}node;
typedef node *tree;

void makenull(tree *t)
{
  *t=NULL;
}
int empty(tree t)
{
  return t==NULL;
}
void insert(int n,tree *root)
{
  if(*root==NULL)
    {
      *root=(node*)malloc(sizeof(node));
      (*root)->data=n;
      (*root)->left=NULL;
      (*root)->right=NULL;
    }
  else if(n>(*root)->data) insert(n,&(*root)->right);
  else if(n<(*root)->data) insert(n,&(*root)->left);
}
int search(int n,tree root)
{
  if(root==NULL) return 0;
  else if(root->data==n) return root->data;
  if(n>root->data) return search(n,root->right);
  if(n<root->data) return search(n,root->left);
}
int main()
{
  int i,n,j;
  tree t;
  char c[10];
  makenull(&t);
  empty(t);
  printf("nhap so luong nut:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      printf("nhap gia tri:");
      scanf("%d",&j);
      insert(j,&t);
    }
  for(i=0;;i++)
    {
  printf("nhap du lieu can tim:");
  scanf("%s",c);
  n=atoi(c);
  if((n==0)&&(strcmp(c,"0")!=0)) break;
  if(search(n,t)!=0)
  printf("du lieu nut can tim la: %d\n",search(n,t)); 
  else printf("khong tim thay gia tri can tim.\n");
    }
  return 0;
}
