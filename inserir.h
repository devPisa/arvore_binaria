int inserir(ArvBin* raiz){
    no *novo=(no *) malloc(sizeof(no));
    if(novo == NULL){
        printf("Sem memoria disponivel!\n");
        exit(0);
    }

    printf("Novo elemento: ");
    scanf("%d", &novo->num);
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL) {
        *raiz = novo;
    }
    else{
        no *atual = *raiz;
        no *ant = NULL;
        while (atual != NULL){
            ant = atual;
            if(novo->num == atual->num){
                printf("Elemento já existe...");
                free(novo);
                return 0;
            }
            if(novo->num > atual->num){
                atual = atual->dir;
            }
            else{
                atual = atual->esq;
            }
        }
        if(novo->num > ant->num){
            ant ->dir = novo;
        }
        else {
            ant->esq = novo;
        }
    }
}