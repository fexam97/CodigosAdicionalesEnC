#include "funciones.h"

int main()
{
    const char nombArch1[] = "Maestro.dat";
    const char nombArch2[] = "Novedades.dat";

    loteDePruebaMaestro(nombArch1);
    mostrarGenerica2(nombArch1, sizeof(tEmpleado), MostrarEmp);

    printf("\n\n");

    loteDePruebaNovedades(nombArch2);
    mostrarGenerica2(nombArch2, sizeof(tNovEmpleado), MostrarEmpNov);

    maestroActualizado(nombArch1, nombArch2, cmpEnt);

    printf("\n\n El archivo actualizado maestro es \n\n");
    mostrarGenerica2(nombArch1, sizeof(tEmpleado), MostrarEmp);
}
