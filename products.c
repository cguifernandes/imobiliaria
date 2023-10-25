#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void interaction_products() {
	int option;
	
	printf("----------------------------------------\n\n");
	printf("PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Cadastrar um produtos\n");
	printf("2 - Listar um produtos\n");
	printf("3 - Excluir um produto\n");
	printf("4 - Voltar ao menu de interação\n");
	printf("5 - Sair\n\n");
	
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &option);
	
	while (option != 5) {
		system("cls");
		
		switch (option) {			
			case 1: 
				printf("cadastrar");
				break;
			case 2: 
				printf("Listar");
				break;
			case 3: 
				printf("Excluir");
				break;
			case 4: 
				interaction_menu();
				break;
			case 5:
				break;
			default:
			 	interaction_products();
				break;
		}
		
		getchar();
	}
	
	
}
