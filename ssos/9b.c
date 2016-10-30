#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main() {
	int  wt;
	pid_t pid;

	pid = fork();

	if(pid < 0) {
		printf("ERROR : Child not created!\n");
		return 1;
	}else if(pid) {
		wait(&wt);

		puts("Parent Process\n");
		printf("PID  : %d\n", getpid());
		printf("Child PID : %d\n", pid);

		puts("");
	}else {
		puts("Child Process\n");
		printf("PID  : %d\n", getpid());
		printf("PPID : %d\n", getppid());

		puts("");
	}

	return 0;
}
