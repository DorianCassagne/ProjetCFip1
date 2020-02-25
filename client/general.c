#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#include <string.h>
 


#include <sys/fcntl.h>

void writeLog(char * str){
  printf("%s\n",str);
}

TubeStruct* initPipeStruc(){
  TubeStruct *tube = malloc(sizeof(TubeStruct));
  return tube;
}

void createReadingPipe(TubeStruct *tube,  char* path){
  /* ouverture du tube */

    //TODO: decommenter

  writeLog(myStrcat("creation pipe lecture : " ,myStrcat(path,".w")));
  tube->read = open (myStrcat(path,".w"), O_RDONLY);
}

void createWritingPipe(TubeStruct *tube, char* path){
  mode_t mode;
  mode = S_IRUSR | S_IWUSR;
  /*création du tube nommé */
   mkfifo (myStrcat(path,".r"), mode);

  writeLog(myStrcat("creation pipe ecriture : " ,myStrcat(path,".r")));
    /* ouverture du tube */
    //TODO: decommenter
  tube->write = open (myStrcat(path,".r"), O_WRONLY);
  writeLog(myStrcat("fin creation pipe ecriture : " ,myStrcat(path,".r")));
}

char* myStrcat(char* arr1,char* arr2){
    char* ret = malloc(sizeof(char)*(strlen(arr1)+strlen(arr2)+1));
    strcpy(ret, arr1);
    strcat(ret, arr2);
    return ret;
}

void sendStructure(Data *data, TubeStruct* tub){
  write (tub->write, data, sizeof(Data));
}

Data* reciveStructure(TubeStruct* tub){
  Data* dataRcv = malloc(sizeof(Data));
  writeLog("struct non recu");
  read (tub->read, dataRcv, sizeof(Data));
  writeLog("struct recu");
  return dataRcv;
}


void closePipe(TubeStruct* pipe){ 
    if(pipe->read!=0){
        close(pipe->read);
    }
    if(pipe->write!=0){
        close(pipe->write);
    }
}
