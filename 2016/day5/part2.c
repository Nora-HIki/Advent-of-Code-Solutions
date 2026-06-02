#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(){
  FILE *pfile=fopen("input.txt","r");
  char buffer[100]={'\0'};
  fgets(buffer,sizeof(buffer),pfile);
  fclose(pfile);
  int inputlength=strlen(buffer)-1;
  int no=0;
  char final[9]={'\0'};
  int alrdone[8]={0};
  // printf("%d",inputlength);

  for(int i=0;i<8;i++){
    int found=0;
    while(!found){
      char strhash[33]={'\0'};
      int hashlen=0;
      sprintf(buffer+inputlength,"%d",no);
      unsigned char hash[MD5_DIGEST_LENGTH];
      MD5((unsigned char*)buffer,strlen(buffer),hash);
      for (int i=0;i<MD5_DIGEST_LENGTH;i++){
      char tmp[3];
      sprintf(tmp,"%02x",hash[i]);
      strhash[hashlen]=tmp[0];
      strhash[hashlen+1]=tmp[1];
      hashlen+=2;
      }
      strhash[32]='\0';
      if(strncmp(strhash,"00000",5)==0){
        int pos=strhash[5]-'0';
        char val=strhash[6];
        if(pos>=0 && pos<=7 && alrdone[pos]==0){
          alrdone[pos]=1;
          final[pos]=val;
          found=1;
          // printf("%s %c %d %d %c\n",strhash,strhash[5],no,pos,val);
        }
      }
      no++;
    }
  }
  printf("%s\n",final);
}
