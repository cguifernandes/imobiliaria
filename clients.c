#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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
				printf("1");
				break;
			case 2: 
				printf("2");
				break;
			case 3: 
				printf("3");
				break;
			case 4: 
				return;
			default:
				break;
		}
	}
	
	getchar();
}
