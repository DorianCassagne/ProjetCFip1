#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct data
{
    int codeRet;//-1 if error
    long data;
    char str[250];
}typedef Data;

int main()
{

      key_t key;
      int msgid;
      Data data;
      // ftok to generate unique key
      key = ftok("progfile", 65);

      // msgget creates a message queue
      // and returns identifier
      msgid = msgget(key, 0666 | IPC_CREAT);
      data.codeRet = 1;

      printf("Write Data : ");
      gets(data.str);

      // msgsnd to send message
      msgsnd(msgid, &data, sizeof(Data), 0);

      // display the message
      printf("Data send is : %s \n", data.str);



    return 0;
}
