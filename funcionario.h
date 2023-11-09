///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////
typedef struct funcio Funcio;
struct funcio {
    char nome[70];
    char cargo[20];
    char cpf[13];
    char dataNas[12];
    char email[30];
    char telefone[12];
    char salario[12];
    char status;
};

void moduloFuncio(void);
char tela_menu_funcionarios(void);
Funcio* tela_cadastro_funcionarios(void);
Funcio* tela_pesquisar_funcionarios(void);
char* tela_alterar_funcionarios(void);
void tela_excluir_funcionarios(void);
void gravaFuncionario(Funcio*);
void listarFuncionarios(void);
void printFuncionarios(Funcio*);
void cadFuncionario(void);
// void atualizaFuncionario(void);
Funcio* buscaFuncionario(char*);
void regravarFuncionario(Funcio*);
// void removeFuncionario(Funcio*);
// void excluirFuncionario(void);
void listagemFuncionarios(void);

int cpfDuplicadoFuncio(const char*);
int emailDuplicadoFuncio(const char*);
