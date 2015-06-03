#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void triagem(Paciente espera, Paciente green, Paciente yellow, Paciente red) {
    int test, check;
    check = listaVazia(espera);
    if (check == 1) {
        printf("Não existem pacientes em espera para a triagem\n");
        return;
    }
    else {
        Paciente paciente = espera->seguinte;
        getchar();
        printf("[1]-Verde \n"
               "[2]-Amarelo \n"
               "[3]-Vermelho \n"
               "[4]-Voltar Atrás \n"
               "O que pretende fazer: \n");
        test = protMenu();
        switch(test) {
            case 1:
                deleteOrdenado(espera);
                inserePaciente(paciente, green);
                break;
            case 2:
                deleteOrdenado(espera);
                inserePaciente(paciente, yellow);
                break;
            case 3:
                deleteOrdenado(espera);
                inserePaciente(paciente, red);
                break;
            case 4:
                return;
                break;
            default:
                printf("Comando inválido \n");
                triagem(espera, green, yellow, red);
                break;
        }
    }
}
