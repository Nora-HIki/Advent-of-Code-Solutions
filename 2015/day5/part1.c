#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main(){

  FILE *pfile=fopen("input.txt","r");

  char buffer[100];
  int nice=0;

while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
  
  int vowels=0;
  bool double_letters=false;
  bool bad_substring=false;

  for (int i=0;i<strlen(buffer);i++){
    if (buffer[i]=='i'||buffer[i]=='o'||buffer[i]=='u'||buffer[i]=='a'||buffer[i]=='e'){
      vowels++;
    }
  }

  for (int i=0;i<strlen(buffer);i++){ 
    if (i>=1 && buffer[i]==buffer[i-1]){
          double_letters=true;
    }
  }

  for (int i=1;i<strlen(buffer);i++){
      if (buffer[i-1]=='a' && buffer[i]=='b' 
        ||buffer[i-1]=='c' && buffer[i]=='d'
        ||buffer[i-1]=='p' && buffer[i]=='q'
        ||buffer[i-1]=='x' && buffer[i]=='y' ){

          bad_substring=true;
      }
  }
  if (vowels>=3 && double_letters == true && bad_substring == false ){
        nice++;
        //printf("%s",buffer);
      }
  }
  
  fclose(pfile);
  printf("%d\n",nice);
  return 0;
}
