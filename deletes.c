#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void delete(Paciente lista, char *BI) {
    /* Vai para o nó em que o nó seguinte tem de ser eliminado*/
    Paciente aux;
    aux = lista;
    while(aux -> seguinte != NULL && strcmp(((aux -> seguinte) -> BI), BI) != 0) {
        aux = aux -> seguinte;
    }
    if(aux -> seguinte == NULL) {
        printf("Paciente não encontrado\n");
        return;
    }
    Paciente temp;
    temp = aux -> seguinte;
    /*temp aponta para o node a ser eliminado*/
    aux -> seguinte = temp -> seguinte;
    free(temp -> BI);
    free(temp -> nome);
    free(temp);
    return;
}

void deleteOrdenado(Paciente lista) {
    Paciente temp = lista -> seguinte;
    lista -> seguinte = temp -> seguinte;
    return;
}

void consulta(Paciente lista) {
    Paciente temp = lista -> seguinte;
    lista -> seguinte = temp -> seguinte;
    free(temp -> BI);
    free(temp -> nome);
    free(temp);
    return;
}

void pacienteDelete(Paciente espera, Paciente green, Paciente yellow, Paciente red) {
    char *BI;
    int test, check_r, check_y, check_g, check_e;
    check_e = listaVazia(espera);
    check_g = listaVazia(green);
    check_y = listaVazia(yellow);
    check_r = listaVazia(red);
    printf("[1]-->Espera\n[2]-->Verde\n[3]-->Amarela\n[4]-->Vermelha\n[5]-->Voltar atrás\n");
    printf("Em que prioridade se encontra o paciente? \n");
    getchar();
    test = protMenu();
    switch (test) {
        case 1:
            if (check_e == 1) {
                printf("Não existem pacientes na espera \n");
                return;
            }
            printf("Insira o BI do paciente para retirar: \n");
            getchar();
            BI = protBI();
            delete(espera, BI);
            break;
        case 2:
            if (check_g == 1) {
                printf("Não existem pacientes na prioridade \n");
                return;
            }
            printf("Insira o BI do paciente para retirar: \n");
            getchar();
            BI = protBI();
            delete(green, BI);
            break;
        case 3:
            if (check_y == 1) {
                printf("Não existem pacientes na prioridade \n");
                return;
            }
            printf("Insira o BI do paciente para retirar: \n");
            getchar();
            BI = protBI();
            delete(yellow, BI);
            break;
        case 4:
            if (check_r == 1) {
                printf("Não existem pacientes na prioridade \n");
                return;
            }
            printf("Insira o BI do paciente para retirar: \n");
            getchar();
            BI = protBI();
            delete(red, BI);
            break;
        case 5:
            return;
        default:
            printf("Prioridade não existente \n");
            break;
    }
}

void deleteList(Paciente lista) {
    Paciente aux = lista;
    Paciente next;
    while (aux != NULL) {
        next = aux -> seguinte;
        free(aux -> nome);
        free(aux -> BI);
        free(aux);
        aux = next;
    }
    lista = NULL;
}
