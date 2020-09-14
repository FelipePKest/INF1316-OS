#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int segmento, *p;
	segmento = shmget (7000, sizeof (char *), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	// associa a memória compartilhada ao processo
	p = (char *) shmat (segmento, 0, 0); // comparar o retorno com -1
	*p = "Mensagem do Dia\n";
	
	// libera a memória compartilhada do processo
	shmdt (p);
    return 0;
}