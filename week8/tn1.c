#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  FILE *fptr1;
  char a[30],b[30];
  char filename1[]="tudien.txt";
  if((fptr1=fopen(filename1,"r"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  fscanf(fptr1,"%s %s",a,b);
  printf("%-10s%-10s\n",a,b);
  strcat(a," ");
  strcat(a,b);
  printf("ket qua:\n");
  printf("%-10s%-10s\n",a,b);
  return 0;
}
