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
    printf("\n[C]Alterar localização do Portátil.");
    printf("\n[D]Devolução do Portátil");
    printf("\n[E]Renovar Requisição");
    printf("\n[F]Registar Avaria");
    printf("\n[G]Estado do Portátil");
    printf("\n[H]Média de multa");
    printf("\n[I]Média de cada processador utilizado");
    printf("\n[J]Tipos de utentes com menor quantidade de requisições");
    printf("\n[K]Devoluções mais Recentes");
    printf("\n[L]Todas as avarias");
    printf("\nOpcao >> ");
    scanf(" %c", &op);
    return op;
}

int main(){
    menu();
return 0;
}
