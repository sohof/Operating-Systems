#include <pthread.h> 
#include <stdio.h>
#define NR_OF_THREADS 10
/* This is an example of asynchronous threads.*/
int sum=0; /* this data is shared by the thread(s). But not used in this ex.*/  
/* threads call this function */
/* The thread will begin control in this function */
void *print_hello(void * tid) {

	printf("Hello world. Greeetings from thread %d\n", tid);
	pthread_exit(0);
} 

int main(int argc, char *argv[])
{ 

	pthread_t threads[NR_OF_THREADS]; /* array of thread identifiers */
	pthread_attr_t attr; /* set of thread attributes */
	/* We set the attributes in the function call pthread attr init(&attr). Because we 
	dont explicitly set any attributes here, we use the default attributes provided. 
	OR AS IN THIS CASE we just send NULL as a parameter to pthread_create instead of sending attr"*/
	pthread_attr_init(&attr); 

	int status;
	for (int i=0; i<NR_OF_THREADS; i++) {

		printf("Main here. Creating thread %d\n",i);
		status = pthread_create(&threads[i],NULL,print_hello,(void *)i); 
		// returns 0 to status if everything went ok.

		if (status !=0) {
			printf("Oops pthread_create returned error code %d\n",status);
		}
	}

}
