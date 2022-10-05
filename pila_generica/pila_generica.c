#include "pila_generica.h"

///-----------------------------PILA ESTATICA GENERICA OPCION 1------------------------------///
void crear_pila(t_pila *p,size_t tamanio,int cant_elem)
{
    p->vpila=malloc(tamanio*cant_elem);
    p->ce=(!p->vpila)?0:cant_elem;
    p->tam=tamanio;
    p->tope=-1;
}

void vaciar_pila(t_pila *p)
{
    p->tope=-1;
}

int poner_en_pila(t_pila *p,const void *d)
{
    if(!p->ce || p->tope==p->ce-1)
        return 0;
    memcpy(p->vpila+(++p->tope)*p->tam,d,p->tam);
    return 1;
}

int sacar_de_pila(t_pila *p,void *d)
{
    if(!p->ce || p->tope==-1)
        return 0;
    memcpy(d,p->vpila+(p->tope--)*p->tam,p->tam);
    return 1;
}

int ver_tope(const t_pila *p, void *d)
{
    if(!p->ce || p->tope==-1)
        return 0;
    memcpy(d,p->vpila+(p->tope)*p->tam,p->tam);
    return 1;
}

int pila_llena(const t_pila *p)
{
    return p->tope==p->ce-1;
}

int pila_vacia(const t_pila *p)
{
    return p->tope==-1;
}

void eliminar_pila(t_pila *p)
{
    free(p->vpila);
}

///-----------------------------PILA ESTATICA GENERICA OPCION 2------------------------------///

void crear_pila_op2(t_pila_op2 *p,size_t tamanio)
{
    p->tope=-1;
    p->tam=tamanio;
}

void vaciar_pila_op2(t_pila_op2 *p)
{
    while(p->tope!=-1)
        free(p->vpila[p->tope--]);
}

int poner_en_pila_op2(t_pila_op2 *p,const void *d)
{
    if(p->tope==TAM-1)
        return 0;
    p->vpila[++p->tope]=malloc(p->tam);
    if(!p->vpila[p->tope--])
        return 0;
    memcpy(p->vpila[++p->tope],d,p->tam);
    return 1;
}
int sacar_de_pila_op2(t_pila_op2 *p,void *d)
{
    if(p->tope==-1)
        return 0;
    memcpy(d,p->vpila[p->tope],p->tam);
    free(p->vpila[p->tope--]);
    return 1;
}

int ver_tope_op2(const t_pila_op2 *p, void *d)
{
    if(p->tope==-1)
        return 0;
    memcpy(d,p->vpila[p->tope],p->tam);
    return 1;
}

int pila_llena_op2(const t_pila_op2 *p)
{
    return p->tope==TAM-1;
}

int pila_vacia_op2(const t_pila_op2 *p)
{
    return p->tope==-1;
}


///-----------------------------PILA DINAMICA GENERICA------------------------------///

void crear_pilaD(t_pilaD *p,size_t tamanio)
{
    p->pila=NULL;
    p->tam=tamanio;
}

void vaciar_pilaD(t_pilaD *p)
{
    t_nodo *aux;
    while(p->pila)
    {
        aux=p->pila->sig;
        free(p->pila);
        p->pila=aux;
    }
}

int poner_en_pilaD(t_pilaD *p,const void *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->d=malloc(p->tam);
    if(!nue->d)
        return 0;
    nue->sig=p->pila;
    memcpy(nue->d,d,p->tam);
    p->pila=nue;
    return 1;
}

int sacar_de_pilaD(t_pilaD *p,void *d)
{
    t_nodo *aux;
    if(!p->pila)
        return 0;
    aux=p->pila;
    memcpy(d,aux->d,p->tam);
    p->pila=aux->sig;
    free(aux);
    return 1;
}

int ver_topeD(const t_pilaD *p, void *d)
{
    if(!p->pila)
        return 0;
    memcpy(d,p->pila->d,p->tam);
    return 1;
}

int pila_llenaD(const t_pilaD *p)
{
    t_nodo *aux=(t_nodo*)malloc(sizeof(t_nodo));
    if(!aux)
        return 1;
    free(aux);
    return 0;
}

int pila_vaciaD(const t_pilaD *p)
{
    return p->pila==NULL;
}
