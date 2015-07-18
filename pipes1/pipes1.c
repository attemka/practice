#include <stdio.h>
#include <unistd.h>

int main() {

int pipemas[2];
int pid;
char data[5];
size_t size;
printf("parrent id = %d\n", getpid());

if(pipe(pipemas) < 0)
	{
		printf("Pipe error\n");
		exit(-1);
	}

	switch(pid=fork() ){
	case -1:

	printf("Fork error\n");
	exit(-1);

	case 0:
	printf("Child process ID after fork %d\n", getpid());
	printf("Enter data\n");
	scanf("%s", &data);
	size=write(pipemas[1], data, 5);
		if(size != 5){
				printf("Can't write\n");
				exit(-1);
			}
		else
			printf("Child exit\n");
	 

	default:
	printf("Parent ID after Fork %d\n", getpid());
	size = read(pipemas[0], data, 5);
	if(size < 0){
				printf("Can't read\n");
				exit(-1);
			}
	printf("Parrent exit\n"); 
	printf("Data = %s\n", data);
	}

}
