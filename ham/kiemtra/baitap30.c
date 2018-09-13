#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sinhvien
{
  int mssv;
  char name[31];
  float diemthi;
  struct sinhvien *next;
}sv;

int sft;
sv mang[50];

int switch_case(int *n)
{    
  scanf("%d",&*n);
  switch(*n)
    {
    case 1:
      {
	int j;
        sv *new;
        sv *cur,*root;
	cur=(sv*)malloc(sizeof(sv));
	root=(sv*)malloc(sizeof(sv));
        root->next=NULL;
        cur=root;

        FILE *fptr1;
        char filename1[]="sv.dat";
        if((fptr1=fopen(filename1,"wb"))==NULL)
          {
            printf("khong the mo %s\n",filename1);
            return 0;
          }

	for(j=0;;j++)
	  {
	new=(sv*)malloc(sizeof(sv));
	while(getchar()!='\n');
	printf("hoten:");
	gets(new->name);
	if(strcmp(new->name,"###")==0) 
	  {
	    free(new);
	    break;
	  }
	printf("nhap mssv:");
	scanf("%d",&new->mssv);
	printf("diem thi:");
	scanf("%f",&new->diemthi);
	new->next=NULL;
	cur->next=new;
	cur=new;
	  }
	cur=root;
	while(cur->next!=NULL)
	  {
	    cur=cur->next;
	    fwrite(cur,sizeof(sv),1,fptr1);
	  }
	fclose(fptr1);
	free(cur);
	free(root);
	break;
      }
    case 2:
      {
	FILE *fptr1;
       	int irc;
	char filename1[]="sv.dat";
	if((fptr1=fopen(filename1,"rb"))==NULL)
	  {
	    printf("khong the mo %s\n",filename1);
	    return 0;
	  }

	while(!feof(fptr1))
	  {
	irc=fread(&mang[sft],sizeof(sv),1,fptr1);
	if(irc) 
	  {
	    printf("%d  %s  %f\n",mang[sft].mssv,mang[sft].name,mang[sft].diemthi);
	    sft++;
	  }
	  }
	/*while(!feof(fptr1))
	  {
	    fscanf(fptr1,"%d  %s  %f\n",&mang[sft].mssv,mang[sft].name,&mang[sft].diemthi);
	    printf("%d  %s  %f\n",mang[sft].mssv,mang[sft].name,mang[sft].diemthi);       
	    sft++;
	    }*/
	fclose(fptr1);
	break;
      }
    case 3:
      {
	int i,j,max;
	sv tt;	
	for(i=1;i<sft;i++)
	  {
            max=mang[sft-i].mssv;
	    for(j=0;j<sft-i;j++)
	      {
  	        if(mang[j].mssv>max)
	         {
		   tt=mang[j];
		   mang[j]=mang[sft-i];
		   mang[sft-i]=tt;
	         }                
	      }
	  }
	for(i=0;i<sft;i++)
	  printf("%d  %s  %f\n",mang[i].mssv,mang[i].name,mang[i].diemthi);
	break;
      }
    case 4:
      {
	int mstk,tb,tr,du,i,t,d;
	printf("nhap ma so sinh vien can tim:");
	scanf("%d",&mstk);
	t=sft-1;
	d=0;
	for(i=0;i<=sft/2;i++)
	  {
	tr=mang[t].mssv;
	du=mang[d].mssv;
	tb=(tr+du)/2;
	if(tb==mstk)
	  {
            printf("%d  %s  %f\n",mang[(t+d)/2].mssv,mang[(t+d)/2].name,mang[(t+d)/2].diemthi);
	    break;
	  }
	if(tr==mstk)
	  {
	    tb=tr;
	    printf("%d  %s  %f\n",mang[t].mssv,mang[t].name,mang[t].diemthi);
	    break;
	  }
	if(du==mstk)
	  {
	    tb=du;
	    printf("%d  %s  %f\n",mang[d].mssv,mang[d].name,mang[d].diemthi);
	    break;
	  }
	if(tb>mstk) t=(t+d)/2;
	if(tb<mstk) d=(t+d)/2;				  
	  }
	if(tb!=mstk) printf("khong co sinh vien can tim.\n");
	break;
      }
    }
}
int main()
{
  int i=1,*n;
  n=&i;
  while((i<=4)&&(i>=1))
    {
  printf("---MENU---\n");
  printf("1.doc thong tin sv va luu vao sv.dat.\n");
  printf("2.in tu sv.dat ra mang.\n");
  printf("3.sap xep theo thu tu tang dan cua mssv.\n");
  printf("4.tim kiem.\n\n");
  switch_case(n);
    }

  return 0;
}
