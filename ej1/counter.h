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

#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

/* counter as a pointer to structs to guarantee encapsulation */
typedef struct _counter *counter; // Definido como puntero

/* Constructors */
counter init(void);
/*
    Create a new counter with initial value. Allocates new memory.
    Being c the returned counter, is_init(c) should be true.
*/

void inc(counter c);
/*
    Increments the counter c.
*/

/* Operations */
bool is_init(counter c);
/*
    Return whether the counter c has the initial value.
*/

void dec(counter c);
/*
    Decrements the counter c.
    PRECONDITION: !is_init(c)
*/

counter copy_counter(counter c);
/*
    Makes a copy of counter c. Allocates new memory.
*/

void destroy_counter(counter c);
/*
   Frees memory for c.
*/

#endif
