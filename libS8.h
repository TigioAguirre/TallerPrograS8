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
printf("|4. MOSTRAR PRODUCTOS\n");
printf("|5. SALIR\n");
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
















package ec.edu.evaluacion;

import java.util.ArrayList;

public class GestionEstudiantes {
    private ArrayList<Estudiante> estudiantes;

    public GestionEstudiantes() {
        estudiantes = new ArrayList<>();
        precargarEstudiantes();
    }

    private void precargarEstudiantes() {
        estudiantes.add(new Estudiante(101, "Ana Torres", "Software", 8.5));
        estudiantes.add(new Estudiante(102, "Juan Pérez", "TI", 7.2));
        estudiantes.add(new Estudiante(103, "Carla López", "Computación", 9.1));
        estudiantes.add(new Estudiante(104, "Luis Mena", "Software", 6.8));
        estudiantes.add(new Estudiante(105, "María Ruiz", "TI", 8.9));
    }

    public boolean agregarEstudiante(Estudiante estudiante) {
        // Validar que el código sea único
        for (Estudiante e : estudiantes) {
            if (e.getCodigo() == estudiante.getCodigo()) {
                return false; // Ya existe, no se agrega
            }
        }
        estudiantes.add(estudiante);
        return true;
    }

    public Estudiante buscarPorCodigoSecuencial(int codigo) {
        for (Estudiante e : estudiantes) {
            if (e.getCodigo() == codigo) {
                return e;
            }
        }
        return null;
    }

    public Estudiante buscarPorNombreSecuencial(String nombre) {
        for (Estudiante e : estudiantes) {
            // equalsIgnoreCase para que no importen las mayúsculas/minúsculas
            if (e.getNombre().equalsIgnoreCase(nombre)) {
                return e;
            }
        }
        return null;
    }

    public Estudiante buscarPorCodigoBinario(int codigo) {
        // Para que la búsqueda binaria funcione, la lista DEBE estar ordenada
        ordenarPorCodigoAscendente();
        
        int inicio = 0;
        int fin = estudiantes.size() - 1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;
            Estudiante estudianteMedio = estudiantes.get(medio);

            if (estudianteMedio.getCodigo() == codigo) {
                return estudianteMedio; // Encontrado
            }
            if (estudianteMedio.getCodigo() < codigo) {
                inicio = medio + 1; // Buscar en la mitad superior
            } else {
                fin = medio - 1; // Buscar en la mitad inferior
            }
        }
        return null; // No encontrado
    }

    public ArrayList<Estudiante> ordenarPorPromedioDescendente() {
        int n = estudiantes.size();
        // Algoritmo de Burbuja manual
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (estudiantes.get(j).getPromedio() < estudiantes.get(j + 1).getPromedio()) {
                    // Intercambio
                    Estudiante temp = estudiantes.get(j);
                    estudiantes.set(j, estudiantes.get(j + 1));
                    estudiantes.set(j + 1, temp);
                }
            }
        }
        return estudiantes;
    }

    public ArrayList<Estudiante> ordenarPorCodigoAscendente() {
        int n = estudiantes.size();
        // Algoritmo de Burbuja manual
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (estudiantes.get(j).getCodigo() > estudiantes.get(j + 1).getCodigo()) {
                    // Intercambio
                    Estudiante temp = estudiantes.get(j);
                    estudiantes.set(j, estudiantes.get(j + 1));
                    estudiantes.set(j + 1, temp);
                }
            }
        }
        return estudiantes;
    }

    public int contarRecursivo(int indice) {
        // Caso base: si el índice alcanza el tamaño del arreglo, retornamos 0
        if (indice >= estudiantes.size()) {
            return 0;
        }
        // Llamada recursiva: sumamos 1 por el estudiante actual y avanzamos el índice
        return 1 + contarRecursivo(indice + 1);
    }

    public double sumaPromediosRecursiva(int indice) {
        // Caso base: si el índice alcanza el tamaño, retornamos 0.0
        if (indice >= estudiantes.size()) {
            return 0.0;
        }
        // Llamada recursiva: sumamos el promedio actual con el resto
        return estudiantes.get(indice).getPromedio() + sumaPromediosRecursiva(indice + 1);
    }

    public double promedioGeneralRecursivo() {
        int cantidad = contarRecursivo(0);
        if (cantidad == 0) {
            return 0.0; // Evitar división por cero
        }
        return sumaPromediosRecursiva(0) / cantidad;
    }

    public double mayorPromedioRecursivo(int indice) {
        // Caso base: si es el último elemento, retornamos su promedio
        if (indice == estudiantes.size() - 1) {
            return estudiantes.get(indice).getPromedio();
        }
        // Por si la lista está vacía
        if (indice >= estudiantes.size()){
            return 0.0;
        }
        
        // Obtenemos el mayor del resto de la lista recursivamente
        double mayorResto = mayorPromedioRecursivo(indice + 1);
        
        // Retornamos el máximo entre el actual y el mayor del resto
        return Math.max(estudiantes.get(indice).getPromedio(), mayorResto);
    }

    public int total() {
        return estudiantes.size();
    }
}

