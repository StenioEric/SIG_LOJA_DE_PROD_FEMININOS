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
#include "../modules/cliente.h"
#include "../modules/vendas.h"
#include "../modules/estoque.h"
#include "../modules/gerencia.h"
#include "../modules/projeto.h"
#include "../modules/util.h"

////
// Assinatura das funcoes
char tela_menu_principal(void);

////
// Programa principal

int main(void) {
    char op;
    do {
        op = tela_menu_principal();
        switch (op) {
            case '1':   moduloCliente();
                        break;
            case '2':   moduloVendas();
                        break;
            case '3':   moduloEstoque();
                        break;
            case '4':   moduloGerencia();
                        break;
            case '5':   moduloSobre();
                        break;
                    
        }

    } while (op !='0');

    return 0;
}

///////////
// Funcoes

char tela_menu_principal(void) {
    char op[2];

    system("clear||cls");
    printf("\n");
    // printf("=============================================================================\n");
    // printf("|                                                                           |\n");
    // printf("|    ███████╗██╗     ███████╗ ██████╗  █████╗ ███╗   ██╗ ██████╗███████╗    |\n");
    // printf("|    ██╔════╝██║     ██╔════╝██╔════╝ ██╔══██╗████╗  ██║██╔════╝██╔════╝    |\n");
    // printf("|    █████╗  ██║     █████╗  ██║  ███╗███████║██╔██╗ ██║██║     █████╗      |\n");
    // printf("|    ██╔══╝  ██║     ██╔══╝  ██║   ██║██╔══██║██║╚██╗██║██║     ██╔══╝      |\n");
    // printf("|    ███████╗███████╗███████╗╚██████╔╝██║  ██║██║ ╚████║╚██████╗███████╗    |\n");
    // printf("|    ╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝    |\n");
    // printf("|                                                                           |\n");
    // printf("|                       LOJA DE ARTIGOS FEMININOS                           |\n");
    // printf("|                                                                           |\n");
    printf("=============================================================================\n");
    printf("|                                                                           |\n");
    printf("|           ------------ SISTEMA DE GERENCIAMENTO ------------              |\n");
    printf("|                                                                           |\n");
    printf("|            1. MENU CLIENTES                                               |\n");
    printf("|            2. MENU VENDAS                                                 |\n");
    printf("|            3. MENU ESTOQUE                                                |\n");
    printf("|            4. MENU GERENCIA                                               |\n");
    printf("|            5. INFORMACOES SOBRE O PROJETO|DESENVOLVEDOR                   |\n");
    printf("|            0. SAIR                                                        |\n");
    printf("|                                                                           |\n");
    printf("|            ESCOLHA A OPCAO DESEJADA: ");
    fgets(op, sizeof(op), stdin);
    printf("|                                                                           |\n");
    printf("=============================================================================\n");
    espacamento();
    return op[0];
}
