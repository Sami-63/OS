#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *fun1();
void *fun2();

int shared = 1;
sem_t s; // semaphore 

int main(){

    sem_init(&s, 0, 1);

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
    sem_wait(&s);

    x = shared;
    printf("Thread1 reads the shared = %d\n", x);
    x++;
    printf("Local updation by thread1 = %d\n", x);
    sleep(2);
    shared = x;
    printf("Value of shared variable by Thread1 = %d\n", x);

    sem_post(&s);

    return NULL;
}

void *fun2()
{
    int y;
    sem_wait(&s);

    y = shared;
    printf("Thread2 reads the shared = %d\n", y);
    y--;
    printf("Local updation by thread2 = %d\n", y);
    sleep(2);
    shared = y;
    printf("Value of shared variable by Thread2 = %d\n", y);

    sem_post(&s);

    return NULL;
}
