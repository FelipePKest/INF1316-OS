#include<stdio.h>
#include<unistd.h>

int main() {
   int fds[2];
   int pid;
   char escrita[2][20]={"OI", "Tchau"};
   char mensagem[20];
   if (pipe(fds) == -1) {
      puts("Erro ao criar pipe");
      return 1;
   }
   pid = fork();
   
   // Processo consumidor
   if (pid == 0) {
      read(fds[0], mensagem, sizeof(mensagem));
      printf("Consumidor - Lendo – Mensagem 1 %s\n", mensagem);
      read(fds[0], mensagem, sizeof(mensagem));
      printf("Consumidor - Lendo – Mensage 2  %s\n", mensagem);
   } else { 
    // Produtor
      printf("Produtor  - Escrevendo - Mensagem 1 %s\n", escrita[0]);
      write(fds[1], escrita[0], sizeof(escrita[0]));
      printf("Produtor - Escrevendo - Mensagem 2 %s\n", escrita[1]);
      write(fds[1], escrita[1], sizeof(escrita[1]));
   }
   return 0;
}