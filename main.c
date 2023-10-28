#include <locale.h>
#include <stdlib.h>
#include "functions.h"

void interaction_menu() {
	int option = 0;
	
	while (option != 4) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("           MENU DE INTERAÇÃO\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Produtos\n");
		printf("2 - Vendedores\n");
		printf("3 - Clients\n");
	//	printf("4 - Sobre a empresa\n");
		printf("4 - Sair\n\n");
		
		printf("Por favor, digite uma das opções para continuar: ");
		scanf("%i", &option);
		
		switch (option) {				
			case 1: 
				interaction_products();
				break;
			case 2: 
				interaction_seller();
				break;
			case 3: 
				interaction_clients();
				break;
			case 4:
				return;
			default:
				break;
		}
			
			getchar();
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	system("color 87");
	interaction_menu();
	
	return 0;
}
