//TALLER SEMANA 8
//AGUIRRE REMIGIO-MACÍAS ISSAC-HIDALGO MATEO
//LIBRERIAS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//CONSTANTES
#define maxRecursos 25
#define maxProductos 5
//VARIABLES GLOBALES
int nR,cR,opcion;
//ESTRUCTURAS    
struct Recursos{
    char nombre[50];
    float cantidad;
    int id;
    char magnitud[50];};
struct CantidadRecursos{
    int id;   
    float cantidad; };
struct Productos{
    char nombre[50];
    int cantRecursos;
    struct CantidadRecursos caR[maxRecursos];
    float mP;//Minutos de produccion
    int id;};
int idRandom(){
    return (rand() % (9999 - 1000 + 1) + 1000);
}
int buscarRecursoPorID(struct Recursos recurso[], int n, int idBuscado) {
    for (int i = 0; i < n; i++) {
        if (recurso[i].id == idBuscado) {
            return i;  // Se encontró el recurso, retorna el índice
        }
    }
    return -1; // No se encontró
}
int buscarProductoPorID(struct Productos producto[], int n, int idBuscado) {
    for (int i = 0; i < n; i++) {
        if (producto[i].id == idBuscado) {
            return i;
        }
    }
    return -1;
}
void limpiarSaltoLinea(char* cadena) {
int len = strlen(cadena);
if (len > 0 && cadena[len - 1] == '\n') {
cadena[len - 1] = '\0';
}
}
void printBienvenida(){
printf("----------------BIENVENIDO A Opti-Fab----------------\n");
printf("-----------------------------------------------------\n");
printf("---------------DECLARACION DE RECURSOS---------------\n");
}
void printMenuP(){
printf("-----------------------------------------------------\n");
printf("--------------------MENU PRINCIPAL-------------------\n");
printf("-----------------------------------------------------\n");
printf("|1. CONSULTAR PRODUCCION POR DEMANDA\n");
printf("|2. EDICION DE PRODUCTOS\n");
printf("|3. ELIMINACION DE PRODUCTOS\n");
printf("|4. SALIR\n");
printf("-----------------------------------------------------\n|");
}

void printCantRecursosInvalid(){
printf("-----------------------------------------------------\n");
printf("---Cantidad de Recursos Invalida, ingrese de nuevo---\n");
printf("-----------------------------------------------------\n");
}

void printidRecursosInvalido(){
printf("-----------------------------------------------------\n");
printf("------Id de Recursos Invalido, ingrese de nuevo------\n");
}

void printIdProductoInvalid(){
printf("-----------------------------------------------------\n");
printf("------Id de Producto Invalido, ingrese de nuevo------\n");  
printf("-----------------------------------------------------\n");
}
