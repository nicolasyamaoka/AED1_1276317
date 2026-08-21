#include <stdio.h>

int Sudoku(int matriz[9][9]){
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
        int matriz[9][9];
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
    }
}