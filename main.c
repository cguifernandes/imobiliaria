#include <locale.h>
#include <stdio.h>

int menu() {
	int response = 0;

	printf("========================================\n\n");
	printf("Menu de interação\n\n");
	printf("========================================\n\n");
	
	printf("(1) - Produtos\n");
	printf("(2) - Vendedores\n");
	printf("(3) - Clients\n");
	printf("(4) - Sair\n\n");
	
	scanf("%i", &response);
	
	getchar();
	
	return response;
}

int seller() {
	return 1;
}

int products() {
	return 2;
}

int clients() {
	return 3;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int response = menu();
	
	while(response < 4) {
		system("cls");		
		response = menu();
		
		switch(response) {
			case 1:
				printf("1");
				break;
			case 2:
				printf("2");
				break;
			case 3:
				printf("3");
				break;
		}
		
	}
	
	
	return 0;
}
