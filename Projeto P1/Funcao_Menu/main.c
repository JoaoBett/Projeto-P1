#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char menu()
{
    setlocale(LC_ALL,"");
    char op;
    printf("\t\t\t\tMenu Principal\n\n");
    printf("Portateis existentes: %d\t\t\t\t\tNumero Total de requisicoes efetuadas: %d");
    printf("\nPortateis disponiveis: %d\t\t\t\t\tNumero de requisicoes ativas: %d");
    printf("\n\n[A]Adicionar Portatil");
    printf("\n[B]Listar Portateis");
    printf("\n[C]Alterar localiza��o do Port�til.");
    printf("\n[D]Devolu��o do Port�til");
    printf("\n[E]Renovar Requisi��o");
    printf("\n[F]Registar Avaria");
    printf("\n[G]Estado do Port�til");
    printf("\n[H]M�dia de multa");
    printf("\n[I]M�dia de cada processador utilizado");
    printf("\n[J]Tipos de utentes com menor quantidade de requisi��es");
    printf("\n[K]Devolu��es mais Recentes");
    printf("\n[L]Todas as avarias");
    printf("\nOpcao >> ");
    scanf(" %c", &op);
    return op;
}

int main(){
    menu();
return 0;
}
