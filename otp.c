//one-time-pad: creates streamkey(pseudo), saves the key and encrypt the input
//		decrypt input

#include <stdio.h>
#include <stdlib.h>
//open()
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//read()
#include <unistd.h>
#define MAX 12
#define PATHFILE "/root/helloWorld/input"

char input[MAX];

void pseudoKey();
void getInput();
void inputToBinary();

void pseudoKey()
{
	printf("Keystream\n");
}

void getInput()
{
	int io,ir;
	if((io=open(PATHFILE,O_RDONLY))==-1)
		perror("cannot open file\n");
	if((ir=read(io,input,MAX))==-1)
		perror("cannot read file\n");
	close(io);
	close(ir);
}



int main()
{
	getInput();
	return 0;
}
