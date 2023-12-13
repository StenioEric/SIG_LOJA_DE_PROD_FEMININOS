///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

////////////////////////////////
/// FUNCOES DO MODULO GERENCIA
void moduloGerencia(void);
char tela_menu_gerencia(void);

///////////////////////
// Modulo Clientes
char telaCli(void);
void listarTodosCli(void);
void listarCliAtivos(void);
void listarCliInativos(void);
void list_alfa_cli(void);

///////////////////////
// Modulo Estoque
char telaEst(void);
void listarTodosProd(void);
void listarProdAtivos(void); 
void listarProdInativos(void);
void list_alfa_est(void);

///////////////////////
// Modulo Vendas
char telaVend(void);
void listarVendasFinal(void); 
void listarVendasAbert(void);
void list_Vend_Cli(void);
void list_idCompra(void);
// void list_alfa_vendas(void); 