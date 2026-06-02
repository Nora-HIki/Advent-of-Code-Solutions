#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *pfile = fopen("input.txt","r");

  char buffer[1000];

  fgets(buffer,sizeof(buffer),pfile);
  fclose(pfile);

  char* token = strtok(buffer,",");
  int xpos[100000]={0};
  int ypos[100000]={0};
  xpos[0]=0;
  ypos[0]=0;
  char facing='N';

  int no=1;
  while (token != NULL) {
        char dir;
        int mov;
        sscanf(token,"%c%d",&dir,&mov);
        //printf("\n%c %d",dir,mov);
        if(dir=='R'&&facing=='N'){
          facing='E';
          for(int i=0;i<mov;i++){
          xpos[no]=xpos[no-1]+1;
          ypos[no]=ypos[no-1];
          no++;
          }
        }
        else if(dir=='L'&&facing=='N'){
          facing='W';
          for(int i=0;i<mov;i++){
          xpos[no]=xpos[no-1]-1;
          ypos[no]=ypos[no-1];
          no++;
          }
        }
        else if(dir=='R'&&facing=='E'){
          facing='S';
          for(int i=0;i<mov;i++){
          ypos[no]=ypos[no-1]-1;
          xpos[no]=xpos[no-1];
          no++;
          }
        }
        else if(dir=='L'&&facing=='E'){
          facing='N';
          for(int i=0;i<mov;i++){
          ypos[no]=ypos[no-1]+1;
          xpos[no]=xpos[no-1];
          no++;
          }
        }
        else if(dir=='R'&&facing=='W'){
          facing='N';
          for(int i=0;i<mov;i++){
          ypos[no]=ypos[no-1]+1;
          xpos[no]=xpos[no-1];
          no++;
          }
        }
        else if(dir=='L'&&facing=='W'){
          facing='S';
          for(int i=0;i<mov;i++){
          ypos[no]=ypos[no-1]-1;
          xpos[no]=xpos[no-1];
          no++;
          }
        }
        else if(dir=='R'&&facing=='S'){
          facing='W';
          for(int i=0;i<mov;i++){
          xpos[no]=xpos[no-1]-1;
          ypos[no]=ypos[no-1];
          no++;
          }
        }
        else if(dir=='L'&&facing=='S'){
          facing='E';
          for(int i=0;i<mov;i++){
          xpos[no]=xpos[no-1]+1;
          ypos[no]=ypos[no-1];
          no++;
          }
        }
        //printf("%c %d %d\n",facing,xpos[no],ypos[no]);
        token = strtok(NULL, " ,");
  }

  int found=0;
  for (int i=0;i<no;i++) {
    for (int j=0;j<no;j++) {
       if (j!=i && xpos[i]==xpos[j] && ypos[i]==ypos[j] && found==0){
         printf("duplicate found at %d %d",xpos[i],ypos[i]);
         printf(" dist %d\n",abs(xpos[i])+abs(ypos[i]));
         found=1;
       }
    }
  }
  
  
  return 0;
}
