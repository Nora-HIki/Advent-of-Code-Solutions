#include <stdio.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[100];

  int mainlength=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    
    int l=0;
    int b=0;
    int h=0;
    int length=0;

    if (sscanf(buffer,"%dx%dx%d",&l,&b,&h)==3){


    if (l*b <= b*h && l*b <= l*h){
    length= 2*(l+b) + l*b*h;
    }
    else if (l*h <= b*h && l*h <= l*b){
    length= 2*(l+h) + l*b*h;
    }
    else if (h*b <= l*h && h*b <= l*h){
    length= 2*(h+b) + l*b*h;
    } 

    mainlength+=length;



    }}
  fclose(pfile);
  printf("%d\n",mainlength);
  return 0;
}
