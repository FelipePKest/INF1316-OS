// #include <sys/time.h>

#include "frame.h"
#include "page.h"

struct tablepage{
    Pagina pag;
    // pag.n_page = 0;
    // pag.desloc = 0;
    // pag.inMemory = 0;
    int n_frame;
    char inMemory;
    char foi_acessado;
    char permissao;
} TP;


// struct frame {
//     char most_sig;
//     char M;
//     int num_page;
//     struct timeval lastUse;
// };

// Frame * create_frame(char most, int num_page) { 
//     Frame f;
//     f.most_sig = most;
//     f.num_page = num_page;
//     // f.lastUse = 0;
//     return &f;
// }

// struct TabelaPagina {
//     char envio_memoria_fisica;
//     char foi_acessado;
//     char permissao;
//     char TaNaMemoriaAgora;
//     int n_frame;
//     Pagina page;
// } TP;