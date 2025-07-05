#include "RegistroDeHumor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando a função para criar um novo registro de humor
RegistroDeHumor* criarRegistro() {
    // Contador estático para manter o controle dos IDs, porque se não a única alternativa seria usar parametros na função
    static int cont = 0;

    RegistroDeHumor *novo = (RegistroDeHumor *) malloc(sizeof(RegistroDeHumor));
    if (novo == NULL) {
        printf("Não foi possível alocar memória.");
        return NULL;
    }

    // Solicitando a data
    // Verifica se a data é válida, se não for, retorna NULL
    printf("\nInforme o dia, mês e ano: (ex: 27 06 2025)\nReposta: ");
    scanf("%d %d %d", &novo->data.dia, &novo->data.mes, &novo->data.ano);
    if (novo->data.dia < 1 || novo->data.dia > 31 || novo->data.mes < 1 || novo->data.mes > 12 || novo->data.ano < 2025) {
        printf("Data inválida! Por favor, insira uma data válida.\n");
        free(novo);
        return NULL;
    }

    // Solicitando o humor
    // Verifica se o humor é válido, se não for, retorna NULL
    printf("\nInforme seu Humor: ");
    printf("\n0- Feliz\n1-Triste\n2-Ansioso\n3-Cansado\n4-Motivado\n5-Estressado\n6-Neutro\nResposta: ");
    scanf("%d", &novo->humor);
    if(novo->humor < 0 || novo->humor > 6) {
        printf("Humor inválido! Por favor, escolha um número entre 0 e 6.\n");
        free(novo);
        return NULL;
    }

    // Solicitando o motivo
    // Verifica se o motivo é menor que 100 caracteres, se não for, retorna NULL
    printf("\nInforme o motivo do seu humor: (Você tem até 100 caracteres!)\nResposta: ");
    scanf(" %[^\n]", &novo->motivo);
    if (strlen(novo->motivo) > 100) {
        printf("Motivo muito longo! Por favor, limite-se a 100 caracteres.\n");
        free(novo);
        return NULL;
    }

    // Solicitando a nota do dia
    // Verifica se a nota do dia é válida, se não for, retorna NULL
    printf("\nInforme a nota do seu dia (0 a 10)\nResposta: ");
    scanf("%d", &novo->notaDoDia);
    if(novo->notaDoDia < 0 || novo->notaDoDia > 10) {
        printf("Nota inválida! Por favor, insira um número entre 0 e 10.\n");
        free(novo);
        return NULL;
    }

    cont++;
    novo->id = cont;
    return novo;
}

// Função para imprimir o registro de humor
void imprimirRegistro(RegistroDeHumor** r) {
    if(r != NULL) {
        printf("\n------------Registro------------\n");
        printf("ID: %d\n", (*r)->id);
        printf("Data: %02d/%02d/%d\n", (*r)->data.dia, (*r)->data.mes, (*r)->data.ano);
        // switch para imprimir o humor como a palavra correspondente
        switch ((*r)->humor) { 
            case 0:
                printf("Humor: Feliz!\n");
                break;
            case 1:
                printf("Humor: Triste!\n");
                break;
            case 2:
                printf("Humor: Ansioso!\n");
                break;
            case 3:
                printf("Humor: Cansado!\n");
                break;
            case 4:
                printf("Humor: Motivado!\n");
                break;
            case 5:
                printf("Humor: Estressado!\n");
                break;
            case 6:
                printf("Humor: Neutro!\n");
                break;
        }
        printf("Motivo: %s\n", (*r)->motivo);
        printf("Nota do dia: %d\n", (*r)->notaDoDia);
    }
    else {
        printf("\nRegistro vazio!");
    }
}

// Função para liberar a memória alocada
void liberarRegistro(RegistroDeHumor** r) {
    if(r != NULL && *r != NULL) {
        free(*r); // Libera a memoria 
        *r = NULL; // Faz o ponteiro apontar para NULL
    }
}