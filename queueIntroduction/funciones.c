#include "funciones.h"

void crearCola(t_cola* cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}
void vaciarCola(t_cola* cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}

int colaVacia(const t_cola* cola)
{
    return (cola->pri == NULL);
}

int colaLlena(const t_cola* cola, unsigned tamDato)
{
    return 0;
}

int ponerEnCola(t_cola* cola, const void* dato, unsigned tamDato)
{

    t_nodo* nue;
    nue = (t_nodo*)malloc(sizeof(t_nodo));

    if (nue == NULL)
        return ERR_ASIG;

    nue->dato = (void*)malloc(tamDato);
    if(nue->dato == NULL)
    {
        free(nue);
        return ERR_ASIG;
    }
    ///ASIGNACION DE MEMORIA

    memcpy(nue->dato, dato, tamDato); //Copio el dato
    nue->tamDato = tamDato; //Copio el tama�o del dato
    nue->sig = NULL; //Inicializo en null su puntero a siguiente
    ///Creacion del nodo

    if(cola->ult)
        cola->ult->sig = nue;
     /// Si hay �ltimo, entonces la cola no est� vac�a, el nuevo sera el siguiente del �ltimo

    else
        cola->pri = nue; ///Caso contrario, el nuevo ser� el primero

    cola->ult = nue; ///En ambos casos, el nuevo ser� el �ltimo en la cola

    return TODO_OK;
}

int sacarDeCola(t_cola* cola, void* dato, unsigned tamDato){

    t_nodo* elim = cola->pri;
    if(elim == NULL)
        return TDA_VACIO;
    ///El primero en entrar es el primero en salir, pero si no hay primero, la cola est� vac�a

    memcpy(dato, elim->dato, MIN(tamDato, elim->tamDato));
    cola->pri = elim->sig;
    ///Copio la informacion del nodo a eliminar (el primero) al puntero dato, y el siguiente al primero sera el nuevo primero

    free(elim->dato);
    free(elim);
    ///Libero memoria

    if (cola->pri == NULL)
        cola->ult = NULL;
    ///Si al liberar memoria qued� NULL, entonces la cola est� vac�a, y ult = pri = NULL

    return TODO_OK;
}

int verPrimero(const t_cola* cola, void* dato, unsigned tamDato){

    if (cola->pri == NULL)
        return TDA_VACIO;
    ///Si la cola est� vac�a, no puedo mostrar nada

    memcpy(dato, cola->pri->dato, MIN(tamDato, cola->pri->tamDato));
    ///Copio la informaci�n al dato

    return TODO_OK;
}
