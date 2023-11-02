#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ARQ_SELLER "seller.txt"

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
		printf("4 - Voltar ao menu de interação\n\n");
		
		printf("Por favor, digite uma das opções para continuar: ");
		scanf("%i", &option);
	
		switch (option) {	
					
			case 1: 
				insert_seller();
				return;
			case 2: 
				list_seller();
				return;
			case 3: 
				remove_seller();
				return;
			case 4: 
				return;
			default:
				break;
		}
	}
	
	getchar();
}

void insert_seller() {
	system("cls");
	seller cads;
	FILE *arq = fopen(ARQ_SELLER, "a+");
	
	printf("----------------------------------------\n\n");
	printf("         CADASTRAR VENDEDOR\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira qual será o ID (Identificador) do Vendedor: ");
	scanf("%i", &cads.id);
	
	printf("Insira o nome do vendedor: ");
	scanf("%s", cads.nome);
	
	printf("Insira qual é o salário do vendedor: ");
	scanf("%f", &cads.salario);
	
	printf("Insira a quantidade de vendas do vendedor: ");
	scanf("%i", &cads.qtdVendas);
	
	int exist = exist_register_seller(ARQ_SELLER, cads.id);
	
		if (exist == 1) {
		printf("\nEsse ID (Identificador) já está sendo usado.\n\n");
	}
	
	else {
		if (arq != NULL) {
			fprintf(arq, "%i %s %.2f %i\n", cads.id, cads.nome, cads.salario, cads.qtdVendas); 
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

void list_seller() {
	system("cls");
	seller cads;
	
	printf("----------------------------------------\n\n");
	printf("          LISTAR VENDEDORES\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do vendedor: ");
	scanf("%i", &cads.id);
	
	seller vendedor = search_seller(ARQ_SELLER, cads.id);   
	
	if (vendedor.id != -1) {
		printf("\nVendedor encontrado. :)\n\n");
		printf("ID (Identificador) do vendedor: %i\n", vendedor.id);
		
		printf("Nome do vendedor(a): %s\n", vendedor.nome);
		
		printf("O salário do vendedor(a): %.2f\n", vendedor.salario);
		
		printf("A quantidade de vendas do vendedor(a): %i\n\n", vendedor.qtdVendas);
		
    } else {
        printf("\nVendedor não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

void remove_seller() {
	system("cls");
	seller cads;
	char status[7];
	int option;
	
	printf("----------------------------------------\n\n");
	printf("         EXCLUIR VENDEDORES\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do vendedor: ");
	scanf("%i", &cads.id);
	
	seller vendedor = search_seller(ARQ_SELLER, cads.id);
	
	if (vendedor.id != -1) {
		printf("\nVendedor encontrado. :)\n\n");
		printf("ID (Identificador) do vendedor: %i\n", vendedor.id);
		
		printf("Nome do vendedor(a): %s\n", vendedor.nome);
		
		printf("O salário do vendedor(a): %.2f\n", vendedor.salario);
		
		printf("A quantidade de vendas do vendedor(a): %i\n\n", vendedor.qtdVendas);
		
		printf("Tem certeza que deseja excluir esse vendedor? (1 - Sim, 2 - Não): ");
		scanf("%i", &option);

		while (option != 2) {
		    if (option == 1) {
		        del_seller(ARQ_SELLER, cads.id);
		        printf("\nO Vendedor com o ID %i foi excluído\n\n", cads.id);
		        break;
		    }
		    else if (option == 2) {
		        break;
		    }
		    else {
		        printf("\nOpção inválida\n\n");
		        break;
		    }
		}
    } else {
        printf("\nVendedor não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}
