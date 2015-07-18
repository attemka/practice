#include <stdio.h>
#include <unistd.h>

int main() {

int pipemas[2];
int pid,readfile;
char data[50];
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
	
	readfile= execl("/tmp/", "ls", "-l", (char*)0 );
	if (readfile== -1)
	perror("read error");
	size=write(pipemas[1], readfile, sizeof(readfile));

	default:
	size=read(pipemas[0],data,sizeof(readfile));
	if(size < 0){
				printf("Can't read\n");
				exit(-1);
		    }
	printf("Parrent exit\n"); 
	printf("%s\n", data);
}
}

