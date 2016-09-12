include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

struct process{
	int id;
	int queueNr;
	int time;
	int prio;
} process;

struct process plist[SIZE];

void init();
void fcfs();
void sjf();
void psjf();
void rr();
void prio();

void init()
{
	int i;
	printf("process-table:\n");
	printf(" ID | \n");
	for(i=0;i<SIZE;i++)
	{
		plist[i].id=i;
		plist[i].queueNr=i;
		plist[i].time=rand()%10;
		plist[i].prio=rand()%5;
		printf("%i %i %i %i\n");
	}
}

void fcfs()
{

}

int main()
{
	struct process plist[4];
	plist[0]={1,1,4,1};
	plist[1]={2,2,2,2};
	plist[2]={3,3,8,1};
	plist[3]={4,4,3,2};

	return 0;
}
