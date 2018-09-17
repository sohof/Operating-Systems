#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>


int main(int argc, char *argv[]) 
{

	pid_t pid;
	int value = 20;
	pid = fork();

	if (pid < 0) {

		fprintf(stderr, "%s\n", "Fork failed" );
		return 1;
	}

	else if (pid == 0) { // child process
		//execlp("/bin/ls","ls",NULL);

		value += 5;
		printf("%s %d\n", "Child value ", value );
		 
	}
	else {

		wait(NULL);

		printf("%s %d\n", "Parent here: Value is ", value);

	}


	return(0); 

}