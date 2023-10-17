///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

/// Assinatura de funcoes

typedef struct estoque Estoque;
typedef struct estoque {
    char produto[20];
    char quantidade[13];
    char valor[30];
    char descricao[30];
    char id[5];
} Estoque;

void moduloEstoque(void);
char tela_menu_estoque(void);
void tela_cadastro_produto(void);
void tela_pesquisar_produto(void);
void tela_alterar_produto(void);
void tela_remover_produto(void);
// void idEstoque(const Estoque*);
// void printEstoque(const Estoque*);
// void limparBuffer(void);
// void valEstoque (Estoque*);

