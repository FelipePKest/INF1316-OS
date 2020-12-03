// // typedef struct frame Frame;
typedef struct tablepage {
    Pagina page;
    char R;
    char F;
    struct timeval lastUse; //??
    // Frame frame;
} TP;
// typedef struct queue Queue;