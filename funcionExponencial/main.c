#include <stdio.h>
#include <stdlib.h>

unsigned int funcionExponencial(int base, int exp);

int main()
{
    int n1; //base
    int n2; // exponente


    printf("Ingrese la base: ");
    scanf("%d", &n1);

    printf("\n Ingrese el exponente: ");
    scanf("%d", &n2);

    if(n1+n2==0)
    {
        printf(" %d^%d es indeterminado \n\n ", n1, n2);
    }
    else
        printf("\n  %d^%d = %d", n1, n2, funcionExponencial(n1, n2));


    return 0;
}

unsigned int funcionExponencial(int base, int exp)
{
    int numero=1;
    int i;

    if(exp != 0)
    {
        for(i=0; i<exp; i++)
        {
          numero = numero*base;
        }

        return numero;
    }
    else
        return numero;


}
