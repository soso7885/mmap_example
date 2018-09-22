#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <assert.h>
#include <errno.h>

#define PAGESIZE	4096

const char *modify = "## User modify! ##";

int main(int argc, char **argv)
{
	int fd;
	unsigned char *addr;

	if(argc < 2){
		printf("%s [mmap path]\ndefault is /dev/my_mmap\n", argv[0]);
		return -1;
	}

	fd = open(argv[1], O_RDWR);
	if(fd < 0){
		printf("Open: %s\n", strerror(errno));
		return -1;
	}

	do{
		addr = mmap(NULL, PAGESIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
		if(addr == MAP_FAILED){
			printf("mmap: %s\n", strerror(errno));
			break;
		}

		printf("The initial data in memory: %s\n", addr);
		memcpy(addr+20, modify, strlen(modify));
		printf("The modified data in memory: %s\n", addr);
	}while(0);

	close(fd);

	return 0;
}
