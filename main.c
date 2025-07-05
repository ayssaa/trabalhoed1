# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "RegistroDeHumor.h"
# include "ListaDuplamenteEncadeada.h"

// 3) Função main para interagir com o usuário (main.c)

void main() {
    int opcao;
    int cont = 0;
    NoLista* lista;
    criarLista(&lista);

    do {
        printf("\n----------------MENU------------------\n");
        printf("1 - Adicionar novo registro\n");
        printf("2 - Remover registro por id\n"); 
        printf("3 - Buscar por humor\n");
        printf("4 - Imprimir todos os registros\n");
        printf("5 - Mostrar média da notaDoDia\n");
        printf("6 - Mostrar humor mais frequente\n");
        printf("7 - Mostrar os motivos do humor\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n--------------------------------------\n");

        switch(opcao) {
            case 1:
                RegistroDeHumor *novo = criarRegistro();

                if(novo == NULL) {
                    printf("Erro ao criar registro. Tente novamente.\n");
                    break;
                }

                inserirElementoFim(&lista, *novo);
                printf("\nRegistro adicionado com sucesso!\n");
                break;
            case 2:
                removerElemento(&lista);
                break;
            case 3:
                buscaElementoPorHumor(&lista);
                break;
            case 4:
                printf("\nImprimindo todos os registros:\n");
                ImprimeListaOrdemDireta(&lista);
                break;
            case 5:
                int dias;

                if (estaVazia(&lista)) {
                    printf("A lista está vazia!\n");
                    break;
                }

                printf("\nInforme quantos dias deseja calcular a média da nota do dia: ");
                scanf("%d", &dias);

                float media = mediaDeNotaDoDia(&lista, dias);

                if (media > 0) {
                    printf("A média das notas dos últimos %d dias é: %.2f\n", dias, media);
                } 
                else {
                    printf("Não há registros suficientes para calcular a média.\n");
                }

                break;
            case 6:
                int diasHumor;

                if (estaVazia(&lista)) {
                    printf("A lista está vazia!\n");
                    break;
                }

                printf("\nInforme quantos dias deseja verificar o humor mais frequente: ");
                scanf("%d", &diasHumor);
                
                Humor humorFreq = humorMaisFreqUltimosDias(&lista, diasHumor);
                if (humorFreq != -1) {
                    printf("O humor mais frequente nos últimos %d dias é: ", diasHumor);
                    switch (humorFreq) {
                        case 0:
                            printf("Feliz\n");
                            break;
                        case 1:
                            printf("Triste\n");
                            break;
                        case 2:
                            printf("Ansioso\n");
                            break;
                        case 3:
                            printf("Cansado\n");
                            break;
                        case 4:
                            printf("Motivado\n");
                            break;
                        case 5:
                            printf("Estressado\n");
                            break;
                        case 6:
                            printf("Neutro\n");
                            break;
                    }
                } 
                
                else {
                    printf("Não há registros suficientes para calcular o humor mais frequente.\n");
                }
                break;
            case 7:
                int h;
                if (estaVazia(&lista)) {
                    printf("A lista está vazia!\n");
                    break;
                }

                printf("\nInforme o humor que deseja buscar os motivos: ");
                printf("\n0- Feliz\n1-Triste\n2-Ansioso\n3-Cansado\n4-Motivado\n5-Estressado\n6-Neutro\nResposta: ");
                scanf("%d", &h);

                if (h < 0 || h > 6) {
                    printf("Humor inválido!\n");
                } 
                else {
                    motivosDosDiasComHumor(&lista, (Humor)h);
                }
                break;
            case 8:
                printf("Saindo do programa...\n");
                break;
        }
    } while (opcao != 8);
}