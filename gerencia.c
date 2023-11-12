///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gerencia.h"
#include "util.h"


void moduloGerencia(void) { 
    char op;

    do {
        op = tela_menu_gerencia();
        switch (op) {
            case '1':   tela_relatorio_cliente();
                        break;
            case '2':   tela_relatorio_vendas();
                        break;
            case '3':   tela_relatorio_estoque();
                        break;
            case '4':   tela_relatorio_funcionarios();
                        break;

        }

    } while (op != '0');
}


char tela_menu_gerencia(void) {
    char op;

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
    printf("///           ------------ MENU GERENCIA ------------                       ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. RELATORIO DE CLIENTES                                     ///\n");
    printf("///            2. RELATORIO DE VENDAS                                       ///\n");
    printf("///            3. RELATORIO DE ESTOQUE                                      ///\n");
    printf("///            4. RELATORIO DE FUNCIONARIOS                                 ///\n");
    printf("///            0. SAIR                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPCAO DESEJADA: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    espacamento();   
    return op;
}


void tela_relatorio_cliente(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///             EEEEEEE lll                                                           ///\n");
    printf("///             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee               ///\n");
    printf("///             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e              ///\n");
    printf("///             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee               ///\n");
    printf("///             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee              ///\n");
    printf("///                                  ggggg                                            ///\n");
    printf("///                                                                                   ///\n");
    printf("///                             LOJA DE ARTIGOS FEMININOS                             ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                 RELATORIO CLIENTE                                 ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                                                                   ///\n");
    printf("///###################################################################################///\n");
    printf("///#Nome do Cliente|CPF|E-mail|Data de Nascimento|Celular|Endereco|Compras realizadas#///\n");                              ///\n");
    printf("///#               |   |      |                  |       |        |                  #///\n");
    printf("///#               |   |      |                  |       |        |                  #///\n");    
    printf("///#               |   |      |                  |       |        |                  #///\n");    
    printf("///#               |   |      |                  |       |        |                  #///\n");    
    printf("///###################################################################################///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    espacamento();
}


void tela_relatorio_vendas(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///             EEEEEEE lll                                                           ///\n");
    printf("///             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee               ///\n");
    printf("///             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e              ///\n");
    printf("///             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee               ///\n");
    printf("///             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee              ///\n");
    printf("///                                  ggggg                                            ///\n");
    printf("///                                                                                   ///\n");
    printf("///                             LOJA DE ARTIGOS FEMININOS                             ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                  RELATORIO VENDAS                                 ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                                                                   ///\n");
    printf("///###################################################################################///\n");
    printf("///#           |Produto|Quantidade de Vendas|ID do Produto|Valor Arrecadado|         #///\n");                                                   
    printf("///#           |       |                    |             |                |         #///\n");
    printf("///#           |       |                    |             |                |         #///\n");    
    printf("///#           |       |                    |             |                |         #///\n");    
    printf("///#           |       |                    |             |                |         #///\n");    
    printf("///###################################################################################///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    espacamento();
}

void tela_relatorio_estoque(void) {

    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///             EEEEEEE lll                                                           ///\n");
    printf("///             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee               ///\n");
    printf("///             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e              ///\n");
    printf("///             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee               ///\n");
    printf("///             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee              ///\n");
    printf("///                                  ggggg                                            ///\n");
    printf("///                                                                                   ///\n");
    printf("///                             LOJA DE ARTIGOS FEMININOS                             ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                 RELATORIO ESTOQUE                                 ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                                                                   ///\n");
    printf("///###################################################################################///\n");
    printf("///#           |Produto|Quantidade em Estoque|ID do Produto|Valor do Produto|        #///\n");                        
    printf("///#           |       |                     |             |                |        #///\n");
    printf("///#           |       |                     |             |                |        #///\n");    
    printf("///#           |       |                     |             |                |        #///\n");    
    printf("///#           |       |                     |             |                |        #///\n");    
    printf("///###################################################################################///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    espacamento();
}


void tela_relatorio_funcionarios(void) {
    
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///             EEEEEEE lll                                                           ///\n");
    printf("///             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee               ///\n");
    printf("///             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e              ///\n");
    printf("///             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee               ///\n");
    printf("///             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee              ///\n");
    printf("///                                  ggggg                                            ///\n");
    printf("///                                                                                   ///\n");
    printf("///                             LOJA DE ARTIGOS FEMININOS                             ///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                                   ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                              RELATORIO FUNCIONARIOS                               ///\n");
    printf("///                      -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                      ///\n");
    printf("///                                                                                   ///\n");
    printf("///###################################################################################///\n");
    printf("///#    |Nome|CPF|Cargo|Data de Nascimento|Email|Telefone|Vendas Realizadas|Salario| #///\n");                    
    printf("///#    |    |   |     |                  |     |        |                 |       | #///\n");
    printf("///#    |    |   |     |                  |     |        |                 |       | #///\n");    
    printf("///#    |    |   |     |                  |     |        |                 |       | #///\n");    
    printf("///#    |    |   |     |                  |     |        |                 |       | #///\n");    
    printf("///###################################################################################///\n");
    printf("///                                                                                   ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
    espacamento();
}
