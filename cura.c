#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void cura(Paciente green, Paciente yellow, Paciente red) {
    int check_r, check_g, check_y;
    check_r = listaVazia(red);
    check_y = listaVazia(yellow);
    check_g = listaVazia(green);
    if ((check_r == 1 && check_y == 1) && check_g == 1) {
        printf("Não se encontra nenhum paciente nas prioridades\n");
        return;
    }
    else if ((check_r == 1 && check_y == 1) && check_g == 0) {
        consulta(green);
        return;
    }
    else if ((check_r == 1 && check_g == 1) && check_y == 0) {
        consulta(yellow);
        return;
    }
    else if ((check_y == 1 && check_g == 1) && check_r == 0) {
        consulta(red);
        return;
    }
    else if (check_r == 1 && (check_y == 0 && check_g == 0)) {
        if (conta_y == 5) {
            consulta(green);
            conta_y = 0;
            return;
        }
        consulta(yellow);
        conta_y++;
        return;
    }
    else if (check_y == 1 && (check_r == 0 && check_g == 0)) {
        if (conta_r == 3) {
            consulta(green);
            conta_r = 0;
            return;
        }
        consulta(red);
        conta_r++;
        return;
    }
    else if (check_g == 1 && (check_r == 0 && check_y == 0)) {
        if (conta_r == 3) {
            consulta(yellow);
            conta_r = 0;
            return;
        }
        consulta(red);
        conta_r++;
        return;
    }
    else {
        if (conta_r == 3) {
            consulta(yellow);
            conta_y++;
            conta_r = 0;
            return;
        }
        else if (conta_y == 5) {
            consulta(green);
            conta_y = 0;
            return;
        }
        consulta(red);
        conta_r++;
        return;
    }
}
