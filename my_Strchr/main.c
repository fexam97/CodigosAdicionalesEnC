#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 char *strchr(char *s, int c);
 Localiza la primera aparici�n de c (convertido a unsigned char) en la cadena apuntada por s (incluyendo el car�cter nulo).
 VALOR DE RETORNO:
 La funci�n retorna un puntero a partir del car�cter encontrado. Si no se ha encontrado el car�cter, c, entonces retorna un puntero null.


pocas palabras: retorna la subcadena/palabra que quiero buscar

 strchr -> string character

*/

char *mStrchr(const char *pString, int c);

int main() // esta lleno de warnings, es problema del codeblocks
{
    char cadena[] = "Esta es una simple cadena";
    char *pch; // puntero character, aca se va a almacernar el valor de strchr

    printf(" Buscando el caracter 's' en \''%s\''...\n", cadena);

    pch = strchr(cadena, 's');

    printf("\n\n pch = %d", pch);
    printf("\n\n cadena = %d", cadena );

    while(pch != NULL) //cuando el contenido este vacio
    {
        printf("\n Encontrado en la posicion %d\n", pch - cadena + 1);
        pch = strchr(pch + 1, 's');
    }

    printf("\n\n ******** SIN USAR STRING.H **********\n\n");

    printf(" Buscando el caracter 's' en \''%s\''...\n", cadena);

    pch = mStrchr(cadena, 's');

    while(pch != NULL)
    {
        printf("\n Encontrado en la posicion %d\n", pch - cadena + 1);
        pch = mStrchr(pch + 1, 's');
    }

    return 0;
}

char *mStrchr(const char *pString, int c)
{
    if(NULL == pString) // casi nunca va a pasar
        return NULL;

    while(*pString)
    {
        if(*pString == (char)c) //necesito castearlo si o si
            return pString;

        pString++; //aumenta la cadena
    }

    return NULL;
}
