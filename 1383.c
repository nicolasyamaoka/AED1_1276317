/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 21/08/2026
Objetivo    : Verificar se a matriz corresponde as especificações do Sudoku
Dificuldade : Verificar repetições de termos nas matrizes 3x3.
Uso de IA   : A IA me ajudou ma solução prática das matrizes 3x3.
-------------------------------------------------------------------------- */

#include <stdio.h>

int Sudoku(int matriz[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(matriz[i][j] < 1 || matriz[i][j] > 9){ //Retorna FALSO se tiver valores não permitidos pelo SUDOKU;
                return 0;
            }

            for(int k = 0; k < 9; k++){
                if(matriz[i][j] == matriz[i][k] && (k != j)){ //Retorna FALSO se valores repetidos nas colunas;
                    return 0;
                }
            }

            for(int k = 0; k < 9; k++){
                if(matriz[j][i] == matriz[k][i] && (k != j)){ //Retorna FALSO se valores repetidos nas linhas;
                    return 0;
                }   
            }

        }


    }

    for(int i = 0; i < 9; i+=3){
        for(int j = 0; j < 9; j+=3){

            int usado[10] = {0}; //Declaração de vetor de elementos já utilizados ou/e Zeramento do vetor;

            for(int k = i; k < i + 3; k++){
                for(int l = j; l < j + 3; l++){

                    int numero = matriz[k][l]; // Salva elemento da atriz;

                    if(usado[numero] == 1){ // Se numero já foi utilizado anteriormente, retorna Falso;
                        return 0;
                    }

                    usado[numero] = 1; // Caso contrário, salva ocorrencia desse número no vetor;
                }
            }
        }
    }

    return 1;
}

int main(){
    int n = 0, k = 1;

    while(n <= 0){ // Número de matrizes a serem produzidas
        scanf("%d", &n);
    }

    while(k <= n){ //gerando Matriz
        int matriz[9][9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", k); //Imprimindo resultado da verificação do Sudoku;
        if(Sudoku(matriz)){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        k++;
        printf("\n");
    }
}
