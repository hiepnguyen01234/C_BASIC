#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct qtmk
{
  char name[31];
  char password[10];
  struct qtmk *left,*right;
}qtmk;
typedef qtmk *tree;

void makenull(tree *root)
{
  *root=NULL;
}
int empty(tree root)
{
  return root==NULL;
}
void insert(char ten[31],char mk[10],tree *root)
{
  if((*root)==NULL)
    {
      (*root)=(qtmk*)malloc(sizeof(qtmk));
      strcpy((*root)->name,ten);
    }
}
void inoderfprintf(tree root)
{
  FILE *fptr1;
  char filename1[]="pass.txt";
  if((fptr1=fopen(filename1,"w"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
    }
  if(root!=NULL)
    {
      inoderfprintf(root->left);
      fprintf(fptr1,"%s   %s\n",root->name,root->password);
      inoderfprintf(root->right);
    }
  fclose(fptr1);
}
tree khoitao(tree *root)
{
  FILE *fptr1;
  int i,n;
  char ten[31],mk[10];
  char filename1[]="pass.txt";
if((fptr1=fopen(filename1,"w"))==NULL)
  {
    printf("khong the mo %s.\n",filename1);
    return 0;
  }
 printf("nhap so nguoi dung:");
 scanf("%d",&n);
 makenull(root);
 for(i=0;i<n;i++)
   {
     printf("nhap ten:");
     scanf("%s",ten);
     printf("password:");
     scanf("%s",mk);
     insert(ten,mk,root);
   }
 inoderfprintf(*root);
 printf("in ra file pass.txt thanh cong.\n");
 fclose(fptr1);
}

int main()
{
  FILE *fptr1;
  char filename1[]="pass.txt";
  int i,n,j;
  tree root;
  char ten[31],mk[10];
  khoitao(&root);
  if((fptr1=fopen(filename1,"r"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  /*for(i=0;;i++)
    {
      printf("nhap username:");
      scanf("%s",ten);
      search(ten,root);
      }*/
  fclose(fptr1);
  return 0;
}
