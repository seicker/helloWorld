#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#define SIZE 4

struct process{
	int id;
	int queueNr;
	int time;
	int prio;
} process;

struct process plist[SIZE];
int sumTime;

void init();
void fcfs();
void sjf();
void psjf();
void rr();
void prio();
void printTable();
struct process[] bubblesort(struct process p[]);

void printTable()
{
	int i;
	printf("\nprocess-table:\n");
        printf("===============\n");
        printf("ID|Nr|Ti|Pr\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%i  %i  %i  %i\n",plist[i].id,plist[i].queueNr,plist[i].time,plist[i].prio);
	}
}

void init()
{
	int i;
	struct timeval t1;
	sumTime=0;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec*t1.tv_sec);
	for(i=0;i<SIZE;i++)
	{
		plist[i].id=i;
		plist[i].queueNr=i+1;
		plist[i].time=(rand()%9)+1;
		plist[i].prio=(rand()%4)+1;
		sumTime=sumTime+plist[i].time;
	}
	printTable();
}

void fcfs()
{
	int i;
	struct process tmp[SIZE];
	memcpy(&tmp,&plist,sizeof(plist));
	printf("\nFirst Come First Serverd\n");
	for(i=0;i<SIZE;i++)
	{
		while(tmp[i].time>0)
		{
			printf("%d ",tmp[i].id);
			tmp[i].time--;
		}
		printf("| ");
	}
}

void sjf()
{
	struct process tmp[SIZE];
	int i;
	memcpy(&tmp,&plist,sizeof(plist));
	printf("\nShortest Job First\n");
	tmp=bubbleSort(tmp);
	for(i=0;i<SIZE;i++)
	{
		while(tmp[i].time>0)
		{
			printf("%d ",tmp[i].id);
			tmp[i].time--;
		}
		printf("| ");
	}
}

struct process[] bubbleSort(struct process p[])
{
	int elements=SIZE;
	struct process tmp;
	while(elements--)
	{
		for(i=1;i<=elements;i++)
		{
			if(p[i-1].time>p[i].time)
			{
				tmp=p[i];
				p[i]=p[i-1];
				p[i-1]=tmp;
			}
		}
	}
	return tmp;
}

int main()
{
	init();
	fcfs();
	sjf();
	return 0;
}
