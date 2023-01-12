#ifndef FUNCOES_PRINCIPAIS_H
#define FUNCOES_PRINCIPAIS_H

#include "estruturas.h"
#include "constantes.h"

///PROTOTIPOS
tipoPc infoPc();
void adicionarPortatil(tipoPc arrayPC[MAX_PORTATIL],int *quantidade);
void infoPortatil();
void dadosEstatisticos(tipoPc arrayPC[MAX_PORTATIL]);
void registarDevolucao(tipoPc arrayPc[MAX_PORTATIL],int quantidade);
void registarAvaria(tipoPc arrayPc[MAX_PORTATIL], int quantidade);
void alterarLocalizacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade);
void listarRequesicao(tipoPc arrayPc[MAX_PORTATEIS], tipoRequisicao arrayReq[MAX_PORTATEIS], int quantidade, int quantidadeReq);
void listarPortatil(tipoPc arrayPc[MAX_PORTATIL], int quantidade);
void listarAvaria(tipoPc arrayPc[MAX_PORTATEIS], int quantidade);
void requisitarPortatil(tipoPc arrayPC[MAX_PORTATIL],int* quantidade,tipoRequisicao arrayReq[MAX_PORTATIL], int *contadorReq);
void renovarPortatil(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL]);
void registarReparacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL]);




#endif // FUNCOES_PRINCIPAIS_H
