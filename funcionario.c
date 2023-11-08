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
#include "funcionario.h"
#include "util.h"

typedef struct funcio Funcio;


void moduloFuncio(void) {
    char op;

    do {
        op = tela_menu_funcionarios();
        switch (op) {
            case '1':   cadFuncionario();
                        break;
            case '2':   tela_pesquisar_funcionarios();
                        break;
            case '3':   tela_alterar_funcionarios();
                        break;
            case '4':   tela_excluir_funcionarios();
                        break;
            case '5':   listarFuncionarios();
                        break;
                
        }

    } while (op != '0');
}



char tela_menu_funcionarios(void) {
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
    printf("///             ------------  MENU FUNCIONARIOS ------------                ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR FUNCIONARIOS                                    ///\n");
    printf("///            2. PESQUISAR DADOS DO FUNCIONARIOS                           ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO FUNCIONARIOS                        ///\n");
    printf("///            4. EXCLUIR DADOS DO FUNCIONARIOS                             ///\n");
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

Funcio* tela_cadastro_funcionarios(void){
    Funcio *fun;
    fun = (Funcio*)malloc(sizeof(Funcio));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                          CADASTRO FUNCIONARIOS                          ///\n");
    printf("///                 -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                 ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("/// NOME:");
        scanf("%s", fun -> nome);
        limparBuffer();
    } while(!validarNome(fun -> nome));
        do {
        printf("/// CARGO:");
        scanf("%s",fun -> cargo);
        limparBuffer();
    } while(!validarNome(fun -> cargo));
    int cpfDuplicado = 0;
    int cpfValido = 0;
    do {
        printf("/// CPF: ");
        scanf("%s", fun->cpf);
        limparBuffer();

        cpfDuplicado = cpfDuplicadoFuncio(fun->cpf);

        if (cpfDuplicado) {
            printf("\n");
            printf("\t\t\tCPF JA EXISTE. TENTE NOVAMENTE.\n");
            printf("\n");
        } else if (validarCPF(fun->cpf)) {
            cpfValido= 1;
        }
        else {
            printf("\n");
            printf("\t\t\tCPF INVALIDO. TENTE NOVAMENTE.\n");
            printf("\n");
        }
    } while (!cpfValido || cpfDuplicado);

    int emailDuplicado = 0;
    int emailValido = 0;
    do {
        printf("/// EMAIL:");
        scanf("%[a-z0-9@.]",fun -> email);
        limparBuffer();

        emailDuplicado = emailDuplicadoFuncio(fun->email);

        if (emailDuplicado) {
            printf("\n");
            printf("\t\t\tEMAIL JA EXISTE. TENTE NOVAMENTE.\n");
            printf("\n");
        } else if (validarEmail(fun->email)) {
            emailValido = 1;
        }
        else {
            printf("\n");
            printf("\t\t\tEMAIL INVALIDO. TENTE NOVAMENTE.\n");
            printf("\n");
        }
    } while (emailDuplicado || !emailValido);

    do {
        printf("/// DATA DE NASCIMENTO:");
        scanf("%[0-9/]",fun -> dataNas);
        limparBuffer();
    } while(!validarData(fun -> dataNas));

    do {
        printf("/// TELEFONE:");
        scanf("%[0-9()]",fun -> telefone);
        limparBuffer();
    } while(!validarFone(fun -> telefone));
    
    fun->status = 1;
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return fun;
}



Funcio* tela_pesquisar_funcionarios(void) {
    FILE* fp;
    char opc[15];
    Funcio* fun;
    fun = (Funcio*)malloc(sizeof(Funcio));
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
    printf("///                        PESQUISAR FUNCIONARIO                            ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///CPF: ");
        scanf("%[0-9]",opc);
        limparBuffer();
    } while(!validarCPF(opc));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        telaErro();
        free(fun);
        exit(1);
    }
    int funEncontrado = 0;
    system("clear||cls");
    while (fread(fun, sizeof(Funcio), 1, fp)) {
        if ((fun->status != 0) && (strcmp(fun->cpf,opc)==0)) {
            printFuncionarios(fun);
            funEncontrado = 1;
        }
    }
    if (!funEncontrado){
        printf("\n");
        printf("\t\t\t FUNCIONARIO NAO REGISTRADO\n");
        limparBuffer();
        return NULL;
    }
    
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return NULL;
}


void tela_alterar_funcionarios(void) {

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
    printf("///                           ALTERAR FUNCIONARIO                           ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              CPF DO FUNCIONARIO:                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_excluir_funcionarios(void) {
    
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
    printf("///                         EXCLUIR FUNCIONARIO                             ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              CPF DO FUNCIONARIO:                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void gravaFuncionario(Funcio* fun) {
    FILE* fp;
    fp = fopen("funcionarios.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    fwrite(fun, sizeof(Funcio), 1, fp);
    fclose(fp);
}


void listarFuncionarios(void) {
    FILE* fp;
    Funcio fun;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("       LISTAGEM DOS FUNCIONARIOS       \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                       \n");
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    while (fread(&fun, sizeof(Funcio), 1, fp)) {
        if (fun.status != 'x') {
            printFuncionarios(&fun);
        }
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fclose(fp);
}

void printFuncionarios(Funcio* fun) {
    printf("\n = = = DADOS DO FUNCIONARIO = = = \n");
    printf("\n");
    printf("+ NOME:%s\n", fun-> nome);
    printf("+ CARGO:%s\n",fun->cargo);
    printf("+ CPF:%s\n", fun-> cpf);                                                         
    printf("+ EMAIL:%s\n", fun-> email);                                                      
    printf("+ DATA DE NASCIMENTO:%s\n", fun-> dataNas);                                          
    printf("+ TELEFONE: %s\n", fun-> telefone);
    printf("===================================\n");                  
}

// Verifica se um CPF já está cadastrado
int cpfDuplicadoFuncio(const char* cpf) {
    FILE* fp = fopen("funcionarios.dat", "rb");

    Funcio fun;
    while (fread(&fun, sizeof(Funcio), 1, fp)) {
        if (fun.status != 0 && strcmp(fun.cpf, cpf) == 0) {
            fclose(fp);
            return 1; // CPF duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // CPF não duplicado
}

// Verifica se um e-mail já está cadastrado
int emailDuplicadoFuncio(const char* email) {
    FILE* fp = fopen("funcionarios.dat", "rb");

    Funcio fun;
    while (fread(&fun, sizeof(Funcio), 1, fp)) {
        if (fun.status != 0 && strcmp(fun.email, email) == 0) {
            fclose(fp);
            return 1; // E-mail duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // E-mail não duplicado
}

// Cadastra um novo cliente
void cadFuncionario(void) {
    Funcio *fun;
    fun = tela_cadastro_funcionarios();
    gravaFuncionario(fun);
    free(fun);
}