#ifndef REGISTRODEHUMOR_H
#define REGISTRODEHUMOR_H

// Criando a struct Data para armazenar a data do registro
typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

// Criando o enum Humor para representar os diferentes estados de humor
typedef enum {
    FELIZ,
    TRISTE,
    ANSIOSO,
    CANSADO,
    MOTIVADO,
    ESTRESSADO,
    NEUTRO
} Humor;

// Criando a struct RegistroDeHumor que contém os dados do registro
typedef struct registrodeHumor {
    int id;
    Data data;
    Humor humor;
    char motivo[101]; // 100 caracteres + 1 para o '\0'
    int notaDoDia;
} RegistroDeHumor;


RegistroDeHumor* criarRegistro();
void imprimirRegistro(RegistroDeHumor** r);
void liberarRegistro(RegistroDeHumor** r);

#endif