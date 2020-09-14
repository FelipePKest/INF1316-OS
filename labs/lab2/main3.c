#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int segmento, pid,id,status;
	char *p;
	// aloca a memória compartilhada
	segmento = shmget (7000, sizeof (char *), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	// associa a memória compartilhada ao processo
	if (id = fork() != 0) {
		//pai
		id = wait(&status);
		shmat(segmento,p,0);
	} else {
		puts(p);
	}
	// libera a memória compartilhada do processo
	shmdt (p);
	// libera a memória compartilhada
	shmctl (segmento, IPC_RMID, 0);
	return 0;
}