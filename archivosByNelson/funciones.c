#include "funciones.h"

void MostrarAlumno(const void *registro)
{
    tAlumuno *pReg = (tAlumuno *)registro;

    if(pReg == NULL)
        puts("DNI \t NOMBRE Y APELLIDO \t\t PROMEDIO\n");
    else
        printf("%d \t %-15s \t\t %.2f\n",pReg->dni, pReg->nya, pReg->prom);
}
int cmpEnt(const void * a,const void * b)
{
    return *(int *)a - *(int *)b;
}

void MostrarProd(const void *registro)
{
    tProd *pProd = (tProd *)registro;

    if(pProd == NULL)
        puts("COD PROD \t INFO DEL PRODUCTO\t PRECIO\n");
    else
        printf("%d \t\t %-20s \t %.2f\n", pProd->codProd, pProd->info, pProd->precio);
}

void MostrarEmp(const void *reg)
{
    tEmpleado *emp = (tEmpleado *)reg;

    if(emp == NULL)
        puts("CLAVE \t NOMB Y APELL\t SUELDO\n");
    else
        printf("%d \t\t%s \t%5.2f\n",emp->clave, emp->nya, emp->sueldo);
}

void MostrarEmpNov(const void *reg)
{
    tNovEmpleado *emp = (tNovEmpleado *)reg;

    if(emp == NULL)
        puts("CLAVE \t NOMB Y APELL\t SUELDO\t TIPO\n");
    else
        printf("%d \t\t%s \t%5.2f\t %c\n",emp->empl.clave, emp->empl.nya, emp->empl.sueldo, emp->tipo);
}

#define REDONDEO(x) (int)(x + 0.5)
//#define REDONDEO(f) f-(int)f > 0.5? (int)f

/**ARCHIVOS

FILE *, fopen , fclose(rename,remove,unlink)
*/


/**BINARIOS

fread
fwrite
feof
fseek
rewind
ftell
fflush

fopen ->  wb o rb
            r+b   el cabezal queda al principio del archivo
*/


int loteDePrueba01(const char *nombArch)
{
    tAlumuno alus[]={{10,"Maria Pia", 9.9},
                    {20,"Juan Perez", 10.0},
                    {20,"Danilo Beltran", 5.5},
                    {15,"Carlos Fulanito", 9.8},
                    {15,"Martin Kiko", 9.8},
                    {15,"Alan Lureano", 9.3}};

    FILE *pf = fopen(nombArch, "wb");

    if(!pf)
        return 0;
    ///    fwrite(alus,sizeof(tAlumno),sizeof(alus)/sizeof(tAlumno),pf);

    /**
        tAlumno palum[]=
        for(i=0 ; i<
    */
    fwrite(alus, sizeof(alus), 1, pf);


    fclose(pf);
    return 1;
}
/*
int leerArch(const char * nombArch)
{
    FILE * pf = fopen(nombArch, modo);


}
*/
int mostrarGenerica(const char *nombArch,void * registro, size_t tam, Mostrar mostrarReg)
{
    FILE *pf = fopen(nombArch, "rb");

    if(!pf)
        return 0;

    mostrarReg(NULL);

    fread(registro, tam, 1, pf);

    while(!feof(pf))
    {
        mostrarReg(registro);
        fread(registro, tam, 1, pf);
    }

    fclose(pf);

    return 1;
}
int loteDePrueba02(const char *nombArch)
{
     tProd prods[] = {{104,"Lata De Durazno",175.25},
                    {204,"Lata De Pera", 152.15},
                    {208,"Lata De Damasco", 145.25},
                    {157,"Lata De Sandia",124.55},
                    {154,"Lata De Frutilla",200},
                    {151,"Lata De Coco",154.62}};

    FILE *pf = fopen(nombArch, "wb");

    if(!pf)
        return 0;
    ///    fwrite(alus,sizeof(tAlumno),sizeof(alus)/sizeof(tAlumno),pf);

    /**
        tAlumno palum[]=
        for(i=0 ; i<
    */
    fwrite(prods, sizeof(prods), 1, pf);


    fclose(pf);
    return 1;
}
int mostrarGenerica2(const char* nombArch, size_t tamReg, Mostrar mostrarReg)
{
    FILE *pf = fopen(nombArch, "rb");
    void *dato = malloc(tamReg);

    if(!pf || !dato)
        return 0;

    mostrarReg(NULL);

    fread(dato, tamReg, 1, pf);

    while(!feof(pf))
    {
        mostrarReg(dato);
        fread(dato, tamReg, 1, pf);
    }
    fclose(pf);
    free(dato);
    return 1;
}
/*
void hacerAlgoGenerico(FILE* pf, size_t tamReg, )
{
    void *aux,

    rewind(pf); ///vuleve al principio el cabezal en el archivo

    while(!feof(pf))
    {
        palum->prom=REDONDEO(palum->prom);
        //palum->prom=round(palum->prom);
        fseek(pf,-(int)sizeof(tAlumuno),SEEK_CUR);
        fwrite(palum,tamReg,1,pf);
        fflush(pf);///fseek(pf,0L,SEEK_CUR);
        fread(palum,tamReg,1,pf);
    }

}
*/
void redondearPromedio(FILE* pf,tAlumuno *palum, size_t tamReg)
{
    fread(palum,tamReg,1,pf);

    while(!feof(pf))
    {
        palum->prom = REDONDEO(palum->prom);
        //palum->prom=round(palum->prom);
        fseek(pf, -(int)sizeof(tAlumuno), SEEK_CUR);
        fwrite(palum, tamReg, 1, pf);
        fflush(pf);///fseek(pf,0L,SEEK_CUR);
        fread(palum, tamReg, 1, pf);
    }

}
int abrirArchivo(const char *nombArch,const char *modo, FILE **pf)
{
    *pf=fopen(nombArch,modo);

    return !(*pf)? 0: 1;
}


int loteDePruebaMaestro(const char *nombArch)
{
    tEmpleado emp[]={{10,"AA",100},
                     {20,"XA",100},
                     {30,"MZ",300},
                     {40,"WH",500},
                     {50,"XN",300},
                     {60,"EM",200}};

    FILE *pf = fopen(nombArch,"wb");

    if(!pf)
        return 0;

    fwrite(emp,sizeof(emp),1,pf);

    fclose(pf);
    return 1;
}
int loteDePruebaNovedades(const char *nombArch)
{
        tNovEmpleado emp[]={
                        {{5,"ZX",300},'a'},
                        {{10,"AA",150},'m'},
                        {{20,"WH",100},'a'},
                        {{31,"XA",200},'m'},
                        {{40,"WH",500},'b'},
                        {{51,"XA",300},'a'},
                        {{70,"WH",500},'b'},
                        {{78,"MZ",200},'b'}

                                            };

    FILE *pf = fopen(nombArch,"wb");

    if(!pf)
        return 0;

    fwrite(emp,sizeof(emp),1,pf);

    fclose(pf);
    return 1;
}

int maestroActualizado(const char *nomArchMaestro,const char *nomArchNov,Cmp cmp)
{
    FILE *pfMaestro,
         *pfNov,
         *pfAct;

    tEmpleado empMaestro;
    tNovEmpleado empNov;


    int comparo;

    pfMaestro = fopen(nomArchMaestro,"rb");

    if(!pfMaestro)
        return 0;
    pfNov = fopen(nomArchNov,"rb");

    if(!pfNov)
        return 0;

    pfAct = fopen("Actualizado.dat","wb");

    if(!pfAct)
        return 0;

    fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
    fread(&empNov,sizeof(tNovEmpleado),1,pfNov);

    while(!feof(pfNov) && !feof(pfMaestro))
    {
        comparo=cmp(&empMaestro.clave,&empNov.empl.clave);//comparo = 5

        if(comparo==0)
        {
            if(empNov.tipo == 'a')
            {
                printf("\nError das de alta algo que ya esta en el maestro\n");
                /// Avanzo ambos
                        fwrite(&empMaestro,sizeof(tEmpleado),1,pfAct);
                fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
                fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
            }
            else if(empNov.tipo == 'b')
                {
                    ///Lo ignoro en los dos archivos
                    fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
                    fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
                }
                else
                {
                    fwrite(&empNov.empl,sizeof(tEmpleado),1,pfAct);
                    fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
                    fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
                }
        }
        else
        {
            if(comparo > 0)
            {
                if(empNov.tipo == 'a')
                {
                    fwrite(&empNov.empl,sizeof(tEmpleado),1,pfAct);
                    fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
                }
                else if(empNov.tipo == 'b')
                {
                    printf("\nError das de baja algo que no esta en el maestro\n");
                    fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
                }
                else
                {
                    printf("\nError modificas algo que no esta en el maestro\n");
                   fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
                }
            }
            else/// comparo < 0
            {
                    if(empNov.tipo == 'a')
                    {
                        fwrite(&empMaestro,sizeof(tEmpleado),1,pfAct);
                        fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
                    }
                    else if(empNov.tipo == 'b')
                    {
                        fwrite(&empMaestro,sizeof(tEmpleado),1,pfAct);
                        fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
                    }
                    else
                    {
                          fwrite(&empMaestro,sizeof(tEmpleado),1,pfAct);
                        fread(&empMaestro,sizeof(tEmpleado),1,pfMaestro);
                    }
            }
        }
    }

    while(!feof(pfMaestro))
    {
         fwrite(&empMaestro,sizeof(tEmpleado), 1, pfAct);
         fread(&empMaestro,sizeof(tEmpleado), 1, pfMaestro);
    }


    while(!feof(pfNov))
    {
        if(empNov.tipo == 'a')
            fwrite(&empNov.empl, sizeof(tEmpleado), 1, pfAct);


        fread(&empNov,sizeof(tNovEmpleado),1,pfNov);
    }

    fclose(pfMaestro);
    fclose(pfNov);
    fclose(pfAct);

    remove(nomArchMaestro);
    rename("Actualizado.dat",nomArchMaestro);



    return 1;


}


/*int mostrarAlum(const char * nombArch)
{

}
*/
/**TEXTO

fgets
fscanf
fprintf
fputs
(**sscanf**)
(**sprintf**)

fopen -> rt o wt
*/
