#define PipeInPath "/tmp/projC/"
#define PipeOutPath "/tmp/projC/"
#define MainPipe "/tmp/projC/mainPipe"

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


TubeStruct* initPipeStruc();

void createReadingPipe(TubeStruct* tubeS, char* path);

void createWritingPipe(TubeStruct* tubeS, char* path);

void closePipe(TubeStruct* tubeS);

void sendStructure(Data* data, TubeStruct* ts);

Data* reciveStructure(TubeStruct* ts);

char* myStrcat(char* arr1,char* arr2);

void startClient();

