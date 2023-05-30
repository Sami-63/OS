#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg){
	printf("Inside thread\n");
}

int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, thread_function, NULL);
	pthread_join(thread, NULL);

	printf("Inside main");


	return 0;
}