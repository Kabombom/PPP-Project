#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void menu(Paciente espera, Paciente green, Paciente yellow, Paciente red) {
    int test;
    FILE *fp;
    fp = fopen("espera.txt", "r");
    readFile(fp, espera);
    fp = fopen("green.txt", "r");
    readFile(fp, green);
    fp = fopen("yellow.txt", "r");
    readFile(fp, yellow);
    fp = fopen("red.txt", "r");
    readFile(fp, red);
    Paciente paciente;
    while (1) {
        printf("[1]-->Admitir paciente \n"
               "[2]-->Triagem \n"
               "[3]-->Cancelar um paciente \n"
               "[4]-->Listar os pacientes de cada prioridade(mais antigos para mais recentes) \n"
               "[5]-->Listar os pacientes de todas as prioridades(os mais recentes primeiros) \n"
               "[6]-->Proximo paciente a ser atendido \n"
               "[7]-->Emergência (inserir paciente diretamente na prioridade vermelha) \n"
               "[8]-->Sair \n"
              );
        test = protMenu();
        switch (test) {
            case 1:
                paciente = printsPaciente();
                inserePaciente(paciente, espera);
                fp = fopen("espera.txt", "w");
                writeList(fp, espera);
                break;
            case 2:
                triagem(espera, green, yellow, red);
                fp = fopen("espera.txt", "w");
                writeList(fp, espera);
                fp = fopen("green.txt", "w");
                writeList(fp, green);
                fp = fopen("yellow.txt", "w");
                writeList(fp, yellow);
                fp = fopen("red.txt", "w");
                writeList(fp, red);
                break;
            case 3:
                pacienteDelete(espera, green, yellow, red);
                fp = fopen("espera.txt", "w");
                writeList(fp, espera);
                fp = fopen("green.txt", "w");
                writeList(fp, green);
                fp = fopen("yellow.txt", "w");
                writeList(fp, yellow);
                fp = fopen("red.txt", "w");
                writeList(fp, red);
                break;
            case 4:
                printf("Pacientes em espera para triagem: \n");
                imprimeLista(espera);
                printf("Pacientes de prioridade verde: \n");
                imprimeLista(green);
                printf("Pacientes de prioridade amarela: \n");
                imprimeLista(yellow);
                printf("Pacientes de prioridade vermelha \n");
                imprimeLista(red);
                break;
            case 5:
                counter(green, yellow, red);
                imprimeTodos(green, yellow, red);
                break;
            case 6:
                cura(green, yellow, red);
                fp = fopen("green.txt", "w");
                writeList(fp, green);
                fp = fopen("yellow.txt", "w");
                writeList(fp, yellow);
                fp = fopen("red.txt", "w");
                writeList(fp, red);
                break;
            case 7:
                emergencia(red);
                fp = fopen("red.txt", "w");
                writeList(fp, red);
                break;
            case 8:
                deleteList(espera);
                deleteList(green);
                deleteList(yellow);
                deleteList(red);
                return;
            default:
                printf("Comando inválido \n");
                break;
        }
    }
}
