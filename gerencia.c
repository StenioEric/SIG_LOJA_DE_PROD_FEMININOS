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
#include "gerencia.h"
#include "util.h"
#include "cliente.h"
#include "estoque.h"
#include "funcionario.h"

void moduloGerencia(void) { 
    char op;

    do {
        op = tela_menu_gerencia();
        switch (op) {
            case '1':   listarTodosCli();
                        break;
            case '2':   listarCliAtivos();
                        break;
            case '3':   listarCliInativos();
                        break;
            case '4':   listarTodosFun();
                        break;
            case '5':   listarFunInativos();
                        break;
            case '6':   listarFunInativos();
                        break;
            case '7':   listarTodosProd();
                        break;
            case '8':   listarProdAtivos();
                        break;
            case '9':   listarProdInativos();
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
    printf("///            1. RELATORIO DE TODOS OS CLIENTES                            ///\n");
    printf("///            2. RELATORIO DE CLIENTES ATIVOS                              ///\n");
    printf("///            3. RELATORIO DE CLIENTES INATIVOS                            ///\n");
    printf("///            4. RELATORIO DE TODOS OS FUNCIONARIOS                        ///\n");
    printf("///            5. RELATORIO DE FUNCIONARIOS ATIVOS                          ///\n");
    printf("///            6. RELATORIO DE FUNCIONARIOS INATIVOS                        ///\n");
    printf("///            7. RELATORIO DE TODOS OS PRODUTOS                            ///\n");
    printf("///            8. RELATORIO DOS PRODUTOS ATIVOS                             ///\n");
    printf("///            9. RELATORIO DOS PRODUTOS INATIVOS                           ///\n");
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


///////////////////////
// Modulo Clientes


void listarTodosCli(void) {

    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(cli); // Libera a memória alocada para o cliente
        exit(1); // Encerra o programa
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         LISTAGEM DOS CLIENTES         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
    while (fread(cli, sizeof(Cliente), 1, fp) == 1)  {
        printCliente(cli); 
    }
    fclose(fp);
    free(cli); 
    espacamento();
}


void listarCliAtivos(void) {
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(cli); // Libera a memória alocada para o cliente
        exit(1); // Encerra o programa
    }

    int clienteEncontrado = 0; // Variável para rastrear se algum cliente foi encontrado

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         LISTAGEM DOS CLIENTES         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status == 1) {
            printCliente(cli); 
            clienteEncontrado = 1; // Marca que um cliente foi encontrado
        }
    }
    fclose(fp);
    free(cli); 
    if (!clienteEncontrado) {
        printf("\nNENHUM CLIENTE ATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    espacamento();
}


void listarCliInativos(void) {
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(cli); // Libera a memória alocada para o cliente
        exit(1); // Encerra o programa
    }

    int clienteEncontrado = 0; // Variável para rastrear se algum cliente foi encontrado
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         LISTAGEM DOS CLIENTES         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status == 0) {
            printCliente(cli); 
            clienteEncontrado = 1; // Marca que um cliente foi encontrado
        }
    }
    fclose(fp);
    free(cli); 
    if (!clienteEncontrado) {
        printf("\nNENHUM CLIENTE INATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    espacamento();
}



///////////////////////
// Modulo Funcionarios

void listarTodosFun(void) {

    FILE* fp;
    Funcio* fun;
    fun = (Funcio*) malloc(sizeof(Funcio));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(fun); // Libera a memória alocada para o Funcio
        exit(1); // Encerra o programa
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("       LISTAGEM DOS FUNCIONARIOS       \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(fun, sizeof(Funcio), 1, fp) == 1)  {
        printFuncionarios(fun);    }
    fclose(fp);
    free(fun); 
    espacamento();
}


void listarFunAtivos(void) {
    FILE* fp;
    Funcio* fun;
    fun = (Funcio*) malloc(sizeof(Funcio));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(fun); // Libera a memória alocada para o Funcio
        exit(1); // Encerra o programa
    }

    int funcioEncontrado = 0; // Variável para rastrear se algum Funcio foi encontrado

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("       LISTAGEM DOS FUNCIONARIOS       \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(fun, sizeof(Funcio), 1, fp)) {
        if (fun->status == 1) {
            printFuncionarios(fun);            
            funcioEncontrado = 1; // Marca que um Funcio foi encontrado
        }
    }
    fclose(fp);
    free(fun); 
    if (!funcioEncontrado) {
        printf("\nNENHUM FUNCIONARIO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    espacamento();
}


void listarFunInativos(void) {

    FILE* fp;
    Funcio* fun;
    fun = (Funcio*) malloc(sizeof(Funcio));
    fp = fopen("Funcios.dat", "rb");                                  
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(fun); // Libera a memória alocada para fun
        exit(1); // Encerra o programa
    }

    int funcioEncontrado = 0; // Variável para rastrear se algum funcionario foi encontrado

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("       LISTAGEM DOS FUNCIONARIOS       \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(fun, sizeof(Funcio), 1, fp)) {
        if (fun->status == 0) {
            printFuncionarios(fun);            
            funcioEncontrado = 1; // Marca que um funcionario foi encontrado
        }
    }
    fclose(fp);
    free(fun); 
    if (!funcioEncontrado) {
        printf("\nNENHUM FUNCIONARIO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum funcionario ativo for encontrado
    }
    espacamento();
}



///////////////////////
// Modulo Funcionarios

void listarTodosProd(void) {

    FILE* fp;
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(est); // Libera a memória alocada para o Estoque
        exit(1); // Encerra o programa
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("       LISTAGEM DOS PRODUTOS      \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(est, sizeof(Estoque), 1, fp) == 1)  {
        printEstoque(est);    }
    fclose(fp);
    free(est); 
    espacamento();
}


void listarProdAtivos(void) {
    FILE* fp;
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(est); // Libera a memória alocada para o Estoque
        exit(1); // Encerra o programa
    }

    int EstoqueEncontrado = 0; // Variável para rastrear se algum Estoque foi encontrado

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         LISTAGEM DOS PRODUTOS         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if (est->status == 1) {
            printEstoque(est);            
            EstoqueEncontrado = 1; // Marca que um Estoque foi encontrado
        }
    }
    fclose(fp);
    free(est); 
    if (!EstoqueEncontrado) {
        printf("\nNENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    espacamento();
}


void listarProdInativos(void) {

    FILE* fp;
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));
    fp = fopen("Estoques.dat", "rb");                                  
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(est); // Libera a memória alocada para est
        exit(1); // Encerra o programa
    }

    int EstoqueEncontrado = 0; // Variável para rastrear se algum Estoquenario foi encontrado

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         LISTAGEM DOS PRODUTOS         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if (est->status == 0) {
            printEstoque(est);            
            EstoqueEncontrado = 1; // Marca que um produto foi encontrado
        }
    }
    fclose(fp);
    free(est); 
    if (!EstoqueEncontrado) {
        printf("\nNENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum produto ativo for encontrado
    }
    espacamento();
}
