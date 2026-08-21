#include <stdio.h>


int Maior(int v[], int n, int *p){
    int x = v[0];
    *p = 0;

    for(int i=1; i<n; i++){
        if(x < v[i]){
            *p = i;
            x = v[i];
        }
    }
    return x;
}


int main() {
    int v[100];
    int posição = 0;

    for(int i = 0; i < 100; i++) {
       scanf("%d", &v[i]);
    }

    printf("%d\n", Maior(v, 100, &posição));
    printf("%d\n", posição + 1);

    return 0;
}