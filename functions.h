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

typedef struct{
	float valor_do_imovel;
}Ficha_Tecnica_Imovel;


void interaction_clients();
void interaction_products();
void interaction_seller();
void interaction_menu();
void interaction_financiamento();

void insert_products();
void insert_clients();
void insert_seller();

void list_seller();
void list_products();
void list_clients();

void financiamentoPrice();
void financiamentoSAC();

products search_products(char *arquivo, int id);
seller search_seller(char *arquivo, int id);
clients search_clients(char *arquivo, int id);

int exist_register_products(char *arquivo, int id);
int exist_register_seller(char *arquivo, int id);
int exist_register_clients(char *arquivo, int id);

void del_products(char *arquivo, int id);
void del_clients(char *arquivo, int id);
void del_seller(char *arquivo, int id);

void remove_products();
void remove_clients();
void remove_seller();

void update_products();
void update_clients();
void update_seller();

void about();


#endif
