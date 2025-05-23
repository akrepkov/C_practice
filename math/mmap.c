#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	struct stat sb;
	char *addr;

	int fd = open("test.txt", O_RDWR);
	fstat(fd, &sb);
	long long size =  (long long)sb.st_size;
	addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	write(1, addr, size);
	munmap(addr, size);
}

