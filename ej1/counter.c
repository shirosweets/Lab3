/* Materia: Algoritmos y Estructura de Datos II - 2020 FAMAF
    <<<<< LABORATORIO 3: TADS - EJ1>>>>>

Alumna:  
    - Vispo, Valentina Solange

Link de descarga: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:lab03_2020.zip

Teórico:
Tipos Abstractos de Datos: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.05.tipos.abstractos.pdf

Videos explicativos:
P1: https://youtu.be/f2EXztXim_4
P2: https://youtu.be/0P-T-43s2HM
*/

#include <stdbool.h>
#include <stdlib.h> // NULL, calloc, malloc
#include <assert.h> // Incluyo assert
#include <stdio.h> // printf

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter init(void) { // Create a new counter with initial count. Allocates new memory.
    //Needs implementation.
    // Para obtener el tamaño de un tipo en C recomendamos utilizar la función ​ sizeof​ .
    //counter c = calloc(1, sizeof(struct _counter)); // Le reservo memoria
    counter c = malloc(sizeof(struct _counter));
    assert(c!=NULL); // Verifico
    (*c).count=0; // Le asigno al campo el valor 0
    return c; // Retorno, Being c the returned counter, is_init(c) should be true.
} // FIN init

void inc(counter c) { // Increments the counter c.
    //Needs implementation.
    // ACA
    assert(c!=NULL); // Verifico
    c->count=c->count+1; // Aunmenta en 1
    //c->count++;
} // FIN inc

bool is_init(counter c) { // Return whether the counter c has the initial count.
    //Needs implementation.
    assert(c!=NULL); // Verifico
    return (c->count==0);
} // FIN is_init

void dec(counter c) { // Decrements the counter c.
    //Needs implementation.
    assert(!is_init(c)); //PRECONDITION: !is_init(c)
    c->count=c->count-1; // Disminuye en 1
} // FIN dec

counter copy_counter(counter c) { // Makes a copy of counter c. Allocates new memory.
    //Needs implementation.
    assert(c!=NULL); // Verifico
    counter a = c;
    return a; // Modificar
} // FIN copy_counter

void destroy_counter(counter c) { // Frees memory for c.
    //Needs implementation.
    free(c); // Libero
    //c=NULL; // Le pongo NULL para evitar violación de segmento
} // FIN destroy_counter
