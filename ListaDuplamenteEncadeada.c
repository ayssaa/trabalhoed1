// 2) Criando o TAD da Lista Duplamente Encadeada

#include "ListaDuplamenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para criar uma lista vazia
void criarLista(NoLista** l) {
    *l = NULL;
}

// Função para verificar se a lista está vazia
int estaVazia(NoLista** l) {
    return *l == NULL;
}

// Função para inserir um elemento no final da lista
void inserirElementoFim(NoLista** l, RegistroDeHumor v) {
    NoLista* novo  = (NoLista*)malloc(sizeof(NoLista));

    if(novo == NULL) {
        printf("Erro ao alocar memória!");
        return;
    }

    novo->info = v;
    novo->prox = NULL;
    novo->ant = NULL;

    if(*l == NULL) {
        *l = novo;
    }
    else {
        NoLista* p;
        for(p = *l; p->prox != NULL; p=p->prox);
        p->prox = novo;
        novo->ant = p;
    }
}

// Função para achar o último elemento da lista
NoLista* ultimoElemento(NoLista** l) {
	if (!estaVazia(l)) {
	    NoLista *p;
		for (p = *l; p->prox != NULL; p = p->prox);
        return p;
    }
    else {
        printf("A Lista está vazia!\n");
    }
}

// Função para imprimir a lista em ordem direta
void ImprimeListaOrdemDireta(NoLista** l){
    if(!estaVazia(l)){
        NoLista *p;
        for(p = *l; p != NULL; p = p->prox) {
            RegistroDeHumor* registro = &p->info; 
            imprimirRegistro(&registro);
        }
    }
    else {
        printf("A Lista está vazia!\n");
    }
}

// Função para imprimir a lista em ordem inversa
void ImprimeListaOrdemInversa(NoLista** l){
	if(!estaVazia(l)){
		NoLista *p;
		for (p = ultimoElemento(l); p != NULL; p = p->ant) {
            RegistroDeHumor* registro = &p->info;
            imprimirRegistro(&registro);
        }
    }
	else {
        printf("A Lista está vazia!\n");
    }
}

// Função para buscar um elemento por ID
NoLista* buscaElementoPorID(NoLista** l){
    int id;
    printf("Informe o ID do registro que deseja remover: ");
    scanf("%d", &id);

    if(!estaVazia(l)) {
        NoLista* p;
        for (p = *l; p != NULL; p = p->prox) {
            if(p->info.id == id) {
                return p;
            }
        }
    }
    return NULL;
}

// Função para buscar um elemento por humor
void buscaElementoPorHumor(NoLista** l) {
    if(!estaVazia(l)) {
        int h;

        printf("\nInforme o humor que deseja buscar:");
        printf("\n0- Feliz\n1-Triste\n2-Ansioso\n3-Cansado\n4-Motivado\n5-Estressado\n6-Neutro\nResposta: ");
        scanf("%d", &h);

        if(h < 0 || h > 6) {
            printf("Humor inválido! Por favor, escolha um número entre 0 e 6.\n");
        }

        NoLista* p;
        for (p = *l; p != NULL; p = p->prox) {
            if(p->info.humor == h) {
                RegistroDeHumor* registro = &p->info; 
                imprimirRegistro(&registro);
            }
        }

        printf("Nenhum registro encontrado com esse humor!\n");
    }
    else {
        printf("A Lista está vazia!\n");
    }
}

// Função para remover um elemento da lista
void removerElemento(NoLista** l){
    if(estaVazia(l)) {
        printf("A Lista está vazia!\n");
        return;
    }

    NoLista* p = buscaElementoPorID(l);
	
    if(p != NULL){
        if(*l == p){
            *l = p->prox;
            if (*l != NULL)
                (*l)->ant = NULL;
        }
        else {
            p->ant->prox = p->prox;
            if(p->prox != NULL)
                p->prox->ant = p->ant;
        }
        printf("\nRegistro removido com sucesso!\n");
        free(p);
    }
    else
        printf("Elemento não encontrado!\n");
}

// Função para liberar a memória da lista
void liberarLista(NoLista** l){
    NoLista *p, *temp;
    for(p = *l;p!=NULL ;p = temp){
        temp = p->prox;
        free (p);
    }
    *l = NULL;
}

// Função para calcular a média das notas dos últimos x dias
float mediaDeNotaDoDia(NoLista** l, int x) {
    int soma = 0, count = 0;
    if (x <= 0) {
        printf("O número de dias deve ser maior que zero.\n");
        return 0;
    }

    NoLista* p;
    NoLista* ultimo;

    for (p = *l; p != NULL; p = p->prox){
        ultimo = p;
    }

    for (p = ultimo; p != NULL && count < x; p = p->ant) {
        soma += p->info.notaDoDia;
        count++;
    }

    if (count != 0)
        return (float)soma / count;
    else
        return 0;
}

// Função para encontrar o humor mais frequente nos últimos x dias
Humor humorMaisFreqUltimosDias(NoLista** l, int x) {
    int freq[7] = {0};  // Um para cada humor
    int count = 0;

    if (x <= 0) {
        printf("O número de dias deve ser maior que zero.\n");
        return -1;
    }

    NoLista* p;
    NoLista* ultimo;
    for (p = *l; p != NULL; p = p->prox){
        ultimo = p;
    }

    for (p = ultimo; p != NULL && count < x; p = p->ant) {
        freq[p->info.humor]++;
        count++;
    }

    int maisFreq = 0;
    for (int i = 1; i < 7; i++) {
        if (freq[i] > freq[maisFreq]) {
            maisFreq = i;
        }
    }

    return (Humor)maisFreq;
}

// Função para mostrar os motivos dos dias com um determinado humor
void motivosDosDiasComHumor(NoLista** l, Humor h) {
    int achei = 0;

    for (NoLista* p = *l; p != NULL; p = p->prox) {
        if (p->info.humor == h) {
            printf("Motivo do Humor no dia %02d/%02d/%d: %s\n", p->info.data.dia, p->info.data.mes, p->info.data.ano, p->info.motivo);
            achei = 1;
        }
    }

    if (achei == 0) {
        printf("Nenhum registro com esse humor foi encontrado.\n");
    }
}