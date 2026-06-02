#include <stdio.h>
#include <string.h>

int tmp=0;

void rect(int width,int height,int lights[6][50]){
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      lights[i][j]=1;
    }
  }
}

void hori(int which,int by,int lights[6][50]){
  for(int i=0;i<by;i++){
    tmp=lights[which][49];
    for(int j=49;j>=1;j--){
    lights[which][j]=lights[which][j-1];
    }
    lights[which][0]=tmp;
  }
}

void vert(int which,int by,int lights[6][50]){
  for(int i=0;i<by;i++){
    tmp=lights[5][which];
    for(int j=5;j>=1;j--){
    lights[j][which]=lights[j-1][which];
    }
    lights[0][which]=tmp;
  }
}

int main(){
  
  FILE *pfile=fopen("input.txt","r");
  char buffer[500]={'\0'};
  int lights[6][50]={0};
  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    if(buffer[1]=='e'){
    int width;
    int height;
    sscanf(buffer,"rect %dx%d",&width,&height);
    // printf("%d %d\n",width,height);
    rect(width,height,lights);
    }
    else if(buffer[1]=='o'){
      int which;
      int by;
      if(buffer[7]=='r'){
        sscanf(buffer,"rotate row y=%d by %d",&which,&by);
        // printf("%d %d\n",which,by);
        hori(which,by,lights);
      }
      else if(buffer[7]=='c'){ 
        sscanf(buffer,"rotate column x=%d by %d",&which,&by);
        // printf("%d %d\n",which,by);
        vert(which,by,lights);
      }
    }
  }
  fclose(pfile);
  for(int i=0;i<6;i++){
    for(int j=0;j<50;j++){
      if(lights[i][j]==1){
        printf("%d",lights[i][j]);
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
