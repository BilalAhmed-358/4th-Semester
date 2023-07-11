#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd1,fd2,fd3, retval1,retval2,retval3;
	char buffer[] = "TESTDATA";
	
	fflush(stdin);
	retval1 = mkfifo("/tmp/myfifo1",0666);
	fd1 = open("/tmp/myfifo1",O_WRONLY);
	write(fd1,buffer,sizeof(buffer));
	close(fd1);

	fflush(stdin);
	retval2 = mkfifo("/tmp/myfifo2",0666);
	fd2 = open("/tmp/myfifo2",O_WRONLY);
	write(fd2,buffer,sizeof(buffer));
	close(fd2);

	fflush(stdin);
	retval3 = mkfifo("/tmp/myfifo3",0666);
	fd3 = open("/tmp/myfifo3",O_WRONLY);
	write(fd3,buffer,sizeof(buffer));
	close(fd3);
	return 0;
}
