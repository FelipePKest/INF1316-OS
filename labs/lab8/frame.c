#include <sys/time.h>

#include "frame.h"

struct frame {
    char most_sig;
    char M;
    int num_page;
    struct timeval lastUse;
};

Frame * create_frame(char most, int num_page) { 
    Frame f;
    f.most_sig = most;
    f.num_page = num_page;
    // f.lastUse = 0;
    return &f;
}

struct TabelaPagina {
    char envio_memoria_fisica;
    char foi_acessado;
    char permissao;
    char TaNaMemoriaAgora;
    Frame f;
};