/*char tu[100];
typedef struct tudien
{
  char ta[30];
  char tv[30];
  struct tudien *left,*right;
}td;
typedef td *tree;

int searchtu(char ta[31],tree root)
{
  if(root==NULL) return 1;
  if(strcmp(ta,root->ta)==0)
    {
      strcat(tu,root->tv);
      strcat(tu," ");
      return 0;
    }
  else if(strcmp(ta,root->ta) > 0) return searchtu(ta,root->right);
  else if(strcmp(ta,root->ta) < 0) return searchtu(ta,root->left);
  }*/


char dichtu(char n[30],tree root)
{
  FILE *fptr1;
  char filename1[]="tudien.txt";
  char *ctr;
  td a[30];
  int i=0,j;

  if((fptr1=fopen(filename1,"ab"))==NULL) //vua doc vua ghi
    {
      printf("khong the mo %s\n",filename1);
      return ;
    }
  if(root==NULL) return 0;
  ctr=strtok(n," ");         //ham cat xau n[]
  while(ctr!=NULL)
    {
      strcpy(a[i].ta,ctr);
      i++;
      j=i;
      ctr=strtok(NULL," ");
    }
    
  for(i=0;i<j;i++)
    {
      if(searchtu(a[i].ta,root)==1)
	{
	  printf("khong co trong tu dien,nhap nghia cua tu %s:",a[i].ta);
	  scanf("%s",a[i].tv);
	  strcat(tu,a[i].tv);
	  strcat(tu," ");
	  fprintf(fptr1,"%s %s\n",a[i].ta,a[i].tv);
	  insert(a[i].ta,a[i].tv,&root);
	}
    }
    printf("nghia tieng viet cua cau :");
    printf("%s\n",tu);
    for(i=0;tu[i]!=NULL;i++)
      {
	tu[i]=NULL;
      }
    printf("\n");
    fclose(fptr1);
}
