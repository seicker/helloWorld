#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 999
#define PATH1 "/root/helloWorld/krypto/chiffrat.txt"
#define PATH2 "/home/simon/helloWorld/krypto/chiffrat.txt"

struct letter{
	int let;
	int cou;
	double rel;
};

char input[MAX];
struct letter letters[26];
void countLetter();
void getChiffrat();
void init();
void print();

void countLetter()
{
	int i,tmp,sum=0;
	double temp;
	for(i=0;i<MAX;i++)
	{
		if(input[i]>64&&input[i]<91)
		{
			tmp=input[i]-65;
			letters[tmp].cou++;
			sum++;
		}
	}
	for(i=0;i<26;i++)
	{
		temp=0;
		temp=(((double)letters[i].cou/sum)*100);
		letters[i].rel=temp;
	}
	print();
}

void print()
{
	int i;
	for(i=0;i<26;i++)
		printf("%c %i =  %lf\n",letters[i].let, letters[i].cou,letters[i].rel);
}

void getChiffrat()
{
	int io,ir;
	if((io=open(PATH1,O_RDONLY))==-1)
		if((io=open(PATH2,O_RDONLY))==-1)
			perror("cannot open chiffrat.txt\n");
	if((ir=read(io,input,MAX))==-1)
		perror("cannot read chiffrat.txt\n");
	close(ir);
	close(io);
	init();
	countLetter();
}

void init()
{
	int i;
	for(i=0;i<26;i++)
	{
		letters[i].let=65+i;
		letters[i].cou=0;
		letters[i].rel=0;
	}
}


int main()
{
	getChiffrat();
	//printf("%s \n",input);
}
