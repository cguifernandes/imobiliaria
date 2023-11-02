#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ARQ_CLIENTS "clients.txt"

void interaction_clients() {
	int option;
	
	while (option != 4) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("                CLIENTE\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Cadastrar um cliente\n");
		printf("2 - Listar um cliente\n");
		printf("3 - Excluir um cliente\n");
		printf("4 - Voltar ao menu de interação\n\n");
		
		printf("Por favor, digite uma das opções para continuar: ");
		scanf("%i", &option);
		
		switch (option) {
						
			case 1: 
				insert_clients();
				return;
			case 2: 
				list_clients();
				return;
			case 3: 
				remove_clients();
				return;
			case 4: 
				return;
			default:
				break;
		}
	}
	
	getchar();
}

void insert_clients() {
	system("cls");
	clients ins;
	FILE *arq = fopen(ARQ_CLIENTS, "a+");
	
	printf("----------------------------------------\n\n");
	printf("          CADASTRAR CLIENTE\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o CPF do cliente (Sem caracteres especiais, apenas os números): ");
	scanf("%f", &ins.cpf);
	
	printf("Insira o nome do cliente: ");
	scanf("%s", ins.nome);
	
	printf("Insira o endereço do cliente: ");
	scanf("%s", ins.endereco);
	
	int exist = exist_register_clients(ARQ_CLIENTS, ins.cpf);
	
	printf("%f", ins.cpf);
	
	if (exist == 1) {
		printf("\nEsse CPF já está sendo usado.\n\n");
	}
	
	else {
		if (arq != NULL) {
			fprintf(arq, "%i %s %s\n", ins.cpf, ins.nome, ins.endereco); 
	    	printf("\nCadastro foi concluído ;)\n\n");
		} 
		else {
			printf("\nAlgo deu errado ;(\n\n");
		}
	}
	
	fclose(arq);
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

void list_clients() {
	system("cls");
	clients ins;
	
	printf("----------------------------------------\n\n");
	printf("          LISTAR CLIENTES\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o CPF do cliente (Sem caracteres especiais, apenas os números): ");
	scanf("%i", &ins.cpf);
	
	clients cliente = search_clients(ARQ_CLIENTS, ins.cpf);   
	
	if (cliente.cpf != -1) {
		printf("\nCliente encontrado. :)\n\n");
		printf("ID (Identificador) do cliente: %i\n", cliente.cpf);
		
		printf("Nome do cliente: %s\n", cliente.nome);
		
		printf("Endereco do cliente: %s\n", cliente.endereco);
		
    } else {
        printf("\nCliente não encontrado. ;(\n");
	}
	
	printf("\nPressione qualquer tecla para prosseguir: ");
	getchar();
}

void remove_clients() {
	system("cls");
	clients rgs;
	int option;
	
	printf("----------------------------------------\n\n");
	printf("            EXCLUIR CLIENTES\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o CPF do cliente (Sem caracteres especiais, apenas os números): ");
	scanf("%i", &rgs.cpf);
	
	clients cliente = search_clients(ARQ_CLIENTS, rgs.cpf);
	
	if (cliente.cpf != -1) {
		printf("\nID (Identificador) do cliente: %i\n", cliente.cpf);
		
		printf("Nome do cliente: %s\n", cliente.nome);
		
		printf("Endereco do cliente: %s\n", cliente.endereco);
		
		printf("\nTem certeza que deseja excluir esse produto? (1 - Sim, 2 - Não): ");
		scanf("%i", &option);

		while (option != 2) {
		    if (option == 1) {
		        del_clients(ARQ_CLIENTS, rgs.cpf);
		        printf("\nO Produto com o ID %i foi excluído\n\n", rgs.cpf);
		        break;
		    }
		    else if (option == 2) {
		        break;
		    }
		    else {
		        printf("\nOpção inválida\n\n");
		        break;
		    }
		}
    } else {
        printf("\nProduto não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

