#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main() {
	char buf1[17] = "abcdefghijklmnop", buf2[17] = "ABCDEFGHIJKLMNOP";
	int fp = open("Hole.txt", O_RDWR|O_CREAT|O_EXCL, 0755);
	write(fp, buf1, 16);
	lseek(fp, 48L, SEEK_SET);
	write(fp, buf2, 16);
	close(fp);
	system("less Hole.txt");
	return 0;
}
