struct No{
    int num;
    struct No *esq;
    struct No *dir;
};
typedef struct No no;
typedef no *ArvBin;

ArvBin* criarArvBin(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    else{
        printf("Erro na alocação....\n");
        exit(0);
    }
    return raiz;
    }