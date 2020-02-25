#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#include <string.h>
 


#include <sys/fcntl.h>

FILE* logfile = NULL;
void initLogFile(){

    
    logfile = fopen(LogFile,"w");
}

void writeLog(char* msg){
    // if(logfile==NULL)
    //      initLogFile();
    // fprintf(logfile,"%s\n", msg);
    printf("%s\n", msg);
    fflush(stdout);
}
void initPath(){
    struct stat st = {0};
    if (stat(LogPath, &st) == -1) {
        mkdir(LogPath, 0700);
    }
}

TubeStruct* initPipeStruc(){
  TubeStruct *tube = malloc(sizeof(TubeStruct));
  return tube;
}

void createReadingPipe(TubeStruct *tube,  char* path){
  /* ouverture du tube */

    //TODO: decommenter

  writeLog(myStrcat("creation pipe lecture : " ,myStrcat(path,".r")));
  tube->read = open (myStrcat(path,".r"), O_RDONLY);
}

void createWritingPipe(TubeStruct *tube, char* path){
  mode_t mode;
  mode = S_IRUSR | S_IWUSR;
  /*création du tube nommé */
   mkfifo (myStrcat(path,".w"), mode);

  writeLog(myStrcat("creation pipe ecriture : " ,myStrcat(path,".w")));
    /* ouverture du tube */
    //TODO: decommenter
  tube->write = open (myStrcat(path,".w"), O_WRONLY);
  writeLog(myStrcat("fin creation pipe ecriture : " ,myStrcat(path,".w")));
}

char* myStrcat(char* arr1,char* arr2){
    char* ret = malloc(sizeof(char)*(strlen(arr1)+strlen(arr2)+1));
    strcpy(ret, arr1);
    strcat(ret, arr2);
    return ret;
}

char* catStr(char* c1,char* c2){
  c1= realloc(c1,sizeof(char)* (strlen(c1)+ strlen(c2)+1));
  strcat(c1,c2);
  return c1;
}
char* catStrChar(char* c1,char c){
  char c2[2];
  c2[0]= c;
  c2[1]='\0';
  return catStr(c1,c2);
}

void sendStructure(Data *data, TubeStruct* tub){
  write (tub->write, data, sizeof(Data));
  writeLog(myStrcat("donnée envoyé : " , data->str));
}

Data* reciveStructure(TubeStruct* tub){
  Data* dataRcv = malloc(sizeof(Data));
  read (tub->read, dataRcv, sizeof(Data));
  printf("%s\n", dataRcv->str);
  writeLog(myStrcat("donnée reçu : ", dataRcv->str));
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
