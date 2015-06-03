#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int listaVazia(Paciente lista) {
    return(lista -> seguinte == NULL ? 1:0);
}

Paciente criaLista(char cor) {
    Paciente aux;
    Data data = criaData(0,0,0,0,0);
    char *string = "head";
    aux = (Paciente) malloc(sizeof(Paciente_node));
    aux -> nome = (char *) malloc ((strlen(string) + 1) * sizeof(char));
    aux -> BI = (char *) malloc ((strlen(string) + 1) * sizeof(char));
    if (aux != NULL) {
        strcpy(aux -> nome, string);
        strcpy(aux -> BI, string);
        aux -> data = data;
        aux -> seguinte = NULL;
    }
    return aux;
}

Paciente criaPaciente(char *nome, char *BI, Data data) {
    Paciente aux;
    aux = (Paciente) malloc (sizeof(Paciente_node));
    aux -> nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    aux -> BI = (char *) malloc((strlen(BI) + 1) * sizeof(char));
    strcpy(aux -> nome, nome);
    strcpy(aux -> BI, BI);
    aux -> data = data;
    aux -> seguinte = NULL;
    return aux;
}

void inserePaciente(Paciente paciente, Paciente lista) {
    Paciente aux;
    int data;
    aux = lista;
    while (aux -> seguinte != NULL) {
        data = comparaDatas(paciente -> data, (aux -> seguinte) -> data);
        if (data != 1) {
            paciente -> seguinte = aux -> seguinte;
            aux -> seguinte = paciente;
            return;
        }
        aux = aux -> seguinte;
    }
    aux -> seguinte = paciente;
    paciente -> seguinte = NULL;
}

void emergencia(Paciente red) {
    Paciente paciente = printsPaciente();
    inserePaciente(paciente, red);
}
