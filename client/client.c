#include "head.h"
#include <stdio.h>
void startClient(){
    
    TubeStruct* mainTube = initPipeStruc();
    createReadingPipe(mainTube,MainPipe); 
    Data* dat = reciveStructure(mainTube);
    closePipe(mainTube);
}