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

void dtsModificado(int **grafo, int v, int visitado[], int V, int *aux) { //dts comum, só que armazena vértices em vetor aux

    visitado[v] = 1;
    aux[v] = 1;

    for (int i = 0; i < V; i++) {
        if (grafo[v][i] == 1 && !visitado[i]) {
            dtsModificado(grafo, i, visitado, V, aux);
        }
    }
}

void analiseGrafo(int **grafo, int V, int E, int numero){
    int status = 1 //Define se todos os vértices já foram analisados (1 para não, 0 para sim)
    int cont = 0; //Define quantas análises foram feitas
    int visitado[V], vertice; //Gera vetor de visitados e variável de vertice específico;


    for(int i=0; i<V; i++) visitado[i] = 0;  //Zera vetor visitado

    printf("Case #%d:\n", numero);

    do{
    
        for(int i=0; i<V; i++){ //Analise de qual será o vertice analizado
          
            if(visitado[i] == 0){ //Se o vertice "i" não foi analisado, ele será utilizado
            vertice = i;
            break;
            }

            if(i == V - 1) status = 0; //Se todos os vértices já foram analisados, status = 0;
            
        }

        if(status){ 
            int *aux = calloc(V, sizeof(int));
            dtsModificado(grafo, vertice, visitado, V, aux); //gera vetor aux que contêm todo o subgrupo dos vértices

            for(int i = 0; i<V; i++)
            if(aux[i] == 1) printf("%c,", 97 + i); //Analisa o vetor e imprime os vértices de forma crescente;
            
            printf("\n");
            free(aux);
            cont++;
        }
        
    } while(status);

    printf("%d connected components\n\n", cont); 
}


int main(){
    int N;
    scanf("%d",&N);
    char v1,v2;

    for(int i=0; i < N; i++){
        int V, E;
        scanf("%d %d", &V, &E); //Recebe Vértices e Arestas

        int **grafo = (int **)calloc(V, sizeof(int *)); //Aloca Matriz 
        for (int i = 0; i < V; i++) {
            grafo[i] = (int *)calloc(V, sizeof(int));
        }

        for(int i = 0; i<E; i++){
            scanf(" %c %c", &v1, &v2); //Preenche Matriz de adjacência
            grafo[v1-97][v2-97] = 1;
            grafo[v2-97][v1-97] = 1;
        }

        analiseGrafo(grafo, V, E, i + 1); //Executa Saida do Programa
      
        for (int j = 0; j < V; j++) //Libera Memória
        free(grafo[j]);
        free(grafo);
    }

    return 0;
}
