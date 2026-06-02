#include <stdio.h>
#include <string.h>


int main(){

  FILE *pfile=fopen("input.txt","r");
  char buffer[1000]={'\0'};
  int validip=0;
  
  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    
    char parts[100][1000]={'\0'};
    int currpart=0;
    int no=0;
    int out=0;
    int in=0;

    for(int i=0;i<strlen(buffer);i++){
       if(buffer[i]=='[' || buffer[i]==']'){
         no=0;
         currpart++;
         i++;
       }
       parts[currpart][no]=buffer[i];
       no++;
    }
    
    for(int p=0;p<currpart+1;p++){
    if(p%2==0){
    for(int i=3;i<strlen(parts[p]);i++){
      if(parts[p][i]==parts[p][i-3] && parts[p][i-1]==parts[p][i-2] && parts[p][i-1]!=parts[p][i] && parts[p][i-2]!=parts[p][i-3]){
          out=1;
      }
    }
    }
    else if(p%2!=0){
    for(int i=3;i<strlen(parts[1]);i++){
      if(parts[p][i]==parts[p][i-3] && parts[p][i-1]==parts[p][i-2] && parts[p][i-1]!=parts[p][i] && parts[p][i-2]!=parts[p][i-3]){
          in=1;
      }
    }
    }
    }
    
    if(out==1 && in==0){
      validip++;
    }

    // printf("%s %s %s",parts[0],parts[1],parts[2]);
  }
  printf("%d\n",validip);
  fclose(pfile);
  return 0;
}
