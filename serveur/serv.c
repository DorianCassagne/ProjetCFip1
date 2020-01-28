#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>


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
      // msgrcv to receive message
      msgrcv(msgid, &data, sizeof(Data), 1, 0);

      // display the message
      printf("Data Received is : %s \n",
                      data.str);

      // to destroy the message queue
      msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
