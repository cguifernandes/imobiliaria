#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void interaction_menu() {
	int option = 0;
	
	while (option != 6) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("           MENU DE INTERA��O\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Im�veis\n");
		printf("2 - Vendedores\n");
		printf("3 - Clientes\n");
		printf("4 - Financiamentos\n");
		printf("5 - Sobre a empresa\n");
		printf("6 - Sair\n\n");
		
		printf("Por favor, digite uma das op��es para continuar: ");
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
				interaction_financiamento();
				break;
			case 5:
				about();
				break;
			case 6:
				return;
			default:
				break;
		}
			
		getchar();
	}
}

void about() {
	int option;
	char url[] = "https://termos-imobiliaria.vercel.app/";
	
	system("cls");
	printf("----------------------------------------\n\n");
	printf("                 SOBRE\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Nome da empresa: Primeira Resid�ncia Imobili�ria.\n");
	printf("CPNJ da empresa: 12.319.648/0001-20.\n");
	printf("Endere�o atual: Rua das Flores, 123, Bairro dos Sonhos, S�o Paulo.\n");
	printf("CEP: 12042-618.\n");
	printf("Atual propriet�rio: Laura Mendes.\n\n");
	
	printf("Deseja visitar o site com os termos e condi��es da empresa? (1 - Sim, 2 - N�o): ");
	scanf("%i", &option);
	
	while (option != 2) {
		    if (option == 1) {
		    	char command[256];
		        snprintf(command, sizeof(command), "start %s", url);
    			system(command);
		        break;
		    }
		    else if (option == 2) {
		        break;
		    }
		    else {
		        printf("\nOp��o inv�lida\n\n");
		        break;
		    }
		}
	
	printf("\nPressione qualquer tecla para prosseguir: ");
	getchar();
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	system("color 87");
	interaction_menu();
	
	return 0;
}

