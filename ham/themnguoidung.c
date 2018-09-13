/*tree root=NULL;
  tree cur;
  FILE *fptr1;
  cur=(node*)malloc(sizeof(node));
  char filename1[]="pass.txt";
  if((fptr1=fopen(filename1,"r+"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  while(!feof(fptr1))
    {
      if(fscanf(fptr1,"%s%s",cur->name,cur->password)>0)
	{
	  //printf("%s %s\n",cur->name,cur->password);
	  insert(cur->name,cur->password,&root);
	}
	}*/


	printf("nhap ten nguoi dung moi:");
	scanf("%s",cur->name);
	printf("nhap password:");
	scanf("%s",cur->password);
	insert(cur->name,cur->password,&root);
fseek(fptr1,0l,0); //dua con tro ve dau file
	inoderfprintf(root);
	fclose(fptr1);


//free(cur);
