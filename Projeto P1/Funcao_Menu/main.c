#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


char menu()
{
    setlocale(LC_ALL, "");
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
}





int main(){
    menu();
return 0;
}
