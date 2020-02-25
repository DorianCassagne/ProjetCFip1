#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h> 

#include <stdio.h>
#include <string.h>

struct threadStruct{
    int countpite;
    TubeStruct* pipe;
}typedef ThreadArg;


void startServ(){
    writeLog("demarrage du serveur principal");
    int countPipe = 10;
    TubeStruct* mainTube = initPipeStruc();
    while (1)
    {

        createWritingPipe(mainTube,MainPipe); 

        //exemple de thread inutile...
        ThreadArg* arg = malloc(sizeof(ThreadArg));
        arg->countpite = countPipe;
        arg->pipe = mainTube;
        pthread_t thread;


        pthread_create(&thread, NULL, sendNewMq, (void *) arg);
        pthread_join(thread,NULL);
        writeLog("fin thread");
        //fin exemple de thread
        closePipe(mainTube);
        char str[10];
        sprintf(str, "%d", countPipe);
        char * newPipe = myStrcat(LogPath, str);
        if(fork()==0) {
            starSecServ(newPipe);

            exit(0);
        }

        countPipe++;

    }
    
    // startMQ("serv");
    // int countMq = 0;
    // while(1){
    //     waitConnection();
    //     char * mqName =  createNewMq(&countMq);

    //     //example de thread inutile...
    //     pthread_t thread;
    //     int rc = pthread_create(&thread, NULL, sendNewMq, (void *)mqName);
    //     if(rc)
    //         stop();
        
    //     //fin example de thread

    //     if(fork()==0)
    //         starSecServ(mqName);
    // }
}

// void stop(){
//     pid_t wpid;
//     int status = 0;
//     while ((wpid = wait(&status)) > 0); 
//     pthread_exit(NULL);
//     exit(-1);
// }


void * sendNewMq(void * args){
    ThreadArg* arg =args;

    


    char str[10];
    sprintf(str, "%d", arg->countpite);
    Data* d = malloc(sizeof(Data));
    strcpy(d->str,LogPath);
    strcat(d->str,str);
    sendStructure(d, arg->pipe);

    

    pthread_exit(NULL);
}