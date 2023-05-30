#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *fun1();
void *fun2();

int shared = 1;
pthread_mutex_t m; // mutex lock

int main(){

    pthread_mutex_init(&m, NULL);

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

    printf("Thread1 is trying to acuire the lock\n");
    pthread_mutex_lock(&m);
    printf("Thread1 acuired the lock\n");

    x = shared;
    printf("Thread1 reads the shared = %d\n", x);
    x++;
    printf("Local updation by thread1 = %d\n", x);
    sleep(2);
    shared = x;
    printf("Value of shared variable by Thread1 = %d\n", x);

    pthread_mutex_unlock(&m);
    printf("Thread1 releases the lock\n");

    return NULL;
}

void *fun2()
{
    int y;
    printf("Thread2 is trying to acuire the lock\n");
    pthread_mutex_lock(&m);
    printf("Thread2 acuired the lock\n");

    y = shared;
    printf("Thread2 reads the shared = %d\n", y);
    y--;
    printf("Local updation by thread2 = %d\n", y);
    sleep(2);
    shared = y;
    printf("Value of shared variable by Thread2 = %d\n", y);

    pthread_mutex_unlock(&m);
    printf("Thread2 releases the lock\n");

    return NULL;
}
