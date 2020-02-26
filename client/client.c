#include "head.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* recupere(int* compteur){
    char c;
    (*compteur)=1;
    int boolean=1;
    char* lien=(char*)malloc(sizeof(char));
    while(boolean){
        c=fgetc(stdin);
        if((*compteur)!=1 && c=='\n'){
            boolean=0;
        }else if(c!='\n'){
            lien[(*compteur)-1]=c;
            (*compteur)++;
            lien=(char*)realloc(lien,sizeof(char)*(*compteur));
        }
        
    }
    lien[(*compteur)-1]='\0';
    return lien;
}

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
    int *t = &id;
    strcpy(d->str, recupere(t));
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
            free (datRcv);
            datRcv = reciveStructure(tube);
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

    printf("Bonjour\n");

    while (1){

        affichageMenu();
        
        Data* d =recupererInput();
        
        sendStructure(d, tube);

        affichageRecu(tube);

        char fin;
        printf("\nAvez-vous fini ? [Y/N]\n");
        scanf("%c", &fin);
        printf("%c", fin);
        if( fin == 'Y') break;
    }
}