///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vendas.h"
#include "util.h"
#include "cliente.h"
#include "funcionario.h"
#include "estoque.h"

typedef struct vendas Vendas;

void moduloVendas(void) {
    char op;

    do {
        op = tela_menu_vendas();
        switch (op) {
            case '1':   listarEstoque();
                        break;
            case '2':   adicionarProdutos();
                        break;
            // // case '3':   tela_ver_carrinho();
            //             break;
            case '4':   tela_excluir_produto();
                        break;
            case '5':   tela_finalizar_compra();
                        break;
        }
    } while (op != '0');
}


char tela_menu_vendas(void) {
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
    printf("///             ------------  MENU VENDAS ------------                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. VER CATALOGO                                              ///\n");
    printf("///            2. ADICIONAR PRODUTO AO CARRINHO                             ///\n");
    printf("///            3. VER CARRINHO                                              ///\n");
    printf("///            4. EXCLUIR PRODUTO                                           ///\n");
    printf("///            5. FINALIZAR COMPRA                                          ///\n");
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


Vendas* adicionarProdutos(void) {
    Vendas* vend;
    vend = (Vendas*)malloc(sizeof(Vendas));
    int adicionarMais = 1;
    do { 

        do {
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
            printf("///             ------------ ADICIONAR PRODUTOS ------------                ///\n");
            printf("///                                                                         ///\n");

            int idDuplicado = 0;
            int idValido = 0;
            do {
                printf("/// ID DO PRODUTO: ");
                scanf("%s", vend->id);
                limparBuffer();

                idDuplicado = verificaIdDuplicado(vend->id);

                if (!idDuplicado) {
                    printf("\n");
                    printf("\t\t\tID NAO EXISTE. TENTE NOVAMENTE.\n");
                    printf("\n");
                } else if (ehDigitos(vend->id)) {
                    idValido = 1;
                } else {
                    printf("\n");
                    printf("\t\t\tID INVALIDO. TENTE NOVAMENTE.\n");
                    printf("\n");
                }
            } while (!idValido && !idDuplicado);

            int quantidade = 0;
            do {
                printf("/// QUANTIDADE DE PRODUTOS: ");
                scanf("%s", vend->quantidade);
                limparBuffer();

                quantidade = verificaQuantidade(vend->quantidade, vend->id);

                if (!quantidade) {
                    printf("\n");
                    printf("\t\tNAO EXISTE ESSA QUANTIDADE EM ESTOQUE. TENTE NOVAMENTE.\n");
                    printf("\n");
                } else {
                    quantidade = 1; // Atribui 1 para indicar que a quantidade é válida
                }
            } while (!quantidade || vend->quantidade == 0);
            do {
                printf("/// ID DA COMPRA:");
                scanf("%s", vend->idCompra);
                limparBuffer();
            } while (!ehDigitos(vend->idCompra));

            vend->status = 1;
            gravaProduto(vend);
            free(vend);
        } while (!ehDigitos(vend->idCompra));

        printf("\n");
        printf("Deseja adicionar mais produtos? (1 para sim, 0 para encerrar): ");
        scanf("%d", &adicionarMais);
        limparBuffer(); // Limpar o buffer para a próxima entrada
    } while (adicionarMais);

    return vend;
}


// Vendas* tela_ver_carrinho(void) {
//     char idCompra[15];
//     Vendas* vend;
//     vend = (Vendas*)malloc(sizeof(Vendas));
//     system("clear||cls");
//     printf("\n");
//     printf("///////////////////////////////////////////////////////////////////////////////\n");
//     printf("///                                                                         ///\n");
//     printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
//     printf("///                        VER CARRINHO DE PRODUTOS                         ///\n");
//     printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
//     printf("///                                                                         ///\n");
//     do {
//         printf("/// ID DA COMPRA: ");
//         scanf("%[0-9]", idCompra);
//         limparBuffer();
//     } while (!ehDigitos(idCompra));
//     recuperarProdutosPorCompra(idCompra);
//     printf("\n");
//     printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
//     getchar();

//     return vend;
// }



void tela_excluir_produto(void) {

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
    printf("///             ------------ EXCLUIR PRODUTOS ------------                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID DO PRODUTO:                                               ///\n");
    printf("///            QUANTIDADE:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_finalizar_compra(void) {
    
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
    printf("///             ------------ FINALIZAR COMPRA ------------                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            PRODUTOS:                                                    ///\n");
    printf("///            QUANTIDADE DE PRODUTOS:                                      ///\n");
    printf("///            VALOR TOTAL:                                                 ///\n");
    printf("///            FORMA DE PAGAMENTO:                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


int verificaQuantidade(const char* quantidade, const char* id) {
    FILE* fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        // Lidar com a falha na abertura do arquivo, se necessário
        return 0;
    }

    Estoque est;
    int quantidadeProduto = atoi(quantidade);
    while (fread(&est, sizeof(Estoque), 1, fp)) {
        if (strcmp(est.id, id) == 0) {
            // Encontrou o produto pelo ID no arquivo
            if (quantidadeProduto <= atoi(est.quantidade)) {
                fclose(fp);
                return 1; // Quantidade suficiente
            } else {
                fclose(fp);
                return 0; // Quantidade insuficiente
            }
        }
    }
    fclose(fp);
    return 0; // Produto não encontrado
}


void gravaProduto(Vendas* vend) {
    FILE* fp;
    fp = fopen("vendas.dat", "ab");
    if (fp == NULL) {
        telaErro();
        exit(1);
    }
    fwrite(vend, sizeof(Vendas), 1, fp);
    fclose(fp);
}



// void recuperarProdutosPorCompra(const char* idCompra) {
//     FILE* fp;
//     Vendas vend;
//     system("clear||cls");

//     // Abre o arquivo de vendas para leitura binária
//     fp = fopen("vendas.dat", "rb");
//     if (fp == NULL) {
//         printf("Erro ao abrir o arquivo de vendas.\n");
//         return;
//     }

//     // Percorre o arquivo de vendas em busca da compra com o ID fornecido
//     while (fread(&vend, sizeof(Vendas), 1, fp)) {
//         if (strcmp(vend.idCompra, idCompra) == 0 && vend.status == 1) {
//             // Encontrou a compra pelo ID no arquivo

//             // Agora, você pode usar o ID do produto na venda para buscar informações no arquivo de estoque
//             // Certifique-se de implementar uma função semelhante para buscar produtos por ID no estoque

//             // Exemplo de como buscar informações no arquivo de estoque
//             Estoque* produto = buscaEstoque(vend.id);

//             // Se o produto for encontrado, você pode imprimir suas informações
//             if (produto != NULL) {
//                 printEstoque(produto);
//                 free(produto);  // Lembre-se de liberar a memória alocada pela função buscarProdutoPorId
//             }
//         }
//     }

//     fclose(fp);  // Fecha o arquivo de vendas
// }

