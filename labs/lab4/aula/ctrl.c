#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void quitHandler(int sinal);
void intHandler(int sinal);

int main(void) {
  void (*p) (int);
  p = signal(SIGINT,intHandler);
  printf("Endereco do manipulador anterior %p\n",p);
  p = signal(SIGQUIT,quitHandler);
  for(;;);
}

void intHandler(int sinal) {
  printf("Ctrl C desabilitado (%d)\n",sinal);
}

void quitHandler(int sinal) {
  puts("Terminando processo");
  exit(0);
}