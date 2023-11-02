#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ARQ_SELLER "seller.txt"

void interaction_seller() {
	int option = 0;
	
	while (option != 5) {
		system("cls");
		printf("----------------------------------------\n\n");
		printf("               VENDEDOR\n\n");
		printf("----------------------------------------\n\n");
		
		printf("1 - Cadastrar um(a) vendedor(a)\n");
		printf("2 - Listar um(a) vendedor(a)\n");
		printf("3 - Alterar cadastro de um(a) vendedor(a)\n");
		printf("4 - Excluir cadastro um(a) vendedor(a)\n");
		printf("5 - Voltar ao menu de interação\n\n");
		
		printf("Por favor, digite uma das opções para continuar: ");
		scanf("%i", &option);
	
		switch (option) {		
			case 1: 
				insert_seller();
				break;
			case 2: 
				list_seller();
				break;
			case 3: 
				update_seller();
				break;
			case 4: 
				remove_seller();
				break;
			case 5: 
				return;
			default:
				break;
		}
		
		getchar();
	}
}

void insert_seller() {
	system("cls");
	seller rgs;
	FILE *arq = fopen(ARQ_SELLER, "a+");
	
	printf("----------------------------------------\n\n");
	printf("         CADASTRAR VENDEDOR\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira um ID (Identificador) ao vendedor(a): ");
	scanf("%i", &rgs.id);
	
	printf("Insira o nome do(a) vendedor(a): ");
	scanf("%s", rgs.nome);
	
	printf("Insira qual o salário do(a) vendedor(a): ");
	scanf("%f", &rgs.salario);
	
	printf("Insira a quantidade de vendas do(a) vendedor(a) desse mês: ");
	scanf("%i", &rgs.qtdVendas);
	
	int exist = exist_register_seller(ARQ_SELLER, rgs.id);
	
	if (exist == 1) {
		printf("\nEsse ID (Identificador) já está sendo usado.\n\n");
	}
	
	else {
		if (arq != NULL) {
			fprintf(arq, "%i %s %.2f %i\n", rgs.id, rgs.nome, rgs.salario, rgs.qtdVendas); 
	    	printf("\nCadastro foi concluído ;)\n\n");
				
		} 
		else {
			printf("\nAlgo deu errado ;(\n\n");
		}
	}

	fclose(arq);
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();

}

void list_seller() {
	system("cls");
	seller rgs;
	
	printf("----------------------------------------\n\n");
	printf("            LISTAR VENDEDORES           \n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do(a) vendedor: ");
	scanf("%i", &rgs.id);
	
	seller vendedor = search_seller(ARQ_SELLER, rgs.id);   
	
	if (vendedor.id != -1) {
		printf("\nVendedor(a) encontrado. :)\n\n");
		printf("ID (Identificador) do(a) vendedor(a): %i\n", vendedor.id);
		
		printf("Nome do(a) vendedor(a): %s\n", vendedor.nome);
		
		printf("Salário do(a) vendedor(a): %.2f\n", vendedor.salario);
		
		printf("A quantidade de vendas do(a) vendedor(a): %i\n\n", vendedor.qtdVendas);
		
    } else {
        printf("\nVendedor(a) não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

void remove_seller() {
	system("cls");
	seller rgs;
	int option;
	
	printf("----------------------------------------\n\n");
	printf("         EXCLUIR VENDEDORES\n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do(a) vendedor(a): ");
	scanf("%i", &rgs.id);
	
	seller vendedor = search_seller(ARQ_SELLER, rgs.id);
	
	if (vendedor.id != -1) {
		printf("ID (Identificador) do(a) vendedor(a): %i\n", vendedor.id);
		
		printf("Nome do(a) vendedor(a): %s\n", vendedor.nome);
		
		printf("O salário do(a) vendedor(a): %.2f\n", vendedor.salario);
		
		printf("Quantidade de vendas do(a) vendedor(a): %i\n\n", vendedor.qtdVendas);
		
		printf("Tem certeza que deseja excluir esse cadastro? (1 - Sim, 2 - Não): ");
		scanf("%i", &option);

		while (option != 2) {
		    if (option == 1) {
		        del_seller(ARQ_SELLER, rgs.id);
		        printf("\nO cadastro do(a) Vendedor(a) com o ID %i foi excluído\n\n", rgs.id);
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
        printf("\nVendedor(a) não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}

void update_seller() {
	system("cls");
	seller rgs, novo;
	
	printf("----------------------------------------\n\n");
	printf("           ALTERAR VENDEDORES           \n\n");
	printf("----------------------------------------\n\n");
	
	printf("Insira o ID (Identificador) do produto: ");
	scanf("%i", &rgs.id);
	
	seller vendedor = search_seller(ARQ_SELLER, rgs.id);
	
	if (vendedor.id != -1) {
		printf("\nID (Identificador) do(a) vendedor(a): %i\n", vendedor.id);
		
		printf("Nome do(a) vendedor(a): %s\n", vendedor.nome);
		
		printf("O salário do(a) vendedor(a): %.2f\n", vendedor.salario);
		
		printf("Quantidade de vendas do(a) vendedor(a): %i\n\n", vendedor.qtdVendas);
		
		printf("Novo cadastro\n\n");

		printf("Insira o novo nome do(a) vendedor(a): ");
		scanf("%s", novo.nome);
		
		printf("Insira o novo salário do(a) vendedor(a): ");
		scanf("%f", &novo.salario);

		printf("Insira a nova quantidade de vendas do(a) vendedor(a): ");
		scanf("%i", &novo.qtdVendas);
		
		del_seller(ARQ_SELLER, vendedor.id);
		
		FILE *arq = fopen(ARQ_SELLER, "a+");
		fprintf(arq, "%i %s %.2f %i\n", rgs.id, novo.nome, novo.salario, novo.qtdVendas);
	    printf("Novo cadastro foi concluído ;)\n\n");
	    fclose(arq);
    } else {
		printf("\Vendedor(a) não encontrado. ;(\n\n");
	}
	
	printf("Pressione qualquer tecla para prosseguir: ");
	getchar();
}
