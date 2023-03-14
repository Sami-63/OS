#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#define MAX_TEXT 50

struct my_msg{
    long int msg_type;
    char some_text[MAX_TEXT];
};

int main() {
    
    int running = 1;
    int msgid;
    struct my_msg some_data;
    char buffer[20];
    msgid = msgget((key_t)12345,066 | IPC_CREAT);


}
