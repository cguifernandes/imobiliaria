#include <stdio.h>
#include "functions.h"

void clients() {
	int option = 0;
	
	printf("----------------------------------------\n\n");
	printf("CLIENTE\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Cadastrar um cliente\n");
	printf("2 - Listar um cliente\n");
	printf("3 - Excluir um cliente\n");
	printf("4 - Sair\n\n");
	
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &option);
	
	getchar();
}
