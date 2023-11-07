#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <math.h>


void interaction_financiamento() {
    int op;
    float juros = 0, juros_c = 0, saldo_devedor = 0, amortizacao = 0, valor_parcela = 0, valor_parcela_aux, tempo = 0, parcela = 0;
    Ficha_Tecnica_Imovel Info;
    system("cls");
    
    printf("----------------------------------------\n\n");
	printf("             FINANCIAMENTO\n\n");
	printf("----------------------------------------\n\n");
	
	printf("1 - Financiamento por Tabela SAC\n");
	printf("2 - Financiamento por Tabela Price\n");
	printf("3 - Voltar ao menu de interação\n\n");
		
	printf("Por favor, digite uma das opções para continuar: ");
	scanf("%i", &op);
    
    switch (op) {
    case 1:
    // SAC
		financiamentoSAC();
        return;

    case 2:
	//PRICE        
		financiamentoPrice();
        return;
    }

    return;
}

 void financiamentoSAC(){
 float juros = 0, juros_c = 0, saldo_devedor = 0, amortizacao = 0, valor_parcela = 0, valor_parcela_aux, tempo = 0, parcela = 0;
    Ficha_Tecnica_Imovel Info;
    system("cls");
    
    printf("----------------------------------------\n\n");
	printf("               TABELA SAC\n\n");
	printf("----------------------------------------\n\n");
    
    printf("Digite o valor do empréstimo: ");
            scanf("%f", &Info.valor_do_imovel);
            printf("Digite a taxa de juros (em percentual): ");
            scanf("%f", &juros);
            juros = juros / 100; 
            printf("Digite o prazo em meses: ");
            scanf("%f", &tempo);
            puts("\n\n");

            amortizacao = Info.valor_do_imovel / tempo;
            saldo_devedor = Info.valor_do_imovel;

            printf("Juros: %.2f\n", juros);
            printf("Amortizacao: %.2f\n", amortizacao);
            printf("Saldo devedor: %.2f\n\n", saldo_devedor);

            printf(":Mês\t:Amortizacao\t:Juros\t:Parcela\t:Saldo Devedor\n");

            for (int i = 1; i <= tempo; ++i) {
                juros_c = saldo_devedor * juros;
                amortizacao = Info.valor_do_imovel / tempo;
                saldo_devedor -= amortizacao;

                valor_parcela = amortizacao + juros_c;

                printf("%d\t%.2f\t\t%.2f\t%.2f\t%.2f\n", i, amortizacao, juros_c, valor_parcela, saldo_devedor);
            }
			
			printf("\nPressione qualquer tecla para prosseguir: ");
			getchar();
			
            return;
 } 
 
 void financiamentoPrice(){
 	float juros = 0, juros_c = 0, saldo_devedor = 0, amortizacao = 0, valor_parcela = 0, valor_parcela_aux, tempo = 0, parcela = 0;
    Ficha_Tecnica_Imovel Info;
    system("cls");
    
    printf("----------------------------------------\n\n");
	printf("             TABELA PRICE\n\n");
	printf("----------------------------------------\n\n");
    
 	printf("Digite o valor: ");
            scanf("%f", &Info.valor_do_imovel);
            printf("Digite o juros: ");
            scanf("%f", &juros);
            printf("Tempo em meses: ");
            scanf("%f", &tempo);
            puts("\n\n");

            juros = (juros / 100) + 1;

            saldo_devedor = Info.valor_do_imovel;
            valor_parcela = (pow(juros, tempo) - 1);
            valor_parcela_aux = pow(juros, tempo) * (juros - 1);
            valor_parcela = (valor_parcela_aux / valor_parcela) * Info.valor_do_imovel;
            juros = juros - 1;
            saldo_devedor = Info.valor_do_imovel;
            
            printf(":Mês:\t:Amortizacao:\t:Juros:\t\t:Parcela:\t:Saldo:\n");
            printf("%0.2f\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);

            while (parcela < tempo) {
                parcela = parcela + 1;
                juros_c = juros * saldo_devedor;
                amortizacao = valor_parcela - juros_c;
                saldo_devedor = saldo_devedor - amortizacao;
                printf("%0.2f\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\n", parcela, amortizacao, juros_c, valor_parcela, saldo_devedor);
            }
            
            printf("\nPressione qualquer tecla para prosseguir: ");
			getchar();

            return;
    }
 
