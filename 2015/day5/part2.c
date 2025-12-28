#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[100];
  int nice=0;
  

while(fgets(buffer,sizeof(buffer),pfile)!=NULL){

  bool rule1=false;
  bool rule2=false;
  char pairs[100][2];
  int  pos_pairs[100][2];
  int count=0;

  for(int i=2;i<strlen(buffer);i++){
    if (buffer[i]==buffer[i-2]){
          rule2=true;
      }    
  }

  for(int i=1 ; i<strlen(buffer); i++){
      pairs[count][0]=buffer[i-1];
      pairs[count][1]=buffer[i];
      pos_pairs[count][0]=i-1;
      pos_pairs[count][1]=i;
      count++;
  }

  for (int i=0;i<count;i++){
  
  for (int j=0;j<count;j++){
  
  if ( j!=i && pairs[i][0]==pairs[j][0] && pairs[i][1]==pairs[j][1]){

  if (pos_pairs[j][0]!=pos_pairs[i][1] && pos_pairs[j][1]!=pos_pairs[i][0]){
      rule1=true;
      break;
    }
  else {
    continue;
  }
  }
  continue;
  }
  
  //printf("%c%c\n",pairs[count][0],pairs[count][1]);
  }


     
  if (rule2==true && rule1==true){
      nice++;
      //printf("%s",buffer);
  }

}
  
  fclose(pfile);
  printf("%d\n",nice);
  return 0;
}
