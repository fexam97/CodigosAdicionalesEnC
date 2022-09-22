#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 20

typedef struct{

    int dni;
    char nya[TAM];
    float prom;

}tAlumuno;

typedef struct{

    int codProd;
    char info[TAM];
    float precio;

}tProd;

typedef struct{
    int clave;
    char nya[TAM];
    float sueldo;
}tEmpleado;

typedef struct{
    tEmpleado empl;
    char tipo;
}tNovEmpleado;


typedef void(*Mostrar)(const void *reg);
typedef int(*Cmp)(const void * a, const void * b);

int leerArch(const char * nombArch);
int loteDePrueba01(const char *nombArch);
int loteDePrueba02(const char *nombArch);
//int mostrarAlum(const char * nombArch);

void MostrarAlumno(const void *registro);
int cmpEnt(const void *a,const void *b);
void MostrarEmpNov(const void *reg);
void MostrarEmp(const void *reg);

int loteDePruebaMaestro(const char *nombArch);
int loteDePruebaNovedades(const char *nombArch);

int mostrarGenerica(const char *nombArch, void * registro, size_t tam, Mostrar mostrarReg);
int mostrarGenerica2(const char *nombArch, size_t tam, Mostrar mostrarReg);/// memoria dinamica


int abrirArchivo(const char *nombArch,const char *modo, FILE **pf);
void redondearPromedio(FILE* pf,tAlumuno *palum, size_t tamReg);

int maestroActualizado(const char *nomArchMaestro,const char *nomArchNov, Cmp cmp);


#endif // FUNCIONES_H_INCLUDED
