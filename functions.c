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
