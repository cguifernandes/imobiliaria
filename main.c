#include <locale.h>
#include <stdlib.h>
#include "functions.h"

void interaction_menu() {
	int option = 0;
	
	while (option != 5) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("           MENU DE INTERAÇÃO\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Imoveis    \n");
		printf("2 - Vendedores\n");
		printf("3 - Clients\n");
		printf("4 - Sobre a empresa\n");
		printf("5 - Sair\n\n");
		
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
				about();
				break;
			case 5:
				return;
			default:
				break;
		}
			
			getchar();
	}
}

void about() {
	system("cls");
	printf("----------------------------------------\n\n");
	printf("                 SOBRE\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Nome da empresa: Primeira Residência Imobiliária.\n");
	printf("CPNJ da empresa: 12.319.648/0001-20.\n");
	printf("Endereço atual: Rua das Flores, 123, Bairro dos Sonhos, São Paulo.\n");
	printf("CEP: 12042-618.\n");
	printf("Atual proprietário: Laura Mendes.\n\n");
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	system("color 87");
	interaction_menu();
	
	return 0;
}

