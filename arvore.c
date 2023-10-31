// Definições das estruturas e funções aqui...

int main() {
    ArvBin *raiz = criaArvore();
    int opc, cont, altdir = 0, altesq = 0;

    do {
        printf("\nMenu de Operações:\n");
        printf("1 - Inserir elemento na árvore\n");
        printf("2 - Imprimir árvore em Pré-Ordem\n");
        printf("3 - Imprimir árvore em Ordem\n");
        printf("4 - Imprimir árvore em Pós-Ordem\n");
        printf("5 - Contar\n");
        printf("6 - Contar altura\n");
        printf("7 - Remover no\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                insere_raiz(raiz);
                break;
            case 2:
                printf("Árvore em Pré-Ordem:\n");
                imprime_PreOrd(raiz);
                break;
            case 3:
                printf("Árvore em Ordem:\n");
                imprime_InOrd(raiz);
                break;
            case 4:
                printf("Árvore em Pós-Ordem:\n");
                imprime_PosOrd(raiz);
                break;
            case 5:
                printf("Contando...\n");
                cont = contar_nos(raiz);
                printf("\nQuantidade de nos: %i\n", cont);
                break;
            case 6:
                printf("Contando...\n");
                cont = cont_altura(raiz);
                printf("Altura = %i", cont);
                break;
            case 7:
                printf("Remover nó\n");
                remove_no(raiz);
                break;
            case 8:
                printf("Saindo\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opc != 8);

    libera_arvore(raiz);

    return 0;
}