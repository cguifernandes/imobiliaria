#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int exist_register_products(char *arquivo, int id) {
	FILE *arq = fopen(arquivo, "r");
	products tmp;
	
	while (!feof(arq)) {
		fscanf(arq,"%i %i %f %s\n", &tmp.id, &tmp.status, &tmp.valor, &tmp.endereco);
		if (tmp.id == id) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	fclose(arq);
}

products search_products(char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "r");
    products tmp;
    
   	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.endereco, &tmp.valor, &tmp.status);
        if (tmp.id == id) {
            return tmp; 
        }
        else {
        	tmp.id = -1;
		}
    }

    fclose(arq);
    return tmp; 
}

void remove(char *arquivo, int id) {
	products tmp;
	FILE *arq = fopen(arquivo, "r");
	FILE *arq_temp = fopen("temp.txt", "w");
	
	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.endereco, &tmp.valor, &tmp.status);
    	
    	if (tmp.id != id) {
    		fprintf(arq_temp, "%i %s %.2f %i\n", tmp.id, tmp.endereco, tmp.valor, tmp.status); 
		}
    }
    
    fclose(arq);
    fclose(arq_temp);
    
    system("del products.txt");
	system("rename temp.txt products.txt");
}

int exist_register_seller(char *arquivo, int id) {
	FILE *arq = fopen(arquivo, "r");
	seller tmp;
	
	while (!feof(arq)) {
		fscanf(arq,"%i %i %f %s\n", &tmp.id, &tmp.qtdVendas, &tmp.salario, &tmp.nome);
		if (tmp.id == id) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	fclose(arq);
}

seller search_seller(char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "r");
    seller tmp;
    
   	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.nome, &tmp.salario, &tmp.qtdVendas);
        if (tmp.id == id) {
            return tmp; 
        }
        else {
        	tmp.id = -1;
		}
    }

    fclose(arq);
    return tmp; 
}

void remove_seller(char *arquivo, int id) {
	seller tmp;
	FILE *arq = fopen(arquivo, "r");
	FILE *arq_teste = fopen("teste.txt", "w");
	
	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.nome, &tmp.salario, &tmp.qtdVendas);
    	
    	if (tmp.id != id) {
    		fprintf(arq_teste, "%i %s %.2f %i \n", tmp.id, tmp.nome, tmp.salario, tmp.qtdVendas); 
		}
    }
    
    fclose(arq);
    fclose(arq_teste);
    
    system("del seller.txt");
	system("rename teste.txt seller.txt");
}
//
int exist_register_clients(char *arquivo, int id) {
	FILE *arq = fopen(arquivo, "r");
	clients tmp;
	
	while (!feof(arq)) {
		fscanf(arq,"%i %s %s\n", &tmp.id, &tmp.nome, &tmp.endereco);
		if (tmp.id == id) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	fclose(arq);
}

clients search_clients(char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "r");
     clients tmp;
    
   	while (!feof(arq)) {
    	fscanf(arq, "%i %s %s", &tmp.id, tmp.nome, &tmp.endereco);
        if (tmp.id == id) {
            return tmp; 
        }
        else {
        	tmp.id = -1;
		}
    }

    fclose(arq);
    return tmp; 
}

