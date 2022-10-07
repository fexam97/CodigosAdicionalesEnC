#include "pila.h"
#define MIN(a,b) a<b? a : b

void crearPila(tPila* pp)
{
    *pp = NULL;
}

int apilar(tPila *pp, const void *dato, unsigned tamDato)
{
    tNodo * nue = (tNodo*)malloc(sizeof(tNodo));
      nue->info = malloc(tamDato);

    if(!nue)
       return 0;
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tam = tamDato;

    nue->sig = *pp;/// Apunto a lo que venia apuntando mi pila a mi nue nodo siguiente
    *pp = nue;     /// Reapunto mi puntero pila al nuevo nodo

    return 1;
}
int desapilar(tPila *pp, void *dato, unsigned tamDato)
{
    if(!pp)
        return 0;

    tNodo *elim = *pp;

    memcpy(dato, elim->info, MIN(tamDato,elim->tam));
    *pp = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}
int pilaVacia(const tPila * pp)
{
    return !*pp;
}

int pilaLlena(const tPila *pp, unsigned tamDato)
{
    tNodo *aux = malloc(sizeof(tNodo));

    if(!aux)
        return 1;

    aux->info = malloc(tamDato);
    if(!aux->info)
    {
        free(aux);
        return 1;
    }

    free(aux->info);
    free(aux);

    return 0;
}

void vaciarPila(tPila * pp)
{
    tNodo *aux;

    while(*pp)
    {
        aux = *pp;
        *pp = aux->sig;


        free(aux);
        free(aux->info);
    }
}
int verTope(const tPila* pp, void *dato, unsigned tamDato)
{
    if(!pp)
        return 0;

    tNodo *aux = *pp;

    memcpy(dato, aux->info, tamDato);
    tamDato = aux->tam;

    return 1;
}
int expresionBalanseado(tPila *pp, char * exp, Cmp cmp)
{
    char *ini = exp;
    char aux;
    int indEncontrada;
    void *dirEncontrado;
/*
    int contLlaves = 0;
    int contCorch = 0;
    int contParen = 0;
*/
    char match[2][3]={
                        {'(','[','{'},
                        {')',']','}'}
                                        };
///"{[2*(5+3)]+9}-(16+3)"
    while(*ini)
    {
        if(*ini=='{' || *ini=='[' || *ini=='(')
            apilar(pp,ini,sizeof(char));

        ini++;
    }

    while(ini > exp)
    {
        if(*ini==')' || *ini==']' || *ini=='}')
        {
            desapilar(pp, &aux, sizeof(char));
            dirEncontrado = bsearch(&aux,match[0], sizeof(match[0])/sizeof(char), sizeof(char), cmp);

            indEncontrada = ((char*)dirEncontrado - match[0])/sizeof(char);

            if(cmp(&match[1][indEncontrada], &aux) == 0)
                return 0;
        }

        ini--;
    }

    if(!pilaVacia(pp))
        return 0;

    return 1;
}
