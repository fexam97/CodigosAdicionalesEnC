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
    nue->tamDato = tamDato; //Copio el tamaño del dato
    nue->sig = NULL; //Inicializo en null su puntero a siguiente
    ///Creacion del nodo

    if(cola->ult)
        cola->ult->sig = nue;
     /// Si hay último, entonces la cola no está vacía, el nuevo sera el siguiente del último

    else
        cola->pri = nue; ///Caso contrario, el nuevo será el primero

    cola->ult = nue; ///En ambos casos, el nuevo será el último en la cola

    return TODO_OK;
}

int sacarDeCola(t_cola* cola, void* dato, unsigned tamDato){

    t_nodo* elim = cola->pri;
    if(elim == NULL)
        return TDA_VACIO;
    ///El primero en entrar es el primero en salir, pero si no hay primero, la cola está vacía

    memcpy(dato, elim->dato, MIN(tamDato, elim->tamDato));
    cola->pri = elim->sig;
    ///Copio la informacion del nodo a eliminar (el primero) al puntero dato, y el siguiente al primero sera el nuevo primero

    free(elim->dato);
    free(elim);
    ///Libero memoria

    if (cola->pri == NULL)
        cola->ult = NULL;
    ///Si al liberar memoria quedó NULL, entonces la cola está vacía, y ult = pri = NULL

    return TODO_OK;
}

int verPrimero(const t_cola* cola, void* dato, unsigned tamDato){

    if (cola->pri == NULL)
        return TDA_VACIO;
    ///Si la cola está vacía, no puedo mostrar nada

    memcpy(dato, cola->pri->dato, MIN(tamDato, cola->pri->tamDato));
    ///Copio la información al dato

    return TODO_OK;
}
