/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 21/08/2026
Objetivo    : Encontrar o maior valor de um vetor
Dificuldade : Aplicação de ponteiros
Uso de IA   : A IA me ajudou na detecção de caracteres que o terminal do beecrowd não reconhecia, como acentos
-------------------------------------------------------------------------- */

#include <stdio.h>

int maior(int v[], int n, int *p){
    int x = v[0]; // Salva valor inicial em "x"
    *p = 0; // Salva a posição inicial no ponteiro

    for(int i = 1; i < n; i++){ //Salva a posição e o valor do maior número do vetor ao percorre-lo.
        if(x < v[i]){ 
            *p = i;
            x = v[i];
        }
    }
    return x;
}

int main() {
    int v[100];
    int posicao = 0;

    for(int i = 0; i < 100; i++) { //Dando valores ao vetor
        scanf("%d", &v[i]);
    }

    printf("%d\n", maior(v, 100, &posicao));
    printf("%d\n", posicao + 1);

    return 0;
}
