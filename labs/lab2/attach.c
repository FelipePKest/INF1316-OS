#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
	char *p,aux[80];
	int segmento;
	// aloca a memória compartilhada
	segmento = shmget (7000, sizeof(char)*80, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IROTH );
	p = (char *) shmat(segmento, 0, 0); // comparar o retorno com -1
	printf("Insira uma mensagem do dia:\n");
	scanf("%[^\n]", p);
	sleep(20);
	// libera a memória compartilhada do processo
	puts(p);
	shmdt(p);
}