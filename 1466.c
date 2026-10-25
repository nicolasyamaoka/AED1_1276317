/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 01/10/2026
Objetivo    : Ver de quantas formas conseguimos reorganizar o trem
Dificuldade : Lógica de fila
Uso de IA   : Correção de erros simples (ex: erros de digitação)
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    int valor;
    struct celula *esq;
    struct celula *dir;
} celula;

typedef celula *arvore;

arvore inserir(arvore r, int letra){
    if(r == NULL){
        arvore novo = malloc(sizeof(celula));
        novo->valor = letra;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if(r->valor > letra) r->esq = inserir(r->esq, letra);
    else if (r->valor < letra) r->dir = inserir(r->dir, letra);
    return r;
}


void liberar(arvore r) {
    if (r != NULL) {
        liberar(r->esq);
        liberar(r->dir);
        free(r);
    }
}

void imprimeNivel(arvore r, int N){
    arvore vet[N]; //Vetor Fila com endereços da árvore;
    int cont=0;

    //x é a análise linear de cada endereço da árvore;
    //cont é a adição de novos endereços a fila
    
    for(int x = -1; x < cont; x++){

        if(x == -1) vet[cont++] = r; //Adiciona raíz como primeiro endereço da fila;

        else {
            if(vet[x]->esq != NULL) vet[(cont++)] = vet[x]->esq; //Se filho esquerdo do elemento X existe, adicione ele no final da fila;

            if(vet[x]->dir != NULL) vet[(cont++)] = vet[x]->dir; //Se filho direito do elemento X existe, adicione ele no final da fila;
        }
    }

    int Nprimeiro=0;
    for(int i=0; i < N; i++){ //Imprime valor das células do inicio ao fim da fila
        if(Nprimeiro){
           printf(" "); 
           
        }
        printf("%d", vet[i]->valor);
        Nprimeiro = 1;
    }
}


int main(){
    int C, N, x;
    arvore r = NULL;
    int p=0;
    scanf("%d", &C);

    for(int i=0; i<C; i++){

        scanf("%d", &N);
        for(int i=0; i<N; i++){ //Produz Árvore Binária
            scanf("%d",&x);
            r = inserir(r, x);
        }

        printf("Case %d:\n", i+1);
        imprimeNivel(r, N); //Imprime valores em ordem de nível;
        printf("\n\n");
        liberar(r);
        r = NULL;
    }
    
    
    return 0;
}
