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
#include "vendas.h"

void moduloGerencia(void) { 
    char op;

    do {

        op = tela_menu_gerencia();
        switch (op) {
            case '1':   
                do{

                    op = telaCli();
                    switch (op) {
                        case '1':   listarTodosCli();
                                    break;
                        case '2':   listarCliAtivos();
                                    break;
                        case '3':   listarCliInativos();
                                    break;
                        case '4':   list_alfa_cli();
                                    break;
                    }
                }while (op != '0');
                break; 

            case '2':
                do{
                    
                    op = telaEst();
                    switch (op) {
                        case '1':   listarTodosProd();
                                    break;
                        case '2':   listarProdAtivos();
                                    break;
                        case '3':   listarProdInativos();
                                    break;
                        case '4':   list_alfa_est();
                                    break;
                    }
                }while (op != '0');
                break; 

            case '3':
                do{
                    
                    op = telaVend();
                    switch (op) {
                        case '1':   listarVendasFinal();
                                    break;
                        case '2':   listarVendasAbert();
                                    break;
                        case '3':   list_Vend_Cli();
                                    break;
                        case '4':   list_idCompra();
                                    break;
                        // case '5':   list_alfa_vendas();
                        //             break;
                        
                    }
                }while (op != '0');
                break; 

        }

    } while (op != '0');
}


char tela_menu_gerencia(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||             MENU GERENCIA             ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  1. RELATORIO DE CLIENTES             ||\n");
    printf("||  2. RELATORIO DO ESTOQUE              ||\n");
    printf("||  3. RELATORIO DAS VENDAS              ||\n");
    printf("||  0. SAIR                              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  ESCOLHA A OPCAO DESEJADA: ");
    scanf(" %c", &op);
    limparBuffer();
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("\n");
    return op;
}



////////////////////////////////////////////////////////////////
///////////////// FUNCOES UTILIZADAS NO CODIGO /////////////////
////////////////////////////////////////////////////////////////


///////////////////////
// Modulo Clientes

char telaCli(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||               RELATORIOS              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  1. TODOS OS CLIENTES                 ||\n");
    printf("||  2. CLIENTES ATIVOS                   ||\n");
    printf("||  3. CLIENTES INATIVOS                 ||\n");
    printf("||  4. LISTAGEM EM ORDEM ALFABETICA      ||\n");
    printf("||  0. SAIR                              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  ESCOLHA A OPCAO DESEJADA: ");
    scanf(" %c", &op);
    limparBuffer();
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("\n");
    return op;
}


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
    printf("\n");
    printf(" _____________________________________________________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                                                             |\n");
    printf("|                                                                    REGISTRO DE CLIENTES                                                                     |\n");
    printf("|                                                                                                                                                             |\n");
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
    printf("\n");
    printf(" _____________________________________________________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                                                             |\n");
    printf("|                                                                    REGISTRO DE CLIENTES                                                                     |\n");
    printf("|                                                                                                                                                             |\n");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status == 1) {
            printCliente(cli); 
            clienteEncontrado = 1; // Marca que um cliente foi encontrado
        }
    }
    fclose(fp);
    free(cli); 
    if (!clienteEncontrado) {
        printf(" -> NENHUM CLIENTE ATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
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
    printf("\n");
    printf(" _____________________________________________________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                                                             |\n");
    printf("|                                                                    REGISTRO DE CLIENTES                                                                     |\n");
    printf("|                                                                                                                                                             |\n");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status == 0) {
            printCliente(cli); 
            clienteEncontrado = 1; // Marca que um cliente foi encontrado
        }
    }
    fclose(fp);
    free(cli); 
    if (!clienteEncontrado) {
        printf(" -> NENHUM CLIENTE INATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    espacamento();
}


void list_alfa_cli(void) {
    FILE* file;
    Cliente* novocli;
    Cliente* lista;

    file = fopen("clientes.dat", "rb");
    if (file == NULL) {
        telaErro();
        exit(1);
    }

    system("clear||cls");
    printf("\n");
    printf(" _____________________________________________________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                                                             |\n");
    printf("|                                                                    REGISTRO DE CLIENTES                                                                     |\n");
    printf("|                                                                                                                                                             |\n");

    lista = NULL;
    novocli = (Cliente*)malloc(sizeof(Cliente));

    if (novocli == NULL) {
        telaErro();
        exit(1);
    }

    while (fread(novocli, sizeof(Cliente), 1, file) == 1) {
        novocli->prox = NULL;

        if ((lista == NULL) || (strcmp(novocli->nome, lista->nome) < 0)) {
            novocli->prox = lista;
            lista = novocli;
        } else {
            Cliente* ant = lista;
            Cliente* atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, novocli->nome) < 0) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novocli;
            novocli->prox = atual;
        }

        novocli = (Cliente*)malloc(sizeof(Cliente));
        if (novocli == NULL) {
            telaErro();
            exit(1);
        }
    }

    fclose(file);

    novocli = lista;
    while (novocli != NULL) {
        printCliente(novocli);
        novocli = novocli->prox;
    }

    novocli = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novocli);
        novocli = lista;
    }

    espacamento();
}


///////////////////////
// Modulo Estoque

char telaEst(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||               RELATORIOS              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  1. TODOS OS PRODUTOS                 ||\n");
    printf("||  2. PRODUTOS ATIVOS                   ||\n");
    printf("||  3. PRODUTOS INATIVOS                 ||\n");
    printf("||  4. LISTAGEM EM ORDEM ALFABETICA      ||\n");
    printf("||  0. SAIR                              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  ESCOLHA A OPCAO DESEJADA: ");
    scanf(" %c", &op);
    limparBuffer();
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("\n");
    return op;
}


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
    printf("\n");
    printf(" ___________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                   |\n");
    printf("|                                                REGISTRO DE ESTOQUE                                                |\n");
    printf("|                                                                                                                   |\n");
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
    printf("\n");
    printf(" ___________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                   |\n");
    printf("|                                                REGISTRO DE ESTOQUE                                                |\n");
    printf("|                                                                                                                   |\n");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if (est->status == 1) {
            printEstoque(est);            
            EstoqueEncontrado = 1; // Marca que um Estoque foi encontrado
        }
    }
    fclose(fp);
    free(est); 
    if (!EstoqueEncontrado) {
        printf(" -> NENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    espacamento();
}


void listarProdInativos(void) {

    FILE* fp;
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "rb");                                  
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(est); // Libera a memória alocada para est
        exit(1); // Encerra o programa
    }

    int EstoqueEncontrado = 0; // Variável para rastrear se algum Estoquenario foi encontrado

    system("clear||cls");
    printf("\n");
    printf(" ___________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                   |\n");
    printf("|                                                REGISTRO DE ESTOQUE                                                |\n");
    printf("|                                                                                                                   |\n");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if (est->status == 0) {
            printEstoque(est);            
            EstoqueEncontrado = 1; // Marca que um produto foi encontrado
        }
    }
    fclose(fp);
    free(est); 
    if (!EstoqueEncontrado) {
        printf(" -> NENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum produto ativo for encontrado
    }
    espacamento();
}


void list_alfa_est(void) {
    FILE* file;
    Estoque* novoEstoque;
    Estoque* lista;

    file = fopen("estoque.dat", "rb");
    if (file == NULL) {
        telaErro();
        exit(1);
    }

    system("clear||cls");
    printf("\n");
    printf(" ___________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                   |\n");
    printf("|                                                REGISTRO DE ESTOQUE                                                |\n");
    printf("|                                                                                                                   |\n");
    lista = NULL;
    novoEstoque = (Estoque*)malloc(sizeof(Estoque));

    if (novoEstoque == NULL) {
        telaErro();
        exit(1);
    }

    while (fread(novoEstoque, sizeof(Estoque), 1, file) == 1) {
        novoEstoque->prox = NULL;

        if ((lista == NULL) || (strcmp(novoEstoque->produto, lista->produto) < 0)) {
            novoEstoque->prox = lista;
            lista = novoEstoque;
        } else {
            Estoque* ant = lista;
            Estoque* atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->produto, novoEstoque->produto) < 0) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novoEstoque;
            novoEstoque->prox = atual;
        }

        novoEstoque = (Estoque*)malloc(sizeof(Estoque));
        if (novoEstoque == NULL) {
            telaErro();
            exit(1);
        }
    }

    fclose(file);

    novoEstoque = lista;
    while (novoEstoque != NULL) {
        printEstoque(novoEstoque);
        novoEstoque = novoEstoque->prox;
    }

    novoEstoque = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novoEstoque);
        novoEstoque = lista;
    }

    espacamento();
}


///////////////////////
// Modulo Vendas

char telaVend(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||               RELATORIOS              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  1. VENDAS FINALIZADAS                ||\n");
    printf("||  2. VENDAS EM PROCESSO                ||\n");    
    printf("||  3. VENDAS POR CLIENTE                ||\n");
    printf("||  4. VENDAS POR ID DE COMPRA           ||\n");
    printf("||  0. SAIR                              ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  ESCOLHA A OPCAO DESEJADA: ");
    scanf(" %c", &op);
    limparBuffer();
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("\n");
    return op;
}


void listarVendasFinal(void) {

    FILE* fp;
    Vendas* vend = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("Vendas.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(vend); // Libera a memória alocada para o Vendas
        exit(1); // Encerra o programa
    }
    int achou = 0;
    system("clear||cls");
    printf("\n");
    printf(" ___________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                   |\n");
    printf("|                                                REGISTRO DE VENDAS                                                 |\n");
    printf("|                                                                                                                   |\n");
    while (fread(vend, sizeof(Vendas), 1, fp) == 1)  {
            if (vend->status == 3) {
                achou = 1;
                printVendas(vend);
            }
    }
    fclose(fp);
    free(vend); 
    if (!achou) {
        printf(" -> NENHUMA VENDA ENCONTRADA.\n"); // Mensagem se nenhum produto ativo for encontrado
    }
    espacamento();
}


void listarVendasAbert(void) {

    FILE* fp;
    Vendas* vend = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("Vendas.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(vend); // Libera a memória alocada para o Vendas
        exit(1); // Encerra o programa
    }
    int achou = 0;
    system("clear||cls");
    printf("\n");
    printf(" ___________________________________________________________________________________________________________________\n");
    printf("|                                                                                                                   |\n");
    printf("|                                                REGISTRO DE VENDAS                                                 |\n");
    printf("|                                                                                                                   |\n");
    while (fread(vend, sizeof(Vendas), 1, fp) == 1)  {
            if (vend->status == 2) {
                achou = 1;
                printVendas(vend);
            }
    }
    fclose(fp);
    free(vend); 
    if (!achou) {
        printf(" -> NENHUMA VENDA ENCONTRADA.\n"); // Mensagem se nenhum produto ativo for encontrado
    }
    espacamento();
}


void list_Vend_Cli(void) {

    FILE* fp;
    Vendas* vend = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("Vendas.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(vend); // Libera a memória alocada para o Vendas
        exit(1); // Encerra o programa
    }

    // Lógica para capturar o CPF do cliente
    char* cpf = lerCPF();

    if (cpf == NULL) {
        return;

    }else{
        
        system("clear||cls");
        printf("\n");
        printf(" ___________________________________________________________________________________________________________________\n");
        printf("|                                                                                                                   |\n");
        printf("|                                                REGISTRO DE VENDAS                                                 |\n");
        printf("|                                                                                                                   |\n");
            while (fread(vend, sizeof(Vendas), 1, fp) == 1)  {
            if (strcmp(vend->cpf, cpf) == 0 && vend->status == 3) {
                printVendas(vend);
            }
        }
    }
    
    fclose(fp);
    free(vend); 
    espacamento();
}


// void list_alfa_vendas(void) {
//     FILE* file;
//     Vendas* novaVenda;
//     Vendas* lista;

//     file = fopen("vendas.dat", "rb");
//     if (file == NULL) {
//         telaErro();
//         exit(1);
//     }

//     system("clear||cls");
//     printf("\n");
//     printf(" ___________________________________________________________________________________________________________________\n");
//     printf("|                                                                                                                   |\n");
//     printf("|                                                        REGISTRO DE VENDAS                                          |\n");
//     printf("|                                                                                                                   |\n");

//     lista = NULL;
//     novaVenda = (Vendas*)malloc(sizeof(Vendas));

//     if (novaVenda == NULL) {
//         telaErro();
//         exit(1);
//     }

//     while (fread(novaVenda, sizeof(Vendas), 1, file) == 1) {
//         novaVenda->prox = NULL;

//         if ((lista == NULL) || (strcmp(novaVenda->id, lista->id) < 0)) {
//             novaVenda->prox = lista;
//             lista = novaVenda;
//         } else {
//             Vendas* ant = lista;
//             Vendas* atual = lista->prox;
//             while ((atual != NULL) && strcmp(atual->id, novaVenda->id) < 0) {
//                 ant = atual;
//                 atual = atual->prox;
//             }
//             ant->prox = novaVenda;
//             novaVenda->prox = atual;
//         }

//         novaVenda = (Vendas*)malloc(sizeof(Vendas));
//         if (novaVenda == NULL) {
//             telaErro();
//             exit(1);
//         }
//     }

//     fclose(file);

//     novaVenda = lista;
//     while (novaVenda != NULL) {
//         printVendas(novaVenda);
//         novaVenda = novaVenda->prox;
//     }

//     novaVenda = lista;
//     while (lista != NULL) {
//         lista = lista->prox;
//         free(novaVenda);
//         novaVenda = lista;
//     }

//     espacamento();
// }


void list_idCompra(void) {
    char idCompra[15];
    int encontraVenda = 1;
    do {
        printf(" ->  ID DA COMPRA: ");
        scanf("%[0-9]", idCompra);
        limparBuffer();

        encontraVenda = verificaIdCompra(idCompra);

    if (encontraVenda) {
        listarProdutosPorCompra(idCompra);

    } else {
        idValido();
    }
    } while (!ehDigitos(idCompra));
    espacamento();
} 