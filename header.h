#include <stdio.h>
#include <stdlib.h>
/*
 Miguel Machado - 2014214547
 Pedro Coelho - 2009116949
 */
#define NAME_SIZE 100
#define BI_SIZE 20
#define READ_SIZE 4
#define PROTECTION_SIZE 30

int conta_y;
int conta_r;
int counter_r;
int counter_y;
int counter_g;

typedef struct Data
{
    int minuto, hora, dia, mes, ano;
}Data;

typedef struct lnode *Paciente;
typedef struct lnode
{
    char *nome;
    char *BI;
    Data data;
    Paciente seguinte;
}Paciente_node;

int bissexto(int ano);
char *protBI();
char *protNome();
int protMenu();
int protTri();
int protDelete();
int protAno();
int protMes();
int protDia(int ano, int mes);
int protHora();
int protMinuto();
Data criaData(int ano, int mes, int dia, int hora, int minuto);
Data printsData();
int comparaDatas(Data data1, Data data2);
Paciente criaLista(char cor);
Paciente criaPaciente(char *nome, char *BI, Data data);
Paciente printsPaciente();
void inserePaciente(Paciente paciente, Paciente lista);
void emergencia(Paciente red);
void triagem(Paciente espera, Paciente green, Paciente yellow, Paciente red);
void menu(Paciente espera, Paciente green, Paciente yellow, Paciente red);
int listaVazia(Paciente lista);
void delete(Paciente lista, char *BI);
void deleteList(Paciente lista);
void deleteOrdenado(Paciente lista);
void pacienteDelete(Paciente espera, Paciente green, Paciente yellow, Paciente red);
void consulta(Paciente lista);
void cura(Paciente green, Paciente yellow, Paciente red);
void imprimeLista(Paciente lista);
int counter(Paciente green, Paciente yellow, Paciente red);
void imprimeTodos(Paciente green, Paciente yellow, Paciente red);
void writeFile(FILE *fp, Paciente paciente);
void readFile(FILE *fp, Paciente lista);
void writeList(FILE *fp, Paciente lista);
