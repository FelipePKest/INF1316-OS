#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int segmento; 
	char letters[80];
	char * dest;
	// segmento = shmget (7000, sizeof (char *), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	// associa a memória compartilhada ao processo
	// letters = (char *) shmat (segmento, 0, 0); // comparar o retorno com -1
	strcpy(letters,"Hello World");
	dest = letters;
	printf("%s \n",dest);
	// libera a memória compartilhada do processo
	// shmdt (letters);
    return 0;
}