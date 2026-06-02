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
    int low=100;
    int lowindex=0;
    for(int j='a';j<='z';j++){
        if(occurencearray[i][j]<low){
          low=occurencearray[i][j];
          lowindex=j;
        }
    }
    printf("%c",lowindex);
  }
  
  printf("\n");
  return 0;
}
