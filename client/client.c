#include "head.h"
#include <stdio.h>
void startClient(){
    
    TubeStruct* mainTube = initPipeStruc();
    createReadingPipe(mainTube,MainPipe); 
    Data* dat = reciveStructure(mainTube);
    closePipe(mainTube);
    //fin reception premier message


    TubeStruct* tube = initPipeStruc();
    createWritingPipe(tube, dat->str);

    createReadingPipe(tube, dat->str);

}