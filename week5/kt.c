#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  int hang;
  int cot;
  char kt;
  struct node *next;
}node;
typedef struct stack
{
  node *top;
}stack;
char xau[100];

int push(node *new,stack *root)
{
  if(root==NULL)
    {
      new->next=NULL;
    }
  else
    {
      new->next=root->top;
      root->top=new;
    }
}
char pop(stack *root)
{
  node *new;
  char cur;
  new=root->top;
  if(new!=NULL)
    {
      root->top=new->next;
      cur=new->kt;
      free(new);
      return cur;
    }
  else return '\0';
}
int ktngoacmo(char tu)
{
  if((tu=='{')||(tu=='[')||(tu=='(')) return 0;
}
int ktngoacdong(char tu)
{
  if((tu=='}')||(tu==']')||(tu==')')) return 0;
}
int ktloi(stack *root)
{
  int i,j;
  j=strlen(xau);
  if((j%2)==0) 
    {
      for(i=0;i++;i<(j/2))
	{
	  j--;
	  if(xau[i]==xau[j])
	    return 1;
	}
    } 
  return 0;
}

int switch_case(int *n)
{
  printf("---menu---\n");
  printf("1.doc file.\n");
  printf("2.kiem tra loi.\n");
  printf("3.in ra vi tri loi.\n");
  printf("4.thoat.\n");
  stack *root;
  root=(stack*)malloc(sizeof(stack));
  root->top=NULL;
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	FILE *fptr1;
	char filename1[30];
        node *new;
	/*new->hang=0;
	  new->cot=0;*/
	printf("nhap ten file can kiem tra:");
	scanf("%s",filename1);
	if((fptr1=fopen(filename1,"r"))==NULL)
	  {
	    printf("khong the mo %s.\n",filename1);
	    return 0;
	  }
	while(!feof(fptr1))
	  {
	    new=(node*)malloc(sizeof(node));
	    new->next=NULL;
	    new->kt=fgetc(fptr1);
	    /*if(new->kt!='\n')
	      {
		new->cot++;
	      }
	    else 
	      {
		new->cot=0;
		new->hang++;
		}*/
	    if(!ktngoacmo(new->kt))
	      {
		push(new,root);
		printf("%c",new->kt);
		char a[2];
		a[0]=new->kt;a[1]=0;
		strcat(xau,a);
	      }
	  }
	printf("\n");
	fseek(fptr1,0,0);
	while(!feof(fptr1))
	  {
	    new->kt=fgetc(fptr1);
	    if(!ktngoacdong(new->kt))
	      {
		char mang[2];
		mang[0]=pop(root);mang[1]=0;
		strcat(xau,mang);
	      }	  
	  }
       	fclose(fptr1);
	break;
      }
    case 2:
      {
	printf("%s\n",xau);
	if(ktloi(root)==1) printf("dung.\n");
	if(ktloi(root)==0) printf("sai.\n");
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
  int i=1,*n;
  n=&i;
  while(i!=4)
    {
      if((i<=4)&&(i>0))
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
