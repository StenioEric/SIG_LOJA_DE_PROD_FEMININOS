///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "estoque.h"
#include "util.h"

typedef struct estoque Estoque;

void moduloEstoque(void) {
    char op;
    Estoque* modelo;
    do { 
        op = tela_menu_estoque();
        switch (op) {
            case '1':   modelo = tela_cadastro_produto();
                        gravaEstoque(modelo);
                        break;
            case '2':   tela_pesquisar_produto();
                        break;
            case '3':   tela_alterar_produto();
                        break;
            case '4':   tela_remover_produto();
                        break;
            case '5':   listarEstoque();
                        break;
        }

    } while (op != '0');
}


char tela_menu_estoque(void) {
    char op;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             ------------  MENU ESTOQUE ------------                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR PRODUTO                                         ///\n");
    printf("///            2. PESQUISAR DADOS DO PRODUTO                                ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO PRODUTO                             ///\n");
    printf("///            4. EXCLUIR DADOS DO PRODUTO                                  ///\n");
    printf("///            0. VOLTAR AO MENU PRINCIPAL                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPCAO DESEJADA: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return op;
}


Estoque* tela_cadastro_produto(void) {
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             ------------ CADASTRO DE PRODUTO ------------               ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("/// PRODUTO:");
        scanf("%s", est->produto);
        limparBuffer();
    } while(!validarNome(est->produto));
    do {
        printf("/// QUANTIDADE DE PRODUTOS:");
        scanf("%s", est->quantidade);
        limparBuffer();
    } while(!ehDigitos(est->quantidade));
    do {
        printf("/// VALOR:");
        scanf("%s",est->valor);
        limparBuffer();
    } while(!ehDigitos(est->valor));
    do {
        printf("/// DESCRICAO:");
        scanf("%s",est->descricao);
        limparBuffer();
    } while(!validarNome(est->descricao));
    do {
        printf("/// ID:");
        scanf("%s",est->id);
        limparBuffer();
    } while(!ehDigitos(est->id));

    est -> status = 'A';
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return est;
}

void tela_pesquisar_produto(void) {

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         PESQUISAR PRODUTO                               ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_alterar_produto(void) {

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         ALTERAR PRODUTO                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_remover_produto(void) {

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         REMOVER PRODUTO                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void gravaEstoque(Estoque* est) {
    FILE* fp;
    fp = fopen("estoque.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    fwrite(est, sizeof(Estoque), 1, fp);
    fclose(fp);
}

void printEstoque(Estoque* est) {
    if ((est == NULL) || (est->status == 'x')) {
        printf("\n= = = Produto Inexistente = = =\n");
    } else {
        printf("PRODUTO:%s\n", est-> produto);
        printf("QUANTIDADE:%s\n", est-> quantidade);                                                         
        printf("VALOR:%s\n", est-> valor);                                                      
        printf("DESCRICAO:%s\n", est-> descricao);                                          
        printf("ID: %s\n", est-> id);
        printf("===================================\n");                  
    }
}


void listarEstoque(void) {
    FILE* fp;
    Estoque est;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          PRINT DADOS ESTOQUE          \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                       \n");
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    while (fread(&est, sizeof(Estoque), 1, fp)) {
        if (est.status != 'x') {
            printEstoque(&est);
        }
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fclose(fp);
    free(fp);
}




