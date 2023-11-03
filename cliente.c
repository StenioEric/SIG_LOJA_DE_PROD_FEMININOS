///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "util.h"

typedef struct cliente Cliente;

void moduloCliente(void) {
    char op;
    do {
        op = tela_menu_cliente();
        switch (op) {
            case '1':   cadCliente();
                        break;
            case '2':   tela_pesquisar_cliente();
                        break;
            case '3':   atualizaCliente();
                        break;
            case '4':   excluirCliente();
                        break;
            case '5':   listarTodosClientes();
                        break;

        }
    } while (op != 0);
}

char tela_menu_cliente(void) {
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
    printf("///                 ------------ MENU CLIENTES ------------                 ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR CLIENTE                                         ///\n");
    printf("///            2. PESQUISAR DADOS DO CLIENTE                                ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO CLIENTE                             ///\n");
    printf("///            4. EXCLUIR DADOS DO CLIENTE                                  ///\n");
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


Cliente* tela_cadastro_cliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    int valido = 0;
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
    printf("///                         CADASTRO CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("/// NOME:");
        scanf("%s", cli -> nome);
        limparBuffer();
    } while(!validarNome(cli -> nome));
    int cpfDuplicado = 0;
    do {
        printf("/// CPF DO CLIENTE: ");
        scanf("%s", cli->cpf);
        limparBuffer();

        cpfDuplicado = verificaCPFDuplicado(cli->cpf);

        if (cpfDuplicado) {
            printf("/// CPF JA EXISTE. TENTE NOVAMENTE.\n");
        } else if (validarCPF(cli->cpf)) {
            valido = 1;
        }
        else {
            printf("/// CPF INVALIDO. TENTE NOVAMENTE.\n");
        }
    } while (!valido || cpfDuplicado);
    do {
        printf("/// EMAIL:");
        scanf("%[a-z0-9@.]",cli -> email);
        limparBuffer();
    } while(!valEmail(cli -> email));
    do {
        printf("/// DATA DE NASCIMENTO:");
        scanf("%[0-9/]",cli -> dataNas);
        limparBuffer();
    } while(!validarData(cli -> dataNas));
    do {
        printf("/// TELEFONE:");
        scanf("%[0-9()]",cli -> telefone);
        limparBuffer();
    } while(!validarFone(cli -> telefone));
    cli->status = 1;
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cli;
}

Cliente* tela_pesquisar_cliente(void) {
    char opc[15];
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
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
    printf("///                        PESQUISAR CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///CPF DO CLIENTE: ");
        scanf("%[0-9]",opc);
        limparBuffer();
    } while(!validarCPF(opc));
    if (cli == NULL){  /// Concertar erro que não aparece essa parte do código
        printf("\n= = = Cliente não registrado = = =\n");
        limparBuffer();
        return NULL;
    }
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro();
        free(cli);
        exit(1);
    }
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if ((cli->status != 0) && (strcmp(cli->cpf,opc)==0)) {
            printCliente(cli);
            limparBuffer();
        }
    }
    fclose(fp);
    free(cli);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return NULL;

}


char* tela_alterar_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(15*sizeof(char));
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
    printf("///                         ALTERAR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///CPF DO CLIENTE: ");
    scanf("%[0-9]", cpf);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

char* tela_excluir_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(15*sizeof(char));
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
    printf("///                         EXCLUIR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///CPF DO CLIENTE: ");
    scanf("%[0-9]", cpf);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}












void printCliente(Cliente* cli) {
    if ((cli == NULL) || (cli->status == 0)) {
        printf("\n= = = CLIENTE INEXISTENTE = = =\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        system("clear||cls");
        printf("\n = = = DADOS DO CLIENTE = = = \n");
        printf("\n");
        printf("NOME:%s\n", cli-> nome);
        printf("CPF:%s\n", cli-> cpf);                                                         
        printf("EMAIL:%s\n", cli-> email);                                                      
        printf("DATA DE NASCIMENTO:%s\n", cli-> dataNas);                                          
        printf("TELEFONE: %s\n", cli-> telefone);
        printf("STATUS: %d\n", cli->status);
        printf("===================================\n");                  
    }

}


void gravaCliente(Cliente* cli) {
    FILE* fp;
    fp = fopen("clientes.dat", "ab");
    if (fp == NULL) {
        telaErro();
        exit(1);
    }
    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
}


void listarTodosClientes(void) {
    FILE* fp;
    Cliente cli;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         PRINT DADOS CLIENTES          \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                       \n");
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro();
        exit(1);
    }
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (cli.status != 0) {
            printCliente(&cli);
        }
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fclose(fp);
}


Cliente* buscaCliente(char* cpf) {
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro();
    }
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0) && (strcmp(cli->cpf, cpf) == 0)) {
            fclose(fp);
            return cli;
        }
    }
	fclose(fp);
	return NULL;
}


void atualizaCliente(void) {
	Cliente* cli;
	char* cpf;

	cpf = tela_alterar_cliente();
	cli = buscaCliente(cpf);
	if (cli == NULL) {
    	printf("\n\nCliente não encontrado!\n\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
  	} else {
		  cli = tela_cadastro_cliente();
		  strcpy(cli->cpf, cpf);
		  regravarCliente(cli);
		  free(cli);
	}
	free(cpf);
}


/// Regravar Cliente
void regravarCliente(Cliente* cli) {
    int achou;
    FILE* fp;
    Cliente* cli_Lido;

    cli_Lido = (Cliente*)malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        telaErro();
    }
    achou = 0;
    while (fread(cli_Lido, sizeof(Cliente), 1, fp) && !achou) {
        if (strcmp(cli_Lido->cpf, cli->cpf) == 0) {
            achou = 1; 
            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fp);
        }
    }
    fclose(fp);
    free(cli_Lido);
}


/// Opção de Cadastrar
void cadCliente(void) {
	Cliente *cli;
	cli = tela_cadastro_cliente();
	gravaCliente(cli);
	free(cli);
}


void excluirCliente(void) {
	Cliente* cli;
	char* cpf;

	cpf = tela_excluir_cliente();
	cli = (Cliente*) malloc(sizeof(Cliente));
	cli = buscaCliente(cpf);
	if (cli == NULL) {
    	printf("\n\nAluno não encontrado!\n\n");
  	} else {
        cli->status = 0;
        regravarCliente(cli);
        free(cli);
        printf("\n= = = CLIENTE EXCLUIDO COM SUCESSO = = =\n");
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        limparBuffer();

	}
	free(cpf);
}


int verificaCPFDuplicado(const char* cpf) {
    FILE* fp = fopen("clientes.dat", "rb");

    Cliente cli;
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (cli.status != 0 && strcmp(cli.cpf, cpf) == 0) {
            fclose(fp);
            return 1; // CPF duplicado
        }
    }

    fclose(fp);
    return 0; // CPF não duplicado
}
