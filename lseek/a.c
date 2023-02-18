#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	int n, f, f1;
	char buf[50];
	f = open("seek.txt", O_RDWR);
	read(f, buf, 10);
	write(1, buf, 10);
	lseek(f, 10, SEEK_CUR);
	read(f, buf, 10);
	write(1, buf, 10);

	write(1, "\n", 1);

	return 0;
}
