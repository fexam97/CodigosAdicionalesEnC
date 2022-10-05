#ifndef PILA_GENERICA_H_INCLUDED
#define PILA_GENERICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    void *vpila;
    size_t tam;
    int tope,
        ce;
}t_pila;///PILA ESTATICA GENERICA OPCION 1  TAMAÑO DE LA PILA LO INGRESA EL USUARIO

typedef struct
{
    void *vpila[TAM];
    size_t tam;
    int tope;
}t_pila_op2;///PILA ESTATICA GENERICA OPCION 2 TAMAÑO DE LA PILA ES TAM

typedef struct snodo
{
    void *d;
    struct snodo *sig;
}t_nodo;

typedef struct
{
    t_nodo *pila;
    size_t tam;
}t_pilaD;///PILA DINAMICA GENERICA

///-----------------------------PILA ESTATICA GENERICA OPCION 1------------------------------///
void crear_pila(t_pila *p, size_t tamanio, int cant_elem);
void vaciar_pila(t_pila *p);
int poner_en_pila(t_pila *p,const void *d);
int sacar_de_pila(t_pila *p,void *d);
int ver_tope(const t_pila *p, void *d);
int pila_llena(const t_pila *p);
int pila_vacia(const t_pila *p);
void eliminar_pila(t_pila *p);/// libero la memoria

///-----------------------------PILA ESTATICA GENERICA OPCION 2------------------------------///
void crear_pila_op2(t_pila_op2 *p,size_t tamanio);
void vaciar_pila_op2(t_pila_op2 *p);
int poner_en_pila_op2(t_pila_op2 *p,const void *d);
int sacar_de_pila_op2(t_pila_op2 *p,void *d);
int ver_tope_op2(const t_pila_op2 *p, void *d);
int pila_llena_op2(const t_pila_op2 *p);
int pila_vacia_op2(const t_pila_op2 *p);

///-----------------------------PILA DINAMICA GENERICA------------------------------///

void crear_pilaD(t_pilaD *p,size_t tamanio);
void vaciar_pilaD(t_pilaD *p);
int poner_en_pilaD(t_pilaD *p,const void *d);
int sacar_de_pilaD(t_pilaD *p,void *d);
int ver_topeD(const t_pilaD *p, void *d);
int pila_llenaD(const t_pilaD *p);
int pila_vaciaD(const t_pilaD *p);



#endif // PILA_GENERICA_H_INCLUDED
