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
    char quantidade[13];
    char id[20];
    char idCompra[20];
    char cpf[15];
    char status;
};

void moduloVendas(void);
char tela_menu_vendas(void);
Vendas* adicionarProdutos(void);
Vendas* excluirProduto(void);
Vendas* tela_ver_carrinho(void);

void gravaProduto(Vendas*);
void removeVenda(Vendas*);
Vendas* finalizarVenda(void);

int verificaQuantidade(const char* quantidade, const char* idProduto);
int verificaIdCompra(const char* idCompra);
int buscaVenda(char*);
// void verificaEstoque(const char* idProduto, int quantidade);
float calcularTotalCompra(const char* IdCompra);
void listarProdutosPorCompra(const char* idCompra);
// void gravaVendas(Vendas* venda);
void listagemVendas(void);
void printVendas(Vendas* vend);
void mostrarDetalhesCompra(const char* idCompra);
// int verStatusVend(const char* idCompra);
char* gera_idCompra(void);
int buscaIdCompra(char* idCompra);

#endif // VENDAS_H
