#include <stdio.h>
#include <stdlib.h>
#include "pila_generica.h"

typedef struct
{
    char cad[50];
} t_nombre;

int main()
{

    t_pila_op2 p;
    t_nombre nom[]= {{"lucas"},
                     {"lucia"},
                     {"wanda"},
                      {"pepe"},
                   {"guidiño"},
                     {"juan"}};
    t_nombre aux;

    int a = 0;
    //b=6;
    crear_pila_op2(&p, sizeof(t_nombre));
    while(!pila_llena_op2(&p))
    {
        poner_en_pila_op2(&p, &nom[a]);
        a++;
    }
    //vaciar_pila_op2(&p);
    while(!pila_vacia_op2(&p))
    {
        sacar_de_pila_op2(&p, &aux);
        printf("%s\n", aux.cad);
    }
    printf("%d\n", pila_vacia_op2(&p));
        ///eliminar_pila(&p);///USAR PARA PILA ESTATICA OPCION 1, DEPREFERENCIA ANTES DEL RETURN

        return 0;

}
