#include "head.h"
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
//prediction mot




struct listeMotMotIt
{
    char val[35];
    int nb;
    struct listeMotMotIt* next;
} typedef ListeMotMotIt;

struct listeMot
{
    
    char val[35];
    int total;
    struct listeMotMotIt* iteration;
    struct listeMot* next;
} typedef ListeMot; 

ListeMotMotIt* inserPosi(ListeMotMotIt* list, char* val){
     if(list == NULL || strcmp(list->val , val)> 0){//fin de liste ou liste vide ou valeur plus petite donc a insérér avant
        ListeMotMotIt* ret = malloc(sizeof(ListeMotMotIt));
        stcpy(ret->val,val);
        ret->next = list;
        ret->nb=1;
        return ret;
    }
       
    if(strcmp(list->val , val) < 0){//valeur a inserer apres
        list->next = inserPosi(list->next,val);
        return list;
    }

    //valeur forcement egale donc iteration a incrementer
    list->nb++;
    return list;

}


ListeMot* insererVal(ListeMot* list,  char* val, char after){
    if(list == NULL || strcmp(list->val , val)> 0){//fin de liste ou liste vide ou valeur plus petite donc a insérér avant
        ListeMot* ret = malloc(sizeof(ListeMot));
        stcpy(ret->val,val);
        ret->next = list;
        ret->iteration = inserPosi(ret->iteration, after);
        ret->total = 1;
        return ret;
    }
    if(strcmp(list->val , val) < 0){//valeur a inserer apres
        list->next = insererVal(list->next,val, after);
        return list;
    }
    //valeur forcement egale donc posistion a inserer
    
    list->iteration = inserPosi(list->iteration, after);
    list->total++;
    return list;
}


ListeMot* readFile(char* path) {
    FILE* fp = fopen(path,"r");
    if (fp == NULL){
        printf("balbal");
        exit(0);
    }
    ListeMot* list = NULL;
    char lastName[35];
    char curr[35];
    char c1= fgetc(fp);
    if(c1 == EOF)
        return list;
    char c2;
    while((c2 = fgetc(fp)) != EOF){
        list = insererVal(list,c1,c2);
        c1 = c2;
    }

    fclose(fp);

    return list;
}



void parcourirLC(ListeMot* list){
    printf("debut parcour\n");
    while (list!= NULL)
    {
        printf("valeur: '%s' ,%d\n", list->val, list->total);

        ListeMotMotIt* sl = list->iteration;
        while (sl!= NULL)
        {
            printf("    -'%s' , %d\n",sl->val,sl->nb);
            sl=sl->next;
        }
        list = list->next;
        
    }
    
}

void clean(ListeMotMotIt* l){
    while (l!= NULL)
    {
       ListeMotMotIt* sav = l ->next;
        free(l);

       l = sav;
    }
    
}

void clean(ListeMot* l){
    while (l!= NULL)
    {
       ListeMotMotIt* sav = l ->next;
       clean(l->iteration);
        free(l);

       l = sav;
    }
    
}