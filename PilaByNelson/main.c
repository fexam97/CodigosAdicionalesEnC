#include "pila.h"

void MostrarEnt(const void *elem)
{
    printf("%d\n", *(int*)elem);
}

int cmpChar(const void* elem1, const void * elem2)
{
    return *(char *)elem1 == *(char *)elem2;
}

int main()
{
    tPila p1;
    int x = 7;
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vec1[10];
    int i;

    char exp[] = "{[2*(5+3)]+9}-(16+3)";

    tPila p2;
    crearPila(&p2);

    if(!expresionBalanseado(&p2, exp, cmpChar))
        puts("La exprecion no esta balanceado");

    crearPila(&p1);
    apilar(&p1, &x, sizeof(int));
    x = 16;
    apilar(&p1, &x, sizeof(int));

    if(pilaVacia(&p1))
        printf("La pila esta vacia\n");

    for(i=0 ; i < sizeof(vec)/sizeof(int) ; i++)
        if(!apilar(&p1, &vec[i], sizeof(int)))
            puts("No pudo apilar");

    if(pilaVacia(&p1))
        printf("La pila esta vacia\n");

    for(i=0 ; i < sizeof(vec)/sizeof(int) ; i++)
        if(!desapilar(&p1, &vec1[i], sizeof(int)))
            puts("No hay mas elementos en la pila");

    for(i=0 ; i< sizeof(vec1)/sizeof(int) ; i++)
            MostrarEnt(&vec1[i]);

    if(pilaVacia(&p1))
        printf("La pila esta vacia\n");

    return 0;
}
