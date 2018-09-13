typedef struct node
{
  char name[31];
  int data;
  struct node *left,*right;
}node;
typedef node *tree;


void makenull(tree *root)
{
  *root=NULL;
}
int empty(tree root)
{
  return root==NULL;
}
void insert(char ten[],int data,tree *root)
{
  if((*root)==NULL)
    {
      (*root)=(node*)malloc(sizeof(node));
      strcpy((*root)->name,ten);
      (*root)->data=data;
      (*root)->right=NULL;
      (*root)->left=NULL;
    }
  else if(strcmp(ten,(*root)->name) > 0) return insert(ten,data,&(*root)->right);
  else if(strcmp(ten,(*root)->name) < 0) return insert(ten,data,&(*root)->left);
}


int search(char ten[],tree root)
{
  if(root==NULL) return 1;
  if(strcmp(ten,root->name)==0)
    {
      printf("ten nguoi dung can tim:%s\n",root->name);
      printf("data:%s\n",root->data);
      return 0;
    }
  else if(strcmp(ten,root->name) > 0) return search(ten,root->right);
  else if(strcmp(ten,root->name) < 0) return search(ten,root->left);
}


void inoderprintf(tree root)
{
  if(root!=NULL)
    {
      inoderprintf(root->left);
      printf("%s  %s\n",root->name,root->data);
      inoderprintf(root->right);
    }
}


int inoderfprintf(tree root)
{
  FILE *fptr1;
  char filename1[]="A.txt";
  if((fptr1=fopen(filename1,"w"))==NULL)
    {
      printf("khong the mo %s.\n",filename1);
      return 0;
    }
  void inoder(tree root)
  {
    if(root!=NULL)
      {
	inoder(root->left);
	fprintf(fptr1,"%s  %s\n",root->name,root->password);
	inoder(root->right);
      }
  }
  inoder(root);
  fclose(fptr1);
}
