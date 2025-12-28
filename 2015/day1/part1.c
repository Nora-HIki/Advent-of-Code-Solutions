#include <stdio.h>
#include <stdlib.h>


int main(){

  FILE *pfile = fopen("input.txt","r");

  fseek(pfile,0,SEEK_END);
  int size=ftell(pfile);
  fseek(pfile,0,SEEK_SET);
  char buffer[size+1];

  fgets(buffer,sizeof(buffer),pfile);
  fclose(pfile);
  int floor=0;

  for (int i=0;i<sizeof(buffer);i++){
    if (buffer[i]=='('){
      floor++;
    }
    if (buffer[i]==')'){
      floor--;
    }
  }
  
  printf("%d\n",floor);
  return 0;
}
