/* Exemplo de uso de semáforo*/

#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

union semun
{
	int val;
	struct semid_ds *buf;
	ushort *array;
};

// inicializa o valor do semáforo
int setSemValue(int semId);
// remove o semáforo
void delSemValue(int semId);
// operação P
int semaforoP(int semId);
//operação V
int semaforoV(int semId);


int main (int argc, char * argv[]){

	int i,status,*p,segmento;
	int semId;
	// aloca a memória compartilhada
	segmento = shmget (8000, sizeof (int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	// associa a memória compartilhada ao processo
	p = (int*) shmat (segmento, 0, 0); // comparar o retorno com -1

    semId = semget (8752, 1, 0666 | IPC_CREAT);

	// *p=0;
		
	}
	
	// libera a memória compartilhada do processo
	shmdt (p);
	// libera a memória compartilhada
	shmctl (segmento, IPC_RMID, 0);
	return 0;
}

int setSemValue(int semId)
{
	union semun semUnion;
	semUnion.val = 1;
	return semctl(semId, 0, SETVAL, semUnion);
}
void delSemValue(int semId)
{
	union semun semUnion;
	semctl(semId, 0, IPC_RMID, semUnion);
}
int semaforoP(int semId)
{
	struct sembuf semB;
	semB.sem_num = 0;
	semB.sem_op = -1;
	semB.sem_flg = SEM_UNDO;
	semop(semId, &semB, 1);
	return 0;
}
int semaforoV(int semId)
{
	struct sembuf semB;
	semB.sem_num = 0;
	semB.sem_op = 1;
	semB.sem_flg = SEM_UNDO;
	semop(semId, &semB, 1);
	return 0;
}

