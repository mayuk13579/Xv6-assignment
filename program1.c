#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"
#include "x86.h"

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int main(int argc, char *argv[]) {
	char str[1024];
	int fd;
	int off; 
	unsigned int len;
	int x;	
	
	if(argc != 5) {
		exit();
	}
	fd = open(argv[1], 0);  
	if(fd == -1) {
		printf(0, "%s", "Failed to open file");
		exit();
	}
	off = atoi(argv[2]);  //offset of file which is to be read
	len = atoi(argv[3]);  //length of data to be read
	lseek(fd, off, SEEK_SET);
	x = read(fd, str, len);
	if(x == -1) {
		printf(0, "%s", "Can't read from file\n");
		exit();
	}
	if(strcmp(argv[4], str) == 0) {
		printf(0, "%s", "Given String:");
		printf(0, "%s", argv[4]);
		printf(0, "%s", "\n");
		printf(0, "%s", "String read from file:");
		printf(0, "%s", str);
		printf(0, "%s", "\n");
		printf(0, "%s", "success\n");
	}
	else {
		printf(0, "%s", "Given String:");
		printf(0, "%s", argv[4]);
		printf(0, "%s", "\n");
		printf(0, "%s", "String read from file:");
		printf(0, "%s", str);
		printf(0, "%s", "\n");		
		printf(0, "%s", "not same\n");
	}
	close(fd);  
	exit();
}
