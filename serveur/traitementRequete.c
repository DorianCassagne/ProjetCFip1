#include "head.h"
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>

int count_char(Data *tube){
    return strlen(tube->str);
}

int count_word(Data *tube){
    int count=0,i,len;
    char lastC;
    len=strlen(tube->str);
    if(len > 0)
    {
        lastC = tube->str[0];
    }
    for(i=0; i<=len; i++)
    {
        if((tube->str[i]==' ' || tube->str[i]=='\0') && lastC != ' ')
        {
            count++;
        }
        lastC = tube->str[i];
    }
    return count;
}

int operation(Data *tube){
    int result = 0 ;
    for (int i = 0; i < strlen(tube->str); i++){
        while(tube->str[i] != '-' || tube->str[i] != '+' || tube->str[i] != '*'){
            char *ptr = strtok(tube->str, &tube->str[i]);
            while(ptr != NULL)
            {
                switch (tube->str[i])
                {
                    case '-':
                        result -= result;
                    case '+':
                        result += result;
                    case '*':
                        result *= result;
                    default:
                        break;
                }
                ptr = strtok(NULL, &tube->str[i]);
            }
            
        }
    }
    return result;
}


//prediction char




struct listeCharIt
{
    char val;
    int nb;
    struct listeCharIt* next;
} typedef ListeCharIt;


struct listeChar
{
    char val;
    int total;
    struct listeCharIt* iteration;
    struct listeChar* next;
} typedef ListeChar; 

ListeCharIt* inserPosi(ListeCharIt* list, char val){
     if(list == NULL || list->val > val){//fin de liste ou liste vide ou valeur plus petite donc a insérér avant
        ListeCharIt* ret = malloc(sizeof(ListeCharIt));
        ret->val = val;
        ret->next = list;
        ret->nb=1;
        return ret;
    }
       
    if(list->val < val){//valeur a inserer apres
        list->next = inserPosi(list->next,val);
        return list;
    }

    //valeur forcement egale donc iteration a incrementer
    list->nb++;
    return list;

}


ListeChar* insererVal(ListeChar* list,  char val, char after){
    if(list == NULL || list->val > val){//fin de liste ou liste vide ou valeur plus petite donc a insérér avant
        ListeChar* ret = malloc(sizeof(ListeChar));
        ret->val = val;
        ret->next = list;
        ret->iteration = inserPosi(ret->iteration, after);
        ret->total = 1;
        return ret;
    }
    if(list->val < val){//valeur a inserer apres
        list->next = insererVal(list->next,val, after);
        return list;
    }
    //valeur forcement egale donc posistion a inserer
    
    list->iteration = inserPosi(list->iteration, after);
    list->total++;
    return list;
}


ListeChar* readFile(char* path) {
    FILE* fp = fopen(path,"r");
    if (fp == NULL){
        printf("balbal");
        exit(0);
    }
    ListeChar* list = NULL;
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



void parcourirLC(ListeChar* list){
    printf("debut parcour\n");
    while (list!= NULL)
    {
        printf("valeur: '%c' ,%d\n", list->val, list->total);

        ListeCharIt* sl = list->iteration;
        while (sl!= NULL)
        {
            printf("    -'%c' , %d\n",sl->val,sl->nb);
            sl=sl->next;
        }
        list = list->next;
        
    }
    
}

