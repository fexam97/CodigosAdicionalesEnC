#ifndef PILA_H
#define PILA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
    void *info;
    unsigned tam;
    struct sNodo * sig;

}tNodo;

typedef tNodo* tPila;

typedef void(*Mostrar)(const void *reg);
typedef int(*Cmp)(const void*, const void *);


void crearPila(tPila* pp);
int apilar(tPila *pp,const void *dato, unsigned tamDato);
int desapilar(tPila *pp,void *dato, unsigned tamDato);
int pilaVacia(const tPila * pp);
int pilaLlena(const tPila *pp, unsigned tamDato);
void vaciarPila(tPila * pp);
int verTope(const tPila* pp, void *dato, unsigned tamDato);


int expresionBalanseado(tPila *pp, char * exp, Cmp cmp);
#endif // PILA_H
