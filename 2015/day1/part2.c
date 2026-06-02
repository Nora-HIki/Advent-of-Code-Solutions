#include <stdio.h>


int main(){

  FILE *pfile = fopen("input.txt","r");


  char buffer[1000];

  fgets(buffer,sizeof(buffer),pfile);

  fclose(pfile);

  int floor=0;

  for(int i =0 ; i<sizeof(buffer);i++){
    if(buffer[i]=='('){
      floor++;
    }
    if(buffer[i]==')'){
      floor--;
    }

    if (floor<0){
      printf("%d\n",i+1);
      break;
    }
  }
  


  return 0;
}
