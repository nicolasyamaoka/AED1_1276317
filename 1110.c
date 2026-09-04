/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 28/08/2026
Objetivo    : Definir quais Cartas foram jogadas fora (ordem) e qual sobrou
Dificuldade : Realizar todo o procedimento, envolvendo desde as camadas de repetição, até repercussão do código
Uso de IA   : Uso moderado para correção, principalmente no "while(scanf("%d", &n) == 1 && n != 0){" e Preenchendo a lista com os valores de 1 até n
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{ //Base de cada carta;
    int valor;
    struct celula *seg;
} celula;

void Desempilha(celula *c, int *saida, int salva, int *cont){
    celula *lixo;
    lixo = c->seg;
    c->seg = lixo->seg;

    if(salva){
        saida[(*cont)++] = lixo->valor; //Salva o valor da carta descartada no vetor de saída
    }

    free(lixo);
}


void MudaEndereco(celula *c){
    celula *aux1;
    aux1 = c->seg;
    c->seg = aux1->seg; //Liga a cabeça da lista para a 2º carta

    celula *p = c;
    while (p->seg != NULL){ //Busca a ultima carta
        p = p -> seg;
    }

    p->seg = aux1; //Liga a ultima carta para a 1º carta, que será descartada na próxima iteração
    aux1->seg = NULL;
}

int JogandoCartasFora(int n, int *saida, celula *lst, int *cont){

   if(n == 1){ //Se só tiver uma carta, ela é a única retornada
        return lst->seg->valor;
    }

    if(lst->seg->seg == NULL){ //Quando só tiver uma carta, ela é a única retornada;
        return lst->seg->valor;
    }

    Desempilha(lst, saida, 1, cont); //elimina primeira carta e salva ela no vetor de saída
    MudaEndereco(lst);  
    //Muda endereço da cabeça para a próxima carta, que será descartada na próxima iteração

    return JogandoCartasFora(n, saida, lst, cont); //Recurssão

}


int main(){
    int n;
    
    while(scanf("%d", &n) == 1 && n != 0){ //Todos os valores devem ser naturais e o programa deve parar quando o valor de n for 0
        if(n == 0){
            break;
        }
    
        celula *lst = malloc(sizeof(celula));  //Cabeça da lista
        lst->seg = NULL;

        int *saida = (int*) malloc((n)*sizeof(int)); //Vetor que armazena as cartas descartadas
        int *cont = (int*) malloc(sizeof(int)); *cont = 0; //Contador de cartas descartadas

        celula *endereco = lst;
        for(int i=1; i<=n; i++){ //Preenchendo a lista com os valores de 1 até n
            celula *novo;
            novo = malloc(sizeof(celula));
            novo->valor = i;
            novo->seg = NULL;
            endereco->seg = novo;
            endereco = novo;
        }

    
        int sobra = JogandoCartasFora(n, saida, lst, cont); //Executa a função de descartaar cartas e retornar a ultima

        printf("Discarded cards:"); //Imprime as cartas descartadas
        for(int i = 0; i < *cont; i++){
            if(i == 0) printf(" %d", saida[i]);
            else printf(", %d", saida[i]);
        }
        
        printf("\nRemaining card: %d\n", sobra); //Imprime a ultima carta que sobrou
    
        while (lst->seg != NULL) { //Limpa a lista (menos a cabeça)
            Desempilha(lst, NULL, 0, cont);
        }

        //Limpa a memória alocada
        free(lst);
        free(saida);
        free(cont);
    }

    return 0;
}
