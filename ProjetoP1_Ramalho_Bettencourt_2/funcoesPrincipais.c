#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#include "funcoesAuxiliares.h"
#include "funcoesPrincipais.h"

tipoPc infoPc()
{
    tipoPc pc;
    //Recebe as informa??es do port?til
    pc.id = lerInteiro("\nID Portatil \t",1,9999);
    pc.processador = lerInteiro("Tipo de processador (0 - i3 || 1 - i5 || 2 - i7)\t", 0, 2);
    pc.ram = lerInteiro("Ram (0 - 4GB || 1 - 8GB || 2 - 16GB || 3 - 32GB || 4 - 64GB)\t",0,4);
    pc.estado = lerInteiro("Estado (0 - Disponivel || 1 - Em Uso || 2 - Avariado)\t", 0, 2);
    pc.localizacao = lerInteiro("Localizacao (0 - Residencias || 1 - Campus 1 || 2 - Campus 2 || 3 - Campus 5)\t",0,3);
    pc.valor = lerFloat("Valor (500?-2000?) ",500,2000);
    pc.quantAvarias = lerInteiro("Avarias : \t",0,999);
    pc.quantRequisicoes = lerInteiro("Requisicoes efetuadas : \t",0,999);
    pc.tipoUtente = lerInteiro("Utente (0 - Estudante || 1 - Docente || 2 - Tecnico administrativo)\t",0,2);
    //prazo de requisicao ainda por fazer

    return pc;
}
void adicionarPortatil(tipoPc arrayPc[MAX_PORTATIL],int *quantidade)      //Acrescenta portateis
{
    if (*quantidade == MAX_PORTATIL)
    {
        printf("\n\tN?o pode adicionar mais portateis!");
    }
    else
    {
        int posicao = 0;
        tipoPc dadosPortatil;

        dadosPortatil = infoPc();
        posicao = procurarPortatil(arrayPc, *quantidade, dadosPortatil.id);
        if (posicao == -1)
        {
            arrayPc[*quantidade] = dadosPortatil;
            (*quantidade)++;

            printf("\n\tUm novo portatil foi criado...\n\n");

        }
        else
        {
            printf("\n\tEste portatil j? est? registado, por favor tente novamente...\n\n");
        }
    }
}

void listarPortatil(tipoPc arrayPc[MAX_PORTATIL], int quantidade)                       //Lista os port?teis todos inseridos
{
    int i = 0;
    if(quantidade<1)        //Se ainda nao existirem portateis na BD...
    {
        printf("\nN?o existem informa??es sobre os port?teis!\n");
    }
    else
    {
        printf("\n\tA listar %d Portateis...\n", quantidade);
        for (; i < quantidade; i++)
        {
            printf("\n\tDesignacao: %d",arrayPc[i].id);
            //Processador do PC
            switch (arrayPc[i].processador)
            {
            case 0:
                printf("\n\tProcessador: i3");
                break;
            case 1:
                printf("\n\tProcessador: i5");
                break;
            case 2:
                printf("\n\tProcessador: i7");
                break;
            default:
                printf("\n\tAlgo est? errado, verifica o processador inserido.");
                break;
            }

            //Quantidade de ram do PC
            switch(arrayPc[i].ram)
            {
            case 0:
                printf("\n\tRAM: 4GB");
                break;
            case 1:
                printf("\n\tRAM: 8GB");
                break;
            case 2:
                printf("\n\tRAM: 16GB");
                break;
            case 3:
                printf("\n\tRAM: 32GB");
                break;
            case 4:
                printf("\n\tRAM: 64GB");
                break;
            }

            //Estado do PC
            switch (arrayPc[i].estado)
            {
            case 0:
                printf("\n\tEstado: Dispon?vel");
                break;
            case 1:
                printf("\n\tEstado: Em Uso");
                break;
            case 2:
                printf("\n\tEstado: Avariado");
                break;
            default:
                printf("\n\tAlgo est? errado, verifica o estado do portatil");
                break;
            }

            //Localizacao do PC
            switch(arrayPc[i].localizacao)
            {
            case 0:
                printf("\n\tLocalizacao: Residencias");
                break;
            case 1:
                printf("\n\tLocalizacao: Campus 1");
                break;
            case 2:
                printf("\n\tLocalizacao: Campus 2");
                break;
            case 3:
                printf("\n\tLocalizacao: Campus 5");
                break;
            }

            //Valor do PC
            printf("\nValor : %.2f",arrayPc[i].valor);

            //Requisicoes efetuadas
            printf("\nRequisicoes efetuadas : %d",arrayPc[i].quantRequisicoes);

            //Avarias
            printf("\nQuantidade de avarias: %d",arrayPc[i].quantAvarias);

            //Tipo de utente
            switch(arrayPc[i].tipoUtente)
            {
            case 0:
                printf("\n\tUtente: Estudante");
                break;
            case 1:
                printf("\n\tUtente: Docente");
                break;
            case 2:
                printf("\n\tUtente: Tecnico administrativo");
                break;
            }
            //prazo de requisicao

            //
        }
    }
   // pressionarContinuar();
}

void informacaoRequesicao(tipoPc arrayPc[MAX_PORTATIL], tipoRequisicao arrayReq[MAX_PORTATIL]){

}

void requisitarPortatil(tipoPc arrayPC[MAX_PORTATIL],int* quantidade,tipoRequisicao arrayReq[MAX_PORTATIL], int *contadorReq)
{
    int idPortatil=0,posicao=0;
    if((*quantidade) < 1)
    {
        printf("N?o existem informa??es sobre os port?teis.");
    }
    else
    {
        printf("Digite a identifica??o do port?til.\n");scanf("%d", &idPortatil);

        posicao = procurarPortatil(arrayPC,*quantidade,idPortatil);

        if(posicao==0){
            printf("O portatil nao existe...confirme o id");
        }else{
        printf("Digite a data da requisicao.\n");

        arrayReq->dataRequisicao = lerData();

        *contadorReq++;
        for (int i = 0; i<5 ; i++){
            arrayPC[i].estado;
        }
        printf("\nAp?s 30 dias da requisicao do portatil ir? ser cobrada uma multa de 10 euros por dia em excesso.\n");
     }
    }
//    pressionarContinuar();
}

void renovarPortatil(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL])
{
    int posicao =-1;
    if (quantidade < 1)
    {
        printf("\n? imposs?vel renovar a requisicao dos port?teis se eles n?o existem...");
    }
    else
    {
        posicao = procurarPortatil(arrayPc, quantidade, 0);

        if (posicao != -1)
        {
            arrayReq->dataRequisicao = lerData();

            printf("\n\tA renovacao foi concluida...\n\n");
        }
        else
        {
            printf("\n\tEste port?til n?o existe...\n\n");
            break;
        }
    }
 //   pressionarContinuar();
}

void alterarLocalizacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade){

    int idPortatil=0,posicao=0, i=0;
    if((quantidade) < 1)
    {
        printf("N?o existem informa??es sobre os port?teis.");
    }
    else
    {
        printf("Digite a identifica??o do port?til.\n");
        scanf("%d", &idPortatil);
        for (i=0; i<MAX_PORTATIL; i++){
          if(idPortatil == arrayPc[i].id){
            posicao = procurarPortatil(arrayPc,quantidade,idPortatil);
            printf("Mude a localizac?o: ");
            arrayPc->localizacao = lerInteiro("Localizacao (0 - Residencias || 1 - Campus 1 || 2 - Campus 2 || 3 - Campus 5)\t",0,3);
          }else{
            printf("O id indicado nao corresponde a nenhum portatil...");
          }
        }
        //posicao = procurarPortatil(arrayPc,quantidade,idPortatil);

        //printf("Mude a localizac?o: ");

        //arrayPc->localizacao = lerInteiro("Localizacao (0 - Residencias || 1 - Campus 1 || 2 - Campus 2 || 3 - Campus 5)\t",0,3);

    }

}

void listarRequesicao(tipoPc arrayPc[MAX_PORTATEIS], tipoRequisicao arrayReq[MAX_PORTATEIS], int quantidade, int quantidadeReq){
    int i = 0;
    if(quantidade<1)        //Se ainda nao existirem portateis na BD...
    {
        printf("\nN?o existem informa??es sobre os port?teis!\n");
    }
    else{
        for (i = 0; i<5 ; i++){
                if(arrayPc[i].estado == 1)
            printf("O portatil %d", arrayPc[i].id); printf("esta requesitado\n");
        }

    }
}

void registarAvaria(tipoPc arrayPc[MAX_PORTATEIS], int quantidade){
    printf("Registar avaria: ");
    int posicao =-1;
    int idPortatil=0;
    if (quantidade < 1)
    {
        printf("\n? imposs?vel renovar a requisicao dos port?teis se eles n?o existem...");
    }
    else
    {
        printf("Indique o id do portatil: ");scanf("%d", &idPortatil);
        posicao = procurarPortatil(arrayPc, quantidade, idPortatil);

        if (posicao != -1)
        {
            arrayPc->tipoAvarias=lerInteiro("Indique o tipo da avaria (0-temporaria, 1-permanente): ",0,9999);

            arrayPc->quantAvarias++;
            printf("\n\tA avaria foi registada...\n\n");
        }
        else
        {
            printf("\n\tEste port?til n?o existe...\n\n");
        }
    }
}

void listarAvaria(tipoPc arrayPc[MAX_PORTATEIS], int quantidade){
    int i = 0;
    int quantidadeAvarias=0;
    if(quantidade<1)        //Se ainda nao existirem portateis na BD...
    {
        printf("\nN?o existem informa??es sobre os port?teis!\n");
    }
    else{
        printf("Listagem Avarias: \n");
        for (i = 0; i<quantidade ; i++){
            quantidadeAvarias = quantidadeAvarias + arrayPc[i].quantAvarias;
        printf("O portatil %d", arrayPc[i].id);printf("tem(teve): %d avarias", arrayPc[i].quantAvarias);
        switch(arrayPc[i].tipoAvarias){
            case 0:
                printf("do tipo temporaria");
                break;
            case 1:
                printf("do tipo permanente");
                break;
            default:
                break;
                }
        }
    }

    printf("Avarias totais: %d\n", quantidadeAvarias);
}

void registarReparacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL])
{
    int posicao =-1;

    if (quantidade < 1)
    {
        printf("\n? imposs?vel a reparacao dos port?teis se eles n?o existem...");
    }
    else
    {
        posicao = procurarPortatil(arrayPc, quantidade, 0);

        if (posicao != -1)
        {
            arrayPc[posicao].estado = 0;

            printf("\n\tA reparacao foi concluida...\n\n");
        }
        else
        {
            printf("\n\tEste port?til n?o existe...\n\n");
        }
    }
 //   pressionarContinuar();
}

void registarDevolucao(tipoPc arrayPc[MAX_PORTATIL],int quantidade)
{
    int posicao =-1;
    int localizacao;

    if (quantidade < 1)
    {
        printf("\n? imposs?vel renovar a devolucao dos portateis se eles nao existem...");
    }
    else
    {
        posicao = procurarPortatil(arrayPc, quantidade, 0);

        if (posicao != -1)
        {
            if (arrayPc[posicao].estado = 1){
                    do{
                printf("Para que localizacao ir? devolver(0 - Residencias || 1 - Campus 1 || 2 - Campus 2 || 3 - Campus 5): ");
                scanf("%d", &localizacao);
                }while(localizacao!= 0 && localizacao!= 1 && localizacao!= 2 && localizacao!= 3);
                switch(localizacao){
            case 0:
                printf("Devolucao registada nas residencias...");
                break;
            case 1:
                printf("Devolucao registada no campus 1...");
                break;
            case 2:
                printf("Devolucao registada no campus 2...");
                break;
            case 3:
                printf("Devolucao registada no campus 3...");
                break;
                }
                arrayPc[posicao].estado = 0;
            }
        }
        else
        {
            printf("\n\tEste port?til n?o existe...\n\n");
        }
    }
 //   pressionarContinuar();
}

void dadosEstatisticos(tipoPc arrayPc[MAX_PORTATEIS]){
    int i = 0;
    int qnt = 0;
    int contadorI3 = 0;
    int contadorI5 = 0;
    int contadorI7 = 0;
    float processadorI3 = 0.0;
    float processadorI5 = 0.0;
    float processadorI7 = 0.0;
    for (i=0; i<MAX_PORTATEIS; i++){
      qnt++;                               //(0 - i3 || 1 - i5 || 2 - i7)
        if (arrayPc[i].processador == 0){
            contadorI3++;
            processadorI3 = contadorI3/qnt;
        }
        else{
            if(arrayPc[i].processador == 1){
                contadorI5++;
                processadorI5 = contadorI5/qnt;
            }
            else{
            if(arrayPc[i].processador == 2){
                contadorI7++;
                processadorI7 = contadorI7/qnt;
            }
        }
        }

    }
}
