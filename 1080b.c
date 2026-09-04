/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 28/08/2026
Objetivo    : Encontrar o maior valor de um vetor
Dificuldade : Aplicação de ponteiros
Uso de IA   : Sem uso
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int maior(int *v, int n, int *p){
    int x = v[0];
    *p = 0;

    for(int i = 1; i < n; i++){
        if(x < v[i]){
            *p = i;
            x = v[i];
        }
    }
    return x;
}

int main() {
    int *v = (int*) malloc(100 * sizeof(int));
    int posicao = 0;

    for(int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);
    }

    printf("%d\n", maior(v, 100, &posicao));
    printf("%d\n", posicao + 1);
    free(v);
    return 0;
}
