#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void writeFile(FILE *fp, Paciente paciente) {
    char *nome = paciente -> nome;
    char *BI = paciente -> BI;
    Data data = paciente -> data;
    fprintf(fp, "%s,", nome);
    fprintf(fp, "%s,", BI);
    fprintf(fp, "%d,", data.ano);
    fprintf(fp, "%d,", data.mes);
    fprintf(fp, "%d,", data.dia);
    fprintf(fp, "%d,", data.hora);
    fprintf(fp, "%d\n", data.minuto);
}

void writeList(FILE *fp, Paciente lista) {
    Paciente paciente = lista -> seguinte;
    while (paciente != NULL) {
        writeFile(fp, paciente);
        fseek(fp, 1, SEEK_CUR);
        paciente = paciente -> seguinte;
    }
    fclose(fp);
}

void readFile(FILE *fp, Paciente lista) {
    Paciente paciente;
    Data data;
    char *BI = (char *) malloc(BI_SIZE * sizeof(char));
    char *nome = (char *) malloc(NAME_SIZE * sizeof(char));
    char *ano = (char *) malloc(READ_SIZE * sizeof(char));
    char *mes = (char *) malloc(READ_SIZE * sizeof(char));
    char *dia = (char *) malloc(READ_SIZE * sizeof(char));
    char *hora = (char *) malloc(READ_SIZE * sizeof(char));
    char *minuto = (char *) malloc(READ_SIZE * sizeof(char));
    while (fscanf(fp, "%[^,\n]", nome) != EOF) {
        /*incrementar para passar das virgulas*/
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^,\n]", BI);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^,\n]", ano);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^,\n]", mes);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^,\n]", dia);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^,\n]", hora);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^,\n]", minuto);
        fseek(fp, 2, SEEK_CUR);
        data = criaData(atoi(ano), atoi(mes), atoi(dia), atoi(hora), atoi(minuto));
        paciente = criaPaciente(nome, BI, data);
        inserePaciente(paciente, lista);
    }
    fclose(fp);
}
