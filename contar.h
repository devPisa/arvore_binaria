int contar(ArvBin *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int altura_dir = 0, altura_esq = 0;
        altura(raiz, &altura_dir, &altura_esq);
        return max(altura_dir, altura_esq);
    }
}