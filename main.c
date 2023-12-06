#include <stdio.h>
#include <string.h>

typedef enum{CHAR,STR,INT,FLOAT,DOUBLE}Types;

typedef struct{
    char nomecol[20];
    Types tipo;
}colunas;

typedef struct{
    char ischar;
    char *istring;
    int isint;
    float isfloat;
    double isdouble;
}Celula;

typedef struct {
  char nomeTabela[50];
  int numLinhas;
  int numColunas;
  colunas *colunas; //para nome e types
  colunas chavePrimaria;
  Celula **dados;  //matriz de dados
} Tabela;

void creator(){
    char nometabelas[20];
    printf("Escolha um nome para a tabela");
    scanf("%s",nometabelas);
    strcpy(tabelas[0].nomeTabela,nometabelas);
    printf("Escolha a quantia de linhas e colunas da tabela");
    scanf("%d %d",&tabelas[0].numLinhas,&tabelas[0].numColunas);
    printf("Digite os nomes das colunas da tabela");
    for(int i=0;i<tabelas[0].numColunas;i++){
    scanf("%s",nomecolunas);
    strcpy(tabelas[0].colunas->nomecol,nomecolunas);
    }
    printf("Tabela criada com sucesso!");
}
int main(){
    Tabela tabelas[5];
    char nometabelas[50];
    char nomecolunas[50];
    char chavesprimarias[50];
 
/*printf("O QUE DESEJA FAZER?\n1 Criar tabela\n2 Criar linha\n3 Excluir tabela\n4 Procurar registro\n5 Excluir linha\n6 ")
    nn sei como q implementa isso xd*/
    
    printf("Escolha um nome para a tabela");
    scanf("%s",nometabelas);
    strcpy(tabelas[0].nomeTabela,nometabelas);
    printf("Escolha a quantia de linhas e colunas da tabela");
    scanf("%d %d",&tabelas[0].numLinhas,&tabelas[0].numColunas);
    printf("Digite os nomes das colunas da tabela");
    for(int i=0;i<tabelas[0].numColunas;i++){
    scanf("%s",nomecolunas);
    strcpy(tabelas[0].colunas->nomecol,nomecolunas);
    }
    printf("Tabela criada com sucesso!");
    return 0;
}


