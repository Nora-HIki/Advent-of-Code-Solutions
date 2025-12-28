#include <stdio.h>
#include <string.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[100];
  int count=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
  
    char inp1[100];
    char operation[10];
    char inp2[100];
    char out[100];
    sscanf(buffer,"%s %s %s -> %s",&inp1,&operation,&inp2,out);

    printf("%s  %s   %s             %s \n",inp1,operation,inp2,out);
    count++;
  }
  printf("%d",count);
  fclose(pfile);
  return 0;
}
