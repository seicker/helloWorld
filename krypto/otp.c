//one-time-pad: creates streamkey(pseudo), saves the key and encrypt the input
//		decrypt input

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX 999
#define PATHFILE "/root/helloWorld/input"
#define PATHFILE2 "/home/simon/helloWorld/input"

char input[MAX];
int key[MAX];
int chiffre[MAX];
int size;

void pseudoKey();
void getInput();
void inputToBinary();

void pseudoKey()
{
	int i;
	srand(time(NULL));
	for(i=0;i<size;i++)
	{
		if(input[i]!=32)
		{
			if(input[i]>99)
				key[i]=rand()%1000;
			else
				key[i]=rand()%100;
		}
	}
}

void getInput()
{
	int io,ir,i;
	if((io=open(PATHFILE,O_RDONLY))==-1)
		if((io=open(PATHFILE2,O_RDONLY))==-1)
			perror("cannot open file\n");
	if((ir=read(io,input,MAX))==-1)
		perror("cannot read file\n");
	close(io);
	close(ir);
	for(i=0;i<MAX;i++)
	{
		if(input[i]==0)
		{
			size=i-1;
			break;
		}
	}
}

void xor()
{
	int i;
	for(i=0;i<size;i++)
	{
		chiffre[i]=input[i]^key[i];
	}
}

int main()
{
	int i;
	getInput();
	pseudoKey();
	xor();
	for(i=0;i<size;i++)
		printf("%d XOR %d = %c\n",input[i],key[i],chiffre[i]);
	return 0;
}
