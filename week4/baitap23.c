#include<stdio.h>
#include<stdlib.h>

typedef struct sv
{
  int mssv;
  char name[31];
  float diemthi;
  struct sv *next;
}sv;
typedef struct stack
{
  sv *top;
}stack;

#define max 50
typedef sv eltype; 
//typedef eltype stacktype[max];

void *initialize();
int empty(const stack *s);
int full();
int push(eltype *new,stack *s);
eltype pop (stack *s);

void *initialize ()
{
  stack *s;
  s= (stack*)malloc(sizeof(stack));
  if(s==NULL){return NULL;}
  s->top=NULL;
  return s;
}
int empty(const stack *s)
{
  return(s->top==NULL);
}
int full()
{
  printf("\nfull stack.\n");
  getchar();
  return 1;
}
int push(eltype *new,stack *s)
{
  eltype* newx=(eltype*)malloc(sizeof(eltype));
  if(newx==NULL)
    {
      full();
      return 1;
    }
  *newx=*new;
  if(empty(s))
    newx->next=NULL;
  else
    newx->next=s->top; 
  s->top=newx;

  return 0;
}
eltype pop(stack *s)
{
  sv *new;
  sv cur;
  // if(empty(s))return NULL;
  new=s->top;
  s->top=new->next;
  cur=*new; 
  free(new);
  return cur;
}

int main()
{
  FILE *fptr1,*fptr2;
  char filename1[]="sinhvien.dat";
  char filename2[]="sinhvien2.dat";
  eltype new;
  int irc;
  stack *s;

  s=initialize();
  if((fptr1=fopen(filename1,"rb"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
    }
  if((fptr2=fopen(filename2,"wb"))==NULL)
    {
      printf("khong the mo %s.\n",filename2);
    }
  do
    {
      irc=fread(&new,sizeof(sv),1,fptr1);
      if(irc)push(&new,s);
    }while(!feof(fptr1));
  if(irc)printf("loi.\n");

  do
    {
      new=pop(s);
      printf("%-5d%-20s%-5f\n",new.mssv,new.name,new.diemthi);
      irc=fwrite(&new,sizeof(sv),1,fptr2);
    }while(!empty(s));
  if(irc)printf("chep thanh cong.\n");
  else printf("loi.\n");

  fclose(fptr1);
  fclose(fptr2);
  return 0;
}
