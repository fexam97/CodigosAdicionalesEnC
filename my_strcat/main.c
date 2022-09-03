#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mstrcat(char *destino, const char *origen);

int main()
{
    char cadena1[] = " volver al futuro ";
    char cadena2[] = " segunda parte";

    printf("\n Cadena 1 : %s", cadena1);

    printf("\n Cadena 2 : %s", cadena2);

    printf("\n Cadena concatenada:%s", strcat(cadena1, cadena2));

    printf("\n Cadena concatenada:%s", mstrcat(cadena1, cadena2)); // esta mal, pero no tan mal

    system("pause");

    return 0;
}

char *mstrcat(char *destino, const char *origen)
{
    char *aux = destino; //creo la variable auxiliar para guardar el contenido de la segunda cadena

    while(*destino != '\0')    // el ciclo termina hasta que el contenido de la primera cadena sea distinto del caracter nulo
    {
        destino++; // con esto ya termino de recorrer toda la cadena
    }

    while(*origen != '\0') // empiezo a leer la segunda cadena
    {
        *(destino++) =* (origen++); // le asigno los valores de la segunda cadena a la cadena destino
    }                               // (no me queda claro eso del tamanio, en este caso sobran caracteres y lo que el programa
                                    // va a hacer es imprimir caracteres de mas, tengo que buscar la forma de sacar esos caracteres de mas).

    return aux; // retorno lo que se modifico en el proceso

}
