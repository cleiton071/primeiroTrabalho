#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// codigo feito por cleiton e rikelmy.
struct PAREDE{
	float altura;
	float largura;
	int qtdporta;
	int qtdjanela;
	
}parede;

struct COMODO{
	struct PAREDE paredes[4];
	
}comodo;

void clrscn (){
	system("@cls || clear");
}

bool calcula_area_permit (float altura, float largura){
	float area_par = altura * largura;
	
	if (area_par>=1 && area_par<=15){
		return true;
	}
	else{
		return false;
	}
}
bool ProporcaoArea (struct PAREDE parede){
	
	float area_parede = parede.altura * parede.largura;
	float area_portas = 1.52 * parede.qtdporta;
	float area_janelas = 2.40 * parede.qtdjanela; 
	
	if ((area_portas + area_janelas) > (area_parede / 2)){
		return false;
	}
	else
		return true;
}
bool AlturaPermit (struct PAREDE parede){
	
	if ((parede.qtdporta>=0 && (parede.altura - 0.30) >= 1.9) || parede.qtdporta == 0){
		return true;
	}
	
	return false;
}

void ConsumoTinta (struct COMODO comodo){
	float altura_total = comodo.paredes[0].altura + comodo.paredes[1].altura + comodo.paredes[2].altura + comodo.paredes[3].altura;
	float largura_total = comodo.paredes[0].largura + comodo.paredes[1].largura + comodo.paredes[2].largura + comodo.paredes[3].largura;
	float area_total = altura_total * largura_total;
	float area_portas = comodo.paredes[0].qtdporta + comodo.paredes[1].qtdporta + comodo.paredes[2].qtdporta + comodo.paredes[3].qtdporta;
	area_portas +=  area_portas * 1.52;
	
	float area_janelas = comodo.paredes[0].qtdjanela + comodo.paredes[1].qtdjanela + comodo.paredes[2].qtdjanela + comodo.paredes[3].qtdjanela;
	area_janelas += parede.qtdjanela * 2.40;
	area_total += area_total - (area_janelas + area_portas);
	
	float qtdlitros = 0;
	float qtdAtual = 0;
	float lata18, lata3_6, lata2_5, lata0_5 = 0;
	float Ltintas[4] = {18,3.6,2.5,0.5};
	
	qtdlitros = area_total / 5;
	qtdAtual = qtdlitros;
	
	while(qtdAtual>0){
		if (qtdAtual>=14.5){
			qtdAtual = qtdAtual - 18;
			lata18++;
		}
		else if (qtdAtual>=3.6 && qtdAtual<=14.4){
			qtdAtual = qtdAtual - 3.6;
			lata3_6++;
		}
		else if (qtdAtual>=2.5 && qtdAtual<=3.5){
			qtdAtual = qtdAtual - 2.5;
			lata2_5++;
		}
		else (qtdAtual>=0.1 && qtdAtual<=2.4);{
			qtdAtual = qtdAtual - 0.5;
			lata0_5++;
		}
	}
	
	printf("\n\narea total de paredes a ser pintada e de: %f",area_total);
	
	printf("\nquantidade de litros que sera gasto e de: %f",qtdlitros);
			
	printf("\nvoce precisa de %f latas de 18 litros",lata18);

	printf("\nvoce precisa de %f latas de 3,6 litros",lata3_6);
	
	printf("\nvoce precisa de %f latas de 2,5 litros",lata2_5);

	printf("\nvoce precisa de %f latas de 0,5 litros",lata0_5);
}

int main(){
	struct COMODO comodo;
	int inicio=0;
	
	while (inicio < 4) {
		printf("\nparede %d\n--------------------------", inicio+1);
		printf("\naltura: ");
		scanf("%f", &comodo.paredes[inicio].altura);
		
		printf("\nlargura: ");
		scanf("%f", &comodo.paredes[inicio].largura);
		
		printf("\nquantidade de portas: (0 caso nao houver).");
		scanf("%d", &comodo.paredes[inicio].qtdporta);
		
		printf("\nquantidade de janelas: (0 caso nao houver).");
		scanf("%d", &comodo.paredes[inicio].qtdjanela);
		
		if(calcula_area_permit(comodo.paredes[inicio].altura,comodo.paredes[inicio].largura)){
			if(ProporcaoArea(comodo.paredes[inicio]) == true);
				
			else{
				clrscn();
				printf("erro: a soma da area das portas e janelas nao pode ultrapassar 50%% da area da parede!\n\n");
			}
			if(AlturaPermit(comodo.paredes[inicio]) == true) {
				inicio++;	
			}
			else{
				clrscn();
				printf("a altura da parede atual deve ter pelo menos 30cm a mais que a porta!\n\n");
			}
		}
		
		else{
			clrscn();
			printf("erro, a area da parede tem que ser de 1 a 15 m2.\n\n");
		}
	}
	ConsumoTinta(comodo);
	return 0;
}
