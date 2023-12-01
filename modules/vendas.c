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
#include <time.h>
#include "vendas.h"
#include "util.h"
#include "cliente.h"
#include "estoque.h"
#include "gerencia.h"

typedef struct vendas Vendas;

void moduloVendas(void) {
    char op;

    do {
        op = tela_menu_vendas();
        switch (op) {
            case '1':   listarProdAtivos();
                        break;
            case '2':   adicionarProdutos();
                        break;
            case '3':   tela_ver_carrinho();
                        break;
            case '4':   excluirProduto();
                        break;
            case '5':   finalizarVenda();
                        break;
            case '6':   listagemVendas();
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
    Vendas* vendas;
    vendas = (Vendas*)malloc(sizeof(Vendas));

    // Gera um ID de Compra unico
    char* idCompra = gera_idCompra();
    snprintf(vendas->idCompra, sizeof(vendas->idCompra), "%s", idCompra);
    free(idCompra); // Liberar memoria alocada para o ID de Compra

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             ------------ ADICIONAR PRODUTOS ------------                ///\n");
    printf("///                                                                         ///\n");  

    // Lógica para capturar o CPF do cliente
    int cpfDuplicado = 0;
    do {
        printf(" -> CPF: ");
        scanf("%[0-9]", vendas->cpf);
        limparBuffer();
        cpfDuplicado = verificaCPFDuplicado(vendas->cpf);

        if (!validarCPF(vendas->cpf) || cpfDuplicado) {
            cpfValido();
        }
    } while (!validarCPF(vendas->cpf) || cpfDuplicado);

    int adicionarMais = 0; 
    do {
        do {
            printf(" -> ID DO PRODUTO: ");
            scanf("%[0-9]", vendas->id);
            limparBuffer();
            if (!ehDigitos(vendas->id)) {
                idValido();
            }
        } while (!ehDigitos(vendas->id));

        int quantidade = 0;
        do {
            printf(" -> QUANTIDADE DE PRODUTOS: ");
            scanf("%s", vendas->quantidade);
            limparBuffer();

            quantidade = verificaQuantidade(vendas->quantidade, vendas->id);

            if (!quantidade) {
                printf("\n");
                printf("\t\tNAO EXISTE ESSA QUANTIDADE EM ESTOQUE. TENTE NOVAMENTE.\n");
                printf("\n");
            } else {
                quantidade = 1; 
            }
        } while (!quantidade || vendas->quantidade == 0);

        printf("\n");
        printf("DESEJA ADICIONAR MAIS PRODUTOS? (1 PARA VOLTAR, 0 PARA SIM): ");
        scanf("%d", &adicionarMais);
        limparBuffer(); 

        vendas->status = 2;
        gravaProduto(vendas);
    } while (adicionarMais != 1);

    listarProdutosPorCompra(vendas->idCompra);
    espacamento();
    free(vendas); 
    return vendas; 
}


Vendas* tela_ver_carrinho(void) {
    char idCompra[15];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                        VER CARRINHO DE PRODUTOS                         ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                                                                         ///\n");
    int encontraVenda = 1;
    do {
        printf("/// ID DA COMPRA: ");
        scanf("%[0-9]", idCompra);
        limparBuffer();

        encontraVenda = buscaVenda(idCompra);

    if (encontraVenda) {
        system("clear||cls");
        listarProdutosPorCompra(idCompra);

    } else {
        printf("\n\t\tNENHUMA VENDA FOI ENCONTRADA COM ESSE ID\n\n");
    }
    } while (!ehDigitos(idCompra));
    espacamento();
}  


Vendas* finalizarVenda(void) {
    char idCompra[15];
    Vendas* vend = (Vendas*)malloc(sizeof(Vendas)); 
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                            FINALIZAR COMPRA                             ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                                                                         ///\n");
    int encontraVenda = 1;
    do {
        printf("/// ID DA COMPRA: ");
        scanf("%[0-9]", idCompra);
        limparBuffer();

        encontraVenda = buscaVenda(idCompra);

    if (encontraVenda) {
        system("clear||cls");
        listarProdutosPorCompra(idCompra);
        vend->status = 3; 
        gravaProduto(vend);

    } else {
        printf("\n\t\tNENHUMA VENDA FOI ENCONTRADA COM ESSE ID\n\n");
    }
    } while (!ehDigitos(idCompra));
    espacamento();
    return NULL;
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
            do {
                printf("/// ID DA COMPRA: ");
                scanf("%s", vend->idCompra);
                limparBuffer();
                
                verificaId = buscaVenda(vend->idCompra);

                if (!ehDigitos(vend->idCompra) || !verificaId) {
                    idErro();
                }
            } while (!ehDigitos(vend->idCompra) || !verificaId);


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


////////////////////////////////////////////////////////////////
///////////////// FUNCOES UTILIZADAS NO CODIGO /////////////////
////////////////////////////////////////////////////////////////


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


// void gravaVendas(Vendas* venda) {
//     FILE* fp = fopen("idCompra.dat", "ab");
//     if (fp == NULL || venda == NULL) {
//         printf("ERRO AO ABRIR O ARQUIVO IDCOMPRA.\n");
//         return;
//     }
//     fwrite(venda, sizeof(Vendas), 1, fp);
//     fclose(fp);
// }


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
        if (strcmp(vend->idCompra, idCompra) == 0 && vend->status == 2) {
            fclose(fp); // Fecha o arquivo
            return 1; // Retorna o Vendas encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(vend); // Libera a memória alocada para o produto
    return 0; // Retorna NULL se o produto não foi encontrado
}


float calcularTotalCompra(const char* idCompra) {
    FILE* fpEstoque = fopen("estoque.dat", "rb");
    FILE* fpVendas = fopen("vendas.dat", "rb");
    float total = 0.0;

    if (fpEstoque == NULL || fpVendas == NULL) {
        return total;
    }

    Estoque est; 
    Vendas vend;

    while (fread(&vend, sizeof(Vendas), 1, fpVendas)) {
        if (strcmp(vend.idCompra, idCompra) == 0) {
            // Procura o produto no arquivo de estoque
            rewind(fpEstoque);
            while (fread(&est, sizeof(Estoque), 1, fpEstoque)) {
                if (strcmp(est.id, vend.id) == 0) {
                    total += atof(est.valor) * atoi(vend.quantidade); // Calcula o valor total do produto
                    return total;
                    break;
                }
            }
        }
    }
    fclose(fpEstoque);
    fclose(fpVendas);
    return total;
}


void listarProdutosPorCompra(const char* idCompra) {
    FILE* fpVendas = fopen("vendas.dat", "rb");
    FILE* fpEstoque = fopen("estoque.dat", "rb");

    if (fpVendas == NULL || fpEstoque == NULL) {
        return;
    }

    float totalCompra = calcularTotalCompra(idCompra);

    Vendas vend;
    Estoque est;
    system("clear||cls");
    printf("\nVALOR TOTAL DA COMPRA %s: R$ %.2f\n", idCompra, totalCompra);
    printf("==============================================================\n");

    while (fread(&vend, sizeof(Vendas), 1, fpVendas)) {
        if (strcmp(vend.idCompra, idCompra) == 0) {
            while (fread(&est, sizeof(Estoque), 1, fpEstoque)) {
                if (strcmp(est.id, vend.id) == 0) {
                    printf("Produto: %s | Quantidade: %s | Valor: %s\n", est.produto, vend.quantidade, est.valor);
                    break; 
                }
            }
            rewind(fpEstoque); // Retorna ao início do arquivo para a próxima busca
        }
    }

    fclose(fpVendas);
    fclose(fpEstoque);
}


void listagemVendas(void) {
    FILE* fp;
    Vendas* venda;
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("idCompra.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(venda); // Libera a memória alocada para o produto
        exit(1); // Encerra o programa
    }

    int VendasEncontrado = 0; // Variável para rastrear se algum produto foi encontrado

    system("clear||cls");
    while (fread(venda, sizeof(Vendas), 1, fp)) {
        if (venda->status == 3) {
            printVendas(venda); 
            VendasEncontrado = 1; // Marca que um produto foi encontrado
        }
    }
    fclose(fp);
    free(venda); 
    if (!VendasEncontrado) {
        printf("\t\t\tNENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum estente ativo for encontrado
    }
    espacamento();
}


void printVendas(Vendas* venda) {
    FILE* fpVendas = fopen("vendas.dat", "rb");
    FILE* fpEstoque = fopen("estoque.dat", "rb");

    if (fpVendas == NULL || fpEstoque == NULL) {
        printf("ERRO AO ABRIR UM DOS ARQUIVOS.\n");
        return;
    }

    Estoque* estoque = (Estoque*)malloc(sizeof(Estoque));

    printf("\nDETALHES DAS VENDAS:\n");
    printf("=============================================================================\n");

    while (fread(venda, sizeof(Vendas), 1, fpVendas)) {
        while (fread(estoque, sizeof(Estoque), 1, fpEstoque)) {
            if (strcmp(estoque->id, venda->id) == 0) {
                printf("ID da Compra: %s | Produto: %s | Quantidade: %s | Valor: %s | Status: %d\n",
                       venda->idCompra, estoque->produto, venda->quantidade, estoque->valor, venda->status);
                break; // Encerra o loop interno após encontrar o produto correspondente
            }
        }
        rewind(fpEstoque); // Retorna ao início do arquivo para a próxima busca
    }

    free(venda);
    free(estoque);
    fclose(fpVendas);
    fclose(fpEstoque);
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


// // Verifica se um id já está cadastrado
int verificaIdCompra(const char* idCompra) {
    FILE* fp = fopen("vendas.dat", "rb");

    Vendas vend;
    while (fread(&vend, sizeof(Vendas), 1, fp)) {
        if (vend.status == 3 && strcmp(vend.idCompra, idCompra) == 0) {
            fclose(fp);
            return 1; // id duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // id não duplicado
}


// void mostrarDetalhesCompra(const char* idCompra) {

//     if (totalCompra > 0) {
//         listarProdutosPorCompra(idCompra);
//     } else {
//         printf("\nCOMPRA COM ID %s NAO ENCONTRADA.\n", idCompra);
//     }
// }


// int verStatusVend(const char* idCompra) {
//     FILE* fp = fopen("vendas.dat", "rb");
// 
//     if (fp == NULL) {
//         return 0;
//     }
//     Vendas vend;
//     int encontrou = 0;
//     while (fread(&vend, sizeof(Vendas), 1, fp)) {
//         if ((strcmp(vend.idCompra, idCompra) == 0) && (vend.status == 3 || vend.status == 2)) {
//             encontrou = 1; // ID de compra encontrado com status 3 ou 2
//             break;
//         }
//     }
//     fclose(fp); 
//     return encontrou; 
// }


char* gera_idCompra(void)
{
    FILE *fp;
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        return "1"; // Caso o arquivo não exista, retorna 1 como o primeiro ID de compra
    }

    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) {
        fclose(fp);
        return "1"; // Se o arquivo estiver vazio, retorna 1 como o primeiro ID de compra
    }
    else {
        fseek(fp, -((long)sizeof(Vendas)), SEEK_END);
        Vendas vend;
        fread(&vend, sizeof(Vendas), 1, fp);
        int id_int = atoi(vend.idCompra);
        int id_soma = id_int + 1;
        char *id = (char *)malloc(sizeof(char) * 20); // Aloca memória para o ID de compra
        snprintf(id, 20, "%d", id_soma); // Converte o novo valor do ID para uma string
        fclose(fp);
        return id;
    }
}


int buscaIdCompra(char* idCompra) {
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
        if (strcmp(vend->idCompra, idCompra) == 0) {
            fclose(fp); // Fecha o arquivo
            return 1; // Retorna o Vendas encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(vend); // Libera a memória alocada para o produto
    return 0; // Retorna NULL se o produto não foi encontrado
}
