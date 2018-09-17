#include <pthread.h> 
#include <stdio.h>

/* This is an example of synchronous threads. Synchronous threading occurs when 
the parent thread creates one or more children and then must wait for all of its 
children to terminate before it resumes —the so-called fork-join strategy. Here, 
the threads created by the parent perform work concurrently, but the parent cannot
continue until this work has been completed.*/

int sum; /* this data is shared by the thread(s).*/  // clearly its outside of main.

void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{ 

	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */


   	if (argc != 2) {
		fprintf(stderr,"usage: a.out <integer value>\n"); 
		return -1;
	}
	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"%d must be >= 0\n", atoi(argv[1])); 
		return -1;
	}

	/* get the default attributes */
	/* We set the attributes in the function call pthread attr init(&attr). Because we 
	dont explicitly set any attributes here, we use the default attributes provided*/
	pthread_attr_init(&attr);

	/* create the thread */
	/* In addition to passing the thread identifier and the attributes for the thread, 
	we also pass the name of the function where the new thread will begin execution — 
	in this case, the runner() function. Last, we pass the integer parameter that was 
	provided on the command line, argv[1].*/
	pthread_create(&tid, &attr,runner,argv[1]); 

	/* wait for the thread to exit */
 	/* after creating the summation thread, the parent thread will wait for it to 
 	terminate by calling the pthread_join() function.*/
	pthread_join(tid,NULL); 
	printf("sum = %d\n",sum);
}

/* The thread will begin control in this function */
void *runner(void *param) { 
	int i, upper = atoi(param); 
	sum = 0;
	for (i = 1; i <= upper; i++)
	       sum += i;
	pthread_exit(0);
}

/* A simple method for waiting on several threads using the pthread join() function 
is to enclose the operation within a simple for loop. Below an array of threads to be joined upon 
 
 pthread_t workers[10];
 for (int i = 0; i < 10; i++) 
 pthread join(workers[i], NULL);

*/
/*
Data sharing between threads occurs easily in Windows and Pthreads, since shared data are simply 
declared globally. As a pure object-oriented language, Java has no such notion of global data. If 
two or more threads are to share data in a Java program, the sharing occurs by passing references to 
the shared object to the appropriate threads. 
*/


