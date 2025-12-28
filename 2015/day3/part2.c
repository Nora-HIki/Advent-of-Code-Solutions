#include <stdio.h>

int main(){

  FILE *pfile=fopen("input.txt","r");


  fseek(pfile,0,SEEK_END);
  int size=ftell(pfile);
  fseek(pfile,0,SEEK_SET);

  char buffer[size];

  int ypos=0;
  int xpos=0;
  int R_xpos=0;
  int R_ypos=0;
  int houses=1;
  int count=0;
  long long history[10000][2];
  history[0][0]=xpos;
  history[0][1]=ypos;
  count++;

  fgets(buffer,sizeof(buffer),pfile);

  for (int i=0;i<sizeof(buffer);i++){


    //odd no original santa
    if (i%2==0 || i==0){
          switch (buffer[i]){      
            case '^':
            ypos++;
            break;

            case 'v':
            ypos--;
            break;

       case '<':
        xpos--;
        break;

      case '>':
        xpos++;
        break;
     }
  int isrepeat=0;

  for (int j=0;j<count;j++){
      if (history[j][0]==xpos && history[j][1]==ypos){
          isrepeat=1;
          break;
      }
  }    
  if (isrepeat==0){
       history[count][0]=xpos;
       history[count][1]=ypos;
       //printf("(%d,%d)\n",xpos,ypos);
       count++;
       houses++;
    }
  }

  if (i%2!=0){
       switch (buffer[i]){      
      case '^':
        R_ypos++;
        break;

      case 'v':
        R_ypos--;
        break;

      case '<':
        R_xpos--;
        break;

      case '>':
        R_xpos++;
        break;
    }
  int isrepeat=0;

  for (int j=0;j<count;j++){
      if (history[j][0]==R_xpos && history[j][1]==R_ypos){
          isrepeat=1;
          break;
      }
  }    
  if (isrepeat==0){
       history[count][0]=R_xpos;
       history[count][1]=R_ypos;
       //printf("(%d,%d)\n",xpos,ypos);
       count++;
       houses++;
    }
    }

    }

  
    
    
  fclose(pfile);
  printf("%d\n",houses);
  return 0;
}
