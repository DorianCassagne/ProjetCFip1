#include "head.h"
#include <stdio.h>
void startClient(){
    
    TubeStruct* mainTube = initPipeStruc();
    createReadingPipe(mainTube,MainPipe); 
    Data* dat = reciveStructure(mainTube);
    closePipe(mainTube);
    //fin reception premier message
    int id;
    char str[250];
    char fin;
    TubeStruct* tube = initPipeStruc();
    createWritingPipe(tube, dat->str);

    createReadingPipe(tube, dat->str);

    printf("Bonjour");

    while (1){
        printf("Veuillez choisir une fonctionnalitée");
        printf(" 1 - Calcul ");
        printf(" 2 - Compter les mots ");
        printf(" 3 - Compter les caracteres ");
        printf(" 4 - Probabilitée de caractere ");
        printf(" 5 - Probabilitée de mot  ");
        
        scanf("%d", id);
        myStrcat(dat->codeRet, id);

        printf("Veuillez envoyer votre données, soit du texte brut, soit fichier texte");

        scanf("%s", str);
        myStrcat(dat->str, str);
        sendStructure(dat, tube);

        Data* datRcv = reciveStructure(tube);
        if (datRcv->data == 0){
            printf(datRcv->str)
        }else if (datRcv->data == 1){
            printf(datRcv->str)
            while (datRcv->data == 1){
                Data* datRcv = reciveStructure(tube);
                printf(datRcv->str)
            } 
        }else{
            printf("Il y a eu une erreur de traitement")
        }

        printf("Avez-vous fini ? [Y/N]");
        scanf("%s", fin);

        if( fin == 'N') break;
    }
}