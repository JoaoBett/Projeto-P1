#include <stdlib.h>
#include <stdio.h>

#include "funcoesPrincipais.h"

void gravarFicheiroBinario(tipoPc portateis[MAX_PORTATIL], int quantidadePortateis, tipoRequisicao* requesicao, int quantidadeRequesicoes) {
    FILE* file;

    file = fopen("dados.dat", "wb");

    if(file != NULL) {
            fwrite(&quantidadePortateis, sizeof(int), 1, file);
            fwrite(portateis, sizeof(tipoPc), quantidadePortateis, file);
            fclose(file);
    } else {
        printf("\nImpossivel abrir o ficheiro\n\n");
    }
}

int leFicheiroBinario(tipoPc vetorPc[])
{
    FILE *f;
    int tamanho, lido;
    f=fopen("dados.dat", "rb");
    if(f!=NULL)
    {
        lido=fread(&tamanho, sizeof(int), 1,f);
        if(lido!=1)
        {
            printf("ERRO NA LEITURA DA QUANTIDADE DE ESTUDANTES");
        }
        else
        {
            lido=fread(vetorPc, sizeof(tipoPc), tamanho, f);
            if(lido!=tamanho)
            {
                printf("ERRO NA LEITURA DE DADOS DO VETOR");
            }
        }
        fclose(f);
    }
    else
    {
        printf("ERRO A ABRIR FICHEIRO");
    }
    return tamanho;
}
