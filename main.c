/**************************************************
NOMBRE:Victor Jofre Miranda
ASIGNATURA:Estructura de Datos
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Estructura Principal*/
struct nodoArbol {
    int Info;
    struct nodoArbol *ptrIzq;
    struct nodoArbol *prtDer;
};

typedef struct nodoArbol NodoArbol; /*Estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol; /*NodoArbol* */

/*Invocando Funciones*/
void insertaNodo(ptrNodoArbol *ptrArbol, int valor);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);


/*Inserta un nodo dentro del árbol */
void insertaNodo(ptrNodoArbol *ptrArbol, int valor){
 /*Validacion encaso de árbol vacio */
 if (*ptrArbol == NULL) {
    *ptrArbol = (ptrNodoArbol)malloc(sizeof(NodoArbol));
 /*En caso que exista memoria asignada, entonces asigna la informacion */
     if (*ptrArbol != NULL) {
        (*ptrArbol)->Info = valor;
        (*ptrArbol)->ptrIzq = NULL;
        (*ptrArbol)->prtDer = NULL;
        }else{
            printf("\nNo se inserto %d. No hay memoria disponible.\n", valor);
        }
    }else{
 /* La informacion < dato en el nodo actual */
         if (valor < (*ptrArbol)->Info) {
         insertaNodo(&((*ptrArbol)->ptrIzq), valor);
         } else if (valor > (*ptrArbol)->Info) {
         insertaNodo(&((*ptrArbol)->prtDer), valor);
             } else {
             printf(" Duplicado\n");/* Informacion ingresada = valor nodo,  se tomara como duplicado*/
             }
        }
    }

/*Recorrido InOrden del árbol*/
void inOrden(ptrNodoArbol ptrArbol){
 /*Se recorre el árbol en caso que no este vacio*/
     if (ptrArbol != NULL) {
     inOrden(ptrArbol->ptrIzq);
     printf("%3d", ptrArbol->Info);
     inOrden(ptrArbol->prtDer);
     }
}

/*Recorrido PreOrden del árbol */
void preOrden(ptrNodoArbol ptrArbol){
 /*Se recorre el árbol en caso que no este vacio*/
     if (ptrArbol != NULL) {
     printf("%3d", ptrArbol->Info);
     preOrden(ptrArbol->ptrIzq);
     preOrden(ptrArbol->prtDer);
     }
}

/*Recorrido PostOrden del árbol */
void postOrden(ptrNodoArbol ptrArbol){
/*Se recorre el árbol en caso que no este vacio*/
     if (ptrArbol != NULL) {
     postOrden(ptrArbol->ptrIzq);
     postOrden(ptrArbol->prtDer);
     printf("%3d", ptrArbol->Info);
     }
}

int contarNodos (ptrNodoArbol ptrArbol){
    if(ptrArbol== NULL){
        return 0;}
    else{
        return(1+ contarNodos(ptrArbol->prtDer) + contarNodos(ptrArbol->ptrIzq));}
}

int contarHojas(ptrNodoArbol ptrArbol){
    if(ptrArbol== NULL){
        return 0;}
    if((ptrArbol->prtDer== NULL) && (ptrArbol->ptrIzq== NULL)){
        return 1;}
    else{
    return contarHojas(ptrArbol->ptrIzq) + contarHojas(ptrArbol->prtDer);}
}

int profundidad(ptrNodoArbol ptrArbol){
    if(ptrArbol== NULL){
        return 0;
    }
    if(profundidad (ptrArbol->prtDer) > profundidad (ptrArbol->ptrIzq)){
        return profundidad (ptrArbol->prtDer) + 1;}
    else{
        return profundidad(ptrArbol->ptrIzq) + 1;}
}
/*Menu*/
int main(){
     int i;
     int elemento; /*Almacena valores random*/
     ptrNodoArbol ptrRaiz = NULL; /* Árbol vacío al inicio */

     srand(time(NULL));
     printf("\nLos numeros colocados en el arbol son:\n");

/*Insertando valores entre 1 y 20 en el árbol*/
     for (i = 1; i <= 10; i++) {
         elemento = rand() % 20;
         printf("%3d", elemento);
         insertaNodo(&ptrRaiz, elemento);
    }

/*Recorriendo PreOrden*/
     printf("\nEl recorrido en preorden es:\n");
     preOrden(ptrRaiz);

/*Recorriendo InOrden*/
     printf("\nEl recorrido inorden es:\n");
     inOrden(ptrRaiz);

/*Recorriendo PostOrden*/
     printf("\nEl recorrido en postOrden es:\n");
     postOrden(ptrRaiz);

     return 0;
}
