/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 23/10/2026
Objetivo    : Programa de manipulação de Árvore
Dificuldade : Erros de nomenclaturas
Uso de IA   : Correção de erros simples (ex: falta de &)
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct celula{
    char valor;
    struct celula *esq;
    struct celula *dir;
} celula;

typedef celula *arvore;

arvore inserir(arvore r, char letra){ //Gera e insere célula na árvore
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

void busca(arvore r, char letra){ 

    if(r == NULL){ //Se busca chegou ao final da árvore sem encontrar valor, imprime "não existe"
        printf("%c nao existe\n", letra);
        return;
    }

    if(r->valor == letra){ //Se busca chegou a uma célula com a "letra", imprime que existe
        printf("%c existe\n", letra);
        return;
    }

    if(r->valor > letra)  busca(r->esq, letra); //Se não encontrou, procura na árcore esquerda ou direita
    else busca(r->dir, letra);
}

void prefixo(arvore r, int *NaoPrimeiro){ 
    if(r != NULL){
        if(*NaoPrimeiro) printf(" ");
        *NaoPrimeiro = 1;
        printf("%c", r->valor);
        prefixo(r->esq, NaoPrimeiro);
        prefixo(r->dir, NaoPrimeiro);
    }
}

void infixo(arvore r, int *NaoPrimeiro){
    if(r != NULL){
        infixo(r->esq, NaoPrimeiro);        
        if(*NaoPrimeiro) printf(" ");
        *NaoPrimeiro = 1;
        printf("%c", r->valor);
        infixo(r->dir, NaoPrimeiro);
    }
}

void posfixo(arvore r, int *NaoPrimeiro){
    if(r != NULL){
        posfixo(r->esq, NaoPrimeiro);
        posfixo(r->dir, NaoPrimeiro);
        if(*NaoPrimeiro) printf(" ");
        *NaoPrimeiro = 1;
        printf("%c", r->valor);
    }
}

void liberar(arvore r) {
    if (r != NULL) {
        liberar(r->esq);
        liberar(r->dir);
        free(r);
    }
}

int main(){
    char letra, comando[10];
    arvore r = NULL;
    int p=0;
    
    while (scanf("%s", comando) != EOF) { //Define repetição dos comandos interativos
        
        if(comando[1] == 'N'){ //INFIXA
            p=0;
            infixo(r, &p);
            printf("\n");
        }
        
        else if(comando[1] == 'R'){ //PREFIXA
            p=0;
            prefixo(r, &p);
            printf("\n");
        }

        else if(comando[1] == 'O'){ //POSFIXA
            p=0;
            posfixo(r, &p);
            printf("\n");
        }

        else if(comando[0] == 'I'){ //Insere elemento
            scanf(" %c", &letra);
            r = inserir(r, letra);
        } 

        else if(comando[0] == 'P'){ //Busca elemento
            scanf(" %c", &letra);
            busca(r, letra);            
        }

    }
    
    liberar(r);
    return 0;
}

