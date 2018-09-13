#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
typedef eltype stacktype[max];
int top;

void initialize(stacktype stack);
int empty(stacktype stack);
int full(stacktype stack);
void push(eltype el,stacktype stack);
eltype pop (stacktype stack);


void initialize(stacktype stack){top=0;}
int empty(stacktype stack){return top==0;}
int full(stacktype stack){return top==max;}
void push(eltype el,stacktype stack)
{
  if(full(stack))
    printf("stack overflow");
  else stack[top++]=el;
};
eltype pop (stacktype stack)
{
  if(empty(stack))
    printf("stack underflow");
  else return stack[--top];
};


int main()
{
  FILE *fptr1,*fptr2;
  sv *new;
  int irc;
  stacktype s;
  char filename1[]="sinhvien.dat";
  char filename2[]="sinhvien2.dat";
  eltype mang;

  initialize(s);
 
  if((fptr1=fopen(filename1,"rb"))==NULL)
    {
      printf("khong the mo %s\n",filename1);
    }
  do
    {
        irc=fread(&mang,sizeof(sv),1,fptr1);
	if(irc)push(mang,s);
	
    }while(!feof(fptr1));
  if(irc)printf("loi.\n");

    if((fptr2=fopen(filename2,"wb"))==NULL)
      {
	printf("khong the mo %s\n",filename2);
      }
  do
    {
     mang= pop(s);
     printf("%-5d%-20s%-5f\n",mang.mssv,mang.name,mang.diemthi);
     irc=fwrite(&mang,sizeof(sv),1,fptr2);
    }while(!empty(s));
  if(irc) printf("chep than cong.\n");
  else printf("loi.\n");

  fclose(fptr1);
  fclose(fptr2);
  return 0;
}
