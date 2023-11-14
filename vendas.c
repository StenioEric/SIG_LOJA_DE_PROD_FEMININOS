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
            case '3':   tela_ver_carrinho();
                        break;
            case '4':   excluirProduto();
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

        } while (!ehDigitos(vend->idCompra));

        printf("\n");
        printf("Deseja adicionar mais produtos? (1 para sim, 0 para encerrar): ");
        scanf("%d", &adicionarMais);
        limparBuffer(); // Limpar o buffer para a próxima entrada
    } while (adicionarMais);
    
    free(vend);
    return vend;
}


Vendas* tela_ver_carrinho(void) {
    char idCompra[15];
    Vendas* vend;
    vend = (Vendas*)malloc(sizeof(Vendas));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                        VER CARRINHO DE PRODUTOS                         ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("/// ID DA COMPRA: ");
        scanf("%[0-9]", idCompra);
        limparBuffer();
    } while (!ehDigitos(idCompra));
    recuperarProdutosPorCompra(idCompra);
    espacamento();
    return vend;
}


Vendas* excluirProduto(void) {
    Vendas* vend;
    vend = (Vendas*)malloc(sizeof(Vendas));
    int excluirMais = 1;
    do { 
        do {
            system("clear||cls");
            printf("\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("///                                                                         ///\n");
            printf("///               ------------ EXCLUIR PRODUTOS ------------                ///\n");
            printf("///                                                                         ///\n");
            int verificaId = 0;
            int achaId = 0;   
            do {
                printf("/// ID DA COMPRA:");
                scanf("%s", vend->idCompra);
                limparBuffer();
                
                verificaId = buscaVenda(vend->idCompra);

                if (!verificaId) {
                    printf("\n");
                    printf("\t\t\tID NAO EXISTE. TENTE NOVAMENTE.\n");
                    printf("\n");
                } else if (ehDigitos(vend->idCompra)) {
                    achaId = 1;
                } else {
                    printf("\n");
                    printf("\t\t\tID INVALIDO. TENTE NOVAMENTE.\n");
                    printf("\n");
                }
            } while (!achaId && !verificaId);

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

            vend->status = 1;
            removeVenda(vend);

        } while (!ehDigitos(vend->idCompra));

        printf("\n");
        printf("EXCLUIR MAIS ALGUM PRODUTO DO CARRINHO? (1 PARA SIM, 0 PARA VOLTAR AO MENU): ");
        scanf("%d", &excluirMais);
        limparBuffer(); // Limpar o buffer para a próxima entrada
    } while (excluirMais);
    
    free(vend);
    return vend;
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



void recuperarProdutosPorCompra(const char* idCompra) {
    FILE* fp;
    Vendas vend;
    system("clear||cls");

    // Abre o arquivo de vendas para leitura binária
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    // Percorre o arquivo de vendas em busca da compra com o ID fornecido
    while (fread(&vend, sizeof(Vendas), 1, fp)) {
        if (strcmp(vend.idCompra, idCompra) == 0 && vend.status == 1) {
            Estoque* produto = buscaEstoque(vend.id);
            if (produto != NULL) {
                printEstoque(produto);
                free(produto);  // Lembre-se de liberar a memória alocada pela função buscarProdutoPorId
            }
        }
    }
    fclose(fp);  // Fecha o arquivo de vendas
}


// Remove um Estoque
void removeVenda(Vendas* vend) {
    FILE* fp;
    Vendas* vend_Lido;
    vend_Lido = (Vendas*)malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "r+b");

    if (fp == NULL) {
        telaErro();
    }

    int achou = 0;

    // Busca o Vendas pelo id no arquivo
    while (fread(vend_Lido, sizeof(Vendas), 1, fp) && !achou) {
        if (strcmp(vend_Lido->id, vend->id) == 0 && vend_Lido->status) {
            achou = 1;
            fseek(fp, -1 * sizeof(Vendas), SEEK_CUR);
            vend_Lido->status = 0; // Marca o Vendas como inativo
            fwrite(vend_Lido, sizeof(Vendas), 1, fp);
        }
    }

    fclose(fp); // Fecha o arquivo
    free(vend_Lido); // Libera a memória alocada para o Vendas lido do arquivo

    if (!achou) {
        printf("\n");
        printf("\t\t\tVENDAS NAO ENCONTRADO OU JA REMOVIDO!\n");
    }
}


// // Verifica se um id já está cadastrado
int verificaIdCompra(const char* idCompra) {
    FILE* fp = fopen("vendas.dat", "rb");

    Vendas vend;
    while (fread(&vend, sizeof(Vendas), 1, fp)) {
        if (vend.status != 0 && strcmp(vend.idCompra, idCompra) == 0) {
            fclose(fp);
            return 1; // id duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // id não duplicado
}

// // Busca um produto pelo id
int buscaVenda(char* idCompra) {
    // Abre o arquivo "Vendas.dat" para leitura binária
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*)malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");

    // Verifica se houve erro ao abrir o arquivo
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
    }

    // Percorre o arquivo em busca do produto com o id fornecido
    while (fread(vend, sizeof(Vendas), 1, fp)) {
        if (strcmp(vend->idCompra, idCompra) == 0 && vend->status == 1) {
            fclose(fp); // Fecha o arquivo
            return 1; // Retorna o Vendas encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(vend); // Libera a memória alocada para o produto
    return 0; // Retorna NULL se o produto não foi encontrado
}
