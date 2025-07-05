all: compila
compila: main.o RegistroDeHumor.o ListaDuplamenteEncadeada.o
    gcc main.o RegistroDeHumor.o ListaDuplamenteEncadeada.o -o trabalho
main.o: main.c
    gcc -c main.c
RegistroDeHumor.o: RegistroDeHumor.c
    gcc -c RegistroDeHumor.c
ListaDuplamenteEncadeada.o: ListaDuplamenteEncadeada.c
    gcc -c ListaDuplamenteEncadeada.c
executa:
    trabalho.exe
clean:
    del main.o RegistroDeHumor.o ListaDuplamenteEncadeada.o trabalho.exe