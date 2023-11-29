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

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for uma alfabético 
/// (letra entre 'A' e 'Z' ou 'a' e 'z') ou retorna 0 caso contrário
///
int ehLetra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}
/////////////////////////////////////////////////////////////////////////////
/// Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2




///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for uma barra
///
int ehBarra(char c) {
  if (c == '/') {
    return 1;
  }
  else {
    return 0;
  }
}
/////////////////////////////////////////////////////////////////////////////
/// Stenio Eric
/// link: https://github.com/StenioEric/SIG_LOJA_DE_PROD_FEMININOS


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for um parentese
///
int ehParentese(char c) {
  if (c == '(' || c == ')') {
    return 1;
  }
  else {
    return 0;
  }
}
/////////////////////////////////////////////////////////////////////////////
/// Stenio Eric
/// link: https://github.com/StenioEric/SIG_LOJA_DE_PROD_FEMININOS





///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
///
int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!ehLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}
/////////////////////////////////////////////////////////////////////////////
/// Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se dia, mes e ano correspondem a uma data válida, inclusive
/// em anos bissextos, ou retorna 0 caso contrário
///
int ehData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (ehBissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}
/////////////////////////////////////////////////////////////////////////////
/// Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2



///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma data válida (apenas dígitos
/// e no formato: ddmmaaaa) ou retorna 0 caso contrário
///
int validarData(char* data) {
  int tam, dia, mes, ano;
  tam = strlen(data);
  if (tam != 10) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(data[i]) && !ehBarra(data[i])) { 
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[3] - '0') * 10 + (data[4] - '0'); 
  ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + 
        (data[8] - '0') * 10 + (data[9] - '0'); 
  if (!ehData(dia, mes, ano)) {
    return 0;
  }
  return 1;
}
/////////////////////////////////////////////////////////////////////////////
/// Adaptado de Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um número de celular válido 
/// (apenas dígitos) ou retorna 0 caso contrário
///
int validarFone(char* fone) {
  int tam;
  tam = strlen(fone);
  if (tam != 13) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i]) && !ehParentese(fone[i])) {
        return 0;
    }
  }
  return 1;
}
/////////////////////////////////////////////////////////////////////////////
/// Adaptado de Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se ano for bissexto (divisível por 4, não divisível por ...
/// 100 ou divisível por 400) e retorna 0 caso contrário
///
int ehBissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}
/////////////////////////////////////////////////////////////////////////////
/// Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um cpf válido 
/// ou retorna 0 caso contrário
///
int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}  // AUTOR: EDUARDO EDSON /// GIT: https://gist.github.com/eduardoedson



///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um email válido 
/// ou retorna 0 caso contrário
///
int validarEmail(char *email )
{
    char usuario[256], site[256], dominio[256];
    if( sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 )
        return 0;
    return 1;
}  // AUTOR: LACOBUS /// STACKOVERFLOW: https://pt.stackoverflow.com/questions/310096/como-validar-um-e-mail-em-c



///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um email válido 
/// ou retorna 0 caso contrário
///
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
/////////////////////////////////////////////////////////////////////////////
///  Autor: Chatgpt


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for um dígito (entre 0 e 9)
/// retorna 0 caso contrário
///
int ehDigitos(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Se qualquer caractere não for um dígito, retorna 0
        }
    }
    return 1; // Todos os caracteres são dígitos
}

/////////////////////////////////////////////////////////////////////////////
/// ChatGpt

int ehDigito(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}
/////////////////////////////////////////////////////////////////////////////
/// Flavius Gorgonio
/// link: https://github.com/flgorgonio/linguasolta_2020.2

void telaErro(void) {
  system("clear||cls");
  printf("\t\t\tOps! Erro na abertura do arquivo!\n");
  printf("\n");
  exit(1);
}


void espacamento(void) {
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


int ehdinheiro(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (!ehvirgula(str[i]))) {
            return 0; // Se qualquer caractere não for um dígito, retorna 0
        }
    }
    return 1; // Todos os caracteres são dígitos
}


int ehvirgula(char c) {
  if (c == ',') {
    return 1;
  }
  else {
    return 0;
  }
}


/// criar função ehdinheiro
// char* pegaNome(void) {
//   char nome[TAMANHO_MAXIMO_NOME];

//   do {
//     printf("/// NOME: ");
//     scanf("%s", nome);
//     limparBuffer();
//   } while(!validarNome(nome));

//   return strdup(nome);
// }

// char* pegaEmail(void) {
//   char email[TAMANHO_MAXIMO_NOME];

//   do {
//     printf("/// EMAIL: ");
//     scanf("%s", email);
//     limparBuffer();
//   } while(!validarEmail(email));

//   return strdup(email);
// }

// char* pegaCPF(void) {
//   Cliente *cli;
//   cli = (Cliente*)malloc(sizeof(Cliente));
//   char cpf[TAMANHO_MAXIMO_CPF];
//   do {
//     printf("/// CPF: ");
//     scanf("%s",cpf);
//     limparBuffer();
//   } while (!validarCPF(cpf));

//   return strdup(cpf);
// }

// char* pegaTelefone(void) {
//   char telefone[TAMANHO_MAXIMO_NUMERO];
//   do {
//     printf("/// TELEFONE: ");
//     scanf("%s", telefone);
//     limparBuffer();
//   } while (!validarFone(telefone));

//   return strdup(telefone);
// }

// char* pegaData(void) {
//   char dataNas[TAMANHO_MAXIMO_DATA];

//   do {
//     printf("/// DATA DE NASCIMENTO: ");
//     scanf("%s", dataNas);
//     limparBuffer();
//   } while (!validarData(dataNas));

//   return strdup(dataNas);
// }


void cpfErro(void){
  printf("\n");
  printf("=============================================\n");
  printf("|         CPF INVALIDO OU JA EXISTE         |\n");
  printf("=============================================\n");
  printf("|                                           |\n");
  printf("|    POR FAVOR, INSIRA UM CPF VALIDO OU     |\n");
  printf("|    QUE NAO ESTEJA CADASTRADO.             |\n");
  printf("|                                           |\n");
  printf("=============================================\n");
  printf("\n");
}

void emailErro(void){
  printf("\n");
  printf("=============================================\n");
  printf("|        EMAIL INVALIDO OU JA EXISTE        |\n");
  printf("=============================================\n");
  printf("|                                           |\n");
  printf("|  POR FAVOR, INSIRA UM EMAIL VALIDO OU     |\n");
  printf("|  QUE NAO ESTEJA CADASTRADO.               |\n");
  printf("|                                           |\n");
  printf("=============================================\n");
  printf("\n");
}

void idErro(void) {
  printf("\n");
  printf("=============================================\n");
  printf("|         ID JA EXISTE OU INVALIDO          |\n");
  printf("=============================================\n");
  printf("|                                           |\n");
  printf("|  O ID INSERIDO JA EXISTE NO SISTEMA OU E  |\n");
  printf("|  INVALIDO POR FAVOR, INSIRA UM NOVO ID.   |\n");
  printf("|                                           |\n");
  printf("=============================================\n");
  printf("\n");
}


void idValido(void) {
  printf("\n");
  printf("=============================================\n");
  printf("|         ID NAO EXISTE OU INVALIDO          |\n");
  printf("=============================================\n");
  printf("|                                           |\n");
  printf("|  O ID INSERIDO NAO EXISTE NO SISTEMA OU E |\n");
  printf("|  INVALIDO POR FAVOR, INSIRA UM NOVO ID.   |\n");
  printf("|                                           |\n");
  printf("=============================================\n");
  printf("\n");
}


void cpfValido(void){
  printf("\n");
  printf("=============================================\n");
  printf("|         CPF INVALIDO OU NAO EXISTE        |\n");
  printf("=============================================\n");
  printf("|                                           |\n");
  printf("|    POR FAVOR, INSIRA UM CPF VALIDO E      |\n");
  printf("|    QUE NAO ESTEJA CADASTRADO.             |\n");
  printf("|                                           |\n");
  printf("=============================================\n");
  printf("\n");
}