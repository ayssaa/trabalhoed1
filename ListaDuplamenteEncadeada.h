// A lista será usada para armazenar os registros de humor

#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H
#include "RegistroDeHumor.h"

typedef struct noLista {
    RegistroDeHumor info;
    struct noLista* ant;
    struct noLista* prox;    
} NoLista;

// Função para criar uma lista vazia
void criarLista(NoLista** l);

int estaVazia(NoLista** l);

void inserirElementoFim(NoLista** l, RegistroDeHumor v);

NoLista* ultimoElemento(NoLista** l);

void ImprimeListaOrdemDireta(NoLista** l);

void ImprimeListaOrdemInversa(NoLista** l);

NoLista* buscaElementoPorID(NoLista** l);

void buscaElementoPorHumor(NoLista** l);

void removerElemento(NoLista** l);

void liberarLista(NoLista** l);

float mediaDeNotaDoDia(NoLista** l, int x);

Humor humorMaisFreqUltimosDias(NoLista** l, int x);

void motivosDosDiasComHumor(NoLista** l, Humor h);

#endif