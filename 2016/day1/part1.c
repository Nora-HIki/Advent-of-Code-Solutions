#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *pfile = fopen("input.txt","r");

  char buffer[1000];

  fgets(buffer,sizeof(buffer),pfile);
  fclose(pfile);

  char* token = strtok(buffer,",");
  int xpos=0;
  int ypos=0;
  char facing='N';

  while (token != NULL) {
        char dir;
        int mov;
        sscanf(token,"%c%d",&dir,&mov);
        printf("\n%c %d",dir,mov);
        if(dir=='R'&&facing=='N'){
          facing='E';
          xpos+=mov;
        }
        else if(dir=='L'&&facing=='N'){
          facing='W';
          xpos-=mov;
        }
        else if(dir=='R'&&facing=='E'){
          facing='S';
          ypos-=mov;
        }
        else if(dir=='L'&&facing=='E'){
          facing='N';
          ypos+=mov;
        }
        else if(dir=='R'&&facing=='W'){
          facing='N';
          ypos+=mov;
        }
        else if(dir=='L'&&facing=='W'){
          facing='S';
          ypos-=mov;
        }
        else if(dir=='R'&&facing=='S'){
          facing='W';
          xpos-=mov;
        }
        else if(dir=='L'&&facing=='S'){
          facing='E';
          xpos+=mov;
        }
        printf("%c %d %d\n",facing,xpos,ypos);
        token = strtok(NULL, " ,");
  }
  
  if (xpos<0){
    xpos=-1*xpos;
  }
  if (ypos<0){
    ypos=-1*ypos;
  }
  printf("%d",xpos+ypos);

  return 0;
}
