	FILE *fptr1;
	char filename1[30];
	char a[30];
	makenull(&root);
	printf("nhap ten file can tim:");
	scanf("%s",filename1);
	if((fptr1=fopen(filename1,"r"))==NULL)
	{
	  printf("khong the mo %s.\n",filename1);
	  return 0;
	}
	while(!feof(fptr1))
	  {
	    if(fscanf(fptr1,"%s",a)>0)
	      {
		insert(a,&root);
	      }
	  }
	inoderprintf(root);
        fclose(fptr1);
