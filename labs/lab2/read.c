#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int segmento; 
	char * shm_conteudo, cont[80];
	segmento = shmget (7000, sizeof(char)*80, IPC_CREAT | S_IRUSR | S_IWUSR);
	// associa a memória compartilhada ao processo
	shm_conteudo = (char *) shmat (segmento, 0, 0);
	printf("%s \n",shm_conteudo);
	// libera a memória compartilhada do processo
	shmdt (shm_conteudo);
	shmctl(IPC_RMID,0,0);
    return 0;
}