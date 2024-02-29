#include <stdio.h>
#include <malloc.h>

typedef struct Pila {
    int *valores;
    int postope;
} Pila;

void inicpila(Pila* p);
void apilar(Pila* p, int dato);
int desapilar(Pila* p);
int tope(Pila* p);
int pilavacia(Pila* p);
void leer (Pila* p);
void mostrar(Pila* p);
void borrarPila(Pila* p);
