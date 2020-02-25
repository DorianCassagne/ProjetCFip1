#include "head.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h> 

#include <stdio.h>
#include <string.h>
void starSecServ(char*  newPath){

    TubeStruct* tube = initPipeStruc();
    createReadingPipe(tube, newPath);
    createWritingPipe(tube, newPath);

    Data* dataRcv = malloc(sizeof(Data));
    Data* dataSend = malloc(sizeof(Data));

    read (tube->read, dataRcv, sizeof(Data));
    // switch (dataRcv->data)
    // {
    //     case 0: // opérations depuis une chaine
    //     case 1:
    //         strncpy(dataSend->str,operation(dataRcv), 250);
    //         sendStructure(dataSend, tube);
    //         break;
    //     case 2: // nb mot depuis une chaine
    //     case 3: // nb mot depuis un fichier
    //         strncpy(dataSend->str, count_word(dataRcv), 250);
    //         sendStructure(dataSend, tube);
    //         break;

    //     case 4: // nb char depuis un fichier
    //     case 5: // nb char depuis un fichier
    //         strncpy(dataSend->str, count_char(dataRcv), 250);
    //         sendStructure(dataSend, tube);
    //         break;
        
    //     case 6: // proba depuis un fichier
    //     case 7: // proba depuis un fichier
    //         char *pointeurResult = count_char(dataRcv);
    //         if (strlen(&pointeurResult) > 250){

    //         }else{
    //             strncpy(dataSend->str, &pointeurResult, 250);
    //             sendStructure(dataSend, tube);
    //             break;
    //         }
        
    //     case 8: // proba depuis un fichier
    //     case 9: // proba depuis un fichier
    //         char *pointeurResult = proba_count_char(dataRcv);
    //         if (strlen(&pointeurResult) > 250){

    //         }else{
    //             strncpy(dataSend->str, &pointeurResult, 250);
    //             sendStructure(dataSend, tube);
    //             break;
    //         }
            
    //     default:
    //         strncpy(dataSend->str, "Code non valide", 16);
    //         sendStructure(dataSend, tube);
    //         break;
    // }


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