void DelMinNode(tree * root, int *ms)
       {
	if((*root)->left == NULL) {
		*ms = (*root)->maso;//
		node* tmp = *root;
		*root = (*root)->right;
		free(tmp);
		return;
	}
	DelMinNode(&(*root)->left, ms);
}
int delNode(tree * root, int ms){
	if(*root != NULL)
		if((*root)->maso < ms)
			return delNode(&(*root)->right, ms);
		else if((*root)->maso > ms)
			return delNode(&(*root)->left, ms);
		else{
			int k = (*root)->maso;
			if(((*root)->left == NULL) && ((*root)->right == NULL))
				{
					free(*root);
					*root = NULL;
				}
			else if((*root)->left == NULL){
				node* tmp = *root;
				*root = (*root)->right;
				free(tmp);
			}
			else if((*root)->right == NULL){
				node* tmp = *root;
				*root = (*root)->left;
				free(tmp);
			}
			else DelMinNode(&(*root)->right, &(*root)->maso);
			return k;
		}
	return -1;
}


