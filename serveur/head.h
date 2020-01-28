#define PipeInPath "/tmp/projetC/mainPipeInput"
#define PipeOutPath "/tmp/projetC/mainPipeOutput"
#define LogFile "/tmp/projetC/log"

#define STR_SIZE 250
struct data
{
    int codeRet;//-1 if error erro info in str 0 if empty
    long data;
    char str[STR_SIZE];
}typedef Data;

int startMQ(char key);

void affiche(int i);

void writeLog(char* msg);

void startServ();

void sendStrucuture(Data* data);

void startSecServ(int newMQ);

char* createNewMq(int * valueInc);

Data* reciveStruture();

void stop();