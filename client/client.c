#include "head.h"
#include <stdio.h>
#include <string.h>
void startClient(){
    
    TubeStruct* mainTube = initPipeStruc();
    createReadingPipe(mainTube,MainPipe); 
    Data* dat = reciveStructure(mainTube);
    closePipe(mainTube);
    //fin reception premier message
    int id;
    char str[250];
    
    TubeStruct* tube = initPipeStruc();
    createWritingPipe(tube, dat->str);

    createReadingPipe(tube, dat->str);

    printf("Bonjour");

    while (1){
        printf("Veuillez choisir une fonctionnalitée\n");
        printf(" 1 - Calcul \n");
        printf(" 2 - Compter les mots \n");
        printf(" 3 - Compter les caracteres \n");
        printf(" 4 - Probabilitée de caractere \n");
        printf(" 5 - Probabilitée de mot  \n");
        
        scanf("%d", &id);
        dat->data = id;

        printf("Veuillez envoyer votre données, soit du texte brut, soit fichier texte\n");

        scanf("%s", str);
        printf("test\n");
        strcpy(dat->str, str);
        printf("test3 : %s\n", dat->str);
        sendStructure(dat, tube);
        printf("test1\n");
        Data* datRcv = reciveStructure(tube);
        printf("test1\n");
        fflush(stdout);
        printf("datRcv : %s", datRcv->str);
        if (datRcv->codeRet == 0){
            printf("%s",datRcv->str);
        }else if (datRcv->codeRet == 1){
            printf("%s",datRcv->str);
            while (datRcv->codeRet == 1){
                Data* datRcv = reciveStructure(tube);
                printf("%s",datRcv->str);
            } 
        }else{
            printf("Il y a eu une erreur de traitement\n");
        }

        char fin;
        printf("Avez-vous fini ? [Y/N]\n");
        scanf("%s", &fin);

        if( fin == 'Y') break;
    }
}