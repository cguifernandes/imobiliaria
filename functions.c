#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int exist_register_products(char *arquivo, int id) {
	FILE *arq = fopen(arquivo, "r");
	products tmp;
	
	while (!feof(arq)) {
		fscanf(arq,"%i %i %f %s\n", &tmp.id, &tmp.status, &tmp.valor, tmp.endereco);
		
		if (tmp.id == id) {
			fclose(arq);
			return 1;
		}
		else {
			fclose(arq);
			return 0;
		}
	}
}

int exist_register_seller(char *arquivo, int id) {
	FILE *arq = fopen(arquivo, "r");
	seller tmp;
	
	while (!feof(arq)) {
		fscanf(arq,"%i %i %f %s\n", &tmp.id, &tmp.qtdVendas, &tmp.salario, tmp.nome);
		
		if (tmp.id == id) {
			fclose(arq);
			return 1;
		}
		else {
			fclose(arq);
			return 0;
		}
	}
}

int exist_register_clients(char *arquivo, int id) {
	FILE *arq = fopen(arquivo, "r");
	clients tmp;
	
	while (!feof(arq)) {
		fscanf(arq,"%i %s %s\n", &tmp.id, tmp.nome, tmp.endereco);
		if (tmp.id == id) {
			fclose(arq);
			return 1;
		}
		else {
			fclose(arq);
			return 0;
		}
	}
}

products search_products(char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "r");
    products tmp;
    
   	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.endereco, &tmp.valor, &tmp.status);
        if (tmp.id == id) {
        	fclose(arq);
            return tmp; 
        }
        else {
        	tmp.id = -1;
		}
    }

    fclose(arq);
    return tmp; 
}

seller search_seller(char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "r");
    seller tmp;
    
   	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.nome, &tmp.salario, &tmp.qtdVendas);
    	
        if (tmp.id == id) {
        	fclose(arq);
            return tmp; 
        }
        else {
        	tmp.id = -1;
		}
    }

    fclose(arq);
    return tmp; 
}

clients search_clients(char *arquivo, int id) {
    FILE *arq = fopen(arquivo, "r");
    clients tmp;
    
   	while (!feof(arq)) {
    	fscanf(arq, "%i %s %s", &tmp.id, tmp.nome, tmp.endereco);
    	
        if (tmp.id == id) {
        	fclose(arq);
            return tmp; 
        }
        else {
        	tmp.id = -1;
		}
    }

    fclose(arq);
    return tmp; 
}

void del_products(char *arquivo, int id) {
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

void del_clients(char *arquivo, int id) {
	clients tmp;
	FILE *arq = fopen(arquivo, "r");
	FILE *arq_temp = fopen("temp.txt", "w");
	
	while (!feof(arq)) {
    	fscanf(arq, "%i %s %s", &tmp.id, tmp.nome, tmp.endereco);
    	
    	if (tmp.id != id) {
    		fprintf(arq_temp, "%i %s %s\n", tmp.id, tmp.nome, tmp.endereco);
		}
    }
    
    fclose(arq);
    fclose(arq_temp);
    
	system("del clients.txt");
	system("rename temp.txt clients.txt");
}

void del_seller(char *arquivo, int id) {
	seller tmp;
	FILE *arq = fopen(arquivo, "r");
	FILE *arq_temp = fopen("temp.txt", "w");
	
	while (!feof(arq)) {
    	fscanf(arq, "%i %s %f %i", &tmp.id, tmp.nome, &tmp.salario, &tmp.qtdVendas);
    	
    	if (tmp.id != id) {
    		fprintf(arq_temp, "%i %s %.2f %i\n", tmp.id, tmp.nome, tmp.salario, tmp.qtdVendas);
		}
    }
    
    fclose(arq);
    fclose(arq_temp);
    
	system("del seller.txt");
	system("rename temp.txt seller.txt");
}
