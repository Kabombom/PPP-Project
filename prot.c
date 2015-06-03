#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int bissexto(int ano) {
    int verifica = 0;
    if (( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0) {
        verifica = 1;
        return verifica;
    }
    return verifica;
}

int protMenu() {
    int check;
    char str[PROTECTION_SIZE];
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou simbolos \n");
                break;
            }
            i++;
        }
        if (i == len) {
            check = atoi(str);
            return check;
        }
     }
    return 0;
}

char *protBI() {
    char *str = (char *) malloc(BI_SIZE * sizeof(char));
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou simbolos \n");
                break;
            }
            i++;
        }
        if (i == len) {
            if (len == 9) {
                return str;
            }
            else {
                printf("BI inválido \n");
            }
        }
    }
    return 0;
}

char *protNome() {
    char *str = (char *) malloc(NAME_SIZE * sizeof(char));
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
                printf("Não pode introduzir números ou símbolos \n");
                break;
            }
            i++;
        }
        if (i == len) {
            if (str[0] >= 'a' && str[0] <= 'z') {
                printf("Nome Inválido \n");
            }
            else {
                return str;
            }
        }
    }
    return 0;
}

int protAno() {
    int check;
    char str[PROTECTION_SIZE];
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou símbolos\n");
                break;
            }
            i++;
        }
        if (i == len) {
            if (atoi(str) < 2010 || atoi(str) > 2030) {
                printf("Ano inválido \n");
                i = 0;
            }
            else {
                check = atoi(str);
                return check;
            }
        }
     }
    return 0;
}

int protMes() {
    int check;
    char str[PROTECTION_SIZE];
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou simbolos\n");
                break;
            }
            i++;
        }
        if (i == len) {
            if (atoi(str) < 1 || atoi(str) > 12) {
                printf("Mês inválido \n");
                i = 0;
            }
            else {
                check = atoi(str);
                return check;
            }
        }
     }
    return 0;
}

int protDia(int ano, int mes) {
    int check;
    int verifica;
    char str[PROTECTION_SIZE];
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou simbolos \n");
                break;
            }
            i++;
        }
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            if (atoi(str) > 31) {
                    printf("Dia invalido \n");
                    i = 0;
            }
            if (atoi(str) < 1) {
                printf("Dia inválido \n");
                i = 0;
            }
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (atoi(str) > 30) {
                    printf("Dia invalido \n");
                    i = 0;
            }
            if (atoi(str) < 1) {
                printf("Dia inválido \n");
                i = 0;
            }
        }
        else if (mes == 2) {
            verifica = bissexto(ano);
            if (verifica == 1) {
                if (atoi(str) > 29) {
                    printf("Dia inválido \n");
                    i = 0;
                }
            }
            else {
                if (atoi(str) > 28) {
                    printf("Dia inválido \n");
                    i = 0;
                }
            }
        }
        if (i == len) {
            check = atoi(str);
            return check;
        }
     }
    return 0;
}

int protHora() {
    int check;
    char str[PROTECTION_SIZE];
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou simbolos \n");
                break;
            }
            i++;
        }
        if (i == len) {
            if (atoi(str) < 0 || atoi(str) > 23) {
                printf("Hora inválido \n");
            }
            else {
                check = atoi(str);
                return check;
            }
        }
     }
    return 0;
}

int protMinuto() {
    int check;
    char str[PROTECTION_SIZE];
    while (scanf(" %[^\n]", str) ) {
        int i = 0;
        int len = strlen(str);
        while (i < len) {
            if (str[i] < '0' || str[i] > '9') {
                printf("Não pode introduzir letras ou simbolos \n");
                break;
            }
            i++;
        }
        if (i == len) {
            if (atoi(str) < 0 || atoi(str) > 59) {
                printf("Minuto inválido \n");
            }
            else {
                check = atoi(str);
                return check;
            }
        }
     }
    return 0;
}
