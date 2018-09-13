#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sinhvien
{
  int mssv;
  char hoten[31];
  float diemthi;
}sv;

typedef struct node
{
  sv thongtinsv;
  struct node *next;
  struct node *prev;
}nd;


int main()
{
  nd *cur,*root,*head;
  cur=(nd*)malloc(sizeof(nd));
  root=(nd*)malloc(sizeof(nd));

  root->next=NULL; root->prev=NULL;
  cur=root;

  int n,a,i;
  printf("nhap so luong sv:\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      nd *new;
      new=(nd*)malloc(sizeof(nd));

      printf("nhap mssv:\n");
      scanf("%d",&(new->thongtinsv).mssv);
      printf("nhap ho ten sv:\n");
      while(getchar()!='\n');
      gets((new->thongtinsv).hoten);
      printf("nhap diem thi:\n");
      scanf("%f",&(new->thongtinsv).diemthi);

      new->next=cur->next;
      new->prev=cur;
      cur->next=new;
      cur=new;
    }

  cur=root;
  while(cur->next!=NULL)
    {
      cur=cur->next;
      printf("\n%-10d%-30s%5f\n",(cur->thongtinsv).mssv,(cur->thongtinsv).hoten,(cur->thongtinsv).diemthi);
    }

  int ham1(int n)
  {
    printf("menu:\n");
    printf("1.bo sung sv.\n");
    printf("2.tim sv.\n");
    printf("3.xoa mssv.\n");
    printf("4.hien thi danh sach.\n");
    printf("5.thoat chuong trinh.\n");
    printf("6.in ra file sinhven.dat.\n");
    printf("7.doc thong tin vao mang cau truc va sv dat diem lon hon 4,ty le.\n");
    scanf("%d",&a);
    switch(a)
      {
      case 1:
	{
	  nd *new;
	  new=(nd*)malloc(sizeof(nd));

          printf("nhap mssv:\n");
          scanf("%d",&(new->thongtinsv).mssv);
          printf("nhap ho ten sv:\n");
          while(getchar()!='\n');
          gets((new->thongtinsv).hoten);
          printf("nhap diem thi:\n");
          scanf("%f",&(new->thongtinsv).diemthi);

          
          // Bo sung sv vao cuoi danh sach!
          cur=root; 
          while (cur->next!=NULL) cur=cur->next;
          new->next=cur->next;
          new->prev=cur;
          cur->next=new;
          
	  break;
	}
      case 2:
	{
	  int mssvct,kt=1;
	  printf("nhap mssv can tim:\n");
	  scanf("%d",&mssvct);

	  cur=root;
	  while(cur->next!=NULL)
	    {
	      cur=cur->next;
	      if((cur->thongtinsv).mssv==mssvct)
		{
		  printf("\nthong tin sv:\n");
                  printf("mssv:%-10d\nho ten:%-30s\ndiem thi:%-5f\n\n",(cur->thongtinsv).mssv,(cur->thongtinsv).hoten,(cur->thongtinsv).diemthi);
		  kt=0;
		}
	    }
	  if(kt)
	    printf("khong tim thay sv nay.\n");
	  break;
	}
      case 3:
	{
	  int mssvcx,kt=1;
	  printf("nhap mssv can xoa:\n");
	  scanf("%d",&mssvcx);

	  cur=root;
	  
	  while (cur->next!=NULL)
	  {
	  	cur=cur->next;
	  	if ((cur->thongtinsv).mssv==mssvcx)
	  	{
		 	nd *cur2;
	  		cur2=(nd*)malloc(sizeof(nd));
	  		if (cur->next==NULL)
	  		{
	  			cur2=cur->prev;
	  			cur2->next=NULL;
	  		
	  		}else
	  		{
	  			cur2=cur->prev;
	  			cur2->next=cur->next;
	  		
	 	 		cur2=cur->prev;
	 	 		cur2->prev;cur->prev;
	 	 	}
	  		free(cur);
			printf("xoa thanh cong.\n");
			kt=0;
		  }
	  }
	  

	  if(kt)
	  printf("khong tim thay mssv.\n");
	  break;
	}
      case 4:
	{
          cur=root;
          while(cur->next!=NULL)
            {
        	  cur=cur->next;
          printf("\n%-10d%-30s%5f\n",(cur->thongtinsv).mssv,(cur->thongtinsv).hoten,(cur->thongtinsv).diemthi);
            }
	  break;
	}
      case 5:
	{
	  break;
	}
      case 6:
	{
	  FILE *fptr1;
	  char filename1[]="sinhvien.dat";
	  if((fptr1=fopen(filename1,"wb"))==NULL)
	    {
	      printf("khong the mo %s.\n",filename1);
	    }

	  	cur=root;
	    while (cur->next!=NULL)
		{
			cur=cur->next;
			int irc=fwrite(cur,sizeof(nd),1,fptr1);
		}
		
		fclose(fptr1);
		printf("Chep Thanh Cong\n");
	  break;
	}
      case 7:
      {
	  FILE *fptr1;
	  nd mang[80];
	  int j;
	  char filename1[]="sinhvien.dat";
	  if((fptr1=fopen(filename1,"rb"))==NULL)
	    {
	      printf("khong the mo %s.\n",filename1);
	    }

	  fread(mang,sizeof(nd),n,fptr1);
	  for(i=0;i<n;i++)
	    {
	      if(mang[i].thongtinsv.diemthi>=4)
		{
		  j++;
	          printf("\n%d\n",mang[i].thongtinsv.mssv);
	          printf("\n%s\n",mang[i].thongtinsv.hoten);
	          printf("\n%f\n",mang[i].thongtinsv.diemthi);
		}
	    }
	  printf("ty le sv thi dat:%d/%d\n",j,n);
	  fclose(fptr1);
	  break;
      }
	
      }
  }

  while(a!=5)
    {
      ham1(n);
      if((a!=1)&&(a!=2)&&(a!=3)&&(a!=4)&&(a!=5)&&(a!=6)&&(a!=7))
	{
	  printf("nhap lai.\n");
	}
    }

  free(root);
  free(cur);
  return 0;
}
