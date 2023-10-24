#include <stdio.h>
#include "functions.h"

void products() {
	int option = 0;
	
	printf("----------------------------------------\n\n");
	printf("PRODUTOS\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Cadastrar um produtos\n");
	printf("2 - Listar um produtos\n");
	printf("3 - Excluir um produto\n");
	printf("4 - Sair\n\n");
	
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &option);
	
	getchar();
}
