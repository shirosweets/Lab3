/* Materia: Algoritmos y Estructura de Datos II - 2020 FAMAF
    <<<<< LABORATORIO 3: TADS - EJ2>>>>>

Alumna:  
    - Vispo, Valentina Solange

Link de descarga: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:lab03_2020.zip

Teórico:
Tipos Abstractos de Datos: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.05.tipos.abstractos.pdf

Videos explicativos:
P1: https://youtu.be/f2EXztXim_4
P2: https://youtu.be/0P-T-43s2HM
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int type_elem; // Definición de tipo
typedef struct node *list; // lista puntero a estructura Node (apunta a)

/* Constructors */

list empty();
/*
    Crea una lista l vacía
*/

bool is_empty(list l); // modificar argumento maybe
/*
    Devuelve True si la lista l es vacía
*/

type_elem head(list l);
/* 
    Devuelve el primer elemento de la lista l
    PRE:not is_empty(l)
*/

list tail(list l);
/*
    Elimina el primer elemento de la lista l
    PRE:not is_empty(l)
*/

list addL(list l, type_elem e);
/*
    Agrega el elemento e al final de la lista l
*/

unsigned int length(list l);
/*
    Devuelve la cantidad de elementos de la lista l
*/

list concat(list l, list l0);
/*
    Agrega al final de l todos los elementos de l0 en el mismo orden
*/

type_elem index(list l, unsigned int n);
/*
    Devuelve el n-ésimo elemento de la lista l
    PRE:length(l) > n
*/

list take(list l, unsigned int n);
/*
    Elimina todos los elementos de l ubicados en las posiciones mayores o iguales a n
*/

list drop(list l, unsigned int n);
/*
    Elimina todos los elementos de l ubicados en las posiciones menores a n
*/

list copy_list(list l);
/*
    Copia todos los elementos de l
*/ 

/*list copy_list(list l1, list l2);*/
/*
    Copia todos los elementos de l1 en la nueva lista l2
*/ 

list destroy(list l);
/*
    Destruye la lista
*/

#endif