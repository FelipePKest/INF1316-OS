#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int joga_dado();

int main(void) {
    srand(time(NULL));
    int espera,pontos_jog1 = 0,pontos_jog2 = 0,pontos_jog3 = 0,pontos_jog4 = 0,pontos_jog5 = 0;
    int dado = joga_dado();
    int childpids[5];
    printf("%d \n",dado);
    
    // cria jogadores 
    for (int jogador = 0; jogador < 5; jogador++) {
        if (fork() < 0) {
            puts('Erro na criacao do fork');
            exit(-1);
        } else if (fork() == 0) {
            // Para a execycao do filho
            childpids[jogador] = getpid();
            raise(SIGSTOP);
        } 
    } 

    for (int i = 0; i < 5; i++) {
        // Continua a execucao dos jogadores
        kill(childpids[i],SIGCONT);
    }


    // enquanto ninguem ganhou
    while (pontos_jog1 < 30 || pontos_jog2 < 30 || pontos_jog3 < 30 || pontos_jog4 < 30 || pontos_jog5 < 30) {
        
    }
    return 0;
}

int joga_dado() {
    return (rand()%6)+1;
}


void rodada(int *p1,int *p2,int *p3, int *p4, int *p5) {
    
    return;
}