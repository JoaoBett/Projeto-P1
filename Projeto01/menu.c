#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"

char menu(int numPort, int numReqEfe, int numPortD, int numReqAti)     //Função que irá apresentar o MENU
{
    char op;
    setlocale(LC_ALL,"");
    printf("\t\t\t\tMenu Principal\n\n");
    printf("Portáteis existentes: %d\t\t\t\t\tNumero Total de requisições efetuadas: %d",numPort,numReqEfe);
    printf("\nPortáteis disponiveis: %d\t\t\t\t\tNúmero de requisições ativas: %d",numPortD,numReqAti);
    printf("\n\n[A]Adicionar Portátil");
    printf("\n[B]Listar Portáteis");
    printf("\n[C]Alterar Localização de um portátil");
    printf("\n[D]Requisitar um Portátil");
    printf("\n[E]Renovar requisição de um portátil");
    printf("\n[F]Listar requisições");
    printf("\n[G]Informação de uma requisição");
    printf("\n[H]Registar Avaria");
    printf("\n[I]Listar Avarias");
    printf("\n[J]Registar devolucção");
    printf("\n[K]Registar reparação");
    printf("\n[L]Armazenar informações dos portáteis e requisições num ficheiro binario");
    printf("\n[M]Mostrar (ler) dados armazenados de um ficheiro binario");
    printf("\n[N]Dados Estatísticos");
    printf("\n[O] SAIR");
    printf("\nOpção >> ");
    scanf(" %c", &op);
    op = toupper(op);
    return op;
}
