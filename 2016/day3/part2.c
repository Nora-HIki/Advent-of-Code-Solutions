#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  FILE *pfile = fopen("input.txt","r");
  char buffer[1000];

  int sides[3][3]={
    {0,0,0}, // T1
    {0,0,0}, // T2
    {0,0,0} // T3
  };

  int possible=0;
  int sideno=0; // first side

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    if (sscanf(buffer,"%d %d %d",&sides[0][sideno],&sides[1][sideno],&sides[2][sideno])==3){
      sideno++;
      if (sideno==3){
        sideno=0;
        for (int i=0;i<3;i++){
          if(sides[i][0]+sides[i][1]>sides[i][2]
            && sides[i][1]+sides[i][2]>sides[i][0]
            && sides[i][0]+sides[i][2]>sides[i][1]){
          possible++;
        }
      }
     }     
    }
  }  
  

  printf("%d\n",possible);
  fclose(pfile);
  return 0;
}
