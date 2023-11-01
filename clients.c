#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ARQ_CLIENTS "clients.txt"

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
				insert_clients ();
				return;
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

void insert_clients (){
	system("cls");
	clients ins;
	FILE *arq = fopen(ARQ_CLIENTS, "a+");
	
	printf("----------------------------------------\n\n");
	printf("         CADASTRAR CLIENTE\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira qual e o CPF (Identificador) do cliente: ");
	scanf("%i", &ins.id);
	
	printf("Insira o nome do cliente: ");
	scanf("%s", ins.nome);
	
	printf("Insira o endereco de recidencia do cliente: ");
	scanf("%s", ins.endereco);
	
	int exist = exist_register_clients(ARQ_CLIENTS, ins.id);
	
		if (exist == 1) {
		printf("\nEsse ID (Identificador) já está sendo usado.\n\n");
	}
	
	else {
		if (arq != NULL) {
			fprintf(arq, "%i %s %s\n", ins.id, ins.nome, ins.endereco); 
	    	printf("\nCadastro foi concluído ;)\n\n");
		} 
		else {
			printf("\nAlgo deu errado ;(\n\n");
		}
    	fclose(arq);
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();

}


