#include <stdio.h>
#include <string.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[500];

  int finalsum=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){

    int prog_len=strlen(buffer)-1;
    int str_len=0;   
    if (strlen(buffer)-1>0){ 
    for (int i=0;i<strlen(buffer)-1;i++){
      if (buffer[i]=='\\'){
        str_len+=2;
      }
      else if (buffer[i]=='\"'){
        str_len+=2;
      }
      else {
        str_len++;
      }
    }

    str_len+=2;

    //printf("pro:%d str:%d buf:%s",prog_len,str_len,buffer);
    finalsum+=str_len-prog_len;
  }
  }
  printf("%d\n",finalsum);
  fclose(pfile);
  return 0;
}
