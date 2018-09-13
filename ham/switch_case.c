#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void switch_case(int *n)
{
  printf("-----menu-----\n");
  printf("1.\n");
  printf("2.\n");
  printf("3.\n");
  printf("4.\n");
  printf("5.\n");

  /*tree root=NULL;
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
		    fgets(cur->dochoi,100,fptr1);
		    if(cur->dochoi[strlen(cur->dochoi)-1]=='\n')
		      cur->dochoi[strlen(cur->dochoi)-1]=0;
		    insert(cur->dochoi,cur->maso,&root);
               }
	} */      //docfile_khoitaocay.
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	break;
      }
    case 2:
      {
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
    case 5:
      {
	break;
      }
    }
  //free(cur);
}

int main()
{
  int *n,i=1;
  n=&i;
  while(i!=5)
    {
      if((i<=5)&&(i>=1))
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
	  /*  if(fscanf(fptr1,"%d",&cur->maso)>0)
	      {
		if(fgetc(fptr1)=='\n')
		  {
		    printf("nhap do choi cua ma so %d:",cur->maso);
		    scanf("%s",cur->dochoi);
		    insert(cur->dochoi,cur->maso,&root);
		  }
               }*/
