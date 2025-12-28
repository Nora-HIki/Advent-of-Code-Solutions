#include <stdio.h>
#include <string.h>

int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[1000];

  int finalsum=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){

    if (strlen(buffer)-1>0){

    int prog_len=strlen(buffer)-1;
    int str_len=0;   

      for(int i=1;i<strlen(buffer)-2;i++){
      if (buffer[i]=='\\'){
        if(buffer[i+1]=='\\'){
          //printf("%c%c\n",buffer[i],buffer[i+1]);
          str_len++;
          i++;
        }
          else if (buffer[i+1]=='\"' && i!=strlen(buffer)-3){
          str_len++;
          //printf("%c%c %d %d\n",buffer[i],buffer[i+1],i,strlen(buffer));
          i++;
        }
          else if (buffer[i+1]=='x'){
          str_len++;
          //printf("%c%c\n",buffer[i],buffer[i+1]);
          i+=3;
        }
      }
      else {
        //printf("%c\n",buffer[i]);
        str_len++;
      }
    }

    //printf("pro:%d str:%d buf:%s",prog_len,str_len,buffer);
    finalsum+=prog_len-str_len;
    }
  }
  printf("%d\n",finalsum);
  fclose(pfile);
  return 0;
}
