#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include  <sys/ipc.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int segmento, *p, id, pid, status;
    // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
    segmento = shmget(8000, sizeof (int)*900, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    // associa a memória compartilhada ao processo
    p = (int *) shmat (segmento, 0, 0); // comparar o retorno com -1
    // inserindo seed no RNG (Random Number Generator)
    srand(time(0));
    if (p == -1) {
        // falha em attach o processo
        puts("Erro no attach da memoria");
    }
    if ((id = fork()) < 0) {
        puts ("Erro na criação do novo processo");
        exit (-2);
    } else if (id != 0) {
        // processo pai
        for (int i = 0;i<300;i++) {
            if (i%100==99) {
                // criar os filhos
                if (fork() == 0) {
                    // criou filho
                    switch (i%3) {
                    case 0:
                        // primeiro filho (600-699)
                        for (int j = 0; j<100;j++) {
                            p[j+600] = p[j]+p[j+300];
                        }
                        exit(status);
                    case 1:
                        // segundo filho (700-799)
                        for (int j = 100; j<200;j++) {
                            p[j+600] = p[j]+p[j+300];
                        }
                        exit(status);
                    case 2:
                        // terceiro filho (800-899)
                        for (int j = 200; j<300;j++) {
                            p[j+600] = p[j]+p[j+300];
                        }
                        exit(status);
                    }
                }
            }
            // Limitando o valor ate 1000 para nao gerar overflow
            p[i] = rand()%1000;
            p[i+300] = rand()%1000;
        }
        pid = wait (&status);

        for (int i = 0;i<300;i++) {
            printf("vector %d pos %d = %d \n",1,i,p[i]);
            printf("vector %d pos %d = %d \n",2,i,p[i+300]);
            printf("vector %d pos %d = %d \n",3,i,p[i+600]);                        
        }
    }
    // libera a memória compartilhada do processo
    if (shmdt(p)==-1) {
        // falha na liberacao da memoria
        puts("Falha na liberacao de memoria");
    }
    // libera a memória compartilhada
    shmctl(segmento, IPC_RMID, 0);
    return 0;
}


