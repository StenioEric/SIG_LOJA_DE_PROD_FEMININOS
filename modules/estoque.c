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
#include "estoque.h"
#include "util.h"


typedef struct estoque Estoque;

void moduloEstoque(void) {
    char op;
    do { 
        op = tela_menu_estoque();
        switch (op) {
            case '1':   cadEstoque();
                        break;
            case '2':   tela_pesquisar_estoque();
                        break;
            case '3':   atualizaEstoque();
                        break;
            case '4':   excluirEstoque();
                        break;
        }

    } while (op != '0');
}


char tela_menu_estoque(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||       BEM-VINDO A LOJA ELEGANCE       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||           MENU DE ESTOQUE             ||\n");
    printf("||                                       ||\n");
    printf("||  1. CADASTRAR PRODUTO                 ||\n");
    printf("||  2. PESQUISAR DADOS DO PRODUTO        ||\n");
    printf("||  3. ATUALIZAR DADOS DO PRODUTO        ||\n");
    printf("||  4. EXCLUIR DADOS DO PRODUTO          ||\n");
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



Estoque* tela_cadastro_estoque(void) {
    Estoque* est = (Estoque*)malloc(sizeof(Estoque));
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            CADASTRO PRODUTO           \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");                                                               
    do {
        printf(" -> PRODUTO: ");
        scanf("%s", est->produto);
        limparBuffer();
    } while(!validarNome(est->produto));
    do {
        printf(" -> QUANTIDADE DE PRODUTOS: ");
        scanf("%s", est->quantidade);
        limparBuffer();
    } while(!ehDigitos(est->quantidade));
    do {
        printf(" -> VALOR: ");
        scanf("%s",est->valor);
        limparBuffer();
    } while(!ehdinheiro(est->valor));
    do {
        printf(" -> DESCRICAO: ");
        scanf("%s",est->descricao);
        limparBuffer();
    } while(!validarNome(est->descricao));

    // Gera um ID unico
    char* id = gera_idProd();
    snprintf(est->id, sizeof(est->id), "%s", id);
    printf(" -> ID: %s",est->id);

    est -> status = 1;
    espacamento();
    return est;
}

Estoque* tela_pesquisar_estoque(void) {
    FILE* fp;
    char id[15];
    Estoque* est = (Estoque*)malloc(sizeof(Estoque));
    if (est == NULL) {
        printf("ERRO DE ALOCACAO DE MEMORIA.");
        exit(1);
    }
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("           PESQUISAR PRODUTO           \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do {
        printf(" -> ID DO PRODUTO: ");
        scanf("%[0-9]", id);
        limparBuffer();
    if (!ehDigitos(id)) {
        idValido();
    }
    } while (!ehDigitos(id));

    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        telaErro();
        free(est);
        exit(1);
    }
    int prodEncontrado = 0;
    system("clear||cls");
    printf("|-------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                  DADOS DO PRODUTO                                                 |\n");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if ((est->status != 0) && (strcmp(est->id,id)==0)) {
            printEstoque(est);
            prodEncontrado = 1;
        }
    }
    fclose(fp);

    if (!prodEncontrado){
        printf("\n");
        printf(" -> PRODUTO NAO REGISTRADO\n");
        espacamento();
        free(est);
        return NULL;
    }

    espacamento();
    return est;
}

char* tela_alterar_estoque(void) {
    char* id;
	id = (char*) malloc(15*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("             ALTERAR PRODUTO           \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do {
        printf(" -> ID DO PRODUTO: ");
        scanf("%[0-9]", id);
        limparBuffer();
    if (!ehDigitos(id)) {
        idValido();
    }
    } while (!ehDigitos(id));
    printf("\n");
    return id;
}

char* tela_exclui_estoque(void) {
    char* id;
	id = (char*) malloc(15*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("             EXCLUIR VENDA             \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do {
        printf(" -> ID DO PRODUTO: ");
        scanf("%[0-9]", id);
        limparBuffer();
    if (!ehDigitos(id)) {
        idValido();
    }
    } while (!ehDigitos(id));
    printf("\n");
    return id;
}



////////////////////////////////////////////////////////////////
///////////////// FUNCOES UTILIZADAS NO CODIGO /////////////////
////////////////////////////////////////////////////////////////


void gravaEstoque(Estoque* est) {
    FILE* fp;
    fp = fopen("estoque.dat", "ab");
    if (fp == NULL) {
        telaErro();
        exit(1);
    }
    fwrite(est, sizeof(Estoque), 1, fp);
    fclose(fp);
}


void printEstoque(Estoque* est) {
    printf("|-------------------------------------------------------------------------------------------------------------------|\n");
    printf("| PRODUTO: %-10s | EM ESTOQUE: %-10s | VALOR: %-10s | DESCRICAO: %-15s | ID: %-10s    |\n",
           est->produto, est->quantidade, est->valor, est->descricao, est->id);
    printf("|___________________________________________________________________________________________________________________|\n");
}



// // Verifica se um id 
int verificaIdDuplicado(const char* id) {
    FILE* fp = fopen("estoque.dat", "rb");

    Estoque est;
    while (fread(&est, sizeof(Estoque), 1, fp)) {
        if (est.status != 0 && strcmp(est.id, id) == 0) {
            fclose(fp);
            return 1; // id duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // id não duplicado
}


// Cadastra um novo estente
void cadEstoque(void) {
    Estoque *est;
    est = tela_cadastro_estoque();
    gravaEstoque(est);
    free(est);
}


// // Atualiza um Estoque
void atualizaEstoque(void) {
    Estoque* est;
    char* id;

    // Obtém o id do Estoque a ser atualizado
    id = tela_alterar_estoque();
    est = buscaEstoque(id);

    if (est == NULL) {
        system("clear||cls");
        printf("\n");
        printf(" ->ESTOQUE NAO ENCONTRADO!\n\n");
        espacamento();
    } else {
        removeEstoque(est);
        est = tela_cadastro_estoque();
        strcpy(est->id, id);
        regravarEstoque(est);
        free(est);
    }

    free(id);
}


// Remove um Estoque
void removeEstoque(Estoque* est) {
    FILE* fp;
    Estoque* est_Lido;
    est_Lido = (Estoque*)malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "r+b");

    if (fp == NULL) {
        telaErro();
    }

    int achou = 0;

    // Busca o Estoque pelo id no arquivo
    while (fread(est_Lido, sizeof(Estoque), 1, fp) && !achou) {
        if (strcmp(est_Lido->id, est->id) == 0 && est_Lido->status) {
            achou = 1;
            fseek(fp, -1 * sizeof(Estoque), SEEK_CUR);
            est_Lido->status = 0; // Marca o Estoque como inativo
            fwrite(est_Lido, sizeof(Estoque), 1, fp);
        }
    }

    fclose(fp); // Fecha o arquivo
    free(est_Lido); // Libera a memória alocada para o Estoque lido do arquivo

    if (!achou) {
        printf("\n");
        printf(" ->ESTOQUE NAO ENCONTRADO OU JA REMOVIDO!\n");
    }
}


// // // Exclui um Estoque
void excluirEstoque(void) {
    Estoque *est;
    char *id;

    // Obtém o id do Estoque a ser excluído
    id = tela_exclui_estoque();
    est = buscaEstoque(id);

    if (est == NULL) {
        printf("\n");
        printf(" ->ESTOQUE NAO ENCONTRADO!\n\n");
    } else {
        est->status = 0;
        regravarEstoque(est);
        free(est);
        est = NULL; // Define est como NULL após remoção
        printf("\n");
        printf(" ->ESTOQUE EXCLUIDO COM SUCESSO!\n");
    }

    free(id);
    espacamento();
}


// // Reescreve os dados de um Estoque no arquivo
void regravarEstoque(Estoque* est) {
    FILE* fp;
    Estoque* est_Lido;

    est_Lido = (Estoque*)malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "r+b");

    if (fp == NULL) {
        telaErro();
    }

    int achou = 0;

    // Busca o Estoque pelo id no arquivo
    while(!feof(fp)) {
        fread(est_Lido, sizeof(Estoque), 1, fp);
        if (strcmp(est_Lido->id, est->id) == 0) {
            achou = 1;
            fseek(fp, -1 * sizeof(Estoque), SEEK_CUR);
            fwrite(est, sizeof(Estoque), 1, fp);
            break;
        }
    }

    fclose(fp); // Fecha o arquivo
    free(est_Lido); // Libera a memória alocada para o produto lido do arquivo

    if (!achou) {
        printf("\n");
        printf(" ->ESTOQUE NAO ENCONTRADO!\n");
    }
}


// // Busca um produto pelo id
Estoque* buscaEstoque(char* id) {
    // Abre o arquivo "estoque.dat" para leitura binária
    FILE* fp;
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "rb");

    // Verifica se houve erro ao abrir o arquivo
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
    }

    // Percorre o arquivo em busca do produto com o id fornecido
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if (strcmp(est->id, id) == 0 && est->status == 1) {
            fclose(fp); // Fecha o arquivo
            return est; // Retorna o Estoque encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(est); // Libera a memória alocada para o produto
    return NULL; // Retorna NULL se o produto não foi encontrado
}


void listagemEstoque(void) {
    FILE* fp;
    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(est); // Libera a memória alocada para o produto
        exit(1); // Encerra o programa
    }

    int EstoqueEncontrado = 0; // Variável para rastrear se algum produto foi encontrado

    system("clear||cls");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if (est->status == 1) {
            printEstoque(est); 
            EstoqueEncontrado = 1; // Marca que um produto foi encontrado
        }
    }
    fclose(fp);
    free(est); 
    if (!EstoqueEncontrado) {
        printf(" ->NENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum estente ativo for encontrado
    }
    espacamento();
}


char* gera_idProd(void)
{
    FILE *fp;
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        return "1"; // Caso o arquivo não exista, retorna 1 como o primeiro ID
    }

    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0) {
        fclose(fp);
        return "1"; // Se o arquivo estiver vazio, retorna 1 como o primeiro ID
    }
    else {
        fseek(fp, -((long)sizeof(Estoque)), SEEK_END);
        Estoque est;
        fread(&est, sizeof(Estoque), 1, fp);
        int id_int = atoi(est.id);
        int id_soma = id_int + 1;
        char *id = (char *)malloc(sizeof(char) * 20); // Aloca memória para o ID
        snprintf(id, 20, "%d", id_soma); // Converte o novo valor do ID para uma string
        fclose(fp);
        return id;
    }
}