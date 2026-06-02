#include <stdio.h>
#include <string.h>

int finalsize=0;

int decompressing(char buffer[11000]){
  int size=0;
  int start=0;
  int end=0;
  int no=0;

  for(int i=0;i<strlen(buffer);i++){
    if(buffer[i]=='('){
      char compressed[100]={'\0'};
      char internal[11000]={'\0'};
      start=i;
      for(int j=i+1;j<strlen(buffer);j++){
        compressed[no]=buffer[j];
        no++;
        if(buffer[j]==')'){
         end=j;
         int chars;
         int times;
         sscanf(compressed,"%dx%d",&chars,&times);
         for(int p=0;p<chars;p++){
            internal[p]=buffer[j+p+1];
         }
         int newdecomp=decompressing(internal);
         chars+=newdecomp;
         for(int p=0;p<11000;p++){
            internal[p]='\0';
         }
         // printf("%d into %d\n",chars,times);
         no=0;
         for(int k=0;k<100;k++){
           compressed[k]='\0';
         }
         size+=chars*times;
         i+=end-start+chars;
         break;
        }
      }
    }
    else if(buffer[i]!='('){
      size++;
    }
  }
  finalsize+=size;
  return size;
}

int main(){
  
  FILE *pfile=fopen("input.txt","r");
  char buffer[11000]={'\0'};
  fgets(buffer,sizeof(buffer),pfile);
  fclose(pfile);
  // printf("%s",buffer);
  decompressing(buffer);
  printf("%d\n",finalsize);
  return 0;
}
