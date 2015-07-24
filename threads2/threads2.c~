#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/unistd.h>
i=0;

void * thread1func (void *arg){

while (1){
i++;
}
}


void * thread2func (void *arg){i;
while (1){
printf("%d\n", i);
}
}

int main() {
int id1,id2,result;
pthread_t thread1,thread2;

id1=1;
result = pthread_create(&thread1, NULL, thread1func, &id1);
if (result != 0) {
perror("Creating the first thread");
return EXIT_FAILURE;
}
id2 = 2;
result = pthread_create(&thread2, NULL, thread2func, &id2);
if (result != 0) {
perror("Creating the second thread");
return EXIT_FAILURE;
}
result = pthread_join(thread1, NULL);
if (result != 0) {
perror("Joining the first thread");
return EXIT_FAILURE;
}
result = pthread_join(thread2, NULL);
if (result != 0) {
perror("Joining the second thread");
return EXIT_FAILURE;
}
printf("Done\n");
return EXIT_SUCCESS;
}



