#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define TEMPO 10

void killHandler(int sinal);

int main(void) {
  void (*p) (int);
  p = signal(SIGKILL,killHandler);
  printf("Endereco do manipulador anterior %p\n",p);
  printf("pid %d\n",getpid());
  for(;;);
}

void killHandler(int sinal) {
  printf("Interceptado KILL (%d)\n",sinal);
  exit(0);
}