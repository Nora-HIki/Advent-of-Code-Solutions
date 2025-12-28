#include <stdio.h>
#include <string.h>

long long factorial(int num){
  long long temp=1;
  for (int i=num;i>=1;i--){
    temp*=i;
  }
  return temp;
}

char buffer[500];
char loc1[100][100];
char loc2[100][100];
char locs[100][100];
int dist[100];
int count=0;
int ucount=0;
long long shortest=1000000; 

void permute(int ucount,char locs[100][100],int start){
  char temp[100];
  if (start<ucount){
   for (int p=start;p<ucount;p++){
    strcpy(temp,locs[start]);
    strcpy(locs[start],locs[p]);
    strcpy(locs[p],temp);
    permute(ucount,locs,start+1);
    strcpy(temp,locs[start]);
    strcpy(locs[start],locs[p]);
    strcpy(locs[p],temp);
    }   
  }
  else if (start>=ucount) {

  int distance=0;
  for (int y=1;y<ucount;y++) {
    for (int o=0;o<count;o++) {
     if (strcmp(locs[y],loc2[o])==0 && strcmp(locs[y-1],loc1[o])==0
        ||strcmp(locs[y-1],loc2[o])==0 && strcmp(locs[y],loc1[o])==0){
       distance+=dist[o];
        //printf("%s to %s\n",loc1[o],loc2[o]);
    }
   }
  }
  
  if (distance<=shortest){
  shortest=distance;
  printf("%d\n",distance);
  }

  //for (int i=0;i<ucount;i++){
  //  (i==ucount-1?printf("%s\n",locs[i]):printf("%s->",locs[i]));
  //}   
  }
}

int main(){


  FILE *pfile=fopen("input.txt","r");
  
 
  while (fgets(buffer,sizeof(buffer),pfile)!=NULL){
    sscanf(buffer,"%s to %s = %d",loc1[count],loc2[count],&dist[count]);

    if (ucount==0) {
      strcpy(locs[0],loc1[0]);
      ucount++;
    }
    else {
      int unique[2]={1,1};
      for (int i=0;i<ucount;i++){
        if(strcmp(loc1[count],locs[i])==0){
          unique[0]=0;
        }
        if(strcmp(loc2[count],locs[i])==0){
          unique[1]=0;
        }
      }
      if (unique[0]==1 && unique[1]==1){
        strcpy(locs[ucount],loc1[count]);
        ucount++;
        strcpy(locs[ucount],loc2[count]);
        ucount++;
      }
      if (unique[0]==1 && unique[1]==0){
        strcpy(locs[ucount],loc1[count]);
        ucount++;
      }
      if (unique[0]==0 && unique[1]==1){
        strcpy(locs[ucount],loc2[count]);
        ucount++;
      }
    }
    count++;
  }
  fclose(pfile);
  permute(ucount,locs,0);
  printf("%lld",shortest);
  return 0;
}
