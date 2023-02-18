
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){

	int n, f, f1;
	char buf[50];
	f = open("seek.txt", O_RDWR);
	
	f1 = lseek(f, 10, SEEK_SET);
	printf("Pointer is at %d position\n", f1);
	read(f, buf, 10);
	write(1, buf, 10);

	return 0;
}
