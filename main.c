///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///                 Disciplina DCT1106 ---- Programação                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////
// Assinatura das funções
void tela_menu_principal(void);
void tela_sobre_projeto(void);
void tela_developed(void);
void tela_menu_cliente(void);
void tela_cadastro_cliente(void);
void tela_pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);

////
// Programa principal
int main(void) {
    tela_menu_principal();
    tela_sobre_projeto();
    tela_developed();
    tela_menu_cliente();
    tela_cadastro_cliente();
    tela_pesquisar_cliente();
    tela_alterar_cliente();
    tela_excluir_cliente();
    return 0;
}


/////
// Funções

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          ");
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");                                                                       
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ------------ SISTEMA DE GERENCIAMENTO ------------            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. MENU CLIENTES                                             ///\n");
    printf("///            2. MENU VENDAS                                               ///\n");
    printf("///            3. MENU PRODUTO                                              ///\n");
    printf("///            4. MENU FUNCIONARIOS                                         ///\n");
    printf("///            5. MENU GERENCIA                                             ///\n");
    printf("///            6. INFORMAÇÕES DO PROJETO                                    ///\n");
    printf("///            0. SAIR                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          ");
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");                                                                       
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  ------------ PROJETO ------------                      ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa em linguagem C desenvolvido com fins didáticos na UFRN Campus ///\n");
    printf("///  Ceres simula uma loja de artigos femininos, permitindo aos estudantes  ///\n");
    printf("///  aplicar conceitos aprendidos em sala de aula de forma prática. Através ///\n");
    printf("///  da manipulação de estruturas de dados, os alunos gerenciam informações ///\n");
    printf("///  sobre produto,preços e categorias,aprimorando habilidades de resolução ///\n");
    printf("///  de problemas e lógica de programação.                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_developed(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          ");  
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");                                                                 
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///     ------------ IFORMAÇÕES SOBRE O DESENVOLVEDOR ------------          ///\n");   
    printf("///                                                                         ///\n");
    printf("///    Discente: Stênio Éric                                                ///\n");
    printf("///    E-mail: stenioeric@gmail.com                                         ///\n");
    printf("///    Redes sociais: @stenioeric                                           ///\n");
    printf("///    Git:https://github.com/StenioEric/SIG_LOJA_DE_PROD_FEMININOS.git     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 


void tela_menu_cliente(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          ");
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");                                                               
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             ------------  MENU CLIENTES ------------                    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR CLIENTE                                         ///\n");
    printf("///            2. PESQUISAR DADOS DO CLIENTE                                ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO CLIENTE                             ///\n");
    printf("///            4. EXCLUIR DADOS DO CLIENTE                                  ///\n");
    printf("///            0. VOLTAR AO MENU PRINCIPAL                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPÇÃO DESEJADA: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_cadastro_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          "); 
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         CADASTRO CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");   
    printf("///                                                                         ///\n");
    printf("///            Nome Completo do Cliente:                                    ///\n");
    printf("///            CPF:                                                         ///\n");
    printf("///            E-mail:                                                      ///\n");
    printf("///            Data de Nascimento (dd/mm/aaaa):                             ///\n");
    printf("///            Celular (apenas números):                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_pesquisar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          "); 
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                        PESQUISAR CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              CPF DO CLIENTE:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_alterar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          "); 
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         ALTERAR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              CPF DO CLIENTE:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_excluir_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                                                                                 ");
    printf("             EEEEEEE lll                                                         ");
    printf("             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee             ");
    printf("             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e            ");
    printf("             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee             ");
    printf("             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee            ");
    printf("                                  ggggg                                          "); 
    printf("                                                                                 ");
    printf("                         LOJA DE ARTIGOS FEMININOS                               ");
    printf("                                                                                 ");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         EXCLUIR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              CPF DO CLIENTE:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


