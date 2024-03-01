#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
 * Diseñe un sistema sencillo con un menú principal que le permita al usuario
 * cargar cuantas notas necesite cargar,
 * visualizar las notas cuantas veces quiera,
 * visualizar la mayor nota, la menor, la cantidad de notas
 * y el promedio general.
 *
 * Para lograr este sistema va a utilizar un switch y
 * una Pila para guardar las notas.
 * Considere la posibilidad de que el usuario
 * quiera ver estadísticas antes de cargar notas.
 * Considere que el usuario podría querer
 * cargar mas notas sobre las que ya tiene o desecharlas para cargar nuevas.
 * No olvide validar las notas entre el 1 y el 10.
 *
 * NOTA: para la posibilidad de desechar los valores de la Pila,
 * se agregó una función vaciarPila()
 * como todas las demás funciones recibe la pila por parámetro
 * con el operador ampersand
 * ej: vaciarPila(&miPila);
 */

int main() {
    Pila notas, aux;
    inicpila(&notas);
    inicpila(&aux);

    const int notaMinimaLimite = 1;
    const int notaMaximaLimite = 10;
    int opcion, nota, notaMaxima, notaMinima;
    int sumatorioNotas = 0, cantidadNotas = 0;
    int cantidadNotasPares = 0, cantidadNotasImpares = 0;
    float promedio;
    char seguir;

    printf("\tBienvenido al sistema de carga de notas del nivelatorio\n\n");
    printf("\tSeleccione una opcion\n\n");
    do {
        printf("\t1 - Cargar notas\n");
        printf("\t2 - Ver notas\n");
        printf("\t3 - Ver estadisticas generales\n");
        printf("\t4 - Borrar notas\n");
        printf("\t0 - Salir\n");
        printf(">>>> ");
        scanf("%i", &opcion);
        switch (opcion) {
        case 1:
            do {
                printf("\tIngrese una nota\n>>>> ");
                scanf("%i", &nota);
                while (nota < notaMinimaLimite || nota > notaMaximaLimite) {
                    printf("\tNota invalida, ingrese una nota entre %i y %i\n>>>> ", notaMinimaLimite, notaMaximaLimite);
                    scanf("%i", &nota);
                }
                apilar(&notas, nota);
                printf("\n\tDesea cargar otra nota? s/n\n\n>>>> ");
                fflush(stdin);
                scanf("%c", &seguir);
            } while (seguir == 's');
            break;
        case 2:
            if (!pilavacia(&notas)) {
                printf("\tSus notas hasta el momento\n\n");
                mostrar(&notas);
            } else {
                printf("\tNo tiene notas cargadas, cargue notas.\n\n");
            }
            break;
        case 3:
            if (!pilavacia(&notas)) {
                int topeActual = tope(&notas);
                notaMaxima = topeActual;
                notaMinima = topeActual;
                apilar(&aux, desapilar(&notas));
                cantidadNotas++;
                sumatorioNotas += topeActual;
                while (!pilavacia(&notas)) {
                    topeActual = tope(&notas);
                    if(topeActual > notaMaxima) {
                        notaMaxima = topeActual;
                    }
                    if (topeActual < notaMinima) {
                        notaMinima = topeActual;
                    }
                    if (topeActual % 2 == 0) {
                        cantidadNotasPares++;
                    } else {
                        cantidadNotasImpares++;
                    }
                    sumatorioNotas += topeActual;
                    cantidadNotas++;
                    apilar(&aux, desapilar(&notas));
                }
                while (!pilavacia(&aux)) {
                    apilar(&notas, desapilar(&aux));
                }
                promedio = (float)sumatorioNotas / cantidadNotas;
                if (cantidadNotas == 1) {
                    printf("\tSe ha cargado 1 nota\n\n");
                } else {
                    printf("\tSe han cargado %i notas\n\n", cantidadNotas);
                }
                printf("\tLa nota mas alta es %i\n\n\tLa nota mas baja es %i\n\n\tEl promedio general es %.2f\n\n", notaMaxima, notaMinima, promedio);
                printf("\tDe todas las notas %i son pares y %i son impares\n\n", cantidadNotasPares, cantidadNotasImpares);
            } else {
                printf("\tNo tiene notas cargadas, cargue notas.\n\n");
            }
            break;
        case 4:
            if (!pilavacia(&notas)) {
                printf("\tSe han desechado las notas cargadas hasta el momento.\n\n");
                vaciarPila(&notas);
            } else {
                printf("\tNo tiene notas cargadas, cargue notas.\n\n");
            }
            break;
        case 0:
            printf("\tHasta luego!\n\n");
            break;
        default:
            printf("\tOpcion invalida\n\n");
            break;
        }
        system("pause");
        system("cls");
    } while (opcion != 0);
    return 0;
}
