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
