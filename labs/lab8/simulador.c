#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "page.h"
#include "frame.h"

int calculate_shift_value(int size) {
    int s = 10;
    while (size != 1) {
        s++;
        size >>= 1;
    }
    return s;
}

Pagina initPage(unsigned int addr, int tam_pag) {
    Pagina page;
    int s;

    // Calcula tamanho do shift baseado no tamanho da pagina recebida como parametro do programa
    s = calculate_shift_value(tam_pag);

    // Numero da pagina a ser encontrada
    page.n_page = addr >> s;
    page.inMemory = 0; // falso
    return page;
}

int checkQueueEmpty(TP queue[], int size) {
    int i;
    int index = -1;
    for(i=0; i <= size; i++) {
        if(queue->F == 0) {

        }
        if(queue->page.inMemory == -1){
            index = 1;
            break;
        }
        queue+=sizeof(TP); 
    }
    return index;
}

void LRU(TP *queue, int size, int *memory,int tam_mem) {
    int index;
    int i;
    for(i = 0; i <= tam_mem; i++){
        if(queue[memory[i]].page->inMemory == 0){
            // TODO: Implement this
            // index = checkLatestUse(TP *queue, int size);
            memory[i] = queue->page.n_page;
        }
        queue+=sizeof(TP); 
    }

}

void NRU(TP *queue, int sizememory, int tam_mem){
    int index;
    int i;
    for(i = 0; i <= sizememory; i++){

    }    
}

void NOVO(TP *queue, int size){
    int index;
    int i;
    for(i = 0; i <= size; i++){

    }
}




int main(int argc, char * argv[]) {
    int i = 0;

    if (argc != 5) {
        puts("Argumentos errados");
        exit(-1);
    }

    // Argumentos recebidos como input do usuario
    char * alg = argv[1];
    char * filename = argv[2];
    int tam_pag = atoi(argv[3]);
    int tam_mem = atoi(argv[4]);
    if(tam_pag < 8 || tam_pag > 32) {
		printf("Tamanho de pagina deve ser entre 8 e 32KB.\n");
	}
	if(tam_mem < 128 || tam_mem > 16384) {
		printf("Tamanho de memoria fisica deve ser entre 128KB e 16MB.\n");
	}
	if(strcmp(alg, "LRU") && strcmp(alg, "NRU") && strcmp(alg, "NOVO")) {
		printf("Algoritmo incorreto.\n");
	}

    int queue_size = tam_mem/tam_pag;
    TP queue[queue_size];
    tam_mem = tam_mem*1024;
    int memory[tam_mem];

    // Verificacao de READ/WRITE
    char rw;
    unsigned int addr;

    // Variaveis para analise
	int time = 0;
	int nPageFaults = 0;
	int nWritten = 0;
    int nRead = 0;


    // Lendo o arquivo recebido como input do programa
    FILE * file = fopen(filename,"r");

    if (file == NULL) {
        puts("File not found");
        exit(-1);
    }

    // lendo o arquivo recebido como parametro
    while (fscanf(file, "%x %c ", &addr, &rw) == 2) {

        if (rw = 'R') {
            nRead++;
            queue[i].R = 1;
            queue[i].F = 0;
        }
        else{
            nWritten++;
            queue[i].F = 1;
            queue[i].R = 0;
        }
        queue[i].page = initPage(addr, tam_pag);     
        i++;
    }
    if(alg = "LRU"){
        LRU(queue, queue_size,memory, tam_mem);
            
    }
    else if(alg = "NRU"){
        NRU(queue, queue_size,memory);
            
    }
    else{ // NOVO
        NOVO(queue, queue_size);
    }   

    return 0;
}