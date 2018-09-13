/*typedef struct sanpham
{
  int masp;
  char tensp[31];
  char motasp[50];
  int giasp;
  int slsp;
  struct sanpham *next;
}sp;

sp mang[50];
int sft;*/


	int j;
	FILE *fptr1;
	char filename1[]="sanpham.txt";
	sp *cur,*root = NULL;
	/*
        cur=(sp*)malloc(sizeof(sp));
	root=(sp*)malloc(sizeof(sp));
	root->next=NULL;
	*/
	cur=root;
	if((fptr1=fopen(filename1,"w"))==NULL)
	  {
	    printf("khong the mo %s\n",filename1);
	    return 0;
	  }
	for(j=0;;j++)
	  {
            sp *new;	    
	    new=(sp*)malloc(sizeof(sp));
	    new->masp=0;
	    printf("nhap ma sp:");
	    char meo[30];
	    scanf("%s",meo);
	    new->masp=atoi(meo);
	    //scanf("%d",&new->masp);
	    if((new->masp==0) &&(strcmp(meo,"0")) )
	      {
		free(new);
		break;
	      }
	    while(getchar()!='\n');
	    printf("nhap tensp:");
	    gets(new->tensp);
	    printf("nhap motasp:");
	    gets(new->motasp);
	    printf("nhap gia sp:");
	    scanf("%d",&new->giasp);
	    printf("nhap sl sp:");
	    scanf("%d",&new->slsp);
	    new->next=NULL;
	    if(root==NULL) root=new;
	    else cur->next=new;
	    cur=new;
	  }
	cur=root;
	while(cur!=NULL)
	  {
	    fprintf(fptr1,"%d  %s  %s  %d  %d\n",cur->masp,cur->tensp,cur->motasp,cur->giasp,cur->slsp);
	    printf("%d  %s  %s  %d  %d\n",cur->masp,cur->tensp,cur->motasp,cur->giasp,cur->slsp);
            cur=cur->next;
	  }
	/*cur=root;
	root=root->next;
	free(cur);*/
	fclose(fptr1);
