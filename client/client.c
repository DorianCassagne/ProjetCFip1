#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void affichageMenu(){

        printf("Veuillez choisir une fonctionnalitée\n");
        printf(" 1 - Calcul \n");
        printf(" 2 - Compter les mots \n");
        printf(" 3 - Compter les caracteres \n");
        printf(" 4 - Probabilitée de caractere \n");
        printf(" 5 - Probabilitée de mot  \n");
        fflush(stdout);
}


Data* recupererInput(){
    Data * d = malloc(sizeof(Data));


    int id;
    char str[250];
    scanf("%d", &id);
    d->data = id;

    printf("Veuillez envoyer votre données, soit du texte brut, soit fichier texte\n");

    scanf("%s", str);
    strcpy(d->str, str);
    return d;

}

void affichageRecu(TubeStruct* tube){


    Data* datRcv = reciveStructure(tube);
    if (datRcv->codeRet == 0){
        printf("%s",datRcv->str);
        fflush(stdout);
        }else if (datRcv->codeRet == 1){
            printf("%s",datRcv->str);
            while (datRcv->codeRet == 1){
                Data* datRcv = reciveStructure(tube);
                printf("%s",datRcv->str);
            } 
    }else{
        printf("Il y a eu une erreur de traitement\n");
    }
}
void startClient(){
    
    TubeStruct* mainTube = initPipeStruc();
    createReadingPipe(mainTube,MainPipe); 
    Data* dat = reciveStructure(mainTube);
    closePipe(mainTube);
    //fin reception premier message
    
    TubeStruct* tube = initPipeStruc();
    createWritingPipe(tube, dat->str);

    createReadingPipe(tube, dat->str);

    printf("Bonjour");

    while (1){

        affichageMenu();
        
        Data* d =recupererInput();
        
        sendStructure(d, tube);

        affichageRecu(tube);

        char fin;
        printf("Avez-vous fini ? [Y/N]\n");
        scanf("%s", &fin);

        if( fin == 'Y') break;
    }
}