///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////
#ifndef VENDAS_H
#define VENDAS_H

typedef struct vendas Vendas;
struct vendas {
    char produto[20];
    char quantidade[13];
    char valor[30];
    char descricao[30];
    char id[20];
    char idCompra[20];
    char status;
};

void moduloVendas(void);
char tela_menu_vendas(void);
Vendas* adicionarProdutos(void);
Vendas* excluirProduto(void);
// void tela_finalizar_compra(void);
Vendas* tela_ver_carrinho(void);
void gravaProduto(Vendas*);
void removeVenda(Vendas*);

int verificaQuantidade(const char* quantidade, const char* idProduto);
// int verificaIdCompra(const char* idCompra);
void recuperarProdutosPorCompra(const char* idCompra);
int buscaVenda(char*);

#endif // VENDAS_H
