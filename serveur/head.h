#define PipeInPath "/tmp/projC/"
#define PipeOutPath "/tmp/projC/"
#define LogPath "/tmp/projC/"
#define LogFile "/tmp/projC/logServ"
#define MainPipe "/tmp/projC/mainPipe"
//#define MainPipe "/tmp/projC/mainPipe"

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


void testFonct();

char * getProbaChar(char* path);

char * getProbaMot(char* path);

char* catStr(char* c1,char* c2);

char* catStrChar(char* c1,char c);

void initPath();

void initLogFile();

void writeLog(char* msg);

void startServ();

int startMQ(char key);

void affiche(int i);

TubeStruct* initPipeStruc();

void createReadingPipe(TubeStruct* tubeS, char* path);

void createWritingPipe(TubeStruct* tubeS, char* path);

void closePipe(TubeStruct* tubeS);

void sendStructure(Data* data, TubeStruct* ts);

Data* reciveStruture(TubeStruct* ts);

void startSecServ(char* newMQ);

char* createNewMq(int * valueInc);

void stop();

void* sendNewMq(void * arg);

char* myStrcat(char* arr1,char* arr2);

void starSecServ(char *);

char* operation(Data *tube);

char* count_word(Data *tube);

char* count_char(Data *tube);