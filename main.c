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

void creator(Tabela *tabelas) {
    char nometabelas[50];
    printf("Escolha um nome para a tabela: ");
    scanf("%s", nometabelas);
    strcpy(tabelas->nomeTabela, nometabelas);
    printf("Escolha a quantia de linhas e colunas da tabela: ");
    scanf("%d %d", &tabelas->numLinhas, &tabelas->numColunas);

    // Aloca dinamicamente o tamanho das colunas
    tabelas->colunas = (colunas *)malloc(tabelas->numColunas * sizeof(colunas));

    printf("Digite os nomes das colunas da tabela:\n");
    for (int i = 0; i < tabelas->numColunas; i++) {
        printf("Coluna %d: ", i + 1);
        scanf("%s", tabelas->colunas[i].nomecol);
    }

    printf("Tabela criada com sucesso!\n");
}

int main() {
    Tabela tabelas[5];

    creator(&tabelas[0]);

    printf("Nome: %s\n%d Linhas\n%d Colunas de nome(s)\n", tabelas[0].nomeTabela, tabelas[0].numLinhas, tabelas[0].numColunas);
    printf("Nomes das colunas:\n");


    // Liberar memória alocada dinamicamente
    free(tabelas[0].colunas);

    return 0;
}
