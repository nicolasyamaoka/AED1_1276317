/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 22/09/2026
Objetivo    : Utilizar a busca binária
Dificuldade : compreender o e= -1
Uso de IA   : Nenhum
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int buscar(int x, int N, int *casa){
    int e = -1, m, d = N;
    while(e < d-1){
        m = (e+d)/2;
        if(x > casa[m]) e=m;
        else d=m; 
    }
    return d;
}

int main() {
    int N, M, cont=0, pos = 0;
    
    scanf("%d %d", &N, &M);

    int *casa = (int*) malloc(N*sizeof(int));
    for(int i=0; i<N; i++){
        scanf("%d", &casa[i]);
    }

    int *entrega = (int*) malloc(M*sizeof(int));
    for(int i=0; i<M; i++){
        scanf("%d", &entrega[i]);
    }

    for(int i=0; i<M; i++){
        int local = buscar(entrega[i], N, casa);
        cont = cont + abs(local - pos);
        pos = local;
    }

    printf("%d\n", cont);
    free(casa);
    free(entrega);
    return 0;
}
