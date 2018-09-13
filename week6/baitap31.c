#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sanpham
{
  int masp;
  char tensp[31];
  char motasp[50];
  int giasp;
  int slsp;
  struct sanpham *next;
}sp;

sp mang[50];
int sft;

int switch_case(int *n)
{
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	int j;
	FILE *fptr1;
	char filename1[]="sanpham.txt";
	sp *cur,*root = NULL;
	/*
        cur=(sp*)malloc(sizeof(sp));
	root=(sp*)malloc(sizeof(sp));
	root->next=NULL;
	*/
	cur=root;
	if((fptr1=fopen(filename1,"w"))==NULL)
	  {
	    printf("khong the mo %s\n",filename1);
	    return 0;
	  }
	for(j=0;;j++)
	  {
            sp *new;	    
	    new=(sp*)malloc(sizeof(sp));
	    new->masp=0;
	    printf("nhap ma sp:");
	    char meo[30];
	    scanf("%s",meo);
	    new->masp=atoi(meo);
	    //scanf("%d",&new->masp);
	    if((new->masp==0) &&(strcmp(meo,"0")) )
	      {
		free(new);
		break;
	      }
	    while(getchar()!='\n');
	    printf("nhap tensp:");
	    gets(new->tensp);
	    printf("nhap motasp:");
	    gets(new->motasp);
	    printf("nhap gia sp:");
	    scanf("%d",&new->giasp);
	    printf("nhap sl sp:");
	    scanf("%d",&new->slsp);
	    new->next=NULL;
	    if(root==NULL) root=new;
	    else cur->next=new;
	    cur=new;
	  }
	cur=root;
	while(cur!=NULL)
	  {
	    fprintf(fptr1,"%d  %s  %s  %d  %d\n",cur->masp,cur->tensp,cur->motasp,cur->giasp,cur->slsp);
	    printf("%d  %s  %s  %d  %d\n",cur->masp,cur->tensp,cur->motasp,cur->giasp,cur->slsp);
            cur=cur->next;
	  }
	/*cur=root;
	root=root->next;
	free(cur);*/
	fclose(fptr1);
	break;
      }
    case 2:
      {
	FILE *fptr1;
	//int irc;
	sp *a;
	char filename1[]="sanpham.txt";
	if((fptr1=fopen(filename1,"r"))==NULL)
	  {
	    printf("khong the mo %s",filename1);
	    return 0;
	  }
	while(!feof(fptr1))
	  {
	    fscanf(fptr1,"%d  %s  %s  %d  %d\n",&mang[sft].masp,mang[sft].tensp,mang[sft].motasp,&mang[sft].giasp,&mang[sft].slsp);
	    printf("%d  %s  %s  %d  %d\n",mang[sft].masp,mang[sft].tensp,mang[sft].motasp,mang[sft].giasp,mang[sft].slsp);
	    sft++;

	  }
	fclose(fptr1);
	break;
      }
    case 3:
      {
	int mstk,i,j=1;
	printf("nhap mstk:");
	scanf("%d",&mstk);
	for(i=0;i<sft;i++)
	  {
	    if(mstk==mang[i].masp)
	      {
		j=0;
		printf("%d  %s  %s  %d  %d\n",mang[i].masp,mang[i].tensp,mang[i].motasp,mang[i].giasp,mang[i].slsp);
		break;
	      }
	  }
	if(j) printf("tim kiem that bai.\n");
	break;
      }
    }
}

int main()
{
  int i=1,*n;
  n=&i;
  while((i<=3)&&(i>=1))
    {
      printf("---menu---\n");
      printf("1.nhap du lieu va ghi vao file sanpham.txt\n");
      printf("2.ghi du lieu tu file vao mang.\n");
      printf("3.nhap masp de tim kiem va in ra so phep so sanh can thuc hien.\n");
      switch_case(n);
    }
  return 0;
}

