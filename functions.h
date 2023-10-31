#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct{
	int id;
	int status;
	float valor;
	char endereco[101];
} products;

typedef struct{
	int id;
	char nome[101];
	float salario;
	int qtdVendas;
} seller;

void remove_seller();
void interaction_clients();
void interaction_products();
void interaction_seller();
void interaction_menu();
void insert_products();
void list_seller();
void list_products();
void insert_seller();
products search_products(char *arquivo, int id);
seller search_seller(char *arquivo, int id);
int exist_register_products(char *arquivo, int id);
int exist_register_seller(char *arquivo, int id);
void remove_products();
void remove(char *arquivo, int id);
void remove_seller(char *arquivo, int id);
#endif
