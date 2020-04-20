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

#include <stdbool.h>
#include <stdlib.h> // NULL, calloc, malloc
#include <assert.h> // Incluyo assert
#include <stdio.h> // printf

#include "list.h"

/*
    Para usar desde algún programa el tipo de las listas, alcanza con su especificación. Mediante 
    sus constructores empty y addl pueden crearse listas vacíaso agregar a una lista un elemento 
    nuevo, respectivamente. Las operaciones permiten manipular las listas de acuerdo a 
    la funcionalidad que el TAD provee. No es necesario conocer la implementación para poder usar el TAD.
*/

struct node{ // Defino y declaro la estructura
    // Campos
    type_elem elem;
    struct node *next;
}; 

/* Constructors */

list empty(){ // Crea una lista l vacía
    list l=NULL;
    return l;
} // FIN empty

bool is_empty(list l){ // Devuelve True si la lista l es vacía
    return l==NULL; // Retorna false si NO es vacía, true si es vacía
} // FIN is_empty

type_elem head(list l){ // Devuelve el primer elemento de la lista l
    // PRE:not is_empty(l)
    assert(!is_empty(l)); // Pre condición, verifico
    return l->elem;
}  // FIN head

/*  tail PSEUDOCÓDIGO
    {-PRE:not is_empty(l) -}
    proc tail(in/out l : List of T)
        var p :pointer to(Node of T)
        p := l
        l := l->next
        free(p)
    end proc
*/

list tail(list l){ // Elimina el primer elemento de la lista l
    // PRE:not is_empty(l)
    assert(!is_empty(l)); // Pre condición, verifico
    // Para eliminar el primer elemento de la lista creo un punto que apunta a la lista 
    list p=l; // es equivalente a poner list *p=l, solo que se omite porque en list.h se definió como puntero
    p=l;
    l=l->next;
    free(p);
    p=NULL; // Por la violación de segmento
    return l;
} // FIN tail

/* addL2 PSEUDOCÓDIGO
    proc addl (in e : T, in/out l : List of T)
        var p :pointer to(Node of T)
        alloc(p)
        p->elem := e
        p->next := l
        l := p
    end proc
*/

list addL2(list l, type_elem e){
    list p=(list) malloc (sizeof (struct node));
    p->elem=e;
    p->next=l;
    l=p;
    return l;
}

/*  addr PSEUDOCÓDIGO
    proc addr (in/out l : List of T, in e : T)
        var p,q :pointer to(Node of T)
        alloc(q)
        q->elem := e
        q->next :=null
        if(not is_empty(l))
            then p := l
            do(p->next !=null)
                p := p->next
            od
            p->next := q
            else l := q
        fi
    end proc
*/

list addL(list l, type_elem e){  // Agrega el elemento e al final de la lista l
    list node=(list) malloc(sizeof(struct node));
    if(node==NULL){ // Si node es nulo
        return NULL; // Retorna NULL
    }
    node->elem=e; // q->elem := e
    node->next=NULL; // q->next :=null
    if(l==NULL){ // Si l es nulo
        l=node;
    }
    else{
        node->next=l;
        l=node;
    }
    return l; // Retorno la lista
} // FIN addL

/*  length PSEUDOCÓDIGO
    fun length(l : List of T) ret n : nat
        var p :pointer to(Node of T)
        n := 0
        p := l
        do(p !=null)
            n := n+1
            p := p->next
        od
    end fun
*/

unsigned int length(list l){ // Devuelve la cantidad de elementos de la lista l
    unsigned int tam=0;
    if(l==NULL){  // Si l es vacío
        return tam;
    }
    list p=l;
    while(p!=NULL){
        tam=tam+1;
        p=p->next;
    }
    return tam; // Retorna el tamaño de l
} // FIN length

list concat(list l, list b){ // Agrega al final de l todos los elementos de l0 en el mismo orden
    list p = copy_list(b);
    list c = copy_list(l);
    if (!is_empty(b)){
        while (!is_empty(p->next)){
            addL(c, p->elem);
            p=p->next;
        }
    } 
    else{
        return c;
    }
    return c;
} // FIN concat

type_elem index(list l, unsigned int n){ // Devuelve el n-ésimo elemento de la lista l
    // PRE:length(l) > n
    type_elem a=0;
    unsigned int aux1=0;
    assert(length(l)>n); // Pre condición, verifico
    while(n-1>length(l)){
        //list p=p->next;
        l=l->next;
        aux1++;
        //a=l[aux1];
    }
    return a;
} // FIN index

list take(list l, unsigned int n){ // Elimina todos los elementos de l ubicados en las posiciones > o = a n
    printf("\n Take");
    assert(length(l)>=n && !is_empty(l)); // Pre condición, verifico
    list aux;
    while(length(l)<n){
        l=l->next;
        aux=l;
    }
    free(l); // Destruye lo almacenado en l
    while(length(l)!=0){ // 
        l=aux->next;
    }
    return l; // Retorna la lista l
} // FIN take

list drop(list l, unsigned int n){  // Elimina todos los elementos de l ubicados en las posiciones menores a n
    printf("\n Drop");
    // PRE:length(l) >= n
    assert(length(l)>=n); // Pre condición, verifico
    while(length(l)>n){
        l=l->next;
    }
    free(l); // Destruye lo almacenado en l
    list p;
    while(length(l)!=0){
        p=l->next;
    }
    return p;
} // FIN drop

list copy_list(list l){  // Copia todos los elementos de l
    if (is_empty(l)){
        return NULL;
    }
    list l2 = malloc(sizeof(struct node));
    l2 -> elem = l ->elem;
    l2 -> next = copy_list(l->next);
    return l2;
} // FIN copy_list

list destroy(list l){  // Destruye la lista
    list p=l;
    while(p!=NULL){
        l=l->next; // Lo recorro
        free(p); // Libero
        p=l;
    }
    free(l);
    return l=NULL;
} // FIN destroy
