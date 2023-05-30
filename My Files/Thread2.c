#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg){
	printf("Inside thread\n");

	int *num = arg;
	int a = num[0];
	int b = num[1];
	int c = num[2];

	printf("a = %d, b = %d, c = %d and sum = %d\n", a, b, c, a+b+c);

	pthread_exit("Task complete\n");
}

int main() {
	pthread_t thread;
	void *result;
	int num[3] = {1,2,3};

	pthread_create(&thread, NULL, thread_function, (void *)num);
	pthread_join(thread, &result);

	printf("Inside main... Return from thread -> %s\n", (char *)result);


	return 0;
}