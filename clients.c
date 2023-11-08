#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ARQ_CLIENTS "clients.txt"

void interaction_clients() {
	int option;
	
	while (option != 5) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("                CLIENTE\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Cadastrar um cliente\n");
		printf("2 - Listar um cliente\n");
		printf("3 - Alterar cadastro de um cliente\n");
		printf("4 - Excluir um cliente\n");
		printf("5 - Voltar ao menu de interação\n\n");
		
		printf("Por favor, digite uma das opções para continuar: ");
		scanf("%i", &option);
		
		switch (option) {			
			case 1: 
				insert_clients();
				break;
			case 2: 
				list_clients();
				break;
			case 3: 
				update_clients();
				break;
			case 4: 
				remove_clients();
				break;
			case 5: 
				return;
			default:
				break;
		}
		
		getchar();
	}
}

void insert_clients() {
	system("cls");
	clients rgs;
	FILE *arq = fopen(ARQ_CLIENTS, "a+");
	
	printf("----------------------------------------\n\n");
	printf("          CADASTRAR CLIENTE\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira um ID (Identificador) ao cliente: ");
	scanf("%i", &rgs.id);
	
	printf("Insira o nome do cliente: ");
	fflush(stdin);
	fgets(rgs.nome, sizeof(rgs.nome), stdin);
	transform_text(rgs.nome);
	
	size_t len = strlen(rgs.nome);
	if (len > 0 && rgs.nome[len - 1] == '\n') {
	    rgs.nome[len - 1] = '\0';
	}
	
	printf("Insira o endereço do cliente: ");
	fflush(stdin);
	fgets(rgs.endereco, sizeof(rgs.endereco), stdin);
	transform_text(rgs.endereco);
	
	len = strlen(rgs.endereco);
	if (len > 0 && rgs.endereco[len - 1] == '\n') {
	    rgs.endereco[len - 1] = '\0';
	}
	
	int exist = exist_register_clients(ARQ_CLIENTS, rgs.id);

	if (exist == 1) {
		printf("\nEsse ID (Identificador) já está sendo usado.\n\n");
	} else {
		if (arq != NULL) {
			fprintf(arq, "%i %s %s\n", rgs.id, rgs.nome, rgs.endereco); 
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
	
	printf("Insira o ID (Identificador) do cliente: ");
	scanf("%i", &ins.id);
	
	clients cliente = search_clients(ARQ_CLIENTS, ins.id);   
	
	if (cliente.id != -1) {
		printf("\nCliente encontrado. :)\n\n");
		
		printf("ID (Identificador) do cliente: %i\n", cliente.id);
		
		remove_space(cliente.nome);
		printf("Nome do cliente: %s\n", cliente.nome);
		
		remove_space(cliente.endereco);
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
	
	printf("Insira o ID (Identificador) do cliente: ");
	scanf("%i", &rgs.id);
	
	clients cliente = search_clients(ARQ_CLIENTS, rgs.id);
	
	if (cliente.id != -1) {
		printf("\nID do cliente: %i\n", cliente.id);
		
		remove_space(cliente.nome);
		printf("Nome do cliente: %s\n", cliente.nome);
		
		remove_space(cliente.endereco);
		printf("Endereço do cliente: %s\n", cliente.endereco);
		
		printf("\nTem certeza que deseja excluir esse cadastro? (1 - Sim, 2 - Não): ");
		scanf("%i", &option);

		while (option != 2) {
		    if (option == 1) {
		        del_clients(ARQ_CLIENTS, rgs.id);
		        printf("\nO Produto com o ID %i foi excluído\n\n", rgs.id);
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

void update_clients() {
	system("cls");
	clients rgs, novo;
	
	printf("----------------------------------------\n\n");
	printf("            ALTERAR CLIENTES\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do cliente: ");
	scanf("%i", &rgs.id);
	
	clients cliente = search_clients(ARQ_CLIENTS, rgs.id);
	
	if (cliente.id != -1) {
		printf("\nID do cliente: %i\n", cliente.id);
		
		remove_space(cliente.nome);
		printf("Nome do cliente: %s\n", cliente.nome);
		
		remove_space(cliente.endereco);
		printf("Endereço do cliente: %s\n", cliente.endereco);
		
		printf("\nNovo cadastro\n\n");
		
		printf("Insira o novo nome do cliente: ");
		fflush(stdin);
		fgets(novo.nome, sizeof(novo.nome), stdin);
		transform_text(novo.nome);
		
		size_t len = strlen(novo.nome);
		if (len > 0 && novo.nome[len - 1] == '\n') {
		    novo.nome[len - 1] = '\0';
		}
		
		printf("Insira o novo endereço do cliente: ");
		fflush(stdin);
		fgets(novo.endereco, sizeof(novo.endereco), stdin);
		transform_text(novo.endereco);
		
		len = strlen(novo.endereco);
		if (len > 0 && novo.endereco[len - 1] == '\n') {
		    novo.endereco[len - 1] = '\0';
		}
		

		del_clients(ARQ_CLIENTS, cliente.id);
		
		FILE *arq = fopen(ARQ_CLIENTS, "a+");
		fprintf(arq, "%i %s %s\n", rgs.id, novo.nome, novo.endereco); 
	    printf("\nNovo cadastro foi concluído ;)\n\n");
	    fclose(arq);
    } else {
		printf("\nProduto não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}
