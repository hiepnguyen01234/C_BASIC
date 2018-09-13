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
}nd;


int main()
{
 	int i,n,a;
	nd *cur,*root;
	cur=(nd*)malloc(sizeof(nd));
	root=(nd*)malloc(sizeof(nd));


	root->next=NULL;
	cur=root;


	int ham1(int n)
	{
		int i;
		for(i=0;i<n;i++)
  		{
			nd *new;
			new=(nd*)malloc(sizeof(nd));

			printf("nhap mssv:\n");
			scanf("%d",&(new->thongtinsv).mssv);

			printf("nhap diem thi:\n");
			scanf("%f",&(new->thongtinsv).diemthi);

			while(getchar()!='\n');
			printf("nhap ho ten sinh vien:\n");
			gets((new->thongtinsv).hoten);

			new->next=NULL;
			cur->next=new;
			cur=new;
		}
	}

	printf("nhap sl sinh vien:\n");
	scanf("%d",&n);

	 if((n<=0)||(n>=11))
  	 {
    	 for(i=0;((n<=0)||(n>=11));i++)
     	  {
    		printf("nhap lai.\n");
   			printf("nhap sl sinh vien:\n");
     		scanf("%d",&n);
     		continue;
     		ham1(n);
       	  }
     }
     

 	if((n>=1)&&(n<=10))
  	{

 		 ham1(n);
   	}
 

	cur=root;
  	while(cur->next!=NULL)
    {
      cur=cur->next;
      printf("\n%d      %s      %f\n",(cur->thongtinsv).mssv,(cur->thongtinsv).hoten,(cur->thongtinsv).diemthi);

    }

 	while(a!=5)
    {
  		printf("menu:\n");
  		printf("1.nhap thong tin sv moi.\n");
  		printf("2.nhap mssv can tim.\n");
  		printf("3.nhap mssv can xoa.\n");
  		printf("4.hien thi tat ca thong tin sv.\n");
  		printf("5.thoat chuong trinh.\n");
  		printf("6.ghi vao file sinhvien.dat.\n");
  		printf("7.hien thi sv co diem thi lon hon 4 va ty le.\n");


  		scanf("%d",&a);
  		switch(a)
   		 {
   			case 1:
    		{
				nd *new;
				new=(nd*)malloc(sizeof(nd)); //nguyen ban tai sao lai la sizeof(nd*)?


				printf("nhap mssv:\n");
				scanf("%d",&(new->thongtinsv).mssv);

				printf("nhap diem thi:\n");
				scanf("%f",&(new->thongtinsv).diemthi);

				while(getchar()!='\n');
				printf("nhap ho ten sinh vien:\n");
				gets((new->thongtinsv).hoten);

				//Chu y cho nay
				
				new->next=root->next;
				root->next=new;
   				break;
   			}
   			
  			case 2:
     		{
				// CHu y cho nay
				
				int mssvcantim,kt=1;
				printf("nhap mssv can tim:\n");
				scanf("%d",&mssvcantim);

				cur=root;
				while(cur->next!=NULL)
				{
					cur=cur->next;
					if((cur->thongtinsv).mssv==mssvcantim)
	    			{
						printf("\n%d     %s     %f\n",(cur->thongtinsv).mssv,(cur->thongtinsv).hoten,(cur->thongtinsv).diemthi);
	      				kt=0; break;
		  			}
	    		}
	    		
	    		if (kt) printf("KHong tim thay\n\n");
	    		break;
	 		 }

	
  			case 3:
     		{
				nd *new;
				int mssvcanxoa,kt=1;
				printf("nhap mssv can xoa:\n");
				scanf("%d",&mssvcanxoa);

				nd* cur,*cur2;
				cur=(nd*)malloc(sizeof(nd));
				cur2=(nd*)malloc(sizeof(nd));
				cur=root;
				while (cur->next!=NULL)
				{
					cur2=cur;
					cur=cur->next;
					if(mssvcanxoa==(cur->thongtinsv).mssv)
					{
						cur2->next=cur->next;
			
						printf("Xoa thanh cong\n");
						kt=0; break;
					}
				}
				
				
				if (kt) printf("Xoa that bai\n\n");
				break;
   			}
    case 4:
      {
  cur=root;
  while(cur->next!=NULL)
    {
      cur=cur->next;
      printf("\n%d     %s     %f\n",(cur->thongtinsv).mssv,(cur->thongtinsv).hoten,(cur->thongtinsv).diemthi);

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
			fwrite(cur,sizeof(nd),1,fptr1);
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

      if((a!=1)&&(a!=2)&&(a!=3)&&(a!=4)&&(a!=5)&&(a!=6)&&(a!=7))
	printf("nhap lai.\n");

    }
    }

  	return 0;
}
