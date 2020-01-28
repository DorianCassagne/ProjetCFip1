#include "head.h"
#include <stdio.h>

int MQcount;


void startServ(){
    writeLog("demarrage du serveur principal");
    startMQ();
    while(1){
        waitConnection();
        int newMq = sendNewMq();
        if(fork()==0)
            starSecServ(newMq);
    }
}