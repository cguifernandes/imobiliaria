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

typedef struct{
	int id;
	char nome[101];
	char endereco[101];
} clients;

void remove_seller();
void interaction_clients();
void interaction_products();
void interaction_seller();
void interaction_menu();
void insert_products();
void insert_clients ();
void list_seller();
void list_products();
void list_clients();
void insert_seller();
products search_products(char *arquivo, int id);
seller search_seller(char *arquivo, int id);
clients search_clients(char *arquivo, int id);
int exist_register_products(char *arquivo, int id);
int exist_register_seller(char *arquivo, int id);
int exist_register_clients(char *arquivo, int id);
void remove_products();
void remove(char *arquivo, int id);
//<<<<<<< HEAD
void about();

//=======
void remove_seller(char *arquivo, int id);
//>>>>>>> 2c27ffa189c514e86277d3072ed066b5eeb0f405
#endif
