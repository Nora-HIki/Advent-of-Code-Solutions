// importing the required libraries
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main() {  
  // making a message
    unsigned char digest[16];
    char inputstring[100]="iwrupvqb"; 
    char nostring[100];
    int sweet_number=1;
    int found=0;
    char tempinputstring[100];
    char compare[33];
  while (found==0){
      found=1;
      sprintf(nostring,"%d",sweet_number);
      for (int i=0;i<100;i++){
      tempinputstring[i]=inputstring[i];
    }
      strcat(inputstring,nostring);
      // encoding the message using the library function
      EVP_Q_digest(NULL,"MD5",NULL,inputstring,strlen(inputstring),digest,NULL);
      for (int i = 0, j = 0; i < 16; i++, j+=2){
        sprintf(compare+j, "%02x", digest[i]);
        compare[sizeof (digest) * 2] = 0;
    }

      for (int i=0;i<5;i++){
      if (compare[i]!='0'){
          found=0;
          //printf("\n%d pos is %c\n",i,compare[i]);
          }
      }
      //printf("%s\n",compare);
      if(found==1){
        break;
        }
      for (int i=0;i<100;i++){
      inputstring[i]=tempinputstring[i];
    }
      sweet_number++;
  }

printf("%d %s\n",sweet_number,compare);
return 0;
}
