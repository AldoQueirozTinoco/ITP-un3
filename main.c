#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { CHAR, STR, INT, FLOAT, DOUBLE } Types;

typedef struct {
    char nomecol[20];
    Types tipo;
} colunas;

typedef struct {
    char ischar;
    char *istring;
    int isint;
    float isfloat;
    double isdouble;
} Celula;

typedef struct {
    char nomeTabela[50];
    int numLinhas;
    int numColunas;
    colunas *colunas; // para nome e types
    colunas chavePrimaria;
    Celula **dados; // matriz de dados
} Tabela;

void creator(Tabela *tabelas, int *counTab) {
    char nometabelas[50];
    printf("Escolha um nome para a tabela: ");
    scanf("%s", nometabelas);

    /*nomes das tabelas devem ser juntos, 
    assim como os nomes das linhas e das colunas*/

    strcpy(tabelas->nomeTabela, nometabelas);
    printf("Escolha a quantia de linhas e colunas da tabela: ");
    scanf("%d %d", &tabelas->numLinhas, &tabelas->numColunas);

    // Aloca dinamicamente o tamanho das colunas
    tabelas->colunas = (colunas *)malloc(tabelas->numColunas * sizeof(colunas));

    printf("Digite os nomes das colunas da tabela e seus tipos:\n");
    for (int i = 0; i < tabelas->numColunas; i++) {
        int temp;
        printf("Coluna %d: ", i + 1); // nome das colunas
        scanf("%s", tabelas->colunas[i].nomecol);
        printf("(CHAR=1,STRING=2,FLOAT=3,DOUBLE=4): "); //tipo das colunas
        scanf("%d",&temp);
        tabelas->colunas[i].tipo = temp;

    }
  tabelas->dados = malloc(tabelas->numLinhas * sizeof(Celula*));//aloca a matriz de dados
  for(int i=0;i<tabelas->numLinhas;i++){
    tabelas->dados[i] = malloc(tabelas->numColunas *sizeof(Celula));
  };
    printf("Tabela criada com sucesso!\n");
    printf("Nome: %s\n%d Linhas\n%d Colunas\n", tabelas->nomeTabela, tabelas->numLinhas, tabelas->numColunas);
    counTab+=1;
  printf("Escreva os registros da tabela:");
  /*Fazer uma função que insere os registros*/
  for(int i=0;i<tabelas->numLinhas;i++){
    for(int j=0;j<tabelas->numColunas;j++){
  switch(tabelas->colunas[j].tipo){
    case CHAR:
    scanf("%c", &tabelas->dados[i][j].ischar);
    break;
    case(STR):
      tabelas->dados[i][j].istring = malloc(sizeof(char)*50);
      printf("Digite uma string de até 50 caracteres de espaço:\n");
      fgets(tabelas->dados[i][j].istring,50,stdin);
    break;
    case(INT):
      scanf("%d", &tabelas->dados[i][j].isint);
    break;
    case(FLOAT):
      scanf("%f", &tabelas->dados[i][j].isfloat);
    break;
    case(DOUBLE):
      scanf("%lf", &tabelas->dados[i][j].isdouble);
    break;
  }

}}}

int main() {
    Tabela tabelas[10];//Permite até 10 tabelas
    int escolha, counTab=0;
    while(escolha!=6){
    printf("O QUE DESEJA FAZER?\n1 - Criar tabela\n2 - Criar linha\n3 - Excluir tabela\n4 - Procurar registro\n5 - Excluir linha\n6 - Sair\n");
    scanf(" %i", &escolha);

    switch (escolha){
    case 1: creator(&tabelas[counTab],&counTab);
    //Criador de tabelas por meio do tipo e nome
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:
        break;
    default:
        printf("Numero invalido");
        break;
        }

    }


    // Liberar memória alocada dinamicamente
    free(tabelas[0].colunas);
    free(tabelas[0].dados);

    return 0;
}

