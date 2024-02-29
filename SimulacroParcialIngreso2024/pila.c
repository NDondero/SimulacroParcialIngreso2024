#include "pila.h"

void inicpila(Pila* p) {
    int *aux;
    aux = (int *)malloc(50*sizeof(int));
    p->valores = aux;
    p->postope=0;
}

void apilar(Pila* p, int dato) {
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(Pila* p) {
    int z = p->valores[p->postope -1];
    p->postope--;
    return z;
}

int tope(Pila* p) {
    return p->valores[p->postope - 1];
}

int pilavacia(Pila* p) {
    return (p->postope == 0);
}

void leer (Pila* p) {
    int aux = 0;
    if (p->postope < 50) {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    } else
        printf("Error: la pila esta llena");
}

void mostrar(Pila* p) {
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}

void borrarPila(Pila* p) {
    free(p->valores);
    inicpila(p);
}
