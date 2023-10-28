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
