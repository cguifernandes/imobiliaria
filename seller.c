#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void interaction_seller() {
	int option;
	
	printf("----------------------------------------\n\n");
	printf("VENDEDOR\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Cadastrar um vendedor\n");
	printf("2 - Listar um vendedor\n");
	printf("3 - Excluir um vendedor\n");
	printf("4 - Voltar ao menu de interação\n");
	printf("5 - Sair\n\n");
	
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &option);
	
	while (option != 5) {
		system("cls");
		
		switch (option) {			
			case 1: 
				printf("1");
				break;
			case 2: 
				printf("2");
				break;
			case 3: 
				printf("3");
				break;
			case 4: 
				interaction_menu();
				break;
			case 5:
				break;
			default:
			 	interaction_seller();
				break;
		}
	}
	
	getchar();
}
