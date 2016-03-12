#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main() {
	int  wt;
	char cmd[20];
	pid_t pid;

	pid = fork();

	if(pid < 0) {

	}else if(pid) {
		wait(&wt);

		puts("Parent Process\n");
		printf("PID  : %d\n", getpid());
		printf("PPID : %d\n", getppid());

		puts("");
	}else {
		puts("Child Process\n");
		printf("PID  : %d\n", getpid());
		printf("PPID : %d\n", getppid());

		puts("");

		printf("Enter a cmd>");
		gets(cmd);
		system(cmd);
	
		puts("");
	}

	return 0;
}
