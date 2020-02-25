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



char* parcourirLC(ListeChar* list){
    char* ret = malloc(sizeof(char));
    ret[0]= '\0';
    ret = catStr(ret, "debut parcour\n");
    while (list!= NULL)
    {
        char str[100];
        snprintf(str, 100,"valeur: '%c' ,%d\n", list->val, list->total);

        ret = catStr(ret, str);

        ListeCharIt* sl = list->iteration;
        while (sl!= NULL)
        {
            
            snprintf(str, 100,"    -'%c' , %d\n",sl->val,sl->nb);
            
            ret = catStr(ret, str);
            sl=sl->next;
        }
        list = list->next;
        
    }
    return ret;
    
}

void cleanSub(ListeCharIt* l){
    while (l!= NULL)
    {
       ListeCharIt* sav = l ->next;
        free(l);

       l = sav;
    }
    
}

void clean(ListeChar* l){
    while (l!= NULL)
    {
       ListeChar* sav = l ->next;
       cleanSub(l->iteration);
        free(l);

       l = sav;
    }
    
}


//prediction mot




struct listeMotMotIt
{
    char val[100];
    int nb;
    struct listeMotMotIt* next;
} typedef ListeMotMotIt;

struct listeMot
{
    
    char val[100];
    int total;
    struct listeMotMotIt* iteration;
    struct listeMot* next;
} typedef ListeMot; 

ListeMotMotIt* inserPosiMot(ListeMotMotIt* list, char* val){
     if(list == NULL || strcmp(list->val , val)> 0){//fin de liste ou liste vide ou valeur plus petite donc a insérér avant
        ListeMotMotIt* ret = malloc(sizeof(ListeMotMotIt));
        strcpy(ret->val,val);
        ret->next = list;
        ret->nb=1;
        return ret;
    }
       
    if(strcmp(list->val , val) < 0){//valeur a inserer apres
        list->next = inserPosiMot(list->next,val);
        return list;
    }

    //valeur forcement egale donc iteration a incrementer
    list->nb++;
    return list;

}


ListeMot* insererValMot(ListeMot* list,  char* val, char* after){
    if(list == NULL || strcmp(list->val , val)> 0){//fin de liste ou liste vide ou valeur plus petite donc a insérér avant
        ListeMot* ret = malloc(sizeof(ListeMot));
        strcpy(ret->val,val);
        ret->next = list;
        ret->iteration = inserPosiMot(ret->iteration, after);
        ret->total = 1;
        return ret;
    }
    if(strcmp(list->val , val) < 0){//valeur a inserer apres
        list->next = insererValMot(list->next,val, after);
        return list;
    }
    //valeur forcement egale donc posistion a inserer
    
    list->iteration = inserPosiMot(list->iteration, after);
    list->total++;
    return list;
}


ListeMot* readFileMot(char* path) {
    FILE* fp = fopen(path,"r");
    if (fp == NULL){
        printf("balbal");
        exit(0);
    }

    ListeMot* list = NULL;
    char last[80];
    last[0]='\0';
    char buf[80];
    while( fscanf(fp, "%s", buf) != EOF )
        {
            
            list = insererValMot(list,buf,last);
            strcpy(last,buf);
            
        }

    fclose(fp);
    return list;
}





char* parcourirLCMot(ListeMot* list){
    char* ret = malloc(sizeof(char));
    ret[0]= '\0';
    ret = catStr(ret, "debut parcour\n");
    while (list!= NULL)
    {
        char str[150];
        snprintf(str, 149,"valeur: '%s' ,%d\n", list->val, list->total);

        ret = catStr(ret, str);

        ListeMotMotIt* sl = list->iteration;
        while (sl!= NULL)
        {
            
            snprintf(str, 149,"    -'%s' , %d\n",sl->val,sl->nb);
            
            ret = catStr(ret, str);
            sl=sl->next;
        }
        list = list->next;
        
    }
    return ret;
    
}

void cleanSubMot(ListeMotMotIt* l){
    while (l!= NULL)
    {
       ListeMotMotIt* sav = l ->next;
        free(l);

       l = sav;
    }
    
}

void cleanMot(ListeMot* l){
    while (l!= NULL)
    {
       ListeMot* sav = l ->next;
       cleanSubMot(l->iteration);
        free(l);

       l = sav;
    }
    
}



char * getProbaChar(char* path){
    return parcourirLC(readFile(path));
}

char * getProbaMot(char* path){
    return parcourirLCMot(readFileMot(path));
}



void* testFonct(){
    char * str = parcourirLCMot(readFileMot("./serveur/general.c"));
    printf("%s",str);
}