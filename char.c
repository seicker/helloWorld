#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 100

void encryption(char *input);
void decryption(char *input);
void stringEncryption(char string[]);
void stringDecryption(char string[]);
int getSize(char string[]);
void menu();
void encryptionStart();
void decryptionStart();


int chose;
int KEY;
char inputBuf[SIZE];
char buf[SIZE];

void encryption(char *input)
{
	if((*input>64) && (*input<91))
	{
		*input=(*input)+KEY;
		if(*input > 90)
			*input=(*input%90)+64;
	}else 
	{
		if((*input>96) && (*input<123))
		{
			*input=*input-32;
			*input=(*input)+KEY;
			if(*input > 90)
				*input=(*input%90)+64;
		}
	}
}

void decryption(char *input)
{
	if((*input>54)&&(*input<91))
	{
		*input=(*input)-KEY;
		if(*input<65)
			*input=91-(65-(*input));
	}
}

void stringEncryption(char string[])
{
	int i,size;
	size=getSize(string);
	printf("Encryption: ");
	for(i=0;i<size;i++)
		encryption(&string[i]);
	printf("%s\n",string);
}

void stringDecryption(char string[])
{
	int i,size;
	size=getSize(string);
	printf("Decryption: ");
	for(i=0;i<size;i++)
		decryption(&string[i]);
	printf("%s\n",string);
}

void encryptionStart()
{
	int in, inbuf[2];
	printf("Enter your Key:\n");
	fgets(inbuf,2,stdin);
	sscanf(buf,"%d",&in);
	printf("Enter your text:\n");
	fgets(buf,SIZE,stdin);
	sscanf(buf,"%c",&inputBuf);
	stringEncryption(inputBuf);
}

void decryptionStart()
{
	printf("decryption\n");
}

int getSize(char string[])
{
	int counter=0;
	while(string[counter]!='\0')
	{
		counter++;
	}
	return counter;
}

void menu()
{
	int chose,bufChose[2];
	printf("======================\n");
	printf("Please Chose:\n");
	printf("1 - Encryption\n");
	printf("2 - Decryption\n");
	printf("0 - End\n");
	fgets(bufChose,2,stdin);
	sscanf(bufChose,"%d",&chose);
	switch(chose)
	{
		case 1: 
			encryptionStart();
			break;
		case 2:
			decryptionStart();
			break;
		case 0:
			printf("Bye\n");
			exit(0);
	}
}

int main()
{
	char string[]="HALLO WELT HALLO WELT HALLO WELT";
	char text[]="Hallo Welt Hallo Welt Hallo Welt";

	while(1)
	{
		menu();
		printf("\n");
	}
	//stringEncryption(string);
	//stringEncryption(text);

	//stringDecryption(string);
	return 0;
}
