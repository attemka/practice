#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/unistd.h>

#define NUM_THREADS 2
int counter=0;
pthread_mutex_t mutex;

void * threadfunc(void *thread){
	int i;
	for(i=0;i<10;i++){
		pthread_mutex_lock(&mutex);
		counter++;
		pthread_mutex_unlock(&mutex);
		sleep(1);
			}
}

void * thread1func(void *thread){
	int i;
	for(i=0;i<10;i++){
		printf ("%d\n", counter);
		sleep(1);
			}
}


int main (){
	pthread_t threads[NUM_THREADS];
	int thread, thread1;
	long tmp;
	printf ("Starting thread 0\n");
	thread = pthread_create(&threads[0],NULL,threadfunc, (void *)0);
	if (thread){
	printf("error in thread 0 %d\n",thread);
	exit(-1);
		}

	printf ("Starting thread 1\n");
	thr1 = pthread_create(&threads[1],NULL,thread1func, (void *)1);
	if (thread1){
	printf("error in thread 1 %d\n",thread);
	exit(-1);
		}


	for (tmp=0;tmp <NUM_THREADS;tmp++){
		pthread_join(threads[tmp],NULL);
		printf("thread #%ld finished\n", tmp);
			}

	return 0;
}
