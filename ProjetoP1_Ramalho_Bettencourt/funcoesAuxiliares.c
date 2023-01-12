#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "funcoesAuxiliares.h"
#include "estruturas.h"

///NAO ESQUECER FUNCOES PARA LER PROCESSADOR/RAM/LOCALIZACAO/ESTADO

//FUNCAO MENU
char menu(int *quantidadePortateis, int *portateisDisponiveis, int *quantidadeRequisicoes, int *quantidadeRequisicoesAtivas){
    char op;
    printf("================================================| Bem vindo |===========================================================\n");
    printf("============================| GRCP |  Gestao da Requisicao de Computadores Portateis |==================================\n");
    printf("========================================================================================================================\n");
    printf("=============================================| Menu Principal |=========================================================\n");
    printf("========================================================================================================================\n");
    printf("Portateis existentes: %d\t\t\t\t\t\t\tNumero Total de requisicoes efetuadas: %d", *quantidadePortateis, *quantidadeRequisicoes);
    printf("\nPortateis disponiveis: %d\t\t\t\t\t\t\tNumero de requisicoes ativas: %d", *portateisDisponiveis, *quantidadeRequisicoesAtivas);
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
    printf("\n[L]Armazenar informa��o portateis e requisicoes em ficheiro binario");
    printf("\n[M]Mostrar (ler) dados armazenados em ficheiro binarios ");
    printf("\n[N]Dados Estatisticos");
    printf("\n[S] SAIR");
    printf("\nOpcao >> ");
    op = getchar();
    op = toupper(op);
    return op;
}
//FUNCOES PROCURAR
int procurarPortatil(tipoPc arrayPc[MAX_PORTATIL], int quantidade, int id)                //Procura o id do port�til no array e retorna a sua posicao
{
    int i;
    int posicao = -1;
    //recebe o id do portatil
    if( id == 0)
    {
        id = lerInteiro("Indique o id:",1,9999);
    }
    //procura o portatil no array e coloca na variavel "posicao"
    for (i=0; i < quantidade; i++)
    {
        if (arrayPc[i].id == id)
        {
            posicao = i;
            i = quantidade;
        }
    }

    return posicao; //devolve a posicao do portatil
}

int procurarRequisicao(tipoPc arrayPc[MAX_PORTATIL], tipoRequisicao arrayReq[MAX_PORTATIL],int quantidade, int id)
{
    int i;
    int posicao = -1;
    //recebe o id do portatil
    if (id == 0)
    {
        id = lerInteiro("\n\tID",1,9999);
    }

    //procura o portatil no array e coloca na variavel "posicao"
    for (i=0; i < quantidade; i++)
    {
        if (arrayPc[i].id == id)
        {
            posicao = i;
            i = quantidade;
        }
    }

    return posicao; //devolve a posicao do portatil
}
/*//FUNCAO QUE LE O PROCESSADOR
int lerProcessador(){
    char opProcessador;
    do{
    printf("\nIndique o processador:");
    printf("\n[1] I3");
    printf("\n[2] I5");
    printf("\n[3] I7");
    printf("\n\tOPCAO >> ");scanf("%d", &opProcessador);
    if(opProcessador != 1 && opProcessador != 2 && opProcessador != 3)
        printf("\nERRO | OPCAO INVALIDA\n");
    }while (opProcessador != 1 && opProcessador != 2 && opProcessador != 3);

    return opProcessador;

}
//FUNCAO QUE LE O ESTADO DO PORTATIL
int lerEstado(){
    char opEstado;
    do{
    printf("\nIndique o estado do portatil:");
    printf("\n[1] Disponivel");
    printf("\n[2] Requesitado");
    printf("\n[3] Avariado");
    printf("\n\tOPCAO >> ");scanf("%d", &opEstado);
    if(opEstado != 1 && opEstado != 2 && opEstado != 3)
        printf("\nERRO | OPCAO INVALIDA\n");
    }while (opEstado != 1 && opEstado != 2 && opEstado != 3);

    switch(opEstado){
        case 1: opEstado = 1;
            break;
        case 2: opEstado = 2;
            break;
        case 3: opEstado = 3;
            break;
    }

    return opEstado;
}
//FUNCAO QUE LE A LOCALIZACAO
int lerLocalizacao(){
    char opLocalizacao;
    do{
    printf("\nIndique a localizacao:");
    printf("\n[1] Resid�ncias");
    printf("\n[2] Campus1");
    printf("\n[3] Campus2");
    printf("\n[3] Campus5");
    printf("\n\tOPCAO >> ");scanf("%d", &opLocalizacao);
    if(opLocalizacao != 1 && opLocalizacao != 2 && opLocalizacao != 3)
        printf("\nERRO | OPCAO INVALIDA\n");
    }while (opLocalizacao != 1 && opLocalizacao != 2 && opLocalizacao != 3);

    switch(opLocalizacao){
        case 1: opLocalizacao = 1;
            break;
        case 2: opLocalizacao = 2;
            break;
        case 4: opLocalizacao = 4;
            break;
    }

    return opLocalizacao;
}*/
//FUNCAO LIMPAR BUFFER
void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}

//FUNCAO LER INTEIRO
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) : ", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores v�lidos obtidos
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
//FUNCAO LER FLOAT
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores v�lidos obtidos
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
//FUNCAO LER STRING
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
//FUNCAO LER DATA
tipoData lerData()
{
    tipoData data;
    int maxDiasMes;

    printf("Insira a data pretendida - ");
    data.ano = lerInteiro("ano:", 1948,2023);
    data.mes = lerInteiro("mes:", 1, 12);


    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }
    data.dia = lerInteiro("dia:", 1, maxDiasMes);
    return data;
}
void pressionarContinuar()
{
    printf("\nPressione qualquer tecla para continuar...");
    while (!kbhit()) {}
    limpaBufferStdin();
    return;
}
void limpaEcra()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
