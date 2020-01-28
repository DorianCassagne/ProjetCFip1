#include "head.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>




void startServ(){
    writeLog("demarrage du serveur principal");
    startMQ("bla");
    int countMq = 0;
    while(1){
        waitConnection();
        char * mqName =  createNewMq(&countMq);

        //example de thread inutile...
        pthread_t thread;
        int rc = pthread_create(&thread, NULL, sendNewMq, (void *)mqName);
        if(rc)
            stop();
        //fin example de thread

        if(fork()==0)
            starSecServ(mqName);
    }
}

void stop(){
    
    pthread_exit(NULL);
    exit(-1);
}


void * sendNewMq(void * arg){
    char* nomMq= (char *)arg;
    Data* d = malloc(sizeof(Data));
    strncpy(d->str, nomMq,STR_SIZE);
    
    pthread_exit(NULL);
}