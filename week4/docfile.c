/*
1.%10d: in truoc tu 10 khoang,%-10d: in sau tu
2.strcpy(tudich,tunguon); 
   -can gan tu[i]='\0' de ket thuc xau.
3.scanf("%d",&a);  de nhap lieu can &
4.fwrite(mangnguon,sizeof(nd),1,controfile);  :ghi vao file 1 phan tu kich co nd
  -fread(ghivaomang,sizeof(nd),n,controfile):  :ghi vao mang luon n phan tu
5.nd*cur;
  cur=(nd*)malloc(sizeof(nd));  :cung cap bo nho cho linklist
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//kiem tra ky tu
#include <string.h>//xu ly xau

typedef struct tutinh{
  char name[50];
  int solan;
  int sodong[50];
}tt;
typedef struct node{
  tt thongtin;
  struct node *next;
  struct node *prev;
}nd;



int main(){
  
  nd *cur,*root;
  cur=(nd*)malloc(sizeof(nd));
  root=(nd*)malloc(sizeof(nd));
  root->next=NULL;
  root->prev=NULL;
  cur=root;

  void display(){
    int sl;    
    cur=root;
    while(cur->next!=NULL){
      cur=cur->next;
      printf("\n%-10s%d",(cur->thongtin).name,(cur->thongtin).solan);
      for(sl=0;sl<(cur->thongtin).solan;sl++){
	printf(",%d",(cur->thongtin).sodong[sl]);
      }
      printf("\n");
    }
  }


  FILE *fptr1;
  char tu[100],tu1[100];
  int i=0,sd=1,kt=0,sotu=0;
  char c,b;
  
  if((fptr1=fopen("vidu.txt","r"))==NULL){
    printf("khong the doc file.\n");
  }

  while(!feof(fptr1)){
    nd *new,*cur2;
    new=(nd*)malloc(sizeof(nd));
    cur2=(nd*)malloc(sizeof(nd));
    
    c=fgetc(fptr1);
    
    if(c=='\n'){
      sd++;
    }
    
    if(c!=' ' && c!='\n' && c!=',' && c!='.' && c!='!' && c!='?'){
      if(c>='A' && c<='Z'){
	c=c+32;
      }
      tu[i]=c;
      i++;
      kt=1;
      continue;
    }
    if(kt){
      cur2=root;
      strncpy(tu1,tu,i);
      tu1[i]='\0';
      while(cur2->next!=NULL){
	cur2=cur2->next;
	if(strcmp((cur2->thongtin).name,tu1)==0){
	  (cur2->thongtin).solan++;
	  (cur2->thongtin).sodong[(cur2->thongtin).solan-1]=sd;
	  strcpy(tu,"");
	  kt=0;
	  i=0;
	  break;
	}
      }
      strcpy(tu1,"");
    }
    if(kt){
      tu[i]='\0';  //luon can;
      //printf("%s\n",tu);
      //strcpy((new->thongtin).name,tu);  //can them:tu[i]='\0';
      strncpy((new->thongtin).name,tu,i); //dung i (con i-1 bi loi);
      (new->thongtin).solan=1;
      (new->thongtin).sodong[0]=sd;
      new->next=cur->next;
      new->prev=cur;
      cur->next=new;
      cur=new;
      //printf("%d\n ",sd);
      //printf("%s\n",(cur->thongtin).name);
      strcpy(tu,"");
      sotu++;
      i=0;
      kt=0;
   
      }
  }
  fclose(fptr1);

  display();
  printf("so luong tu: %d\n",sotu);
  /*cur=root;
  while(cur->next!=NULL){
    cur=cur->next;
    printf("%s\n",(cur->thongtin).name);
    }*/

  FILE *fptr2;
  if((fptr2=fopen("outfile.txt","w+"))==NULL){
    printf("khong the ghi file.\n");
  }
  cur=root;
  while(cur->next!=NULL){
    cur=cur->next;
    fprintf(fptr2,"%-10s",(cur->thongtin).name);
    fprintf(fptr2,"%d",(cur->thongtin).solan);
    for(i=0;i<(cur->thongtin).solan;i++){
      fprintf(fptr2,",%d",(cur->thongtin).sodong[i]);
    }
    fputs("\n",fptr2);
  }
  fclose(fptr2);
  

  free(cur);
  free(root);
  return 0;
}
