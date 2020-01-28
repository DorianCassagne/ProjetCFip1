#include "head.h"
#include <pthread.h>


void startSecServ(int newMQ){
    int mq = startMQ(newMQ);
    Data* query = reciveStruture();
    switch (query->codeRet)
    {
    case 10:
        break;
    
    default:
        break;
    }


}