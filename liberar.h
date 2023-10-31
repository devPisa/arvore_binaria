void libera_no(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }else{
        libera_no(no_liberar->esq);
        libera_no(no_liberar->dir);
        free(no_liberar);
    }
}

int libera_arvore(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        libera_no(*raiz);
    }
    free(raiz);
}

void imprime_no_PreOrd(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        printf("%i\n", no_print->num);
        imprime_no_PreOrd(no_print->esq);
        imprime_no_PreOrd(no_print->dir);
    }
}

int imprime_PreOrd(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no_PreOrd(*raiz);
    }
   
}

void imprime_no_InOrd(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        imprime_no_InOrd(no_print->esq);
        printf("%i\n", no_print->num);
        imprime_no_InOrd(no_print->dir);
    }
}

int imprime_InOrd(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no_InOrd(*raiz);
    }
}

void imprime_no_PosOrd(no *no_print){
    if(no_print == NULL){
        return;
    }else{
        imprime_no_PosOrd(no_print->esq);
        imprime_no_PosOrd(no_print->dir);
        printf("%i\n", no_print->num);
    }
}

int imprime_PosOrd(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        imprime_no_PosOrd(*raiz);
    }
}

void contador(no *no_print, int*cont){
    if(no_print == NULL){
        return;
    }else{
        contador(no_print->esq, cont);
        contador(no_print->dir, cont);
        *cont += 1;
    }
}

int contar_nos(ArvBin * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        int cont = 0;
        contador(*raiz, &cont);
        return cont;
    }
}