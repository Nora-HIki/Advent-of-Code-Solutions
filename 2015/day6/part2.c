#include <stdio.h>
#include <string.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[100];
  int field[1000][1000];
   for (int i=0;i<1000;i++){
    for (int j=0;j<1000;j++){
      field[i][j]=0;
    }
  }


  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){

    char instruction[50];
    int startx=0;
    int starty=0;
    int endx=0;
    int endy=0;

    int input_fine=0;
    if (buffer[1]=='o'){
    if (sscanf(buffer,"%s %d,%d through %d,%d",&instruction,&startx,&starty,&endx,&endy)==5){
      input_fine++;
    }}
    else if (buffer[1]=='u'){
    if (sscanf(buffer,"turn %s %d,%d through %d,%d",&instruction,&startx,&starty,&endx,&endy)==5){
      input_fine++;
    }}
      
    if (input_fine==1){
    
    instruction[strlen(instruction)]='\0';

    if (strcmp(instruction,"on")==0){
        for(int i=startx;i<=endx;i++){
          for (int j=starty;j<=endy;j++){
            field[i][j]+=1;
          }
        }
      }


    if (strcmp(instruction,"off")==0){
        for(int i=startx;i<=endx;i++){
          for (int j=starty;j<=endy;j++){
            field[i][j]-=1;
            if (field[i][j]<0){
              field[i][j]=0;
            }
          }
        }
      }


    if (strcmp(instruction,"toggle")==0){
        for(int i=startx;i<=endx;i++){
          for (int j=starty;j<=endy;j++){
              field[i][j]+=2;
          }
        }
      }
    }
  }

  int sum=0;
  for (int i=0;i<1000;i++){
    for (int j=0;j<1000;j++){
      sum+=field[i][j];
    }
  }

  printf("%d\n",sum);
  fclose(pfile);
  return 0;
}
