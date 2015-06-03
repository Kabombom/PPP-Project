#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Paciente printsPaciente() {
    char *nome, *BI;
    Data data;
    Paciente paciente;
    printf("Nome do paciente: \n");
    getchar();
    nome = protNome();
    printf("BI do paciente: \n");
    getchar();
    BI = protBI();
    data = printsData();
    paciente = criaPaciente(nome, BI, data);
    return paciente;
}

Data printsData() {
    int ano, mes, dia, hora, minuto;
    Data data;
    printf("Ano: \n");
    getchar();
    ano = protAno();
    printf("Mês: \n");
    getchar();
    mes = protMes();
    printf("Dia: \n");
    getchar();
    dia = protDia(ano, mes);
    printf("Hora: \n");
    getchar();
    hora = protHora();
    printf("Minuto: \n");
    getchar();
    minuto = protMinuto();
    data = criaData(ano, mes, dia, hora, minuto);
    return data;
}
