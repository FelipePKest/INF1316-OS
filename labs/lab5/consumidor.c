#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include  <sys/ipc.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char *p;
    int segmento;
    // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
    segmento = shmget(8000, sizeof (char)*900, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    // associa a memória compartilhada ao processo
    p = (char *) shmat (segmento, 0, 0); // comparar o retorno com -1

    if (p == -1) {
        // falha em attach o processo
        puts("Erro no attach da memoria");
        exit(1);
    }
    *p = 'A';

    puts(p);
    // libera a memória compartilhada do processo
    if (shmdt(p)==-1) {
        // falha na liberacao da memoria
        puts("Falha em shmdt");
        exit(2);
    }
    // libera a memória compartilhada
	if (shmctl(segmento,IPC_RMID,0)==-1) {
        // falha na liberacao da memoria
        puts("Falha em shmctl");
		exit(3);
    }
    return 0;
}


