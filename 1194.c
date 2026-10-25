/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 23/10/2026
Objetivo    : Formar posfixo a partir de infixo e prefixo.
Dificuldade : Desenvolver lógica sem produzir árvore.
Uso de IA   : Entender lógica de resolução
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

char prefixo[53], infixo[53];
int pos;

void posfixo(int inicio, int fim) {
    if (inicio > fim) return; //Sem valor de entrada, retorna vazio

    char raiz = prefixo[pos++]; //Encontra raiz em prefixo
    int i;

    for (i = inicio; i <= fim; i++) {
        if (infixo[i] == raiz) //endereço raiz no infixo
            break;
    }

    posfixo(inicio, i - 1); //Sub-árvore Esquerda;
    posfixo(i + 1, fim); //Sub-árvore Direita;

    printf("%c", raiz); //Imprime quando sobra raiz da sub-árvore;
}

int main() {
    int C, N;
    scanf("%d", &C);

    while (C--) {
        scanf("%d %s %s", &N, prefixo, infixo); //Absorve Entrada

        pos = 0;
        posfixo(0, N - 1);
        printf("\n");
    }

    return 0;
}
