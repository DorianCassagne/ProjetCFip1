#define PipeInPath "/tmp/projetC/mainPipeInput"
#define PipeOutPath "/tmp/projetC/mainPipeOutput"
#define LogFile "/tmp/projetC/log"

struct data
{
    int codeRet;//-1 if error erro info in str 0 if empty
    long data;
    char str[250];
}typedef Data;


void affiche(int i);

void writeLog(char* msg);

void startServ();

void sendStrucuture(Data);

void startSecServ(int newMQ);

Data* reciveStruture();
