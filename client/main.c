int main(){
    
}


#define STR_SIZE 250
struct tube
{
  int write;
  int read;
}typedef TubeStruct;


struct data
{
    int codeRet;//-1 if error erro info in str 0 if empty
    long data;
    char str[STR_SIZE];
}typedef Data;


TubeStruct* initPipeStruc(){
  TubeStruct *tube = malloc(sizeof(TubeStruct));
  return tube;
}

void createReadingPipe(TubeStruct *tube,  char* path){
  /* ouverture du tube */

    //TODO: decommenter
  tube->read = open (myStrcat(path,".r"), O_RDONLY);
}

void createWritingPipe(TubeStruct *tube, char* path){
  mode_t mode;
  mode = S_IRUSR | S_IWUSR;
  /*création du tube nommé */
   mkfifo (myStrcat(path,".w"), mode);
    /* ouverture du tube */
    //TODO: decommenter
  tube->write = open (myStrcat(path,".w"), O_WRONLY);
}

char* myStrcat(char* arr1,char* arr2){
    char* ret = malloc(sizeof(char)*(strlen(arr1)+strlen(arr2)+1));
    strcpy(ret, arr1);
    strcat(ret, arr2);
    return ret;
}

void sendStructure(Data *data, TubeStruct* tub){
  write (tub->write, data, sizeof(Data));
  writeLog(myStrcat("donnée reçu : " , data->str));
}

Data* reciveStructure(TubeStruct* tub){
  Data* dataRcv = malloc(sizeof(Data));
  read (tub->read, dataRcv, sizeof(Data));
  printf("%s\n", dataRcv->str);
  writeLog(myStrcat("donnée reçu : ", dataRcv->str));
  return dataRcv;
}