#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include  <sys/ipc.h>
#include <unistd.h>

#define NUM_THREADS 8

void soma_no_vetor(int * vet, int indice_inicial) {
  int i = indice_inicial;
  for (i;i<(indice_inicial+1024/NUM_THREADS);i++) {
    vet[1024]+=vet[i];
  }
}
int main(void) {
  int segmento, *p, id, pid, status;
  // aloca a memória compartilhada com o tamanho do vetor de 900 inteiros
  segmento = shmget(IPC_PRIVATE, sizeof (int)*1025, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
  // associa a memória compartilhada ao processo
  p = (int *) shmat (segmento, 0, 0); // comparar o retorno com -1
  pthread_t threads[NUM_THREADS];
  
  int t;

  srand(time(0));
      
  // preencher o vetor com numeros aleatorios
  for (int i = 0;i<1024;i++) {
    p[i] = rand()%256;
  }

  for (int t;t<NUM_THREADS;t++) {
    pthread_create(&threads[t],NULL,soma_no_vetor,p,t*(1024/NUM_THREADS));
  }

  return 0;

} 