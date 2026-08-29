/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 21/08/2026
Objetivo    : Verificar se a matriz corresponde as especificações do Sudoku
Dificuldade : Verificar repetições de termos nas matrizes 3x3.
Uso de IA   : Nenhum uso
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int Sudoku(int **matriz){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(matriz[i][j] < 1 || matriz[i][j] > 9){
                return 0;
            }

            for(int k = 0; k < 9; k++){
                if(matriz[i][j] == matriz[i][k] && (k != j)){
                    return 0;
                }
            }

            for(int k = 0; k < 9; k++){
                if(matriz[j][i] == matriz[k][i] && (k != j)){
                    return 0;
                }   
            }

        }


    }

    for(int i = 0; i < 9; i+=3){
        for(int j = 0; j < 9; j+=3){

            int usado[10] = {0};

            for(int k = i; k < i + 3; k++){
                for(int l = j; l < j + 3; l++){

                    int numero = matriz[k][l];

                    if(usado[numero] == 1){
                        return 0;
                    }

                    usado[numero] = 1;
                }
            }
        }
    }

    return 1;
}

int main(){
    int n = 0, k = 1;

    while(n <= 0){
        scanf("%d", &n);
    }

    while(k <= n){
        
        int **matriz = (int**) malloc(9 * sizeof(int*));
        for(int i = 0; i < 9; i++){
            matriz[i] = (int*) malloc(9 * sizeof(int));
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        if(Sudoku(matriz)){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        k++;
        printf("\n");

        for(int i=0; i<9;i++){
            free(matriz[i]);
        }
        free(matriz);
    }
}
