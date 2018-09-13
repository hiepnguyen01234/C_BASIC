#include<stdio.h>

typedef struct sinhvien
{
  int mssv;
  char name[31];
  float diemthi;
  struct sinhvien *next;
}sv;

int main()
{
  int i=0,irc;
  FILE *fptr1;
  char filename1[]="sv.dat";
  sv mang[5];
  if((fptr1=fopen(filename1,"rb"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  while(!feof(fptr1))
    {
      irc=fread(&mang[i],sizeof(sv),1,fptr1);     
      if(irc) printf("%d  %s  %f\n",mang[i].mssv,mang[i].name,mang[i].diemthi); 
      i++;
    }
  fclose(fptr1);
  return 0;
}
