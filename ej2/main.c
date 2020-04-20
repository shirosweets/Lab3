/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/*  Ejemplo de uso del TAD Lista
    fun promedio (l : List of float)ret r : float
        var largo : nat
        var elem : float
        var laux : List of float

        laux := copy(l)
        r := 0.0
        largo := length(l)
        do(not is_empty(laux))
            elem := head(laux)
            r := r + elem
            tail(laux)
        od
        destroy(laux)
        r := r / largo
    end proc
*/

float average(list l) { // Función promedio
    //Needs implementation.
    if(length(l)==0){ 
        return 0; // Retorna 0
    }
    type_elem largo;
    float r;
    float elem;
    list laux=NULL; // La inicializo en NULL

    laux=copy_list(l); // Copia la lista l
    //laux=copy_list(l, laux); // Copia la lista l tomada de argumento a laux
    r=0.0;
    largo=length(l);
    while(laux!=NULL){
        elem=head(laux);
        r=r+elem;
        laux=tail(laux);
    }

    destroy(laux); // Destruye la lista auxiliar
    r=r/largo;

    return r;
}

list array_to_list(int array[], unsigned int length) { // Convierte de array a lista (?)
    list l=empty(); // Initialize the list
    for (unsigned int i = 0u; i < length; ++i) {
        l=addL(l, array[i]);
    }
    return l; // Return list
}

int main(int argc, char *argv[]) {
    printf(" ********* Inicio programa *********\n\n");
    char *filepath = NULL;
    //FILE *file = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    array_dump(array, length);

    /* transform from array to our list type */
    list l = array_to_list(array, length);

    /* call the average function */
    printf("\n The average is: %.2f \n", average(l)); // ACA

    destroy(l);
    printf("\n ********* Fin programa *********\n");
    return (EXIT_SUCCESS);
}

/* PARA CORRER

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c list.c array_helpers.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o average *.o main.c
./average input/all-negative-100.in
./average input/all-positive-100.in
./average input/example-sorted.in
./average input/empty.in
./average input/example-unsorted.in

DEBUGEAR

gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -c list.c array_helpers.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -g -o average *.o main.c
gdb ./average input/all-negative-100.in

*/