#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_ASIG -1
#define TDA_VACIO 0
#define TODO_OK 1
#define MIN(X, Y) (X)>(Y)?(X):(Y)

typedef struct s_nodo{
    void* dato;
    unsigned tamDato;
    struct s_nodo* sig;
} t_nodo;

typedef struct{
    t_nodo* pri;
    t_nodo* ult;
} t_cola;

void crearCola(t_cola* cola);
void vaciarCola(t_cola* cola);

int colaVacia(const t_cola* cola);
int colaLlena(const t_cola* cola, unsigned tamDato);

int ponerEnCola(t_cola* cola, const void* dato, unsigned tamDato);
int sacarDeCola(t_cola* cola, void* dato, unsigned tamDato);
int verPrimero(const t_cola* cola, void* dato, unsigned tamDato);

#endif // FUNCIONES_H_INCLUDED
