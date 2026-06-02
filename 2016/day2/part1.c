#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *pfile = fopen("input.txt","r");
  char buffer[1000];

  int keypad[3][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  int x=1;
  int y=1;
  int currpos=keypad[y][x];
  int code[1000]={0};
  int codelength=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    
    for(int i=0;i<strlen(buffer);i++){
      switch (buffer[i]){
        case 'U':
          if(y-1>=0){
            y--;
          }
          break;
        case 'D':
          if(y+1<=2){
            y++;
          }
          break;
        case 'L':
          if(x-1>=0){
            x--;
          }
          break;
        case 'R':
          if(x+1<=2){
            x++;
          }
          break;
      }
    }
    currpos=keypad[y][x];
    code[codelength]=currpos;
    codelength++;
  }  

  for(int i=0;i<codelength;i++){
    printf("%d",code[i]);
  }
  printf("\n");

  
  fclose(pfile);
  return 0;
}
