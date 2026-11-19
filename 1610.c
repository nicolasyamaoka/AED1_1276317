/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Looping de Grafos
Dificuldade : Entender enunciado
Uso de IA   : Entender como usar DFS em Listas, em Looping e em situação Não direcionada (nunca tinha feito anteriormente)
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{ //Gerar Célula Base
    int V_lig;
    struct celula *seg;
} celula;

int dfs_verificarLoop(celula **Vet_Adj, int visitado[], int v, int V) { //dfs que imprime 1 se existe loop e 0 se não existe.
    visitado[v] = 1; 

    for (celula *p = Vet_Adj[v]; p != NULL; p = p->seg) { //Percorre a lista de um dos vértices

        if (visitado[p->V_lig] == 1) { //Se algum já foi percorrido antes, então existe looping
            return 1; 
        }
        if (visitado[p->V_lig] == 0) { //Se algum caso anterior demonstrou looping, então existe looping
            if (dfs_verificarLoop(Vet_Adj, visitado,p->V_lig, V)) {
                return 1; 
            }
        }
    }


    visitado[v] = 2; //Se todos os vértices que "v" se liga não ocasionaram problemas, esse vértice fica livre de análises.
    return 0; //Implica que não houve problema com ele.
}

void verificarLoop_Completo(celula **Vet_Adj, int V) { //Função usada para verificar todos os subgrafos/vértices de um grafo.
  
    int *visitado = (int *)calloc(V+1, sizeof(int)); //Vetor que armazena se o vértice já foi visitado. Em que: 0 => não visitado / 1 => sendo visitado / 2 => totalmente visitado; 
    int loop = 0; //status de looping, sendo 1 verdadeiro, 0 falso;

    for (int i = 1; i <= V && !loop; i++) { /
        if (visitado[i] == 0) {
            if (dfs_verificarLoop(Vet_Adj, visitado, i, V)) { //Se a função de verificação de subgrafo retornar 1, quer dizer que existe loop.
                loop = 1;
                break;
            }
        }
    }

    if (loop) { //Imprimir se existe Loop
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    free(visitado);
}



int main(){
    int T; //ºn operações
    scanf("%d",&T);
    int v1,v2;

    for(int i=0; i < T; i++){
        int N, M; //nº de vértices e arestas respectivamente
        scanf("%d %d", &N, &M);

        celula **Vet_Adj = (celula **) calloc(N+1, sizeof(celula *)); //vetor de listas, onde gera uma lista para cada vértice

        for(int i = 0; i<M; i++){ //Preenche listas respectivas de cada vértice
            scanf(" %d %d", &v1, &v2);
            celula *novo = (celula *)malloc(sizeof(celula));
            novo->V_lig = v2;
            novo->seg = Vet_Adj[v1];
            Vet_Adj[v1] = novo;
        }

        verificarLoop_Completo(Vet_Adj, N); //Função de verificação de loop


        for (int i = 1; i <= N; i++) { //Aqui para baixo é liberação de memória
            celula *p = Vet_Adj[i];
            while (p) {
                celula *t = p;
                p = p->seg;
                free(t);
            }
        }
        free(Vet_Adj);
    }

    return 0;
}
