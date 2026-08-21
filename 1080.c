#include <stdio.h>

int maior(int v[], int n, int *p){
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
    int v[100];
    int posicao = 0;

    for(int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);
    }

    printf("%d\n", maior(v, 100, &posicao));
    printf("%d\n", posicao + 1);

    return 0;
}
