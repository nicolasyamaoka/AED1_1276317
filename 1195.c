/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 23/10/2026
Objetivo    : Imprimir Prefixo, Infixo e Posfixo;
Dificuldade : Erros bobos;
Uso de IA   : Corrigir erros de escrita;
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct celula{ //Base da célula
    int valor;
    struct celula *esq;
    struct celula *dir;
} celula;

typedef celula *arvore; //Vetores que ligam células em forma de árvore;

arvore criarRaiz(int x){ //Gera nova célula;
    arvore novo = malloc(sizeof(celula));
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

arvore Inserir(arvore r, int x){ //Adiciona nova célula na árvore
    if(r == NULL){
        return criarRaiz(x);
    }

    if(r->valor > x) r->esq = Inserir(r->esq, x);
    else if (r->valor < x) r->dir = Inserir(r->dir, x);
    return r;
}

void Prefixo(arvore r, int *NaoPrimeiro){ //Imprime Prefixo
    if(r != NULL){
        if(*NaoPrimeiro) printf(" ");
        *NaoPrimeiro = 1;
        printf("%d", r->valor); //Imprime Raiz
        Prefixo(r->esq, NaoPrimeiro); //Imprime Sub-árvore esquerda
        Prefixo(r->dir, NaoPrimeiro); //Imprime Sub-árvore direita
    }
}

void Infixo(arvore r, int *NaoPrimeiro){ //Imprime Infixo
    if(r != NULL){
        Infixo(r->esq, NaoPrimeiro); //Imprime Sub-árvore esquerda    
        if(*NaoPrimeiro) printf(" ");
        *NaoPrimeiro = 1;
        printf("%d", r->valor); //Imprime Raiz
        Infixo(r->dir, NaoPrimeiro); //Imprime Sub-árvore direita
    }
}

void Posfixo(arvore r, int *NaoPrimeiro){ //Imprime Posfixo
    if(r != NULL){
        Posfixo(r->esq, NaoPrimeiro); //Imprime Sub-árvore esquerda   
        Posfixo(r->dir, NaoPrimeiro); //Imprime Sub-árvore direita
        if(*NaoPrimeiro) printf(" ");
        *NaoPrimeiro = 1;
        printf("%d", r->valor); //Imprime Raiz
    }
}

void LiberarArvore(arvore r){
    if(r != NULL){
        LiberarArvore(r->esq);
        LiberarArvore(r->dir);
        free(r);
    }
}

void VarreArvore(int N, int *v, int i){

    arvore r = criarRaiz(v[0]);

    for(int j=1; j<N; j++){ //Gera Árvore
        Inserir(r, v[j]);
    }

    int p = 0;
    printf("Case %d:\n", i);

    p = 0;
    printf("Pre.: ");
    Prefixo(r, &p); //Varre Prefixo
    printf("\n");

    p = 0;
    printf("In..: ");
    Infixo(r, &p); //Varre Infixo
    printf("\n");

    p = 0;
    printf("Post: ");
    Posfixo(r, &p); //Varre Posfixo
    printf("\n\n");

    LiberarArvore(r);
}


int main() {
    int C, N;
    scanf("%d", &C);

    for(int i=1; i<= C; i++){
        scanf("%d", &N);

        int *v = (int *) malloc(N * sizeof(int)); //Vetor de entrada;
        for(int j=0; j<N; j++) scanf("%d", &v[j]);

        VarreArvore(N, v, i);

        free(v);
    }

    return 0;
}
