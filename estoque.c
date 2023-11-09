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
            case '5':   listagemEstoque();
                        break;
        }

    } while (op != '0');
}


char tela_menu_estoque(void) {
    char op;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///             ------------  MENU ESTOQUE ------------                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR PRODUTO                                         ///\n");
    printf("///            2. PESQUISAR DADOS DO PRODUTO                                ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO PRODUTO                             ///\n");
    printf("///            4. EXCLUIR DADOS DO PRODUTO                                  ///\n");
    printf("///            5. LISTAR PRODUTOS                                           ///\n");
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


Estoque* tela_cadastro_estoque(void) {
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
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
    printf("///             ------------ CADASTRO DE PRODUTO ------------               ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("/// PRODUTO:");
        scanf("%s", est->produto);
        limparBuffer();
    } while(!validarNome(est->produto));
    do {
        printf("/// QUANTIDADE DE PRODUTOS:");
        scanf("%s", est->quantidade);
        limparBuffer();
    } while(!ehDigitos(est->quantidade));
    do {
        printf("/// VALOR:");
        scanf("%s",est->valor);
        limparBuffer();
    } while(!ehDigitos(est->valor));
    do {
        printf("/// DESCRICAO:");
        scanf("%s",est->descricao);
        limparBuffer();
    } while(!validarNome(est->descricao));

    int idDuplicado = 0;
    int idValido = 0;
    do {
        printf("/// ID DO PRODUTO: ");
        scanf("%s", est->id);
        limparBuffer();

        idDuplicado = verificaIdDuplicado(est->id);

        if (idDuplicado) {
            printf("\n");
            printf("\t\t\tID JA EXISTE. TENTE NOVAMENTE.\n");
            printf("\n");
        } else if (ehDigitos(est->id)) {
            idValido= 1;
        }
        else {
            printf("\n");
            printf("\t\t\tID INVALIDO. TENTE NOVAMENTE.\n");
            printf("\n");
        }
    } while (!idValido || idDuplicado);

    est -> status = 1;
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return est;
}

Estoque* tela_pesquisar_estoque(void) {
    FILE* fp;
    char opc[15];
    Estoque* est;
    est = (Estoque*)malloc(sizeof(Estoque));
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
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         PESQUISAR PRODUTO                               ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///ID: ");
        scanf("%[0-9]",opc);
        limparBuffer();
    } while(!ehDigitos(opc));
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        telaErro();
        free(est);
        exit(1);
    }
    int prodEncontrado = 0;
    system("clear||cls");
    while (fread(est, sizeof(Estoque), 1, fp)) {
        if ((est->status != 0) && (strcmp(est->id,opc)==0)) {
            printEstoque(est);
            prodEncontrado = 1;
        }
    }
    if (!prodEncontrado){
        printf("\n");
        printf("\t\t\t PRODUTO NAO REGISTRADO\n");
        limparBuffer();
        return NULL;
    }

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return NULL;
}

char* tela_alterar_estoque(void) {
    char* id;
	id = (char*) malloc(15*sizeof(char));
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
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         ALTERAR PRODUTO                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///ID: ");
    scanf("%[0-9]", id);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return id;
}

char* tela_exclui_estoque(void) {
    char* id;
	id = (char*) malloc(15*sizeof(char));
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
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         EXCLUIR PRODUTO                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///ID: ");
    scanf("%[0-9]", id);
    printf("\n");
    return id;
}

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
    printf("\n = = = DADOS DO PRODUTO = = = \n");
    printf("PRODUTO:%s\n", est-> produto);
    printf("QUANTIDADE:%s\n", est-> quantidade);                                                         
    printf("VALOR:%s\n", est-> valor);                                                      
    printf("DESCRICAO:%s\n", est-> descricao);                                          
    printf("ID: %s\n", est-> id);
    printf("===================================\n"); 
}

void listarEstoque(void) {
    FILE* fp;
    Estoque est;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          PRINT DADOS ESTOQUE          \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                       \n");
    fp = fopen("estoque.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    while (fread(&est, sizeof(Estoque), 1, fp)) {
        if (est.status != 'x') {
            printEstoque(&est);
        }
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fclose(fp);
    free(fp);
}


// // Verifica se um id já está cadastrado
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
        printf("\t\t\tESTOQUE NAO ENCONTRADO!\n\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
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
        printf("\t\t\tESTOQUE NAO ENCONTRADO OU JA REMOVIDO!\n");
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
        printf("\t\t\tESTOQUE NAO ENCONTRADO!\n\n");
        limparBuffer();
    } else {
        est->status = 0;
        removeEstoque(est);
        free(est);
        est = NULL; // Define est como NULL após remoção
        printf("\n");
        printf("\t\t\tESTOQUE EXCLUIDO COM SUCESSO!\n");
        limparBuffer();
    }

    free(id);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
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
        printf("\t\t\tEstoque NAO ENCONTRADO!\n");
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
        printf("\t\t\tNENHUM PRODUTO ATIVO ENCONTRADO.\n"); // Mensagem se nenhum estente ativo for encontrado
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}


