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
    //Colocando os nomes e os tipos, é possível fazer os registros nas linhas com a função "inserir"
    printf("Digite os nomes das colunas da tabela e seus tipos:\n");
    for (int i = 0; i < tabelas->numColunas; i++) {
        int temp;
        printf("Coluna %d: ", i + 1); // nome das colunas
        scanf("%s", tabelas->colunas[i].nomecol);
        printf("(CHAR=0,STRING=1,INT=2,FLOAT=3,DOUBLE=4): \n"); //tipo das colunas
        scanf("%d",&temp);
        tabelas->colunas[i].tipo = temp;

    }
  tabelas->dados = malloc(tabelas->numLinhas * sizeof(Celula*));//aloca as linhas da matriz de dados
  for(int i=0;i<tabelas->numLinhas;i++){
    tabelas->dados[i] = malloc(tabelas->numColunas *sizeof(Celula));//aloca as colunas da matriz de dados
  };
    printf("Tabela criada com sucesso!\n\n");
    printf("Nome: %s\n%d Linhas\n%d Colunas\n\n", tabelas->nomeTabela, tabelas->numLinhas, tabelas->numColunas);
    counTab+=1;
  }

void inserir(Tabela *tabelas) {
  printf("Escreva os registros da tabela:\n");
    /*Fazer uma função que insere os registros*/
    char temp;
    for(int i=0;i<tabelas->numLinhas;i++){
      for(int j=0;j<tabelas->numColunas;j++){
    switch(tabelas->colunas[j].tipo){
      case CHAR:
      if(tabelas->dados[i][j].ischar=='\0'){
          printf("Registro %d %d: ",i,j);
      scanf(" %c", &tabelas->dados[i][j].ischar);}
      break;
      case(STR):
      if(tabelas->dados[i][j].istring!=NULL){
          printf("Registro %d %d: ",i,j);
        tabelas->dados[i][j].istring = malloc(sizeof(char)*50);
        printf("Digite uma string de até 50 caracteres de espaço:\n");
        fgets(tabelas->dados[i][j].istring,50,stdin);
        scanf("%c",&temp);}
      break;
      case(INT):
      if(tabelas->dados[i][j].isint=='\0'){
          printf("Registro %d %d: ",i,j);
        scanf("%d", &tabelas->dados[i][j].isint);}
      break;
      case(FLOAT):
      if(tabelas->dados[i][j].isfloat=='\0'){
          printf("Registro %d %d: ",i,j);
        scanf("%f", &tabelas->dados[i][j].isfloat);}
      break;
      case(DOUBLE):
      if(tabelas->dados[i][j].isdouble=='\0'){
          printf("Registro %d %d: ",i,j);
        scanf("%lf", &tabelas->dados[i][j].isdouble);}
      break;
      default:
      printf("Tipo inválido!");
      break;
    }

  }}
}

void supercolliner(Tabela *tabelas) {
    tabelas->numLinhas++;

    // Realoca a matriz de dados para a nova quantidade de linhas
    tabelas->dados = realloc(tabelas->dados, tabelas->numLinhas * sizeof(Celula*));

    // Aloca as colunas para a nova linha
    tabelas->dados[tabelas->numLinhas - 1] = malloc(tabelas->numColunas * sizeof(Celula));

    printf("Linha criada!\n\n");
}

void excluirTab(Tabela*tabelas,int *counTab){
  Tabela temp[10];
  int count=0;
  for(int i=0;i<10;i++){
    if(tabelas[i].nomeTabela[0]!='\0'){
      if(strcmp(tabelas[i].nomeTabela,tabelas->nomeTabela)!=0){
        temp[count]=tabelas[i];
        count++;
      }
      }
    }
  for(int i=0;i<10;i++){
    tabelas[i]=temp[i];
  }
  counTab--;
  }

void pesquisarString(Tabela *tabela, int coluna, char *valorPesquisa, int escolhaOpcao) {
    int numLinhas = tabela->numLinhas;
    int colunaSelecionada = coluna;
    int encontrados = 0;

    switch (escolhaOpcao) {
        
        case 1: // Valores maiores que o informado
            for (int i = 0; i < numLinhas; i++) {
                if (strcmp(tabela->dados[i][colunaSelecionada].istring, valorPesquisa) > 0) {
                    // Faça algo com o registro encontrado (por exemplo, imprimir ou armazenar)
                    encontrados++;
                }
            }
            break;
        case 2: // Valores maiores ou iguais ao informado
            for (int i = 0; i < numLinhas; i++) {
                if (strcmp(tabela->dados[i][colunaSelecionada].istring, valorPesquisa) >= 0) {
                    encontrados++;
                }
            }
            break;
        case 3: // Valores iguais ao informado
            for (int i = 0; i < numLinhas; i++) {
                if (strcmp(tabela->dados[i][colunaSelecionada].istring, valorPesquisa) == 0) {
                    encontrados++;
                }
            }
            break;
        case 4: // Valores menores que o informado
            for (int i = 0; i < numLinhas; i++) {
                if (strcmp(tabela->dados[i][colunaSelecionada].istring, valorPesquisa) < 0) {
                    encontrados++;
                }
            }
            break;
        case 5: // Valores menores ou iguais ao informado
            for (int i = 0; i < numLinhas; i++) {
                if (strcmp(tabela->dados[i][colunaSelecionada].istring, valorPesquisa) <= 0) {
                    encontrados++;
                }
            }
            break;
        default:
            printf("Opção de pesquisa inválida.\n");
            return;
    
    }

    if (encontrados > 0) {
        printf("Registros encontrados: %d\n", encontrados);
    } else {
        printf("Nenhum registro encontrado.\n");
    }
}

void pesquisarNaoString(Tabela *tabela, int coluna, int escolhaOpcao) {
    int numLinhas = tabela->numLinhas;
    int colunaSelecionada = coluna;
    int encontrados = 0;

    switch (escolhaOpcao) {
        
        case 1: // Valores maiores que o informado
            for (int i = 0; i < numLinhas; i++) {
                if (tabela->dados[i][colunaSelecionada].isint > valorPesquisaInt) {
                    // Faça algo com o registro encontrado
                    encontrados++;
                }
            }
            break;
        case 2: // Valores maiores ou iguais ao informado
            for (int i = 0; i < numLinhas; i++) {
                if (tabela->dados[i][colunaSelecionada].isint >= valorPesquisaInt) {
                    encontrados++;
                }
            }
            break;
        case 3: // Valores iguais ao informado
            for (int i = 0; i < numLinhas; i++) {
                if (tabela->dados[i][colunaSelecionada].isint == valorPesquisaInt) {
                    encontrados++;
                }
            }
            break;
        case 4: // Valores menores que o informado
            for (int i = 0; i < numLinhas; i++) {
                if (tabela->dados[i][colunaSelecionada].isint < valorPesquisaInt) {
                    encontrados++;
                }
            }
            break;
        case 5: // Valores menores ou iguais ao informado
            for (int i = 0; i < numLinhas; i++) {
                if (tabela->dados[i][colunaSelecionada].isint <= valorPesquisaInt) {
                    encontrados++;
                }
            }
            break;
        default:
            printf("Opção de pesquisa inválida.\n");
            return;
    
    }

    if (encontrados > 0) {
        printf("Registros encontrados: %d\n", encontrados);
    } else {
        printf("Nenhum registro encontrado.\n");
    }
}

void procurarRegistro(Tabela *tabelas) {
    char nomeTabela[50];
    printf("Digite o nome da tabela onde deseja realizar a pesquisa: ");
    scanf("%s", nomeTabela);

    // Procurar a tabela pelo nome
    int indiceTabela = -1;
    for (int i = 0; i < 10; i++) {
        if (strcmp(tabelas[i].nomeTabela, nomeTabela) == 0) {
            indiceTabela = i;
            break;
        }
    }

    if (indiceTabela == -1) {
        printf("Tabela %s não encontrada.\n", nomeTabela);
        return;
    }

    // Mostrar as colunas disponíveis na tabela
    printf("Colunas disponíveis na tabela %s:\n", nomeTabela);
    for (int i = 0; i < tabelas[indiceTabela].numColunas; i++) {
        printf("%d - %s\n", i + 1, tabelas[indiceTabela].colunas[i].nomecol);
    }

    int escolhaColuna;
    printf("Escolha o número da coluna para a pesquisa: ");
    scanf("%d", &escolhaColuna);
    escolhaColuna--; // Ajustar para o índice do array

    if (escolhaColuna < 0 || escolhaColuna >= tabelas[indiceTabela].numColunas) {
        printf("Escolha de coluna inválida.\n");
        return;
    }

    // Se a coluna for do tipo string, oferecer opções adicionais
    if (tabelas[indiceTabela].colunas[escolhaColuna].tipo == STR) {
        printf("Opções de pesquisa para coluna %s:\n", tabelas[indiceTabela].colunas[escolhaColuna].nomecol);
        printf("1. Valores maior que o informado\n");
        printf("2. Valores maior ou igual ao informado\n");
        printf("3. Valores igual ao informado\n");
        printf("4. Valores menor que o informado\n");
        printf("5. Valores menor ou igual ao informado\n");

        int escolhaOpcao;
        printf("Escolha a opção de pesquisa: ");
        scanf("%d", &escolhaOpcao);

        char valorPesquisa[50];
        printf("Digite o valor para pesquisa na coluna %s: ", tabelas[indiceTabela].colunas[escolhaColuna].nomecol);
        scanf("%s", valorPesquisa);

        pesquisarString(&tabelas[indiceTabela], escolhaColuna, valorPesquisa, escolhaOpcao);

    } else {
        // Se a coluna não for do tipo string, a pesquisa será simples
        int escolhaOpcao;
        printf("Opções de pesquisa para coluna %s:\n", tabelas[indiceTabela].colunas[escolhaColuna].nomecol);
        printf("1. Valores maior que o informado\n");
        printf("2. Valores maior ou igual ao informado\n");
        printf("3. Valores igual ao informado\n");
        printf("4. Valores menor que o informado\n");
        printf("5. Valores menor ou igual ao informado\n");

        printf("Escolha a opção de pesquisa: ");
        scanf("%d", &escolhaOpcao);

        pesquisarNaoString(&tabelas[indiceTabela], escolhaColuna, escolhaOpcao);
    }
}

int main() {
    Tabela tabelas[10];//Permite até 10 tabelas
    int escolha, counTab=0,qualtab;
    while(escolha!=7){
    printf("O QUE DESEJA FAZER?\n1 - Criar tabela\n2 - Criar linha\n3 - Excluir tabela\n4 - Adicionar registro(s)\n5 - Procurar registro\n6 - Excluir linha\n7 - Sair\n");
    scanf(" %i", &escolha);
    printf("\e[1;1H\e[2J");
    switch (escolha){
    case 1: creator(&tabelas[counTab],&counTab);
    //Criador de tabelas por meio do tipo e nome
    inserir(&tabelas[counTab]);
    //Inserir os registros
        break;
    case 2:
    printf("Em qual tabela deseja inserir uma linha?\n");
    for(int i=0;i<=counTab;i++){
        printf("%d - %s\n",i,tabelas[i].nomeTabela);
      }
     scanf("%d",&qualtab);
     supercolliner(&tabelas[qualtab]);
     qualtab =0;
        break;
    case 3:
      printf("Qual tabela deseja excluir?\n");
      for(int i=0;i<=counTab;i++){
        printf("%d - %s\n",i,tabelas[i].nomeTabela);
      }
      scanf("%d",&qualtab);
      excluirTab(&tabelas[qualtab],&counTab);
      printf("Tabela %d excluida!\n",qualtab);
      qualtab=0;
        break;
    case 4:
    printf("Em qual tabela deseja inserir um registro?\n");
    for(int i=0;i<=counTab;i++){
        printf("%d - %s\n",i,tabelas[i].nomeTabela);
      }
      scanf("%d",&qualtab); //Maybe fazer uma função para "qualtab"?
      inserir(&tabelas[qualtab]);
      qualtab=0;
      break;
    case 5:
        void procurarRegistro(Tabela *tabelas);
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        printf("Numero invalido");
        break;
        }

    }


    // Liberar memória alocada dinamicamente
    for(int i=0;i<counTab;i++){
    free(tabelas[i].colunas);
    free(tabelas[i].dados);}

    return 0;
}

