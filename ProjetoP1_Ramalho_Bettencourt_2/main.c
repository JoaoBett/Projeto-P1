#include <stdio.h>
#include <stdlib.h>

#include "funcoesAuxiliares.h"
#include "funcoesPrincipais.h"
#include "ficheiros.h"

int main()
{
    int quantidadePortateis = 0;
    int portateisDisponiveis = 0;
    int quantidadeRequesicoes = 0;
    int quantidadeRequesicoesAtivas = 0;
    int quantidadeAvarias = 0;

    tipoPc portateis[MAX_PORTATEIS];
    tipoRequisicao arrayReq[MAX_PORTATEIS];

    char op;

    do{
      op = menu(&quantidadePortateis, &portateisDisponiveis, &quantidadeRequesicoes, &quantidadeRequesicoesAtivas);
        switch(op){
        case 'A'://adicionar portatil
            adicionarPortatil(portateis,&quantidadePortateis);
            break;
        case 'B'://listar portateis
            listarPortatil(portateis, quantidadePortateis);
            break;
        case 'C'://alterar localizacao portatil
            alterarLocalizacao(portateis, quantidadePortateis);
            break;
        case 'D'://requisitar um portatil
            requisitarPortatil(portateis, &quantidadePortateis, arrayReq, &quantidadeRequesicoes);
            break;
        case 'E'://renovar requisicao
            renovarPortatil(portateis,quantidadePortateis,arrayReq);
            break;
        case 'F'://listar requisicoes
            listarRequesicao(portateis,arrayReq,quantidadePortateis,quantidadeRequesicoes);
            break;
        case 'G'://informacao de uma requisicao
            break;
        case 'H'://registar avaria
            registarAvaria(portateis, quantidadePortateis);
            break;
        case 'I'://listar avarias
            listarAvaria(portateis,quantidadePortateis);
            break;
        case 'J'://registar devolucao
            registarDevolucao(portateis,quantidadePortateis);
            break;
        case 'K'://registar reparacao
            registarReparacao(portateis, quantidadePortateis, arrayReq);
            break;
        case 'L'://Armazenar informação portateis e requisicoes em ficheiro binario
            gravarFicheiroBinario(portateis, quantidadePortateis, arrayReq, quantidadeRequesicoes);
            break;
        case 'M'://Mostrar (ler) dados armazenados em ficheiro binarios
            quantidadeAvarias=leFicheiroBinario(portateis);
            break;
        case 'N'://dados estatisticos
            dadosEstatisticos(portateis);
            break;
        case 'S':// SAIR
            printf("A sair.......");
            break;
        default:
            printf("ERRO | OPCAO INVALIDA\n");
        }
    }while(op != 'S');
}

//funcoes auxiliares e depois fazer por ordem as funcoes do menu

