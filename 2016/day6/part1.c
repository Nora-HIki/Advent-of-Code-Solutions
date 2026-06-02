#include <stdio.h>
#include <string.h>

int main(){

  FILE *pfile=fopen("input.txt","r");
  char buffer[10];
  
  int occurencearray[8][123]={0};

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    for(int i=0;i<8;i++){
      int ascii=(int)buffer[i];
      occurencearray[i][ascii]++;
    }
  }

  fclose(pfile);
  
  for(int i=0;i<8;i++){
    int max=0;
    int maxindex=0;
    for(int j='a';j<='z';j++){
        if(occurencearray[i][j]>max){
          max=occurencearray[i][j];
          maxindex=j;
        }
    }
    printf("%c",maxindex);
  }
  
  printf("\n");
  return 0;
}
