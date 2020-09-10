#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int segmento, *p, id, pid, status;
    // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
    segmento = shmget (IPC_PRIVATE, sizeof (int)*900, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    // associa a memória compartilhada ao processo
    p = (int *) shmat (segmento, 0, 0); // comparar o retorno com -1
    if ((id = fork()) < 0) {
        puts ("Erro na criação do novo processo");
        exit (-2);
    } else if (id == 0) {
        // primeiro filho
        
    } else {
        for (int i = 0;i<300;i++) {
            if (i%100==99) {
                // criar os filhos
            }
            p[i] = rand();
            p[i+300] = rand();
        }
        pid = wait (&status);

        for (int i = 0;i<300;i++) {
            printf("vector %d pos %d = %d \n",1,i,p[i]);
            printf("vector %d pos %d = %d \n",2,i,p[i+300]);
            // printf("vector %d pos %d = %d \n",3,i,p[i+600]);                        
        }
    }
    // libera a memória compartilhada do processo
    shmdt (p);
    // libera a memória compartilhada
    shmctl (segmento, IPC_RMID, 0);
    return 0;
}


