#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ARQ_PRODUCTS "products.txt"

void interaction_products() {
	int option = 0;
	
	while (option != 4) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("               PRODUTOS\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Cadastrar um produtos\n");
		printf("2 - Listar um produtos\n");
		printf("3 - Excluir um produto\n");
		printf("4 - Voltar ao menu de intera��o\n\n");
		
		printf("Por favor, digite uma das op��es para continuar: ");
		scanf("%i", &option);
		
		switch (option) {	
			case 1: 
				insert_products();
				return;
			case 2: 
				list_products();
				break;
			case 3: 
				remove_products();
				break;
			case 4: 
				return;
			default:
				break;
		}
		
		getchar();
	}
}

void insert_products (){
	system("cls");
	products rgs;
	FILE *arq = fopen(ARQ_PRODUCTS, "a+");
	
	printf("----------------------------------------\n\n");
	printf("           CADASTRAR PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do produto: ");
	scanf("%i", &rgs.id);
	
	printf("Insira o endere�o do im�vel: ");
	scanf("%s", rgs.endereco);
	
	printf("Insira o valor do im�vel: ");
	scanf("%f", &rgs.valor);
	
	printf("Qual � o status do im�vel? (1 - Vendido, 2 - � venda): ");
	scanf("%i", &rgs.status);
	int exist = exist_register_products(ARQ_PRODUCTS, rgs.id);

	if (exist == 1) {
		printf("\nEsse ID (Identificador) j� est� sendo usado.\n\n");
	}
	
	else {
		if (arq != NULL) {
			fprintf(arq, "%i %s %.2f %i\n", rgs.id, rgs.endereco, rgs.valor, rgs.status); 
	    	printf("\nCadastro foi conclu�do ;)\n\n");
		} 
		else {
			printf("\nAlgo deu errado ;(\n\n");
		}
    	fclose(arq);
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

void list_products() {
	system("cls");
	products rgs;
	char status[7];
	
	printf("----------------------------------------\n\n");
	printf("            LISTAR PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do produto: ");
	scanf("%i", &rgs.id);
	
	products produto = search_products(ARQ_PRODUCTS, rgs.id);   
	
	if (produto.id != -1) {
		printf("\nProduto encontrado. :)\n\n");
		printf("ID (Identificador) do produto: %i\n", produto.id);
		
		printf("Endere�o do im�vel: %s\n", produto.endereco);
		
		printf("Valor do im�vel: %.2f\n", produto.valor);
		
		if (produto.status == 1) {
		    strcpy(status, "Vendido");
		}
		else {
		    strcpy(status, "� venda");
		}
		
		printf("Status do im�vel: %s\n\n", status);
    } else {
        printf("\nProduto n�o encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

void remove_products() {
	system("cls");
	products rgs;
	char status[7];
	int option;
	
	printf("----------------------------------------\n\n");
	printf("            EXCLUIR PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do produto: ");
	scanf("%i", &rgs.id);
	
	products produto = search_products(ARQ_PRODUCTS, rgs.id);
	
	if (produto.id != -1) {
		printf("ID (Identificador) do produto: %i\n", produto.id);
		
		printf("Endere�o do im�vel: %s\n", produto.endereco);
		
		printf("Valor do im�vel: %.2f\n", produto.valor);
		
		if (produto.status == 1) {
		    strcpy(status, "Vendido");
		}
		else {
		    strcpy(status, "� venda");
		}
		
		printf("Status do im�vel: %s\n\n", status);
		
		printf("Tem certeza que deseja excluir esse produto? (1 - Sim, 2 - N�o): ");
		scanf("%i", &option);

		while (option != 2) {
		    if (option == 1) {
		        remove(ARQ_PRODUCTS, rgs.id);
		        printf("\nO Produto com o ID %i foi exclu�do\n\n", rgs.id);
		        break;
		    }
		    else if (option == 2) {
		        break;
		    }
		    else {
		        printf("\nOp��o inv�lida\n\n");
		        break;
		    }
		}
    } else {
        printf("\nProduto n�o encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}
