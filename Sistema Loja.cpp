#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct cadastro{
    char nome[31];
    int anoDeNascimento;
    float montanteGasto;
    int cod;
    int vazio;
    int incremento;
}cadastro;



//PREENCHE OS VETORES
void preencher(cadastro *cliente){
    printf("\nDigite o Nome do Cliente: ");
    gets(cliente->nome);
    printf("Digite o Ano de Nascimento: ");
    scanf("%i", &cliente->anoDeNascimento);
    getchar();
    printf("Digite o Montante Gasto: ");
    scanf("%f", &cliente->montanteGasto);
    getchar();
    cliente->vazio = 1;
    system("cls");
    printf("-------------------\n");
    printf("     INSERIDO\n");
    printf("-------------------\n");
    int i, j;
    for(i = 0 ; i < 5000 ; i++){
    	for(j = 0 ; j < 200000 ; j ++){
		}
	}
	system("cls");
    printf("----------------------------\n");
    printf("     Cliente Cadastrado\n");
    printf("----------------------------\n");
    for(i = 0 ; i < 5000 ; i++){
    	for(j = 0 ; j < 200000 ; j ++){
		}
	}
	system("cls");
}



void imprimir(cadastro *cliente){
        printf("Nome: %s\n", cliente->nome);
        printf("Ano: %i\n", cliente->anoDeNascimento);
        printf("Montante: %.2f\n\n", cliente->montanteGasto);
}




int main(){

    cadastro *cliente;
    cliente = (cadastro *) calloc(10, sizeof(cadastro));

    int i, j, opcao;
    int incremento = 0;
    int incremento2 = 0;
    int retorno;
    do{
		printf("\n---------- Menu Principal ----------\n");
		printf("1 - Cadastrar Novo Cliente\n");
		printf("2 - Listar Clientes\n");
		printf("3 - Atualizar ou Zerar Montante\n");
		printf("4 - Remover Cliente\n");
		printf("8 - Sair\n");
		printf("------------------------------------\n");
		printf("Digite sua opcao: ");
		scanf("%i", &opcao);
		getchar();

		if(opcao == 1){
            int cont = 0;
            system("cls");
            if(incremento == 10){
				printf("-------------------------------------------------------\n");
    			printf("     Espa�o de memoria realocado em +10 posicoes\n");
    			printf("-------------------------------------------------------\n");
    			for(i = 0 ; i < 5000 ; i++){
    				for(j = 0 ; j < 200000 ; j ++){
					}
				}
			system("cls");
			}
            if(incremento == 10){
            	cliente = (cadastro *) realloc(cliente, sizeof(struct cadastro)*10+10);
            	incremento = 0;
			}
            for (cont = 0 ; cont <= 900 ; cont++){
                if (cliente[cont].vazio == 0){
                    retorno = cont;
                    break;
                }else {retorno = -1;}
            }
			if(retorno != -1){
                preencher(&cliente[retorno]);
            }
            incremento = incremento + 1;
            incremento2 = incremento2 + 1;
		}

		else if(opcao == 2){
			system("cls");
			int opc;
			cadastro aux;
			do{
				printf("\n---------- Menu de Listagem ----------\n");
				printf("1 - Listar Todos os Clientes\n");
				printf("2 - Listar a Partir do Melhor Comprador\n");
				printf("3 - Listar Montante de Cliente especifico\n");
				printf("4 - Voltar ao Menu Principal\n");
				printf("--------------------------------------\n");
				printf("Digite sua opcao: ");
				scanf("%i", &opc);
				getchar();

				if(opc == 1){
					system("cls");
					for(i = 0 ; i < incremento ; i++){
                        if(cliente[i].vazio != 0){
                            printf("------------------------------------\n\n");
                            imprimir(&cliente[i]);
                        }
					}
				}else if(opc == 2){
					system("cls");
					for(i = 0 ; i < incremento ; i++){
						for(j = i+1; j < incremento ; j++){
							if(cliente[j].montanteGasto > cliente[i].montanteGasto){
								aux = cliente[j];
								cliente[j] = cliente[i];
								cliente[i] = aux;
							}
						}
                    if(cliente[i].vazio != 0){
                        printf("------------------------------------\n");
                        printf("\nNome: %s\n", cliente[i].nome);
                        printf("Ano: %i\n", cliente[i].anoDeNascimento);
                        printf("Montante: %.2f\n\n", cliente[i].montanteGasto);
                    }
					}
				}else if(opc == 3){
					char nome[31];
					int ano, nomeInt;
					system("cls");
					printf("\nInforme o Nome do Cliente: ");
					gets(nome);
					printf("Informe o Ano de Nascimento: ");
					scanf("%i", &ano);
					getchar();
					nomeInt = atoi(nome);
					for(i = 0 ; i < incremento ; i++){
						if(ano == cliente[i].anoDeNascimento && nomeInt == atoi(cliente[i].nome) && cliente[i].vazio != 0){
							system("cls");
							printf("\n-------------------------\n\n");
							printf("\nNome: %s\n", cliente[i].nome);
        					printf("Ano: %i\n", cliente[i].anoDeNascimento);
        					printf("Montante: %.2f\n\n", cliente[i].montanteGasto);
						}
					}
				}
			}while(opc != 4);
			system("cls");
		}

		else if(opcao == 3){
			int opc;
			do{
				system("cls");
				int opc;
				printf("\n---------- Menu de Valores ----------\n");
				printf("1 - Atualizar Montante\n");
				printf("2 - Zerar Montantes\n");
				printf("3 - Voltar ao Menu Principal\n");
				printf("---------------------------------------\n");
				printf("Digite sua opcao: ");
				scanf("%i", &opc);
				getchar();

				if(opc == 1){
					char nome[31];
					int ano, nomeInt;
					float novoMontante;
					system("cls");
					printf("\nInforme o Nome do Cliente: ");
					gets(nome);
					printf("Informe o Ano de Nascimento: ");
					scanf("%i", &ano);
					getchar();
					nomeInt = atoi(nome);
					for(i = 0 ; i < incremento ; i++){
						if(ano == cliente[i].anoDeNascimento && nomeInt == atoi(cliente[i].nome)){
							system("cls");
							printf("\nDigite o Novo Valor do Montante: ");
							scanf("%f", &novoMontante);
							getchar();
							cliente[i].montanteGasto = novoMontante;
							system("cls");
						}
					}
					printf("-------------------\n");
    				printf("    ATUALIZANDO\n");
    				printf("-------------------\n");
    				int i, j;
    				for(i = 0 ; i < 5000 ; i++){
    					for(j = 0 ; j < 200000 ; j ++){
						}
					}
					system("cls");
                    printf("--------------------------\n");
                    printf("     Valor Atualizado\n");
                    printf("--------------------------\n");
                    for(i = 0 ; i < 5000 ; i++){
                        for(j = 0 ; j < 100000 ; j ++){
                        }
                    }
                    system("cls");
				}

				if(opc == 2){
					for(i = 0 ; i < incremento ; i++){
						cliente[i].montanteGasto = 0;
					}
					system("cls");
					printf("-------------------\n");
    				printf("     ZERANDO\n");
    				printf("-------------------\n");
    				int i, j;
    				for(i = 0 ; i < 5000 ; i++){
    					for(j = 0 ; j < 200000 ; j ++){
						}
					}
					system("cls");
                    printf("----------------------------\n");
                    printf("     Valores Zerados\n");
                    printf("----------------------------\n");
                    for(i = 0 ; i < 5000 ; i++){
                        for(j = 0 ; j < 100000 ; j ++){
                        }
                    }
                    system("cls");
				}
			}while(opc != 3 && opc < 3);
			system("cls");
		}

		else if(opcao == 4){
            system("cls");
            char nome[31];
            int nomeInt, ano, cont = 0;
            char resp;
            printf("\nNome do Cliente Que Deseja Excluir: ");
            gets(nome);

            printf("Ano de Nascimento do Cliente: ");
            scanf("%i", &ano);

            nomeInt = atoi(nome);

            while(cont <= incremento2){
                if(ano == cliente[cont].anoDeNascimento && nomeInt == atoi(cliente[cont].nome)){
                    if (cliente[cont].vazio == 1 ){
                        printf("\n-------------------------------\n\n");
                        printf("Nome: %s\n", cliente[cont].nome);
                        printf("Ano De Nascimento: %i\n", cliente[cont].anoDeNascimento);
                        printf("Montante: %s\n", cliente[cont].montanteGasto);
                        getchar();
                        printf("\nDeseja realmente excluir este cliente? s/n: ");
                        scanf("%s",&resp);
                        getchar();
                        if ( ( resp == 'S' ) || ( resp == 's' ) ){
                            cliente[cont].vazio = 0;
                            system("cls");
                            printf("-------------------\n");
                            printf("     EXCLUINDO\n");
                            printf("-------------------\n");
                            int i, j;
                            for(i = 0 ; i < 5000 ; i++){
                                for(j = 0 ; j < 200000 ; j ++){
                                }
                            }
                            system("cls");
                            printf("\n****** Exclusao feita com sucesso ******\n");
                            for(i = 0 ; i < 5000 ; i++){
                                for(j = 0 ; j < 100000 ; j ++){
                                }
                            }
                            system("cls");
                            break;
                        }else{
                            if ( ( resp == 'N' ) || ( resp == 'n' ) ){
                                printf("--------------------\n");
                                printf(" Exclus�o cancelada\n");
                                printf("--------------------\n");
                            }
                        }
                    }
                }else{
                    system("cls");
                    printf("-----------------------------------\n");
                    printf("     Valores Nao Encontrados\n");
                    printf("-----------------------------------\n");
                    for(i = 0 ; i < 5000 ; i++){
                        for(j = 0 ; j < 200000 ; j ++){
                        }
                    }
                    system("cls");
                    break;
                };
                cont++;
                if (cont > incremento2){
                    printf("\nValor invalidoo\n");
                }
            }
        }
    }while(opcao != 8);
}

