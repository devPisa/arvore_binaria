void liberar(no *no_libera){
    if(no_libera == NULL){
        return
    }
}else {
    libera_NO(no_libera->esq);
    libera_NO(no_libera->dir);
    free(no_libera);
}
int libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        libera_NO(*raiz);
    }
    free(raiz);
}