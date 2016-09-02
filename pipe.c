#define MAX_ZEICHEN 20
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
	// status ist Returnwert des Syscall wait()
	// fd-array ist parameter für pipe syscall
	int fd[2], status; 
	pid_t pid;
	char string[MAX_ZEICHEN] = "Hallo Welt.\n";
	char output[MAX_ZEICHEN] = "Initialer Output";

	printf("Parent wurde gestartet.\n\n")

	// Pipe erzeugen
	if (pipe(fd) < 0) {
		perror("Kann keine Pipe einrichten");
		exit(EXIT_FAILURE);
	} else {
		printf("Pipe? - Check!\n\n");
	}
	// Child erzeugen
	switch(pid = fork()) {
		/* Forking Error abfragen. */
		case -1:
			perror("Kann keine Pipe einrichten");
			exit(EXIT_FAILURE);
		break;

		printf("Fork() wurde ausgefuehrt.\n\n");
		/* Kindprozess pid==0 liest aus der Pipe */
		case 0: 
			printf("Child wurde gestartet.\n\n");
			// Schreibseite schließen
			close(fd[1]);

			// Von Leseseite in output schreiben
			read(fd[0], output, MAX_ZEICHEN);
			printf("Child hat string aus Lesepipe gelesen.\n");
			printf("Output: %s \n", output);

			return(0);
		break;
		/* Elternprozess: Schreibe in Pipe */
		default:
			printf("Elternprozess schliesst Lesepipe.\n\n");
			close(fd[0]); 	// Leseseite schließen
			// write(wohin, was, groesse)
			// Schreiben des Strings in Schreibseite inkl. Fehlerabfrage
			if((write (fd[1], string, MAX_ZEICHEN)) != MAX_ZEICHEN) {
				perror ("write() failed");
				exit (EXIT_FAILURE);
			} else {
				printf("Parent hat string in Schreibpipe geschrieben.\n");
			}
			// Bleib solang offen bis Kind tot
			if(wait(&status) != pid) {
					perror("wait() failed");
					exit(EXIT_FAILURE);
			}
			exit(0);
		break;
	}
	exit(0);
}
