#include <stdio.h>
#include <string.h>

int main(){
  
  FILE *pfile=fopen("input.txt","r");
  char buffer[11000]={'\0'};
  fgets(buffer,sizeof(buffer),pfile);
  fclose(pfile);
  // printf("%s",buffer);

  int size=0;
  int start=0;
  int end=0;
  int no=0;

  for(int i=0;i<strlen(buffer);i++){
    if(buffer[i]=='('){
      char compressed[100]={'\0'};
      start=i;
      for(int j=i+1;j<strlen(buffer);j++){
        compressed[no]=buffer[j];
        no++;
        if(buffer[j]==')'){
         end=j;
         int chars;
         int times;
         sscanf(compressed,"%dx%d",&chars,&times);
         // printf("%d into %d\n",chars,times);
         no=0;
         for(int k=0;k<100;k++){
           compressed[k]='\0';
         }
         size+=chars*times;
         i+=end-start+chars;
         // size--;
         break;
        }
      }
    }
    // size++;    
  }
  printf("%d\n",size);
  return 0;
}
