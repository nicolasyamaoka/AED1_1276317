/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 01/10/2026
Objetivo    : Ver de quantas formas conseguimos reorganizar o trem
Dificuldade : Entender enunciado
Uso de IA   : Nenhum
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int valor;
    struct celula *seg;
} celula;

void empilhar(celula *lst, int valor){ 
    celula *nova = malloc(sizeof(celula));
    nova->seg = lst->seg;
    lst->seg = nova;
    nova->valor = valor;
}

int desempilhar(celula *lst){
    celula *lixo;
    lixo = lst->seg;

    int x = lixo->valor;
    lst->seg = lixo->seg;

    free(lixo);
    return x;
}




void trilhos(int N, int OrdemDesejada[]){
    int OrdemA = 1; //Sequência de Entrada do Trem
    int OrdemB[N]; //Sequencia de Saída do Trem

    int contD=0; //Qual elemento da OrdemDesejada estamos analisando
    int contB=0; //Qual elemento da OrdemB estamos inserindo

    celula *lst = malloc(sizeof(celula)); //Pilha auxiliar
    lst->seg = NULL;

    while(OrdemA <= N){
        
        if(OrdemA == OrdemDesejada[contD]){ //Se o termo A é o mesmo termo Desejado, já coloca na OrdemB
            OrdemB[contB++] = OrdemA++;
            contD++;
        } 

        else if(lst->seg != NULL && lst->seg->valor == OrdemDesejada[contD]){ //Se o termo Desejado está na cabeça da Pilha, já coloca na OrdemB
            OrdemB[contB++] = desempilhar(lst);
            contD++;
        }

        else{ //Se não temos onde colocar o termo, joga na pilha para ser colocado depois
            empilhar(lst, OrdemA++); 
        }
    }

    while(lst->seg != NULL){ //Todos elementos que sobraram na pilha devem ser colocados na OrdemB
        OrdemB[contB++] = desempilhar(lst);
    }

    int status = 1;
    for(int i=contD; i<N; i++){ //Se as duas ordens são iguais. O status é Verdadeiro
        if(OrdemB[i] != OrdemDesejada[i]){ 
            status = 0;//SE houve diferença entre a Ordem B e OrdemDesejada. O status é Falso
            break;
        }
    }

    if(status){
        printf("Yes\n"); //Se for igual, imprime Yes, caso contrário, imprime No
    } else {
        printf("No\n");
    }
}


int main(){
    int N;
    scanf("%d",&N); //primeiro valor N

    while(N !=0){

        int status = 1; //Define execução do programa 
        int vet[N];
        
        for(int i=0; i<N; i++){
            scanf("%d",&vet[i]); //Gera novo vetor de entrada

            if(vet[0] == 0){ 
                printf("\n");
                scanf("%d",&N); //Novo valor de N
                status = 0; //Cancela execução do programa
                break;
            }
        }

        if(status){ //**Programa Principal**//
            trilhos(N, vet);
        }
    }

    return 0;
}
