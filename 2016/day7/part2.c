#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

  FILE *pfile=fopen("input.txt","r");
  char buffer[1000]={'\0'};

  int validip=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    int start[100]={0};
    int end[100]={0};
    int startno=0;
    int endno=0;
    int no=0;

    for(int i=0;i<strlen(buffer);i++){ 
      if(buffer[i]=='['){
        start[startno]=i;
        startno++;
      }
      else if(buffer[i]==']'){
        end[endno]=i;
        endno++;
      }
    }
    
    char pattern[100][3]={'\0'};
    int patterno=0;
    for (int i=2;i<strlen(buffer);i++){
      if(start[no]==i){
        i+=end[no]-start[no]+2;
        no++;
      }
      if(buffer[i]==buffer[i-2]
        && buffer[i-2]!=buffer[i-1]
        && buffer[i]!=buffer[i-1]){
        pattern[patterno][0]=buffer[i];
        pattern[patterno][1]=buffer[i-1];
        pattern[patterno][2]=buffer[i-2];
        patterno++;
      }
    }

    printf("\n");
    int found=0;
    for(int i=0;i<patterno;i++){
      if(found==0){
      for(int j=0;j<startno;j++){
        if(end[j]-start[j]>=3){
          for(int k=start[j]+2;k<=end[j];k++){
            if(buffer[k]==pattern[i][1]
              && buffer[k-1]==pattern[i][0]
              && buffer[k-2]==pattern[i][1]){
              validip++;
              found=1;
              break;
            }
          }
        }
      }
      }
    }

  }

  printf("%d\n",validip);
  fclose(pfile);
  return 0;
}
