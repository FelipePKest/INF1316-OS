<<<<<<< HEAD
typedef struct tablepage TP;
=======
// // typedef struct frame Frame;
typedef struct tablepage {
    Pagina page;
    char R;
    char F;
    struct timeval lastUse; //??
    // Frame frame;
} TP;
// typedef struct queue Queue;
>>>>>>> 98b7cb44d7c7e92f729698575c6c184a7917ab67
