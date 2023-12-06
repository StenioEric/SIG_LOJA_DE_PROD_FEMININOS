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
            case '4':   excluirVenda();
                        break;
            case '5':   finalizarVenda();
                        break;
            case '6':   listarVendas();
                        break;
        }
    } while (op != '0');
}


char tela_menu_vendas(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||            MENU DE VENDAS             ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  1. VER CATALOGO                      ||\n");
    printf("||  2. ADICIONAR PRODUTO AO CARRINHO     ||\n");
    printf("||  3. VER CARRINHO                      ||\n");
    printf("||  4. EXCLUIR PRODUTO                   ||\n");
    printf("||  5. FINALIZAR COMPRA                  ||\n");
    printf("||  0. VOLTAR AO MENU PRINCIPAL          ||\n");
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


Vendas* adicionarProdutos(void) {
    Vendas* vendas;
    vendas = (Vendas*)malloc(sizeof(Vendas));
    char* cpf;
    char* quant;
    char* prod;

    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("    ADICIONAR PRODUTOS AO CARRINHO     \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n"); 

    // Lógica para capturar o CPF do cliente
    cpf = lerCPF();
    strcpy(vendas->cpf, cpf);

    // Gera um ID de Compra unico
    char* idCompra = gera_idCompra();
    snprintf(vendas->idCompra, sizeof(vendas->idCompra), "%s", idCompra);

    int adicionarMais = 0; 
    do {
        
        prod = lerIdProd();
        strcpy(vendas->id, prod);
        quant = lerQuantidade(vendas);
        strcpy(vendas->quantidade, quant);
        
        printf("\n");
        printf("DESEJA ADICIONAR MAIS PRODUTOS? (1 PARA VOLTAR, 0 PARA SIM): ");
        scanf("%d", &adicionarMais);
        limparBuffer(); 

    } while(!adicionarMais);

    vendas->status = 2;
    gravaProduto(vendas);
    listarProdutosPorCompra(vendas->idCompra);
    espacamento();
}


void tela_ver_carrinho(void) {
    char idCompra[15];
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("              VER CARRINHO             \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n"); 
    int encontraVenda = 1;
    do {
        printf(" ->  ID DA COMPRA: ");
        scanf("%[0-9]", idCompra);
        limparBuffer();

        encontraVenda = buscaIdCompra(idCompra);

    if (encontraVenda) {
        system("clear||cls");
        listarProdutosPorCompra(idCompra);

    } else {
        printf("\n");
        printf("\n\t\tNENHUMA VENDA FOI ENCONTRADA COM ESSE ID\n\n");
        printf("\n");
    }
    } while (!ehDigitos(idCompra));
    espacamento();
}  


Vendas* finalizarVenda(void) {
    char idCompra[15];
    Vendas* vend = (Vendas*)malloc(sizeof(Vendas)); 
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            FINALIZAR COMPRA           \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n"); 
    int encontraVenda = 1;
    do {
        printf(" ->  ID DA COMPRA: ");
        scanf("%14s", idCompra);
        limparBuffer();

        encontraVenda = buscaIdCompra(idCompra);

        if (encontraVenda) {
            system("clear||cls");
            listarProdutosPorCompra(idCompra);
        
            vend->status = 3; 
            gravaProduto(vend);

        } else {
            printf("\n");
            printf("\n\t\tNENHUMA VENDA FOI ENCONTRADA COM ESSE ID\n\n");
            printf("\n");
        }

    } while (!ehDigitos(idCompra));

    espacamento();
    return NULL;
}




void excluirVenda(void) {

    FILE* fp = fopen("vendas.dat", "r+b");
    if (fp == NULL) {
        telaErro();
        return;
    }

    Vendas* vend = (Vendas*)malloc(sizeof(Vendas));
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("           EXCLUIR CARRINHO            \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n"); 

    int achouId = 1;
    printf(" -> ID DA COMPRA: ");
    scanf("%s", vend->idCompra);
    limparBuffer();

    achouId = buscaIdCompra(vend->idCompra);

    if (achouId) {
        while (fread(vend, sizeof(Vendas), 1, fp) == 1) {
            if (strcmp(vend->idCompra, vend->idCompra) == 0) {
                achouId = 1;
                vend->status = 0;
                fseek(fp, -1 * sizeof(Vendas), SEEK_CUR);
                fwrite(vend, sizeof(Vendas), 1, fp);
                printf("\n");
                printf("\n\t\tVENDA EXCLUIDA COM SUCESSO\n\n");
                printf("\n");
                getchar();
                break;
            }
        }

    }else{
        printf("\n\t\tNENHUMA VENDA FOI ENCONTRADA COM ESSE ID\n\n");
        espacamento();
    }
        
    fclose(fp); // Fecha o arquivo
    free(vend);
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
Vendas* buscaVenda(char* idCompra) {
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
            return vend; // Retorna o Vendas encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(vend); // Libera a memória alocada para o produto
    return NULL; // Retorna NULL se o produto não foi encontrado
}


double calcularTotal(const char* idCompra) {
    double total = 0.0;
    Vendas vend;
    Estoque est;

    FILE* fpVendas = fopen("vendas.dat", "rb");
    FILE* fpEstoque = fopen("estoque.dat", "rb");

    if (fpVendas == NULL || fpEstoque == NULL) {
        return -1; 
    }

    while (fread(&vend, sizeof(Vendas), 1, fpVendas)) {
        if (strcmp(vend.idCompra, idCompra) == 0) {
            rewind(fpEstoque);
            while (fread(&est, sizeof(Estoque), 1, fpEstoque)) {
                if (strcmp(est.id, vend.id) == 0) {
                    total += atof(est.valor) * atoi(vend.quantidade);
                    // Não retorne aqui para calcular o total de todos os produtos
                }
            }
        }
    }

    fclose(fpEstoque);
    fclose(fpVendas);
    return total; // Retornar o total após percorrer todos os produtos
}


void listarProdutosPorCompra(const char* idCompra) {
    FILE* fpVendas = fopen("vendas.dat", "rb");
    FILE* fpEstoque = fopen("estoque.dat", "rb");

    if (fpVendas == NULL || fpEstoque == NULL) {
        return;
    }

    float totalCompra = calcularTotal(idCompra);

    Vendas vend;
    Estoque est;
    system("clear||cls");
    printf("\nVALOR TOTAL DA COMPRA %s: R$ %.2f\n", idCompra, totalCompra);
    printf("======================================================================================\n");

    while (fread(&vend, sizeof(Vendas), 1, fpVendas)) {
        if (strcmp(vend.idCompra, idCompra) == 0 && vend.status != 0) {
            while (fread(&est, sizeof(Estoque), 1, fpEstoque)) {
                if (strcmp(est.id, vend.id) == 0) {
                    printf("| ID CLIENTE: %s | PRODUTO: %s | QUANTIDADE: %s | VALOR: %s | STATUS: %d\n",
                       vend.cpf, est.produto, vend.quantidade, est.valor, vend.status);
                       break;
                }
            }
            rewind(fpEstoque); // Retorna ao início do arquivo para a próxima busca
        }
    }

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
        if (strcmp(vend->idCompra, idCompra) == 0 && vend->status != 0) {
            fclose(fp); // Fecha o arquivo
            return 1; // Retorna o Vendas encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(vend); // Libera a memória alocada para o produto
    return 0; // Retorna NULL se o produto não foi encontrado
}


void listarVendas(void) {

    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("Vendas.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(vend); // Libera a memória alocada para o Vendas
        exit(1); // Encerra o programa
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         LISTAGEM DOS VendasS         \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
    while (fread(vend, sizeof(Vendas), 1, fp) == 1)  {
        printVendas(vend); 
    }
    fclose(fp);
    free(vend); 
    espacamento();
}


void printVendas(Vendas* vend) {
    printf("\n");
    printf(" ______________________________________________________ \n");
    printf("|                  REGISTRO DE VENDAS                  |\n");
    printf("|______________________________________________________|\n");
    printf("| CPF:-------------%-20s\n", vend->cpf);    
    printf("| ID PRODUTO:------%-20s\n", vend->id);
    printf("| QUANTIDADE:------%-20s\n", vend->quantidade);
    printf("| ID COMPRA:-------%-20s\n", vend->idCompra);
    printf("| VALOR TOTAL:-----%-20s\n", vend->valorCompra);
    printf("|======================================================|\n");
}

char* lerCPF(void) {
    char* cpf = (char*)malloc(12 * sizeof(char)); 
    if (cpf == NULL) {
        telaErro();
        return NULL;
    }

    int cpfDuplicado = 1;
    do {
        printf(" -> CPF: ");
        scanf("%11s", cpf);
        limparBuffer();
        cpfDuplicado = verificaCPFDuplicado(cpf);

        if (!validarCPF(cpf) || !cpfDuplicado) {
            cpfValido();
        }
    } while (!validarCPF(cpf) || !cpfDuplicado);

    return cpf;
}


char* lerIdProd(void) {
    char* id = (char*)malloc(10 * sizeof(char)); 
    if (id == NULL) {
        telaErro();
        return NULL;
    }
    int idDuplicado = 1;
    
    do {
        printf(" -> ID DO PRODUTO: ");
        scanf("%[0-9]", id);
        limparBuffer();
        idDuplicado = verificaIdDuplicado(id);

        if (!ehDigitos(id) || !idDuplicado) {
            idValido();
        }
    } while (!ehDigitos(id) || !idDuplicado);

    return id;
}


char* lerQuantidade(Vendas* vendas) {
    int quantidade = 0;
    char* qtde;
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

    qtde = (char *)malloc(strlen(vendas->quantidade) + 1);
    strcpy(qtde, vendas->quantidade);

    return qtde;
}

