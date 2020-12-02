#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <math.h>
#include <stdbool.h>

#include "page.h"
#include "frame.h"

// struct main {
//     /* data */
// };


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
    // Deslocamento
    page.desloc = (addr >> s;) << s;
    // A pagina está na memória?
    page.inMemory = 0; // falso
    return page;
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

    int tam_frame = tam_pag/2;
    TP queue[200]; // tam a calcular

    // Verificacao de READ/WRITE
    char rw;
    unsigned int addr;

    // Variaveis para Tabela de Paginas 

    // Lendo o arquivo recebido como input do programa
    FILE * file = fopen(filename,"r");

    if (file == NULL) {
        puts("File not found");
        exit(-1);
    }

    // lendo o arquivo recebido como parametro
    while (fscanf(file, "%x %c ", &addr, &rw) == 2) {

    //     // if (i == 0) {
    //     //     new_addr = addr;
    //     // } else if (i == 1) {
    //     //     new_addr2 = addr;
    //     // }
    //     // i++;
    //     printf("%d %c\n",addr,rw);
    //     int num_pag = addr >> s;
    //     printf("NUM PAG =  %d\n",num_pag);
    }
    if(alg = "LRU"){ // sepa definir processos com si
    }
    else if(alg = "NRU"){
    }
    else{ // NOVO
    }
    // printf("addr,addr1,addr2 = %d\n",addr,new_addr);
    // printf("page_num = %d\n",num_pag);

    return 0;
}