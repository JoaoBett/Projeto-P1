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
    //Recebe as informações do portátil
    pc.id = lerInteiro("\nID Portatil \t",1,9999);
    pc.processador = lerInteiro("Tipo de processador (0 - i3 || 1 - i5 || 2 - i7)\t", 0, 2);
    pc.ram = lerInteiro("Ram (0 - 4GB || 1 - 8GB || 2 - 16GB || 3 - 32GB || 4 - 64GB)\t",0,4);
    pc.estado = lerInteiro("Estado (0 - Disponivel || 1 - Em Uso || 2 - Avariado)\t", 0, 2);
    pc.localizacao = lerInteiro("Localizacao (0 - Residencias || 1 - Campus 1 || 2 - Campus 2 || 3 - Campus 5)\t",0,3);
    pc.valor = lerFloat("Valor (500€-2000€) ",500,2000);
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
        printf("\n\tNão pode adicionar mais portateis!");
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
            printf("\n\tEste portatil já está registado, por favor tente novamente...\n\n");
        }
        pressionarContinuar();
    }
}

void listarPortatil(tipoPc arrayPc[MAX_PORTATIL], int quantidade)                       //Lista os portáteis todos inseridos
{
    int i = 0;
    if(quantidade<1)        //Se ainda nao existirem portateis na BD...
    {
        printf("\nNão existem informações sobre os portáteis!\n");
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
                printf("\n\tAlgo está errado, verifica o processador inserido.");
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
                printf("\n\tEstado: Disponível");
                break;
            case 1:
                printf("\n\tEstado: Em Uso");
                break;
            case 2:
                printf("\n\tEstado: Avariado");
                break;
            default:
                printf("\n\tAlgo está errado, verifica o estado do portatil");
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
            printf("\n\tValor : %.2f",arrayPc[i].valor);

            //Requisicoes efetuadas
            printf("\n\tRequisicoes efetuadas : %d",arrayPc[i].quantRequisicoes);

            //Avarias
            printf("\n\tQuantidade de avarias: %d",arrayPc[i].quantAvarias);

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
    pressionarContinuar();
}

void requisitarPortatil(tipoPc arrayPC[MAX_PORTATIL],int* quantidade,tipoRequisicao arrayReq[MAX_PORTATIL], int *contadorReq)
{
    int idPortatil=0,posicao=-1;
    if((*quantidade) <= 0)
    {
        printf("Não existem informações sobre os portáteis.");
    }
    else
    {
        printf("Digite a identificação do portátil.\n");scanf("%d", &idPortatil);

        posicao = procurarPortatil(arrayPC,*quantidade,idPortatil);

        if(posicao == -1){
            printf("O portatil nao existe...confirme o id");
        }

        printf("Digite a data da requisicao.\n");

        arrayReq->dataRequisicao = lerData();

        *contadorReq++;

        printf("\nApós 30 dias da requisicao do portatil irá ser cobrada uma multa de 10 euros por dia em excesso.\n");
    }
    pressionarContinuar();
}

void renovarPortatil(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL])
{
    int posicao =-1;

    if (quantidade < 1)
    {
        printf("\nÉ impossível renovar a requisicao dos portáteis se eles não existem...");
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
            printf("\n\tEste portátil não existe...\n\n");
        }
    }
    pressionarContinuar();
}

void alterarLocalizacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade){

    int idPortatil = 0,posicao = 0;
    if((quantidade) < 1)
    {
        printf("Não existem informações sobre os portáteis.");
    }
    else
    {
        printf("Digite a identificação do portátil.\n");

        posicao = procurarPortatil(arrayPc,quantidade,idPortatil);

        printf("Mude a localizacão: ");

        arrayPc->localizacao = lerInteiro("Localizacao (0 - Residencias || 1 - Campus 1 || 2 - Campus 2 || 3 - Campus 5)\t",0,3);;

    }
    pressionarContinuar();
}

void listarRequisicao(tipoPc arrayPc[MAX_PORTATEIS], tipoRequisicao arrayReq[MAX_PORTATEIS], int quantidade, int quantidadeReq){
    int i = 0;
    if(quantidade<1)        //Se ainda nao existirem portateis na BD...
    {
        printf("\nNão existem informações sobre os portáteis!\n");
    }
    else{
        for (i = 0; i<quantidadeReq ; i++){
            printf("O portatil %d", arrayReq[i].id, "esta requesitado\n");
        }
    }
    pressionarContinuar();
}

void registarAvaria(tipoPc arrayPc[MAX_PORTATEIS], int quantidade){
    printf("Registar avaria: ");
    int posicao =-1;
    int idPortatil=0;
    if (quantidade < 1)
    {
        printf("\nÉ impossível renovar a requisicao dos portáteis se eles não existem...");
    }
    else
    {
        posicao = procurarPortatil(arrayPc, quantidade, idPortatil);

        if (posicao != -1)
        {
            arrayPc->quantAvarias++;

            printf("\n\tA avaria foi registada...\n\n");
        }
        else
        {
            printf("\n\tEste portátil não existe...\n\n");
        }
    }
    pressionarContinuar();
}

void listarAvaria(tipoPc arrayPc[MAX_PORTATEIS], int quantidade){
    int i = 0;
    int quantidadeAvarias=0;
    if(quantidade<1)        //Se ainda nao existirem portateis na BD...
    {
        printf("\nNão existem informações sobre os portáteis!\n");
    }
    else{
        printf("Listagem Avarias: ");
        for (i = 0; i<quantidade ; i++){
            quantidadeAvarias = quantidadeAvarias + arrayPc[i].quantAvarias;
        printf("O portatil %d", arrayPc[i].id);printf("tem(teve): %d avarias", arrayPc[i].quantAvarias);
        }
        printf("Avarias totais: %d", quantidadeAvarias);
    }
    pressionarContinuar();
}

void registarReparacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL])
{
    int posicao =-1;

    if (quantidade < 1)
    {
        printf("\nÉ impossível renovar a requisicao dos portáteis se eles não existem...");
    }
    else
    {
        posicao = procurarPortatil(arrayPc, quantidade, 0);

        if (posicao != -1)
        {
            arrayPc[posicao].estado = 0;

            printf("\n\tA renovacao foi concluida...\n\n");
        }
        else
        {
            printf("\n\tEste portátil não existe...\n\n");
        }
    }
    pressionarContinuar();
}

void registarDevolucao(tipoPc arrayPc[MAX_PORTATIL],int quantidade)
{
    int posicao =-1;

    if (quantidade < 1)
    {
        printf("\nÉ impossível renovar a devolucao dos portateis se eles nao existem...");
    }
    else
    {
        posicao = procurarPortatil(arrayPc, quantidade, 0);

        if (posicao != -1)
        {
            if (arrayPc[posicao].estado = 1){
                printf("Devolucao registada...");
                arrayPc[posicao].estado = 0;
            }
        }
        else
        {
            printf("\n\tEste portátil não existe...\n\n");
        }
    }
    pressionarContinuar();
}

void dadosEstatisticos(tipoPc arrayPc[MAX_PORTATEIS],int quantidade){
    int i = 0;
    //Processadores
    int qnt = 0;
    int contadorI3 = 0;
    int contadorI5 = 0;
    int contadorI7 = 0;
    float processadorI3 = 0.0;
    float processadorI5 = 0.0;
    float processadorI7 = 0.0;
    //Utentes
    int qnt2 = 0;
    int contadorEst = 0;
    int contadorDoc = 0;
    int contadorTecA = 0;
    int menor;
    int menorUtente;
    int menorAux = 0;

    if(quantidade == 0)
    {
        printf("Não existem dados de portáteis...");
        pressionarContinuar();
    }
    else{
    for (i=0; i<MAX_PORTATEIS; i++){
      qnt++;                               //(0 - i3 || 1 - i5 || 2 - i7)
        if (arrayPc[i].processador == 0){
            contadorI3++;
        }
        else{
            if(arrayPc[i].processador == 1){
                contadorI5++;
            }
            else{
            if(arrayPc[i].processador == 2){
                contadorI7++;
            }
        }
        }
    }
    //Medias dos Processadores
    processadorI3 = (contadorI3/qnt)*100;
    processadorI5 = (contadorI5/qnt)*100;
    processadorI7 = (contadorI7/qnt)*100;
    printf("A percentagem de processadores I3 presentes é de %f.\n",processadorI3);
    printf("A percentagem de processadores I5 presentes é de %f.\n",processadorI5);
    printf("A percentagem de processadores I7 presentes é de %f.\n",processadorI7);

    for (i = 0;i<MAX_PORTATEIS; i++)
    {
    qnt2++;
       if (arrayPc[i].tipoUtente == 0)
        {
           contadorEst++;
       }
       else{
            if(arrayPc[i].tipoUtente == 1)
            {
           contadorDoc++;
            }
            else{
                if(arrayPc[i].tipoUtente == 2)
                {
                  contadorTecA++;
                }
            }
        }
    }

    //tipo de utente com a menor quantidade de requisições
    menor = contadorDoc;
    menorAux = 1;
    if (contadorTecA < menor)
    {
    menor = contadorTecA;
    menorAux = 2;
    }
    if (contadorEst < menor)
    {
    menor = contadorEst;
    menorAux = 0;
    }

    menorUtente = 0;
    if (contadorDoc == contadorEst && contadorDoc == contadorTecA) {
        menorAux = 6;
    }
    else
    {
        if (contadorDoc == contadorEst)
        {
        contadorDoc = menor;
        menorAux = 3;
        }
        else
        {
            if (contadorDoc == contadorTecA)
            {
            contadorDoc = menor;
            menorAux = 5;
            }
            else{
                if(contadorEst == contadorTecA)
                {
                    contadorEst = menor;
                    menorAux = 4;
                }
            }
        }
    }
    switch(menorAux)
    {
        case 0:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas e o Estudante.");
        case 1:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas e o Docente.");
        case 2:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas e o Tecnico Administrativo.");
        case 3:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas sao os Estudantes e Docentes.");
        case 4:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas sao os Estudantes e os Tecnicos Administrativos.");
        case 5:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas sao os Docentes e Tecnicos Administrativos.");
        case 6:
            printf("\nO tipo de utente com a menor quantidade de requisições efetuadas são todos.");
    }
    pressionarContinuar();
    }
}
