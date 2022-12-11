#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"

char menu(int numPort, int numReqEfe, int numPortD, int numReqAti)     //Fun��o que ir� apresentar o MENU
{
    char op;
    setlocale(LC_ALL,"");
    printf("\t\t\t\tMenu Principal\n\n");
    printf("Port�teis existentes: %d\t\t\t\t\tNumero Total de requisi��es efetuadas: %d",numPort,numReqEfe);
    printf("\nPort�teis disponiveis: %d\t\t\t\t\tN�mero de requisi��es ativas: %d",numPortD,numReqAti);
    printf("\n\n[A]Adicionar Port�til");
    printf("\n[B]Listar Port�teis");
    printf("\n[C]Alterar Localiza��o de um port�til");
    printf("\n[D]Requisitar um Port�til");
    printf("\n[E]Renovar requisi��o de um port�til");
    printf("\n[F]Listar requisi��es");
    printf("\n[G]Informa��o de uma requisi��o");
    printf("\n[H]Registar Avaria");
    printf("\n[I]Listar Avarias");
    printf("\n[J]Registar devoluc��o");
    printf("\n[K]Registar repara��o");
    printf("\n[L]Armazenar informa��es dos port�teis e requisi��es num ficheiro binario");
    printf("\n[M]Mostrar (ler) dados armazenados de um ficheiro binario");
    printf("\n[N]Dados Estat�sticos");
    printf("\n[O] SAIR");
    printf("\nOp��o >> ");
    scanf(" %c", &op);
    op = toupper(op);
    return op;
}
