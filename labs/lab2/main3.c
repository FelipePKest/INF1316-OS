#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int segmento, pid,id,status;
	char * p;
	char aux[80];
	// aloca a memória compartilhada
	
	// associa a memória compartilhada ao processo
	if (id = fork() != 0) {
		//pai espera o filho alocar memoria e guardar a mensagem do dia;
		id = wait(&status);
		printf("%s",p);
	} else {
		// filho
		segmento = shmget (7000, sizeof (char)*80, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IROTH );
		p = shmat(segmento,0,0);
		scanf("%s",aux);
		p = aux;
		exit(status);
	}
	// libera a memória compartilhada do processo
	shmdt (p);
	// libera a memória compartilhada
	shmctl (segmento, IPC_RMID, 0);
	return 0;
}