#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  char dochoi[31];
  int maso;
  struct node *left,*right;
}node;
typedef node *tree;

node tang[100];
node mang[100];
int sft=1;
int j;

void makenull(tree *root)
{
  *root=NULL;
}
int empty(tree root)
{
  return root==NULL;
}
void insert(char dc[],int ms,tree *root)
{
  if((*root)==NULL)
    {
      (*root)=(node*)malloc(sizeof(node));
      strcpy((*root)->dochoi,dc);
      (*root)->maso=ms;
      (*root)->right=NULL;
      (*root)->left=NULL;
    }
  else if(ms>(*root)->maso) return insert(dc,ms,&(*root)->right);
  else if(ms<(*root)->maso) return insert(dc,ms,&(*root)->left);
}
void inoderprintf(tree root)
{
  if(root!=NULL)
    {
      inoderprintf(root->left);
      printf("%d  %s\n",root->maso,root->dochoi);
      inoderprintf(root->right);
    }
}
void inoderprintf1(tree root)
{
  if(root!=NULL)
    {
      inoderprintf1(root->right);
      printf("%d %s\n",root->maso,root->dochoi);
      inoderprintf1(root->left);
    }
}
void inoderprintf2(tree root)
{
  if(root!=NULL)
    {
      inoderprintf2(root->left);
      strcpy(tang[j++].dochoi,root->dochoi);
      inoderprintf2(root->right);
    }
}
void thongke(node tang[])
{
  int i,a,b;
  for(i=0;i<j;i++)
    {
      tang[i].maso=1;
      for(a=i+1;a<j;a++)
	{
	  if(strcmp(tang[i].dochoi,tang[a].dochoi)==0)
	    {
	      tang[i].maso++;
	      for(b=a;b<j;b++)
		{
		  tang[b]=tang[b+1];
		}
	      j--;
	    }
	}
    }
}
int search(int ms,tree root)
{
  if(root==NULL) return 1;
  if(ms==root->maso)
    {
      printf("ma so can tim:%d\n",root->maso);
      printf("do choi:%s\n",root->dochoi);
      return 0;
    }
  else if(ms>root->maso) return search(ms,root->right);
  else if(ms<root->maso) return search(ms,root->left);
}

void DelMinNode(tree * root, int *ms)
       {
	if((*root)->left == NULL) {
		*ms = (*root)->maso;//
		node* tmp = *root;
		*root = (*root)->right;
		free(tmp);
		return;
	}
	DelMinNode(&(*root)->left, ms);
}
int delNode(tree * root, int ms){
	if(*root != NULL)
		if((*root)->maso < ms)
			return delNode(&(*root)->right, ms);
		else if((*root)->maso > ms)
			return delNode(&(*root)->left, ms);
		else{
			int k = (*root)->maso;
			if(((*root)->left == NULL) && ((*root)->right == NULL))
				{
					free(*root);
					*root = NULL;
				}
			else if((*root)->left == NULL){
				node* tmp = *root;
				*root = (*root)->right;
				free(tmp);
			}
			else if((*root)->right == NULL){
				node* tmp = *root;
				*root = (*root)->left;
				free(tmp);
			}
			else DelMinNode(&(*root)->right, &(*root)->maso);
			return k;
		}
	return -1;
}

int sosanh(node mang[],tree *root)
{
  int i;
  for(i=0;i<sft;i++)
    {
      if(search(mang[i].maso,*root)==0)
	{
	  delNode(root,mang[i].maso);
	}
      return 0;
    }
  printf("khong co nguoi nao bi trung.\n");
}
int chen(node mang[],tree *root)
{
  int i;
  for(i=0;i<sft;i++)
    {
      insert(mang[i].dochoi,mang[i].maso,root);
    }
  //inoderprintf1(*root);
}

void switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.doc file A\n");
  printf("2.doc file B\n");
  printf("3.tim kiem\n");
  printf("4.tong hop\n");
  printf("5.thong ke\n");
  printf("6.thoat.\n");
  tree root;
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	root=NULL;
	tree cur;
	FILE *fptr1;
	cur=(node*)malloc(sizeof(node));
	char filename1[]="A.txt";
	if((fptr1=fopen(filename1,"r"))==NULL)
	  {
	    printf("khong the mo %s.\n",filename1);
	    return;
	  }
	while(!feof(fptr1))
	  {
	    if(fscanf(fptr1,"%d",&cur->maso)>0)
	      {
		if(fgetc(fptr1)=='\n')
		  {
		    printf("nhap do choi cua ma so %d:",cur->maso);
		    scanf("%s",cur->dochoi);
		    insert(cur->dochoi,cur->maso,&root);
		  }
		else
		  {
		    fgets(cur->dochoi,100,fptr1);
		    if(cur->dochoi[strlen(cur->dochoi)-1]=='\n')
		      cur->dochoi[strlen(cur->dochoi)-1]=0;
		    insert(cur->dochoi,cur->maso,&root);
		  }
	      }
	    else break;
	  }
	inoderprintf(root);
	fclose(fptr1);
	break;
      }
    case 2:
      {
	FILE *fptr2;
	int i=0;
	char filename2[]="B.txt";
	if((fptr2=fopen(filename2,"r"))==NULL)
	  {
	    printf("khong the mo %s",filename2);
	    return ;
	  }
	while(!feof(fptr2))
	  {
	    if(fscanf(fptr2,"%d",&mang[i].maso)>0)
	      {
		if(fgetc(fptr2)=='\n')
		  {
		    printf("nhap do choi cua ma so %d:",mang[i].maso);
		    scanf("%s",mang[i].dochoi);
		  }
		else
		  {
		    fgets(mang[i].dochoi,100,fptr2);
		    if(mang[i].dochoi[strlen(mang[i].dochoi)-1]=='\n')
		      mang[i].dochoi[strlen(mang[i].dochoi)-1]=0;
		    printf("%d %s\n",mang[i].maso,mang[i].dochoi);
		    i++;
		    sft++;
		  }
	      }
	    else break;
	  }
	fclose(fptr2);
	break;
      }
    case 3:
      {
	sosanh(mang,&root);
	inoderprintf(root);
	break;
      }
    case 4:
      {
	chen(mang,&root);
	inoderprintf1(root);
	break;
      }
    case 5:
      {
	int i;
	j=0;
	inoderprintf2(root);
	thongke(tang);
	for(i=0;i<j;i++)
	  {
	    printf("%s %d\n",tang[i].dochoi,tang[i].maso);
	  }
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
