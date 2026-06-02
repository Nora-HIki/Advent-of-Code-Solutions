#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findmax(char name[500],char calchash[6]){
  //printf("%s %s",name,calchash);
  int occurencearray['z'+1]={0};
  for (int i=0;i<123;i++){
    occurencearray[name[i]]++;
    if(i>='a'){
    // printf("%d",occurencearray[i]);
    }
  }
  // printf("\n");
  int max[5]={0};
  int no=0;
  for (int i='a';i<123;i++){
    if(occurencearray[i]>max[0]){
    max[0]=occurencearray[i];
    }
  }
  no++;
  for (int j=0;j<4;j++){
  for (int i='a';i<123;i++){
    if(occurencearray[i]>max[no] && occurencearray[i]<max[no-1]){
    max[no]=occurencearray[i];
    }
  }
  no++;
  }
  // for(int j=0;j<5;j++){
  //   printf("%d ",max[j]);
  // }
  // printf("\n");  
  int maxindex[27]={0};
  int indexes=0;
  for (int j=0;j<5;j++){
    for (int i='a';i<123;i++){
      if(occurencearray[i]==max[j]){
        maxindex[indexes]=i;
        indexes++;
      }
    }
  }
  // for(int j=0;j<27;j++){
  //   printf("%d ",maxindex[j]);
  // }
  for (int i=0;i<5;i++){
    int tmp=maxindex[i];
    calchash[i]=(char)tmp;
  }
  // printf("\n");
}

int main(){

  FILE *pfile=fopen("input.txt","r");
  char buffer[1000];
  int Finalsum=0;

  while(fgets(buffer,sizeof(buffer),pfile)!=NULL){
    char* token=strtok(buffer,"-");
    char  hash[6]={'\0'};
    char  name[500]={'\0'};
    int   id=0;
    int   prevtokenlen=0;
    char  calchash[6]={'\0'};
    while(token!=NULL){
      if((token[0]>'0' && token[0]<'9') || token[0]=='0' || token[0]=='9' ){
        sscanf(token,"%d[%s",&id,&hash);
        for(int i=5;i<10;i++){
          hash[i]='\0';
        }
        findmax(name,calchash);
        printf("%s\n",hash);
        if(strcmp(hash,calchash)==0){
          Finalsum+=id;
        }
      }
      else if((token[0]>'a' && token[0]<'z') || token[0]=='a' || token[0]=='z'){
        strcpy(name+prevtokenlen,token);
        prevtokenlen+=strlen(token);
      }
      token=strtok(NULL,"-");
    }
    printf("\n");
  }
  printf("%d\n",Finalsum);
  return 0;
}
