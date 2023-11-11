///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

/// Assinatura de funcoes
typedef struct estoque Estoque;
struct estoque {
    char produto[20];
    char quantidade[13];
    char valor[30];
    char descricao[30];
    char id[20];
    char status;
};

void moduloEstoque(void);
char tela_menu_estoque(void);
Estoque* tela_cadastro_estoque(void);
Estoque*  tela_pesquisar_estoque(void);
char* tela_alterar_estoque(void);
char* tela_exclui_estoque(void);
void gravaEstoque(Estoque*);
void printEstoque(Estoque*);
void cadEstoque(void);
void listarEstoque(void);
Estoque* buscaEstoque(char*);
void regravarEstoque(Estoque*);
void removeEstoque(Estoque*);
void atualizaEstoque(void);
void excluirEstoque(void);


int verificaIdDuplicado(const char*);

