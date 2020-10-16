#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
  int pids[] = {};
  printf("Pai = %d\n",getpid());
  for (int i = 0;i<5;i++) {
    printf("%d \n",i);
    if (fork() == 0) {
    // filhos executandos indefinidamente
      pids[i] = getpid();
      printf("Filhos = %d\n",getpid());
    }
  } 

  for (int i = 0; i<10; i++) {
    // trocar contextos 
    if (i%4==3) {
      kill(pids[(i%4)],SIGSTOP);
      kill(pids[0],SIGCONT);
    } else {
      kill(pids[(i%4)],SIGSTOP);
      kill(pids[(i%4)+1],SIGCONT);
    }
  }

  for (int i = 0;i<4;i++) {
    // matar processos
    // kill(pids[i],SIGKILL);
  }

  return 0;
}