//node tang[100];

void inoderprintf2(tree root)
{
  if(root!=NULL)
    {
      inoderprintf2(root->left);
      strcpy(tang[j++].dochoi,root->dochoi);
      inoderprintf2(root->right);
    }
}
void thongke(node tang[])
{
  int i,a,b;
  for(i=0;i<j;i++)
    {
      tang[i].maso=1;
      for(a=i+1;a<j;a++)
	{
	  if(strcmp(tang[i].dochoi,tang[a].dochoi)==0)
	    {
	      tang[i].maso++;
	      for(b=a;b<j;b++)
		{
		  tang[b]=tang[b+1];
		}
	      j--;
	    }
	}
    }
}
