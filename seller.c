#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void interaction_seller() {
	int option = 0;
	
	while (option != 4) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("               VENDEDOR\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Cadastrar um vendedor\n");
		printf("2 - Listar um vendedor\n");
		printf("3 - Excluir um vendedor\n");
		printf("4 - Voltar ao menu de intera��o\n\n");
		
		printf("Por favor, digite uma das op��es para continuar: ");
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
