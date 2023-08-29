int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    char op;
    do {
        tela_menu_principal();
        scanf(" %c", &op); 
        getchar();

        switch (op) {
            case '1':   
                tela_menu_cliente();
                scanf("%c", &op);
                getchar();

                switch (op) {
                    case '1':
                        system("clear||cls");
                        tela_cadastro_cliente();
                        break;
                    case '2':
                        system("clear||cls");
                        tela_pesquisar_cliente();
                        break;
                    case '3':
                        system("clear||cls");
                        tela_alterar_cliente();
                        break;
                    case '4':
                        system("clear||cls");
                        tela_excluir_cliente();
                        break;
                    case '0':
                        system("clear||cls");
                        tela_menu_principal();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                break;
            case '0':
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
         }
    } while (op != '0');
    
    return 0;
}


int main(void) {
    setlocale(LC_ALL, "Portuguese_Brazil");
    char op;
    do {
        tela_menu_cliente();
        scanf(" %c", &op);
        getchar();  

        switch (op) {
            case '1':   
                do {
                    tela_menu_cliente();
                    scanf(" %c", &op);
                    
                    switch (op) {
                        case '1':
                            system("clear||cls");
                            tela_cadastro_cliente();
                            // Implemente a lógica para cadastro de cliente
                            break;
                        case '2':
                            system("clear||cls");
                            tela_pesquisar_cliente();
                            // Implemente a lógica para pesquisar cliente
                            break;
                        case '3':
                            system("clear||cls");
                            tela_alterar_cliente();
                            // Implemente a lógica para alterar cliente
                            break;
                        case '4':
                            system("clear||cls");
                            tela_excluir_cliente();
                            // Implemente a lógica para excluir cliente
                            break;
                        case '0':
                            break;
                        default:
                            printf("Opção inválida!\n");
                            break;
                    }
                } while (op != '0');
                break;
            case '0':
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (op != '0');
    
    return 0;
}
