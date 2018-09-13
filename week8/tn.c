#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tu
{
  char data[100];
}tu;

int main()
{
  int i=0,j;
  char *n;
  char mang[100];
  tu a[20],b[20];
  FILE *fptr1;
  char filename1[]="tn.txt";
  if((fptr1=fopen(filename1,"r+"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }

  printf("nhap xau ky tu:");
  //while(getchar()!='\n');
  gets(mang);
  printf("%s\n",mang);
  n=strtok(mang," ");
  while(n!=NULL)
    {
      strcpy(a[i].data,n);
      i++;
      j=i;
      n=strtok(NULL," ");
    }
  while(!feof(fptr1))
    {
      for(i=0;i<j;i++)
	{
	  if(fscanf(fptr1,"%s",b[i].data))
	  printf("%s\n",b[i].data);
	}
    }
  fclose(fptr1);
  return 0;
}
