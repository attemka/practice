#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 3

pthread_cond_t cond;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int tmp = 1;

void *threadwork (void *num){
	long t_num;
	t_num = (long) num;

	pthread_mutex_lock(&mut);
	tmp++;
        pthread_mutex_unlock(&mut); 
	sleep (tmp);
	printf("thread %ld,finished work\n", t_num);
	pthread_mutex_lock(&mutex1);
	if (tmp != 1 + NUM_THREADS){
        	pthread_cond_wait(&cond, &mutex1);
	}
	else{
		pthread_mutex_unlock(&mutex1); 
		pthread_cond_broadcast(&cond);
	}	
}


int main () {
    pthread_cond_init(&cond, NULL);
    pthread_t threads[NUM_THREADS];
    int k, i;

    for(i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        k = pthread_create(&threads[t], NULL, threadwork, (void*) i);
        if (k) {
            printf("error creating thread  %d\n", k);
            exit(-1);
        }
    }

    for(i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[t], NULL);
        printf("Thread %d finished work \n", i);
    }
return 0;
}
