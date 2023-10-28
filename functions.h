#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct{
	int id;
	int status;
	float valor;
	char endereco[101];
} products;

void interaction_clients();
void interaction_products();
void interaction_seller();
void interaction_menu();
void insert_products();
void list_products();
products search_products(char *arquivo, int id);
char insert();
int exist_register_products(char *arquivo, int id);

#endif
