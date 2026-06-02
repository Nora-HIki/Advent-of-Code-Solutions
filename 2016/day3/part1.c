#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *pfile = fopen("input.txt","r");
  char buffer[1000];

  int sides[3]={0};
  int possible=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
  
    if (sscanf(buffer, "%d %d %d",&sides[0],&sides[1],&sides[2])==3){
     if(sides[0]+sides[1]>sides[2]
        && sides[1]+sides[2]>sides[0]
        && sides[0]+sides[2]>sides[1]){
      possible++;
     }     
    }
  }  
  

  printf("%d\n",possible);
  fclose(pfile);
  return 0;
}
