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

int main()
{
  char filename1[]="sinhvien.dat";
  FILE *fptr1;
  if((fptr1=fopen(filename1,"wb"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }

  sv *cur,*root;
  int i,n,irc;
  cur=(sv*)malloc(sizeof(sv));
  root=(sv*)malloc(sizeof(sv));
  root->next=NULL;
  cur=root;

  printf("nhap so luong sinh vien:\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      sv *new;
      new=(sv*)malloc(sizeof(sv));
      printf("nhap mssv:\n");
      scanf("%d",&new->mssv);
      printf("nhap ho ten sinh vien:\n");
      while(getchar()!='\n');
      gets(new->name);
      printf("nhap diem thi:\n");
      scanf("%f",&new->diemthi);
      new->next=NULL;
      cur->next=new;
      cur=new;
    }

  cur=root;
  for(i=0;i<n;i++)
    {
      cur=cur->next;
      printf("%-5d%-20s%-5f\n",cur->mssv,cur->name,cur->diemthi);
      irc=fwrite(cur,sizeof(sv),1,fptr1);
    }
  if(irc)printf("chep thanh cong.\n");
  else printf("loi.\n");

  fclose(fptr1);
  free(cur);
  free(root);
  return 0;
}
