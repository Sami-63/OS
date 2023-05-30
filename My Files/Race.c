#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fun1();
void *fun2();

int shared = 1;

int main(){

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Fincal value of shared is %d\n", shared);

}

void *fun1()
{
    int x;
    x = shared;
    printf("Thread1 reads the shared = %d\n", x);
    x++;
    printf("Local updation by thread1 = %d\n", x);
    
    shared = x;
    printf("Value of shared variable by Thread1 = %d\n", x);

    return NULL;
}

void *fun2()
{
    int y;
    y = shared;
    printf("Thread2 reads the shared = %d\n", y);
    y--;
    printf("Local updation by thread2 = %d\n", y);
    
    shared = y;
    printf("Value of shared variable by Thread2 = %d\n", y);

    return NULL;
}
