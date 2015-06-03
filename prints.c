#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void imprimeLista(Paciente lista) {
    Paciente aux;
    aux = lista;
    if (aux -> seguinte == NULL)
        printf("Prioridade sem pacientes \n");
    else
    {
        aux = aux->seguinte;
        do
        {
            printf("%s - %s\n", aux -> nome, aux -> BI);
            aux = aux -> seguinte;
        }while(aux != NULL);
    }
}

int counter(Paciente green, Paciente yellow, Paciente red) {
    int check_g = listaVazia(green);
    int check_y = listaVazia(yellow);
    int check_r = listaVazia(red);

    if (check_g == 0) {
        Paciente aux3 = green -> seguinte;
        while (aux3 -> seguinte != NULL) {
            aux3 = aux3 -> seguinte;
            counter_g++;
        }
    }
    if (check_y == 0) {
        Paciente aux2 = yellow -> seguinte;
        while (aux2 -> seguinte != NULL) {
            aux2 = aux2 -> seguinte;
            counter_y++;
        }
    }
    if (check_r == 0) {
        Paciente aux1 = red -> seguinte;
        while (aux1 -> seguinte != NULL) {
            aux1 = aux1 -> seguinte;
            counter_r++;
        }
    }
    if (check_g == 1 && check_y == 1 && check_r == 1) {
        printf("Não existem pacientes \n");
        return 1;
    }
    return 0;
}

void imprimeTodos(Paciente green, Paciente yellow, Paciente red) {
    int i, j, k, compara;
    Paciente aux3, aux2, aux1;
    aux3 = green;
    aux2 = yellow;
    aux1 = red;
    int check_g = listaVazia(green);
    int check_y = listaVazia(yellow);
    int check_r = listaVazia(red);
    if (check_g == 0) {
        for (k = 0; k <= counter_g; k++) {
            aux3 = aux3 -> seguinte;
        }
    }
    else {
        counter_g--;
    }
    if (check_y == 0) {
        for (j = 0; j <= counter_y; j++) {
            aux2 = aux2 -> seguinte;
        }
    }
    else {
        counter_y--;
    }
    if (check_r == 0) {
        for (i = 0; i <= counter_r; i++) {
            aux1 = aux1 -> seguinte;
        }
    }
    else {
        counter_r--;
    }
    if (counter_r < 0 && counter_y < 0 && counter_g < 0) {
        counter_r = 0;
        counter_y = 0;
        counter_g = 0;
        return;
    }
    else if (counter_r < 0 && (counter_y >= 0 && counter_g >= 0)) {
        compara = comparaDatas(aux2 -> data, aux3 -> data);
        if (compara == 1) {
            printf("Prioridade amarela: \n");
            printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
            counter_y--;
            imprimeTodos(green, yellow, red);
        }
        else if (compara == (-1)) {
            printf("Prioridade verde: \n");
            printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
            counter_g--;
            imprimeTodos(green, yellow, red);
        }
        else {
            printf("Prioridade amarela: \n");
            printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
            printf("Prioridade verde: \n");
            printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
            counter_y--;
            counter_g--;
            imprimeTodos(green, yellow, red);
        }
    }
    else if (counter_y < 0 && (counter_r >= 0 && counter_g >= 0)) {
        compara = comparaDatas(aux1 -> data, aux3 -> data);
        if (compara == 1) {
            printf("Prioridade vermelha: \n");
            printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
            counter_r--;
            imprimeTodos(green, yellow, red);
        }
        else if (compara == (-1)) {
            printf("Prioridade verde: \n");
            printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
            counter_g--;
            imprimeTodos(green, yellow, red);
        }
        else {
            printf("Prioridade vermelha: \n");
            printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
            printf("Prioridade verde: \n");
            printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
            counter_r--;
            counter_g--;
            imprimeTodos(green, yellow, red);
        }
    }
    else if (counter_g < 0 && (counter_r >= 0 && counter_y >= 0)) {
        compara = comparaDatas(aux1 -> data, aux2 -> data);
        if (compara == 1) {
            printf("Prioridade vermelha: \n");
            printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
            counter_r--;
            imprimeTodos(green, yellow, red);
        }
        else if (compara == (-1)) {
            printf("Prioridade amarela: \n");
            printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
            counter_y--;
            imprimeTodos(green, yellow, red);
        }
        else {
            printf("Prioridade vermelha: \n");
            printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
            printf("Prioridade amarela: \n");
            printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
            counter_r--;
            counter_y--;
            imprimeTodos(green, yellow, red);
        }
    }
    else if (counter_r >= 0 && (counter_g < 0 && counter_y < 0)) {
        compara = comparaDatas(aux1 -> data, aux1 -> data);
        printf("Prioridade vermelha: \n");
        printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
        counter_r--;
        imprimeTodos(green, yellow, red);
    }
    else if (counter_y >= 0 && (counter_g < 0 && counter_r < 0)) {
        compara = comparaDatas(aux2 -> data, aux2 -> data);
        printf("Prioridade amarela: \n");
        printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
        counter_y--;
        imprimeTodos(green, yellow, red);
    }
    else if (counter_g >= 0 && (counter_y < 0 && counter_r < 0)) {
        compara = comparaDatas(aux3 -> data, aux3 -> data);
        printf("Prioridade verde: \n");
        printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
        counter_g--;
        imprimeTodos(green, yellow, red);
    }
    else {
        compara = comparaDatas(aux1 -> data, aux2 -> data);
        if (compara == 1) {
            compara = comparaDatas(aux1 -> data, aux3 -> data);
            if (compara == 1) {
                printf("Prioridade vermelha: \n");
                printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
                counter_r--;
                imprimeTodos(green, yellow, red);
            }
            else if (compara == (-1)) {
                printf("Prioridade verde: \n");
                printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
                counter_g--;
                imprimeTodos(green, yellow, red);
            }
            else {
                printf("Prioridade vermelha: \n");
                printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
                printf("Prioridade verde: \n");
                printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
                counter_r--;
                counter_g--;
                imprimeTodos(green, yellow, red);
            }
        }
        else if (compara == (-1)) {
            compara = comparaDatas(aux2 -> data, aux3 -> data);
            if (compara == 1) {
                printf("Prioridade amarela: \n");
                printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
                counter_y--;
                imprimeTodos(green, yellow, red);
            }
            else if (compara == (-1)) {
                printf("Prioridade verde: \n");
                printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
                counter_g--;
                imprimeTodos(green, yellow, red);
            }
            else {
                printf("Prioridade amarela: \n");
                printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
                printf("Prioridade verde: \n");
                printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
                counter_y--;
                counter_g--;
                imprimeTodos(green, yellow, red);
            }
        }
        else {
                compara = comparaDatas(aux1 -> data, aux3 -> data);
                if (compara == 1) {
                    printf("Prioridade vermelha: \n");
                    printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
                    printf("Prioridade amarela: \n");
                    printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
                    counter_r--;
                    counter_y--;
                    imprimeTodos(green, yellow, red);
                }
                else if (compara == (-1)) {
                    printf("Prioridade verde: \n");
                    printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
                    counter_g--;
                    imprimeTodos(green, yellow, red);
                }
                else {
                    printf("Prioridade vermelha: \n");
                    printf("%s - %s\n", aux1 -> nome, aux1 -> BI);
                    printf("Prioridade amarela: \n");
                    printf("%s - %s\n", aux2 -> nome, aux2 -> BI);
                    printf("Prioridade verde: \n");
                    printf("%s - %s\n", aux3 -> nome, aux3 -> BI);
                    counter_r--;
                    counter_y--;
                    counter_g--;
                    imprimeTodos(green, yellow, red);
                }
        }
    }
}
