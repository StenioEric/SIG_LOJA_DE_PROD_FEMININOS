///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cliente.c"
#include "vendas.c"
#include "estoque.c"
#include "funcionario.c"
#include "gerencia.c"
#include "projeto.c"

////
// Assinatura das funcoes
int tela_menu_principal(void);


////
// Programa principal
int main(void) {
    int op;

    do {
        op = tela_menu_principal();
        switch (op) {

                case 1: moduloCliente();
                        break;
                case 2: moduloVendas();
                    break;
                case 3: moduloEstoque();
                    break;
                case 4: moduloFuncio();
                        break;
                case 5: moduloGerencia();
                        break;
                case 6: moduloSobre();
                        break;
        
        }

    } while (op != 0);
}

/////
// Funcoes

int tela_menu_principal(void)
{
    int op;
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
    printf("///           ------------ SISTEMA DE GERENCIAMENTO ------------            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. MENU CLIENTES                                             ///\n");
    printf("///            2. MENU VENDAS                                               ///\n");
    printf("///            3. MENU ESTOQUE                                              ///\n");
    printf("///            4. MENU FUNCIONARIOS                                         ///\n");
    printf("///            5. MENU GERENCIA                                             ///\n");
    printf("///            6. INFORMACOES SOBRE O PROJETO/DESENVOLVEDOR                 ///\n");
    printf("///            0. SAIR                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPCAO DESEJADA: ");
    scanf("%d", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}






