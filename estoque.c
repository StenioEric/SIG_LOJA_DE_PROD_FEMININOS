///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "estoque.h"
#include "util.h"

typedef struct estoque Estoque;

void moduloEstoque(void) {
    char op;
    // Estoque* exemplo;

    do { 
        op = tela_menu_estoque();
        switch (op) {
            case '1':   tela_cadastro_produto();
                        break;
            case '2':   tela_pesquisar_produto();
                        break;
            case '3':   tela_alterar_produto();
                        break;
            case '4':   tela_remover_produto();
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


void tela_cadastro_produto(void) {
    // Estoque* est;
    // est = (Estoque*)malloc(sizeof(Estoque));
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
    printf("///            PRODUTO:                                                     ///\n");
    printf("///            QUANTIDADE DE PRODUTOS:                                      ///\n");
    printf("///            VALOR DO PRODUTO:                                            ///\n");
    printf("///            DESCRICAO DO PRODUTO:                                        ///\n");
    printf("///            ID:                                                          ///\n");
    // valEstoque(est);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    // return est;
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

    // idEstoque(est);
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
    // idEstoque(est);
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
    // idEstoque(est);
}

///////////////////////////////////////////////////////////////////////////////
/// Validador de nome, cpf , email , telefone e data de nascimento.
///
// void valEstoque (Estoque *est ) {

//     do {
//         printf("/// PRODUTO:");
//         scanf("%s", est -> produto);
//         limparBuffer();
//     } while(!validarNome(est -> produto));

//     do {
//         printf("/// QUANTIDADE DE PRODUTOS:");
//         scanf("%c", est -> quantidade);
//         limparBuffer();
//     } while(!ehDigito(est -> quantidade));

//     do {
//         printf("/// VALOR:");
//         scanf("%c",est -> valor);
//         limparBuffer();
//     } while(!ehDigito(est -> valor));

//     do {
//         printf("/// DESCRICAO:");
//         scanf("%s",est -> descricao);
//         limparBuffer();
//     } while(!validarNome(est -> descricao));

//     do {
//         printf("/// ID:");
//         scanf("%c",est -> id);
//         limparBuffer();
//     } while(!ehDigito(est -> id));

// }

// void idEstoque( const Estoque* est) {
//     char* id;
//     id = (char*)malloc(sizeof(char));

//     do {
//         printf("///     ID:");
//         scanf("%s", id);
//         limparBuffer();    
//     } while(!ehDigito(id));

//     if (ehDigito(id) == 1) {
//         printEstoque(id);
//     } else {
//         printf("\n");
//         printf("///     USUARIO NAO ENCONTRADO");
//         printf("\n");
//         printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//         limparBuffer();
//     }
// }

// void printEstoque( const Estoque* est)
// {
//     system("clear||cls");
//     printf("\n");
//     printf("///////////////////////////////////////////////////////////////////////////////\n");
//     printf("///                                                                         ///\n");
//     printf("///        EEEEEEE lll                                                      ///\n");
//     printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
//     printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
//     printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
//     printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
//     printf("///                             ggggg                                       ///\n");
//     printf("///                                                                         ///\n");
//     printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
//     printf("///                                                                         ///\n");
//     printf("///////////////////////////////////////////////////////////////////////////////\n");
//     printf("///                                                                         ///\n");
//     printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
//     printf("///                          PRINT DADOS PRODUTO                            ///\n");
//     printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
//     printf("///                                                                         ///\n");
//     printf("///            PRODUTO:%s\n", est-> produto);
//     printf("///            QUANTIDADE:%s\n", est-> quantidade);                                                         
//     printf("///            VALOR:%s\n", est-> valor);                                                      
//     printf("///            DESCRICAO:%s\n", est-> descricao);                                          
//     printf("///            ID: %s\n", est-> id);                    
//     printf("///                                                                         ///\n");
//     printf("///                                                                         ///\n");
//     printf("///                                                                         ///\n");
//     printf("///////////////////////////////////////////////////////////////////////////////\n");
//     getchar();
// }
