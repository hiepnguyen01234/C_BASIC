#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char tu[100];
typedef struct tudien
{
  char ta[30];
  char tv[30];
  struct tudien *left,*right;
}td;
typedef td *tree;

void makenull(tree *t)
{
  *t=NULL;
}
int empty(tree t)
{
  return t==NULL;
}
void insert(char ta[31],char tv[10],tree *root)
{
  if((*root)==NULL)
    {
      (*root)=(td*)malloc(sizeof(td));
      strcpy((*root)->ta,ta);
      strcpy((*root)->tv,tv);
      (*root)->right=NULL;
      (*root)->left=NULL;
    }
  else if(strcmp(ta,(*root)->ta) > 0) return insert(ta,tv,&(*root)->right);
  else if(strcmp(ta,(*root)->ta) < 0) return insert(ta,tv,&(*root)->left);
}
int search(char ta[31],tree root)
{
  if(root==NULL) return 0;
  if(strcmp(ta,root->ta)==0)
    {
      printf("tu tien anh:%s\n",root->ta);
      printf("nghia tien viet:%s\n",root->tv);
      return 0;
    }
  else if(strcmp(ta,root->ta) > 0) return search(ta,root->right);
  else if(strcmp(ta,root->ta) < 0) return search(ta,root->left);
}
int searchtu(char ta[31],tree root)
{
  if(root==NULL) return 1;
  if(strcmp(ta,root->ta)==0)
    {
      strcat(tu,root->tv);
      strcat(tu," ");
      return 0;
    }
  else if(strcmp(ta,root->ta) > 0) return searchtu(ta,root->right);
  else if(strcmp(ta,root->ta) < 0) return searchtu(ta,root->left);
}

void inoderprintf(tree root)
{
  if(root!=NULL)
    {
      inoderprintf(root->left);
      printf("%s  %s\n",root->ta,root->tv);
      inoderprintf(root->right);
    }
}
char dichtu(char n[30],tree root)
{
  FILE *fptr1;
  char filename1[]="tudien.txt";
  char *ctr;
  td a[30];
  int i=0,j;

  if((fptr1=fopen(filename1,"ab"))==NULL)
    {
      printf("khong the mo %s\n",filename1);
      return ;
    }
  if(root==NULL) return 0;
  ctr=strtok(n," ");
  while(ctr!=NULL)
    {
      strcpy(a[i].ta,ctr);
      i++;
      j=i;
      ctr=strtok(NULL," ");
    }
    
  for(i=0;i<j;i++)
    {
      if(searchtu(a[i].ta,root)==1)
	{
	  printf("khong co trong tu dien,nhap nghia cua tu %s:",a[i].ta);
	  scanf("%s",a[i].tv);
	  strcat(tu,a[i].tv);
	  strcat(tu," ");
	  fprintf(fptr1,"%s %s\n",a[i].ta,a[i].tv);
	  insert(a[i].ta,a[i].tv,&root);
	}
    }
    printf("nghia tieng viet cua cau :");
    printf("%s\n",tu);
    for(i=0;tu[i]!=NULL;i++)
      {
	tu[i]=NULL;
      }
    printf("\n");
    fclose(fptr1);
}
int switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.doc file tudien.txt va luu vao cay nhi phan.\n");
  printf("2.hien thi cay.\n");
  printf("3.dich anh viet.\n");
  printf("4.thoat.\n");
  FILE *fptr1;
  tree root=NULL;
  tree cur;
  char filename1[]="tudien.txt";
  char mang[30];
  cur=(td*)malloc(sizeof(td));
  if((fptr1=fopen(filename1,"r"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  while(!feof(fptr1))
    {
      if(fscanf(fptr1,"%s%s",cur->ta,cur->tv)>0)
	{
	  //printf("%s %s\n",cur->name,cur->password);
	  insert(cur->ta,cur->tv,&root);
	}
    }
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	printf("in vao cay thanh cong.\n");
	fclose(fptr1);
	break;
      }
    case 2:
      {
	inoderprintf(root);
	break;
      }
    case 3:
      {
	printf("nhap tu can dich:");
	while(getchar()!='\n');
	gets(mang);
	dichtu(mang,root);
	break;
      }
    case 4:
      {
	break;
      }
    }
  free(cur);
}

int main()
{
  FILE *fptr1;
  char filename1[]="tudien.txt";
  tree root;
  int *n,i=1;
  n=&i;
  if((fptr1=fopen(filename1,"r+"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  makenull(&root);
  while(i!=4)
    {
      switch_case(n);
      if((i<1)||(i>4))
	{
	  printf("nhap lai:");
	}
    }
  fclose(fptr1);
  return 0;
}
