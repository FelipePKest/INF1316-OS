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

char randomLetter();

int main (int argc, char * argv[]){

    char *string;
    int segmento,semId;

    
    semId = semget(8752,1, 0666 | IPC_CREAT);
	setSemValue(semId);
	
    if (semId == -1) {
        puts("Semaforo com erro");
        exit(-1);
    }
    // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
    segmento = shmget(8000, sizeof (char)*64, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    
    string = (char *) shmat(segmento, 0,0);

    
    if (fork() != 0) {	
		printf("Processo produtor iniciado\n");

		for (int i = 0; i < 64; i++) {
        	semaforoP(semId);
			string[i] = randomLetter();
			semaforoV(semId);
		}

		printf("Processo produtor encerrado\n");
	} else {	
		printf("Processo consumidor iniciado \n");

		for (int i = 0; i < 64; i++) {
			semaforoP(semId);
			printf("\nPRODUZ: %c\n", string[i]);
        	semaforoV(semId);
		}

		printf("\n=== Processo consumidor encerrado ===\n");
	}

	shmdt (string);
	shmctl (segmento, IPC_RMID, 0);
	
    delSemValue(semId);

	return 0;
}

char randomLetter() {
	 return 'A' + (random() % 26);
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

