#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Data criaData(int ano, int mes, int dia, int hora, int minuto) {
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    data.hora = hora;
    data.minuto = minuto;
    return data;
}

/*Retorna -1 se data2 for mais antiga, 1 se data1 for mais antiga e 0 se for a mesma data*/
int comparaDatas(Data data1, Data data2) {
    long int aux1, aux2;
    aux1 = ((long int)data1.ano * 100000000)
            + ((long int)data1.mes * 1000000)
            + ((long int)data1.dia * 10000)
            + ((long int)data1.hora * 100)
            + (long int)data1.minuto;
    aux2 = ((long int)data2.ano * 100000000)
            + ((long int)data2.mes * 1000000)
            + ((long int)data2.dia * 10000)
            + ((long int)data2.hora * 100)
            + (long int)data2.minuto;
    if (aux1 < aux2)
        return -1;
    else if (aux1 > aux2)
        return 1;
    else
        return 0;
}
