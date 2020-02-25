#include "head.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void starSecServ(char*  newPath){
    TubeStruct* tube = initPipeStruc();
    createReadingPipe(tube, newPath);
    createWritingPipe(tube, newPath);

    Data* dataSend = malloc(sizeof(Data));
    char tempo[15];  

    while(1){
        Data* dataRcv = reciveStruture(tube);
        



        switch (dataRcv->data)
        {
        case 1l:
            strcpy(dataSend->str, "1\n"); //operation(dataRcv));
            dataSend->codeRet = 0;
            sendStructure(dataSend, tube);
            break;
        
        default:
            strcpy(dataSend->str, "operation inconnue\n");
            dataSend->codeRet = 0;
            sendStructure(dataSend, tube);
            break;
        }

        free(dataRcv);

    }    

    // switch (dataRcv->data)
    // {
    //     case 1l:
    //         printf("yes");
    //         sprintf(dataSend->str,"resultat : %d",operation(dataRcv));
    //         fflush(stdout);
    //         sendStructure(dataSend, tube);
    //         printf("fin resultat");
    //         break;
    //     case 2l: // nb mot depuis une chaine
    //         break;
    //     case 3l: // nb mot depuis un fichier
    //         sprintf(dataSend->str,"%d",count_word(dataRcv));
    //         sendStructure(dataSend, tube);
    //         break;

    //     case 4l: // nb char depuis un fichier
    //         printf("fonc 4");
    //          break;
    //     case 5l: // nb char depuis un fichier
    //         sprintf(dataSend->str,"%d",count_char(dataRcv));
    //         sendStructure(dataSend, tube);
    //         break;
        
    //     // case 6: // proba depuis un fichier

    //     //     break;
    //     // case 7: // proba depuis un fichier
    //     //     char* pointeurResult ="TODO :" ;//count_char(dataRcv);
    //     //     if (strlen(&pointeurResult) > 250){

    //     //     }else{
    //     //         strncpy(dataSend->str, &pointeurResult, 250);
    //     //         sendStructure(dataSend, tube);
    //     //     }

    //     //     break;
        
    //     // case 8: // proba depuis un fichier
    //     // case 9: // proba depuis un fichier
    //     //     char *pointeurResult = "TODO :" ;//count_char(dataRcv);
    //     //     if (strlen(&pointeurResult) > 250){

    //     //     }else{
    //     //         strncpy(dataSend->str, &pointeurResult, 250);
    //     //         sendStructure(dataSend, tube);
                
    //     //     }
    //     //     break;
            
    //     default:
    //         printf("erreur");
    //         strncpy(dataSend->str, "Code non valide", 16);
    //         sendStructure(dataSend, tube);
    //         break;
    // }


    // int mq = startMQ(newMQ);
    // Data* query = reciveStruture(tube);
    // switch (query->codeRet)
    // {
    // case 10:
    //     break;
    
    // default:
    //     break;
    // }


}