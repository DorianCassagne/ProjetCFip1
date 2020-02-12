#include "head.h"
#include <pthread.h>


void starSecServ(char*  newPath){

    TubeStruct* tube = initPipeStruc();
    createReadingPipe(tube, newPath);
    createWritingPipe(tube, newPath);



    //int mq = startMQ(newMQ);
    //Data* query = reciveStruture();
    // switch (query->codeRet)
    // {
    // case 10:
    //     break;
    
    // default:
    //     break;
    // }


}