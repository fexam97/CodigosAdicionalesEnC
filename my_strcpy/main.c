#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mStrcpy(char *destino, const char *origen);


int main()
{

    char cadena1[] = " street of rage ";
    char cadena2[] = " ultimate mortal kombat 3 ";

    printf("\n Cadena 1 : ''%s'' ", cadena1);
    printf("\n Cadena 2 : ''%s'' ", cadena2);


    printf("\n\n %s", strcpy(cadena1, cadena2));

    printf("\n\n %s", mStrcpy(cadena1, cadena2));

    return 0;
}

char *mStrcpy(char *destino, const char *origen)  // const char *origen: el contenido origen nunca se va a modificar
{
    char *aux = destino;    // creo una variable auxiliar para guardar la cadena que se va a modificar

    while(*origen != '\0')  // si la segunda cadena llega al caracter nulo se termina el ciclo
    {
        *(destino++) = *(origen++); // copia caracter por caracter y avanza una posicion
    }

    return aux; // retorno la segunda cadena copiada en la primera
}

