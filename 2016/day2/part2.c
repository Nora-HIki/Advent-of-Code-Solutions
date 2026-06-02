#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *pfile = fopen("input.txt","r");
  char buffer[1000];

  char keypad[5][5]={
    {'0','0','1','0','0'},
    {'0','2','3','4','0'},
    {'5','6','7','8','9'},
    {'0','A','B','C','0'},
    {'0','0','D','0','0'},
  };

  int x=0;
  int y=2;
  char currpos=keypad[y][x];
  char code[1000]={'\0'};
  int codelength=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    
    for(int i=0;i<strlen(buffer);i++){
      switch (buffer[i]){
        case 'U':
          if(y-1>=0 && keypad[y-1][x]!='0'){
            y--;
          }
          break;
        case 'D':
          if(y+1<=4 && keypad[y+1][x]!='0'){
            y++;
          }
          break;
        case 'L':
          if(x-1>=0 && keypad[y][x-1]!='0'){
            x--;
          }
          break;
        case 'R':
          if(x+1<=4 && keypad[y][x+1]!='0'){
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
    printf("%c",code[i]);
  } 
  printf("\n");

  
  fclose(pfile);
  return 0;
}
