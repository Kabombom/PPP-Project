#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/*
 Miguel Machado - 2014214547
 Pedro Coelho - 2009116949
 */

int main() {
    Paciente e = (Paciente) malloc(sizeof(Paciente_node));
    Paciente r = (Paciente) malloc(sizeof(Paciente_node));
    Paciente y = (Paciente) malloc(sizeof(Paciente_node));
    Paciente g = (Paciente) malloc(sizeof(Paciente_node));
    e = criaLista('E');
    r = criaLista('R');
    y = criaLista('Y');
    g = criaLista('G');
    menu(e, g, y, r);
    return 0;
}
