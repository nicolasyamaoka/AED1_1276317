/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 04/09/2026
Objetivo    : Aplicar teste, denominando se a expressão era uma Lista, Pilha, Prioridade, Nenhuma, ou incerto.
Dificuldade : Aplicação da lógica na união de três listas diferentes.
Uso de IA   : Corrigiu erros de lógica, principalmente envolvendo o "BUSCAR", obrigando-me a fazer 3 listas
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{ //Forma das Células
    int valor;
    struct celula *seg;
} celula;

// Adiciona celula a lista, o qual terá valor "X"
void inserir(celula *lst, int x) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = x;
    nova->seg = lst->seg;
    lst->seg = nova;
}

// Remove celula "ENDERECO" da lista, o qual usa um auxiliar para achar o antecessor.
void remover(celula *lst, celula *endereco){
    celula *aux = lst;

    if(lst->seg == NULL){
        return;
    }

    while(aux != NULL && aux->seg != endereco){
        aux = aux->seg;
    }

    if(aux == NULL || endereco == NULL){
        return;
    } 
    aux->seg = endereco->seg;
    free(endereco);
}

// Retorna o endereço da ultima célula
celula *ultimo(celula *lst){
    celula *aux = lst->seg;

    if(aux == NULL){
        return NULL;
    }

    while(aux->seg != NULL){
        aux = aux->seg;
    }

    return aux;
}


// Retorna o endereço da célula de maior valor
celula *maior(celula *lst){
    celula *aux = lst->seg;

    if(aux == NULL){
        return NULL;
    }

    celula *enderecoMaior = aux;
    while(aux != NULL){

        if(aux->valor > enderecoMaior->valor){
            enderecoMaior = aux;
        }

        aux = aux->seg;
    }

    return enderecoMaior;
}

//Libera as células em sequência toda a lista
void liberar(celula *lst){
    celula *aux = lst;

    while(aux != NULL){ 
        celula *proximo = aux->seg;
        free(aux);
        aux = proximo;
    }
}



int main(){
    int N, operacao, valor;

    while(scanf("%d", &N) != EOF){
        celula *fila = malloc(sizeof(celula)); //Gerando Cabeça FILA
        fila->seg = NULL;
        celula *pilha = malloc(sizeof(celula)); //Gerando Cabeça PILHA
        pilha->seg = NULL;
        celula *prioridade = malloc(sizeof(celula)); //Gerando Cabeça PRIORIDADE
        prioridade->seg = NULL;


        int *status = malloc(4*sizeof(int));
        for(int i=0; i<4; i++) status[i] = 1;  
        //status[0] = FILA ; 
        //status[1] = PILHA; 
        //status[2] = PRIORIDADE; 
        //status[3] = IMPOSSIVEL


        for(int i=0; i<N; i++){
            scanf("%d %d", &operacao, &valor);

            if(status[3]){ //Se condição ser impossivel, código não precisa ser rodado..

                if(operacao == 1){ //Opção 1: Insere valores nas reespectivas listas ainda possiveis.
                    if(status[0]) inserir(fila, valor);
                    if(status[1]) inserir(pilha, valor);
                    if(status[2]) inserir(prioridade, valor);
                }

                if(operacao == 2){
            
                    if(status[0]){
                        celula *aux = ultimo(fila); //Encontra a ultima célula

                        if(aux == NULL || aux->valor != valor){ //Se "valor do ultimo termo" for diferente do "valor de entrada", então não é FILA.
                            status[0] = 0;

                        } else {
                            remover(fila, aux); //Caso for fila, removemos ultima célula e continuamos a testar.
                        }
                    }   

                    if(status[1]){
                        celula *aux = pilha->seg; //Encontra a primeira célula

                        if(aux == NULL || aux->valor != valor){ //Se "valor do primeiro termo" for diferente do "valor de entrada", então não é PILHA.
                            status[1] = 0;
                        } else {
                            remover(pilha, aux); //Caso for pilha, removemos primeira célula e continuamos a testar.
                        }
                    }

                    if(status[2]){
                        celula *aux = maior(prioridade);//Encontra a célula com maior valor

                        if(aux == NULL || aux->valor != valor){ //Se "o maior valor" for diferente do "valor de entrada", então não é prioridade
                            status[2] = 0;
                        } else {
                            remover(prioridade, aux); //Caso for prioridade, removemos célula maior e continuamos a testar.
                        }
                    }   
                }   

                if(status[0] + status[1] + status[2] == 0){ //Caso todos não seja nada, ele se torna impossivel
                status[3] = 0;
                }
            }
        }    
    

        if(status[3]){
            int resultado = status[0] + status[1] + status[2]; //Imprimimos os resultados de STATUS

            if(resultado > 1) printf("not sure\n");
            else if(status[0]) printf("queue\n");
            else if(status[1]) printf("stack\n");
            else if(status[2]) printf("priority queue\n");

        } else {
            printf("impossible\n");
        }
        
        liberar(fila); //Liberando memória
        liberar(pilha);
        liberar(prioridade);
    }

    return 0;
}
