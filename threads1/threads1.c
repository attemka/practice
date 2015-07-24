#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/unistd.h>

#define NUM_THREADS 5

void * thrfunc(void *thread){
	int i;
	for(i=0;i<=5;i++){
		int threadid;
		threadid=pthread_self();
		printf ("%d\n", threadid);
		sleep(1);
	}
}

	
int main (){
	pthread_t threads[NUM_THREADS];
	int thr;
	long tmp;

	for (tmp=0;tmp<NUM_THREADS; tmp++){
		printf ("Starting thread %ld\n",tmp);
		thr = pthread_create(&threads[tmp],NULL,thrfunc, (void *)&tmp);
		if (thr){
			printf("error in thread %d\n",thr);
			exit(-1);
		}
	}

	for (tmp=0;tmp <NUM_THREADS;tmp++){
		pthread_join(threads[tmp],NULL);
		printf("thread #%ld finished\n", tmp);
	}	

	return 0;
}

