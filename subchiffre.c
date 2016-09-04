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
	char buf[3];
	printf("Enter your Key: (0-26)\n");
	fgets(buf,sizeof(buf),stdin);
	KEY=atoi(buf);
	scanf("%c",&buf[0]);
	printf("Enter your text: (A-z)\n");
	fgets(inputBuf,SIZE,stdin);
	stringEncryption(inputBuf);
}

void decryptionStart()
{
	char buf[3];
	printf("Enter your Key: (0-26)\n");
	fgets(buf,sizeof(buf),stdin);
	KEY=atoi(buf);
	scanf("%c",&buf[0]);
	printf("Enter your text: (A-z)\n");
	fgets(inputBuf,SIZE,stdin);
	stringDecryption(inputBuf);
}

int getSize(char string[])
{
	int counter=0;
	while(string[counter]!='\0')
		counter++;
	return counter;
}

void menu()
{
	char in[2];
	int chose;
	printf("======================\n");
	printf("Welcome to Substition-Chiffre\n");
	printf("Please Chose:\n");
	printf("1 - Encryption\n");
	printf("2 - Decryption\n");
	printf("0 - End\n");
	scanf("%d",&chose);
	fgets(in,2,stdin);
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
