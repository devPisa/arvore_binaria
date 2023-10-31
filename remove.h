void remover_folha(no *no_print, no *ant){
    if(ant->num > no_print->num){
        ant->esq = NULL;
        free(no_print);
    }else{
        ant->dir = NULL;
        free(no_print);
    }
}

void remover_umFilho(no *no_print, no *ant){
    if(ant->num > no_print->num){
        if(no_print->dir != NULL){
            ant->esq = no_print->dir;
            free(no_print);
        }else{
            ant->esq = no_print->esq;
            free(no_print);
        }
    }else{
        if(no_print->dir != NULL){
            ant->dir = no_print->dir;
            free(no_print);
        }else{
            ant->dir = no_print->esq;
            free(no_print);
        }   
    }
}

void remover_interno(no *no_print, no *ant){
    no *atual2; 
    no *anterior2;
    atual2 = no_print->esq;
    anterior2 = no_print->esq;
    printf("passei");
    while(atual2->dir != NULL){
        anterior2 = atual2;
        printf("Atual num %i", atual2->num);
        atual2 = atual2->dir;
    }
    printf("passei2");
    anterior2->dir = NULL;
    atual2->dir = no_print->dir;
    if(atual2 == no_print->esq){
        atual2->esq = NULL;
    }else{
        atual2->esq = no_print->esq;
    }
    if(ant->num > no_print->num){
         ant->esq = atual2;
    }else{
        ant->dir = atual2;
    }
    free(no_print);
    return;
}

void acha_no(no *no_print, int remove, no *ant){
    if(no_print == NULL){
        return;
    }else{
        acha_no(no_print->esq, remove, no_print);
        acha_no(no_print->dir, remove, no_print);
        if(no_print->num == remove){
            if(no_print->esq == NULL && no_print->dir == NULL){
                remover_folha(no_print, ant);
                return;
            }else if((no_print->esq == NULL && no_print->dir != NULL) || (no_print->esq != NULL && no_print->dir == NULL)){
                remover_umFilho(no_print, ant);
                return;
            }else{
                remover_interno(no_print, ant);
                return;
            }
        }
    }
}

int remove_no(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        int remove;
        printf("Digite o no a ser removido ");
        scanf("%i", &remove);
        acha_no(*raiz, remove, *raiz);
    }

}