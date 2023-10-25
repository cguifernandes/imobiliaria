#include <locale.h>
#include <stdlib.h>
#include "functions.h"

void interaction_menu() {
	int option;

	printf("----------------------------------------\n\n");
	printf("MENU DE INTERAÇÃO\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Produtos\n");
	printf("2 - Vendedores\n");
	printf("3 - Clients\n");
	printf("4 - Sair\n\n");
	
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &option);
	
	while (option != 4) {
		system("cls");
		
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
				break;
			default:
				interaction_menu();
				break;
		}
		
		getchar();
	}
	
	
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	interaction_menu();
	
	return 0;
}
