#include <stdio.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[100];

  int mainsum=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    
    int l=0;
    int b=0;
    int h=0;
    int area=0;

    if (sscanf(buffer,"%dx%dx%d",&l,&b,&h)==3){


    if (l>=b && l>=h){
    area=2*l*b+2*b*h+2*l*h + b*h;
    }
    else if (h>=b && h>=l){
    area=2*l*b+2*b*h+2*l*h + l*b;
    }
    else   if (b>=l && b>=h){
    area=2*l*b+2*b*h+2*l*h + h*l;
    } 

    mainsum+=area;



    }}
  fclose(pfile);
  printf("%d\n",mainsum);
  return 0;
}
