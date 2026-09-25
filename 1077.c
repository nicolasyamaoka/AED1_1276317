/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Fenalti Yamaoka
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 25/09/2026
Objetivo    : Transformar infixo em posfixo
Dificuldade : Diversidade de situações 
Uso de IA   : Criou um direcionamento sobre problemas de lógica, em relação a duplicatas ou exagero de complexidade
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{ //Base de cada celula;
    char valor;
    struct celula *seg;
} celula;

void empilha(celula *pilha, char x) { //empilha e adiciona caractere "x"
    celula *nova = malloc(sizeof(celula));

    nova->valor = x;
    nova->seg = pilha->seg;
    pilha->seg = nova;
}

char desempilha(celula *pilha) { // Desempilha, e retorna caractere "x"
    if (pilha->seg == NULL) {
        return '\0'; // pilha vazia
    }

    celula *lixo = pilha->seg;
    char valor = lixo->valor;

    pilha->seg = lixo->seg;

    free(lixo);

    return valor;
}

int prioridade(char caractere){

    if(caractere == '\0') return 0; //Se não existe mais expressão, tem prioridade mínima
    if(caractere == '+' || caractere == '-') return 1; //Soma e Subtração prioridade 1
    if(caractere == '*' || caractere == '/') return 2; //Multiplicação e Divisão prioridade 2
    if(caractere == '^') return 3; //Exponencial prioridade 3
    return -1; //Possivel erro;
}

void gerandoExpressaoPosfixa(char *expressao, int tamanho, char *posfixo){

    celula *operadores0 = malloc(sizeof(celula)); //Geramos cabeça da pilha dos operadores
    operadores0->seg = NULL;
    int cont=0; //determina tamanho da expressão posfixa.


    for(int i=0; i<tamanho; i++){

        //SE for número/caractere, adiciona na string posfixo
        if((expressao[i]>=48 && expressao[i]<=57) || (expressao[i]>=65 && expressao[i]<=90) || (expressao[i]>=97 && expressao[i]<=122)){
            posfixo[cont++] = expressao[i]; 
        }

        //OU SE for um operador, teremos:
        else if((expressao[i]>=42 && expressao[i]<=47) || (expressao[i]=='^')){

            //Caso a pilha não esteja vazia:
            if(prioridade(expressao[i]) != -1 && operadores0->seg != NULL){

                //Se existir na pilha um elemento de maior prioridade, ele sera imprimido
                while(operadores0->seg != NULL && prioridade(operadores0->seg->valor) >= prioridade(expressao[i])) {
                    posfixo[cont++] = desempilha(operadores0);
                }

                //Depois, colocamos na pilha novo valor;
                empilha(operadores0, expressao[i]);
            }

            //Caso a pilha esteja vazia:
            else if(operadores0->seg == NULL){
              empilha(operadores0, expressao[i]);  
            }
        }

        //Se abrir parenteses, adiciona diretamente na lista.
        else if(expressao[i] == '('){
            empilha(operadores0, expressao[i]);
        }

        //Se for fechar parenteses, desempilhe todos os elementos de dentro do parênteses
        else if(expressao[i] == ')'){
            while(operadores0->seg != NULL && operadores0->seg->valor != '('){
                posfixo[cont++] = desempilha(operadores0);
            }
            desempilha(operadores0); // Remove o '(' da pilha
        }
    }

    //Ao acabar expressão, desempilhe todos os operadores restantes
    while(operadores0->seg != NULL){
    posfixo[cont++] = desempilha(operadores0);
    }
    posfixo[cont] = '\0';
    free(operadores0);
}


int main() {
    int N; //Número de operações
    char *entrada = (char *) malloc(300 * sizeof(char)); //Infixo
    char *posfixo = (char *) malloc(300 * sizeof(char)); //Posfixo

    //entrada N
    scanf("%d",&N);
    getchar();

    for(int i=0; i<N; i++){
        //Entrada Infixo
        fgets(entrada, 300, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        int tamanho = strlen(entrada);
        
        //Saida Posfixo
        gerandoExpressaoPosfixa(entrada, tamanho, posfixo);
        printf("%s\n",posfixo);
    }

    return 0;
}
