#include <stdio.h>
#include <string.h>

struct tu{
char ten[30];
int solan;
int dong[30];
};

int main()
{
    FILE *fp;
   char buff[255];
   char test[255];
   struct tu mang[100];
   char c;
   int i=0;

   fp = fopen("vidu1.txt", "r");

   /*
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );*/

   while(!feof(fp)){

   //c= fgetc(fp);
   //if(c!="NULL")
   //{
    fscanf(fp, "%s", buff);
    while((buff != ' ') || (buff != '\n')){
        fscanf(fp, "%s", buff);
    }
    strcpy(test,buff);


    int j;
    //mang[i].solan = 1;
    for(j=0;j<=i;j++){
        int thamso = strcmp(mang[j].ten,test);
        if(thamso == 0 )
        {
            mang[j].solan ++;
        }

        else{
            strcpy(mang[i].ten,test);
        }
    }
    //printf("%s\n", buff);
    i++;
   //}
   //printf("4: %c\n", c);
}
   fclose(fp);

   printf("tu              so lan\n\n");
   do{
       printf("%s              %d \n",mang[i].ten,mang[i].solan);
       i--;
   }
   while(i>=0);

}
