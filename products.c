#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define ARQ_PRODUCTS "products.txt"

void interaction_products() {
	int option = 0;
	
	while (option != 4) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("                PRODUTOS\n\n");
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
				printf("Listar");
				break;
			case 3: 
				printf("Excluir");
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
	printf("                PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do Produto: ");
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
