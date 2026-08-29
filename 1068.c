/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 21/08/2026
Objetivo    : Encontrar o maior valor de um vetor
Dificuldade : Entender que N não era uma entrada
Uso de IA   : A IA me ajudou na solução de erros bobos, como resetar j, e na problematica de vir um ")" inicialmente
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{ //Estrutura de dados para a pilha
    struct celula *seg;
} celula;

void Empilha(celula *c){ //Adiciona nova célula após a cabeça
    celula *novo;
    novo = malloc(sizeof(celula));
    novo->seg = c->seg;
    c->seg = novo;
}

int Desempilha(celula *c){ //Remove 1º célula após a cabeça
    if(c->seg == NULL){
    return 0;
    }

    celula *lixo;
    lixo = c->seg;
    c->seg = lixo->seg;
    free(lixo);
    return 1;
}

int main(){
    celula *lst = malloc(sizeof(celula)); //Gera a cabeça
    lst->seg = NULL;

    char expressao[1002]; 

    while(fgets(expressao, 1002, stdin) != NULL){
        int j = 0, correto = 1;

        while(expressao[j] != '\0'){
            if(expressao[j] == '(' ){
                Empilha(lst); //Caso veja parênteses abertos, ele adiciona para serem preenchidos

            } else if(expressao[j] == ')' ){
                if(!Desempilha(lst)){ // Verifica se existe parênteses abertos, caso exista, ele desempilha.
                    correto = 0;
                    break; //Caso não exista, ele quebra while e define expressão como incorreta
                }
            }
            j++;
        }

        if(lst->seg != NULL || !correto){ //Se tivermos parênteses abertos OU parênteses fechados incorretamente, é incorreto.
            printf("incorrect \n");
        } else {
            printf("correct \n");
        }

        while(lst->seg != NULL){
            Desempilha(lst); //Limpa todas as células (menos a cabeça)
        }
    }

    free(lst); //limpa a cabeça
}

int soluçaoSemFilas(){
    char expressao[1001];

    while(fgets(expressao, 1001, stdin) != NULL){

        int status = 0, j = 0;
        scanf("%s", expressao); 

        while(expressao[j] != '\0'){

            if(expressao[j] == '(' ){
                status++;
            } else if(expressao[j] == ')' ){
                status--;
            }

            if(status < 0){
                break;
            }

            j++;
        }

        if(status != 0){ 
            printf("incorrect \n");
        } else {
            printf("correct \n");
        }
    }

    return 0;
}
