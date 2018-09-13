#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct quantrimatkhau
{
  char name[31];
  char password[10];
  struct quantrimatkhau *left,*right;
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
      strcpy((*root)->password,mk);
      (*root)->right=NULL;
      (*root)->left=NULL;
    }
  else if(strcmp(ten,(*root)->name) > 0) return insert(ten,mk,&(*root)->right);
  else if(strcmp(ten,(*root)->name) < 0) return insert(ten,mk,&(*root)->left);
}
int search(char ten[31],tree root)
{
  if(root==NULL) return 0;
  if(strcmp(ten,root->name)==0)
    {
      printf("ten nguoi dung can tim:%s\n",root->name);
      printf("password:%s\n",root->password);
      return 0;
    }
  else if(strcmp(ten,root->name) > 0) return search(ten,root->right);
  else if(strcmp(ten,root->name) < 0) return search(ten,root->left);
}
int searchuser(char ten[31],char mk[10],tree root)
{
  if(root==NULL) return 0;
  if((strcmp(ten,root->name)==0)&&(strcmp(mk,root->password)==0))
    {
      printf("nhap password moi:");
      scanf("%s",root->password);
      return 1;
    }
  else if(strcmp(ten,root->name) > 0) return search(ten,root->right);
  else if(strcmp(ten,root->name) < 0) return search(ten,root->left);
}
int doimk(char ten[31],tree root)
{
  if(root==NULL) return 0;
  if(strcmp(ten,root->name)==0)
    {
      printf("nhap password moi:");
      scanf("%s",root->password);
      return 1;
    }
  else if(strcmp(ten,root->name) > 0) return search(ten,root->right);
  else if(strcmp(ten,root->name) < 0) return search(ten,root->left);
}
void inoderprintf(tree root)
{
  if(root!=NULL)
    {
      inoderprintf(root->left);
      printf("%s  %s\n",root->name,root->password);
      inoderprintf(root->right);
    }
}
int inoderfprintf(tree root)
{
  FILE *fptr1;
  char filename1[]="pass.txt";
  if((fptr1=fopen(filename1,"w"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  void inoder(tree root)
  {
    if(root!=NULL)
      {
	inoder(root->left);
	fprintf(fptr1,"%s  %s\n",root->name,root->password);
	inoder(root->right);
      }
  }
  inoder(root);
  fclose(fptr1);
}

int switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.them nguoi dung vao he thong.\n");
  printf("2.doi mat khau cho nguoi dung.\n");
  printf("3.in ra danh sach nguoi dung.\n");
  printf("4.thoat chuong trinh.\n");
  tree root=NULL;
  tree cur;
  FILE *fptr1;
  cur=(qtmk*)malloc(sizeof(qtmk));
  char filename1[]="pass.txt";
  if((fptr1=fopen(filename1,"r+"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  while(!feof(fptr1))
    {
      if(fscanf(fptr1,"%s%s",cur->name,cur->password)>0)
	{
	  //printf("%s %s\n",cur->name,cur->password);
	  insert(cur->name,cur->password,&root);
	}
    }
  scanf("%d",&(*n));
  switch(*n)
    {
    case 1:
      {

	printf("nhap ten nguoi dung moi:");
	scanf("%s",cur->name);
	printf("nhap password:");
	scanf("%s",cur->password);
	insert(cur->name,cur->password,&root);
	fseek(fptr1,0l,0);
	inoderfprintf(root);
	fclose(fptr1);
	break;
      }
    case 2:
      {
	char ten[31];
        if((fptr1=fopen(filename1,"w"))==NULL)
          {
            printf("khong the mo %s.\n",filename1);
            return 0;
	  }
	printf("nhap ten nguoi dung can doi mat khau:");
	scanf("%s",ten);
        if(doimk(ten,root)!=1)
	printf("khong co ten nguoi dung can tim.\n");
	inoderfprintf(root);
	fclose(fptr1);
	break;
      }
      case 3:
	{
	  inoderprintf(root);
	  break;
	}
      case 4:
	{
	  break;
	}
      }
  free(cur);
    }
  int sosanh(char ten[31],char mk[10])
  {
    int *n,j=1;
    n=&j;
    if((strcmp(ten,"admin") == 0)&&(strcmp(mk,"123")==0)) 
      {
	while(j!=4)
	  {
	    switch_case(n);
	    if((j<1)||(j>4)) printf("nhap lai.\n");
	  }
      }
    return 1;
  }
  int main()
  {
    FILE *fptr1;
    char filename1[]="pass.txt";
    char ten[31],mk[10];
    int i,n,j;
    tree root;
    if((fptr1=fopen(filename1,"r+"))==NULL)
      {
	printf("khong the mo %s.\n",filename1);
	return 0;
      }
    makenull(&root);
    while(!feof(fptr1))
      {
	if(fscanf(fptr1,"%s%s",ten,mk)>0)
	  {
	    //printf("%s %s\n",ten,mk);
	    insert(ten,mk,&root);
	  }
      }
    printf("nhap ten tai khoan:");
    scanf("%s",ten);
    printf("nhap mat khau:");
    scanf("%s",mk);
    sosanh(ten,mk);
    if(searchuser(ten,mk,root)!=1) 
    printf("khong the truy cap.\n");
    inoderfprintf(root);
    /*for(i=0;;i++)
      {
      printf("nhap username:");
      scanf("%s",ten);
      search(ten,root);
      }*/
    fclose(fptr1);
    return 0;
  }
