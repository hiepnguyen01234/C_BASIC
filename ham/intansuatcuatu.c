/*void insert(char n[],tree *root)
{
  if((*root)==NULL)
    {
      (*root)=(node*)malloc(sizeof(node));
      strcpy((*root)->data,n);
      (*root)->left=NULL;
      (*root)->right=NULL;
      (*root)->t=1;
    }
  else if(strcmp(n,(*root)->data)>0) return insert(n,&(*root)->right);
  else if(strcmp(n,(*root)->data)<0) return insert(n,&(*root)->left);
  else if(strcmp(n,(*root)->data)==0) ((*root)->t)++;
}
int search(char n[30],tree root)
{
  if(root==NULL) return 1;
  if(strcmp(n,root->data)==0) 
    {
      printf("%d\n",root->t);
      return 0;
    }
  else if(strcmp(n,root->data)>0) return search(n,root->right);
  else if(strcmp(n,root->data)<0) return search(n,root->left);
  }*/


	char a[30];
	printf("nhap tu can tim tan suat xuat hien:");
	scanf("%s",a);
	if(search(a,root)==1)
	  {
	    printf("0\n");
	  }
