#include "funciones.h"

int main()
{
    int i;
    for (i=0; i<10; i++)
        {
        printf("[%d]\n", rand()%3);
        }


    /*
    int num1=1, num2=2, num3=3, numMostrar, numSacar;
    t_cola cola;

    crearCola(&cola);

    ponerEnCola(&cola, &num1, sizeof(int));
    ponerEnCola(&cola, &num2, sizeof(int));
    ponerEnCola(&cola, &num3, sizeof(int));

    verPrimero(&cola, &numMostrar, sizeof(int));
    printf("El primero es: %d\n", numMostrar);

    sacarDeCola(&cola, &numSacar, sizeof(int));
    printf("\nSalio el numero: %d\n", numSacar);
    verPrimero(&cola, &numMostrar, sizeof(int));
    printf("El primero ahora es: %d\n", numMostrar);
    */

    return 0;
}
