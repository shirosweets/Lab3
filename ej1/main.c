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

/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "counter.h"

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Check if in a given file there is a perfect match between all opening and closing parentheses.\n"
           "\n",
           program_name);
}

FILE * open_input_file(const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    return (file);
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

bool matching_parentheses(FILE * file) {
    counter c = NULL; // Crea el counter c como NULL
    bool balanced = true;
    char letter;

    //Agregado
    c = init();
    //
    while (!feof(file) && balanced) {
        letter = fgetc(file);
        if (letter == '(') {
            inc(c); // Aunmenta en 1 el contador c
        } else if (is_init(c)) {
            balanced = (letter != ')');
        } else if (letter == ')') {
            dec(c); // Disminuye en 1 el contador c
        }
    }
    //
    balanced = (balanced && is_init(c));
    destroy_counter(c);
    return (balanced); // Retorna el balance
}

int main(int argc, char *argv[]) {
    printf(" ********* Inicio programa *********\n\n");

    char *filepath = NULL;
    FILE *file = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* open the input file */
    file = open_input_file(filepath);

    /* call the function for the matching parentheses check */
    if (matching_parentheses(file)) {
        printf("Parentheses match.\n");
    } else {
        printf("Parentheses mismatch.\n");
    }

    printf("\n ********* Fin programa *********\n");
    return (EXIT_SUCCESS);
}