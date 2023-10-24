#include <locale.h>
#include <stdlib.h>
#include "functions.h"

int menu() {
	int option = 0;

	printf("----------------------------------------\n\n");
	printf("MENU DE INTERAÇÃO\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Produtos\n");
	printf("2 - Vendedores\n");
	printf("3 - Clients\n");
	printf("4 - Sair\n\n");
	
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &option);
	
	getchar();
	
	return option;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int option = menu();
	
	while (option != 4) {
		system("cls");
		
		if (option == 1) {
			products();
			break;
		}
		
		else if (option == 2) {
			seller();
			break;
		}
		
		else if (option == 3) {
			clients();
			break;
		} 
		
		else {
			break;
		}
	}
	
	
	
	return 0;
}
