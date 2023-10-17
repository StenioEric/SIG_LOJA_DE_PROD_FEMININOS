///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////
typedef struct vendas Vendas;
struct vendas {
    char idProduto[20];
    char quantidade[30];
    char valor[13];
};

void moduloVendas(void);
char tela_menu_vendas(void);
void tela_catalogo(void);
void tela_carrinho_produtos(void);
void tela_excluir_produto(void);
void tela_finalizar_compra(void);
void tela_ver_carrinho(void);