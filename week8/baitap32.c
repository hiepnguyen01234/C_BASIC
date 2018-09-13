#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  char data[30];
  int t;
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
void insert(char n[30],tree *t)
{
  if((*t)==NULL)
    {
      (*t)=(node*)malloc(sizeof(node));
      strcpy((*t)->data,n);
      (*t)->left=NULL;
      (*t)->right=NULL;
      (*t)->t=1;
    }
  else if(strcmp(n,(*t)->data)>0) insert(n,&(*t)->right);
  else if(strcmp(n,(*t)->data)<0) insert(n,&(*t)->left);
  else if(strcmp(n,(*t)->data)==0) ((*t)->t)++;
}
int search(char n[30],tree root)
{
  if(root==NULL) return 1;
  if(strcmp(n,root->data)==0) 
    {
      printf("%d\n",root->t);
      return 0;
    }
  else if(strcmp(n,root->data)>0) return search(n,root->right);
  else if(strcmp(n,root->data)<0) return search(n,root->left);
}
void inoderprintf(tree root)
{
  if(root!=NULL)
    {
      inoderprintf(root->left);
      printf("%s\n",root->data);
      inoderprintf(root->right);
    }
}
void inoderprintf1(tree root)
{
  if(root!=NULL)
    {
      inoderprintf1(root->left);
      printf("%s  %d\n",root->data,root->t);
      inoderprintf1(root->right);
    }
}
int switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.tim va in noi dung file.\n");
  printf("2.in tan suat cua tu can tim.\n");
  printf("3.in bang thong ke.\n");
  printf("4.thoat.\n");
  scanf("%d",&*n);
  tree root;

  switch(*n)
    {
    case 1:
      {
	FILE *fptr1;
	char filename1[30];
	char a[30];
	makenull(&root);
	printf("nhap ten file can tim:");
	scanf("%s",filename1);
	if((fptr1=fopen(filename1,"r"))==NULL)
	{
	  printf("khong the mo %s.\n",filename1);
	  return 0;
	}
	while(!feof(fptr1))
	  {
	    if(fscanf(fptr1,"%s",a)>0)
	      {
		insert(a,&root);
	      }
	  }
	inoderprintf(root);
        fclose(fptr1);
	break;
      }
    case 2:
      {
	char a[30];
	printf("nhap tu can tim tan suat xuat hien:");
	scanf("%s",a);
	if(search(a,root)==1)
	  {
	    printf("0\n");
	  }
	break;
      }
    case 3:
      {
	inoderprintf1(root);
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
  int i=1,*n;
  n=&i;
  while(i!=4)
    {
      switch_case(n);
      if((i>4)||(i<1))
	printf("nhap lai.\n");
    }
  return 0;
}
