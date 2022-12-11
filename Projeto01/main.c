///METER AS FUNCOES EM FICHEIROS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"

//defines
#define valorMulta 10
#define MAX_STRING 80
#define MAX_PORTATIL 30

typedef struct
{
    int dia, mes, ano;
} tipoData;

/*typedef struct
{
    char cod[5];
    tipoData dataDevolucao;
    char localDevolucao[11];
    float multa;
} tipoDevolucao;*/

typedef struct
{
    int id;
    char processador[2];
    int ram;
    char designacao[MAX_STRING];
    char estado[11];
    char localizacao[11];
    tipoData dataAquisicao;
    float valor;
} tipoPc;

typedef struct
{
    char cod[5];
    tipoPc id;
    char designacao[MAX_STRING];
    char nomeUtente[MAX_STRING];
    char tipoUtente[20];
    tipoData dataRequisicao;
    int prazo[30];
    char estadoRequisicao[15];
    //tipoDevolucao inforDevolucao;
    tipoData dataDevolucao;
    char localDevolucao[11];
    float multa;
} requisicao;

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
tipoPc adicionarPortatil();
void limparEcra();
/*int procuraId(tipoPc vetor[], int num, int aProcurar);
int procuraPc(tipoPc vetor[], int num, int aProcurar);*/
void lerProcessador(char processador[2]);
void listarPortateis(tipoPc vetor[]);
void limpaBufferStdin(void);
char menu();

int main()
{
    tipoPc portateis[MAX_PORTATIL];
    printf("\t\t GRCP |  Gestao da Requisicao de Computadores Portateis \n\n\n");
    setlocale(LC_ALL, "");
    char op;
    do
    {
        op = menu(MAX_PORTATIL,);       //Falta colocar o numero de Requisoções, numero de portateis disponiveis e numero de requisçoes ativas
        switch(op)
        {
        case 'A':
            adicionarPortatil();
            break;
        case 'B':
            listarPortateis(portateis);
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'E':
            break;
        case 'F':
            break;
        case 'G':
            break;
        case 'H':
            break;
        case 'I':
            break;
        case 'J':
            break;
        case 'K':
            break;
        case 'L':
            break;
        case 'M':
            break;
        case 'N':
            break;
        case 'O':
            break;
        }
    }
    while (op != 'O');
    return 0;
}

/*char menu()
{

    char op;
    printf("\t\t\t\tMenu Principal\n\n");
    printf("Portateis existentes: \t\t\t\t\tNumero Total de requisicoes efetuadas: ");
    printf("\nPortateis disponiveis: \t\t\t\t\tNumero de requisicoes ativas: ");
    printf("\n\n[A]Adicionar Portatil");
    printf("\n[B]Listar Portateis");
    printf("\n[C]Alterar Localizacao de um portatil");
    printf("\n[D]Requesitar um Portatil");
    printf("\n[E]Renovar requisicao de um portatil");
    printf("\n[F]Listar requesicoes");
    printf("\n[G]Informacao de uma requisicao");
    printf("\n[H]Registar Avaria");
    printf("\n[I]Listar Avarias");
    printf("\n[J]Registar devolucao");
    printf("\n[K]Registar reparacao");
    printf("\n[L]Armazenar informação portateis e requisicoes em ficheiro binario");
    printf("\n[M]Mostrar (ler) dados armazenados em ficheiro binarios ");
    printf("\n[N]Dados Estatisticos");
    printf("\n[O] SAIR");
    printf("\nOpcao >> ");
    scanf(" %c", &op);
    op = toupper(op);
    return op;
}*/

void lerProcessador(char processador[2]){
    char op;
    do{
    printf("\nIndique o processador:");
    printf("\n[A] I3");
    printf("\n[B] I5");
    printf("\n[C] I7");
    printf("\n\tOPCAO >> ");scanf(" %c", &op);
    op = toupper(op);
    if(op != 'A' && op != 'B' && op != 'C'){
        printf("\nERRO | OPCAO INVALIDA\n");
    }
    }while (op != 'A' && op != 'B' && op != 'C');

    if (op == 'A'){
        strcpy(processador, "I3");
    }else if (op == 'B'){
        strcpy(processador, "I5");

    }else if (op == 'C'){
        strcpy(processador, "I7");

    }
}

void lerEstado(char estado[11]){
    char op;
    do{
    printf("\nIndique o estado do portatil:");
    printf("\n[A] Disponivel");
    printf("\n[B] Requesitado");
    printf("\n[C] Avariado");
    printf("\n\tOPCAO >> ");scanf(" %c", &op);
    op = toupper(op);
        if(op != 'A' && op != 'B' && op != 'C'){
            printf("\nERRO | OPCAO INVALIDA\n");
        }
    }while (op != 'A' && op != 'B' && op != 'C');


    if (op == 'A'){
        estado = "Disponivel";
    }else if (op == 'B'){
        estado = "Requesitado";
    }else if (op == 'C'){
        estado = "Avariado";
    }

}

void lerLocalizacao(char localizacao[11]){
    char op;
    do{
        printf("\nIndique a localizacao:");
        printf("\n[A] Residências");
        printf("\n[B] Campus1");
        printf("\n[C] Campus2");
        printf("\n[D] Campus5");
        printf("\n\tOPCAO >> ");scanf(" %c", &op);
        op = toupper(op);
        if (op != 'A' && op != 'B' && op != 'C' && op != 'D'){
            printf("ERRO | OPCAO INVALIDA");
        }
    }while(op != 'A' && op != 'B' && op != 'C' && op != 'D');

    if (op == 'A'){
        localizacao = "Residencias";
    }else if (op == 'B'){
        localizacao = "Campus1";
    }else if (op == 'C'){
        localizacao = "Campus2";
    }else if (op == 'D'){
        localizacao = "Campus5";
    }

}

tipoPc adicionarPortatil(){
    tipoPc a;
    char x[2];
    char localizacao1[11];
    int id1;
    printf("Adicionar um Portatil");
    //printf("\nID portatil >> ");scanf("%d", &id1);
    a.id = lerInteiro("\nID portatil >>",1,9999);
    lerString("Indique a designação do portatil >>",a.designacao,MAX_STRING);
    printf("Processador");
    lerProcessador(x);
    strcpy(a.processador, x);
    printf("Localizacao");
    lerLocalizacao(localizacao1);
    printf("\nTESTES\n");
    printf("\n&d", a.id);
    printf("\n%s", a.designacao);
    printf("\n%s", a.processador);
    printf("\n%s", a.localizacao);
    printf("\n%s", a.estado);


    return a;
}

/*int procuraId(tipoPc vetor[], int num, int aProcurar)
{
    int i, pos=-1;
    for(i=0; i<num; i++)
    {
        if(vetor[i].id==aProcurar)
            pos = i;
    }
    return pos;
}

int procuraPc(tipoPc vetor[], int num, int aProcurar){
    int i;
    int pos =-1;
    for (i=0; i<num; i++){
        if (vetor[i].id == aProcurar)
            pos=1;
    }
    return pos;
}*/

void listarPortateis(tipoPc vetor[]){
    for (int i = 0 ; i<30 ; i++){
        printf("%d", vetor[i].id);
        printf("\n%d", vetor[i].processador);
    }
}

///FUNÇÕES PREDEFINIDAS
void limparEcra(){
      int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) : ", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    }
    while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}

void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
