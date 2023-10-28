#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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
		printf("4 - Voltar ao menu de interação\n\n");
		
		printf("Por favor, digite uma das opções para continuar: ");
		scanf("%i", &option);
		
		switch (option) {	
			case 1: 
				insert_products();
				break;
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
	
	int id, status;
	float valor;
	char endereco[101];
	
	printf("----------------------------------------\n\n");
	printf("                PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o Identificador do Produto: ");
	scanf("%i", &id);
	
	printf("Insira o endereço do imóvel: ");
	scanf("%s", endereco);
	
	printf("Insira o valor do imóvel: ");
	scanf("%f", &valor);
	
	printf("Qual é o status do imóvel? (1 - Vendido, 2 - À venda): ");
	scanf("%i", &status);
	
	printf("%i \n", id);
	printf("%i \n", status);
	printf("%f \n", valor);
	printf("%s \n", endereco);

	scanf("%i", &status);
	
}
