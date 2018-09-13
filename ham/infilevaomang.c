        //node mang[100];
	//int irc;
	//sp *a;
	FILE *fptr2;
        int i=0;
	char filename2[]="sanpham.txt";
	if((fptr2=fopen(filename2,"r"))==NULL)
	  {
	    printf("khong the mo %s",filename2);
	    return 0;
	  }
	while(!feof(fptr2))
	  {
	    if(fscanf(fptr2,"%d",&mang[i].maso)>0)
	      {
		fgets(mang[i].dochoi,100,fptr2);
		if(mang[i].dochoi[strlen(mang[i].dochoi)-1]=='\n')
		  mang[i].dochoi[strlen(mang[i].dochoi)-1]=0;
		printf("%d %s\n",mang[i].maso,mang[i].dochoi);
                i++;
	      }
	    else break;
	  }
	fclose(fptr2);

	 /*   if(fscanf(fptr2,"%d",&mang[i].maso)>0)
	      {
		if(fgetc(fptr2)=='\n')
		  {
		    printf("nhap do choi cua ma so %d:",mang[i].maso);
		    scanf("%s",mang[i].dochoi);
		  }*/
