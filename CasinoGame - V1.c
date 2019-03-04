/*-------------------------------------------------------------------------------------------------------
Objectivo: Registrar as jogadas de um jogador durante uma noite no casino
Autor: EdsonGreg�rio;
Ultima Edi��o: 21/05/2018;
--------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SENTINELA 0

/* Prototipo de Fun��es */
void calcular_lucro(int factor, int aposta, int *lucro, int *quantiaEmPosse);
void terminarJogo(int jogada, int quantiaEmPosse);

/* Defini��o de Fun��es */
void calcular_lucro(int factor, int aposta, int *lucro, int *quantiaEmPosse){
	*lucro = aposta * factor;
	*lucro -= aposta;
	*quantiaEmPosse += *lucro;
}

void terminarJogo(int jogada, int quantiaEmPosse){
	if(jogada > 0)
	{
		printf("\n\n\t------------------------------------------------------------------------------------\n");
		if(quantiaEmPosse < 0)
			printf("\tAp�s de uma sequ�ncia de %d jogadas o jogador teve uma perda de %d Kz.", jogada, -quantiaEmPosse);
		else
			printf("\tAp�s de uma sequ�ncia de %d jogadas o jogador teve  um ganho de %d Kz.", jogada, quantiaEmPosse);
		printf("\n\t------------------------------------------------------------------------------------\n\n\n");
	}
}


void main(){
	setlocale(LC_ALL, "Portuguese");
	int quantiaApostada, numeroApostado, numeroSorteado, jogada = 0, quantiaEmPosse = 0, lucro;

	printf("\n\t====================================================================================");
	printf("\n\t------------------------|       JOGO DO CASINO v1.0       |-------------------------");
	printf("\n\t------------------------| Desenvolvido por EDSON_GREG�RIO |-------------------------");
	printf("\n\t====================================================================================\n");

	do{
		FazerAposta:
		printf("\n\t>> Informe a quantia apostada, o N� Apostado e o N� sorteado: ");
		scanf("%d %d %d", &quantiaApostada, &numeroApostado, &numeroSorteado);

		if(quantiaApostada == SENTINELA && numeroApostado == SENTINELA && numeroSorteado == SENTINELA)
		{
			terminarJogo(jogada, quantiaEmPosse);
		}
		else
		{	//validacao da quantia e aposta
			if(quantiaApostada <= 0)
			{
				printf("\n\n\t\t ERRO: Quantia inv�lida!\n\n");
			    terminarJogo(jogada, quantiaEmPosse);
			    return;
			}
			else
				if(numeroApostado < 1 || numeroApostado > 38)
				{
					printf("\n\n\t\t ERRO: N�mero Apostado inv�lido!\n\n");
					terminarJogo(jogada, quantiaEmPosse);
			   		return;
				}
				else
					if(numeroSorteado < 1 || numeroSorteado > 38)
					{
						printf("\n\n\t\t ERRO: N�mero Sorteado inv�lido!\n\n");
						terminarJogo(jogada, quantiaEmPosse);
			   			return;
					}

			lucro = 0;
			jogada++;
			printf("\t------------------------------------------------------------------------------------");
			printf("\n\tJOGADA %d",jogada);
			printf("\n\tQuantia apostada: %d Kz", quantiaApostada);
			printf("\n\tN�mero apostado: %d", numeroApostado);
			printf("\n\tN�mero sorteado: %d", numeroSorteado);

			if(numeroApostado == numeroSorteado)
			{         //REGRA1: numeros iguais
				calcular_lucro(5, quantiaApostada, &lucro, &quantiaEmPosse);
				printf("\n\tJogador acertou o n�mero sorteado : lucrou %d Kz", lucro);
			}
			else
				if((numeroApostado / 10) == (numeroSorteado / 10))
				{          //Regra2: dezenas iguais
					calcular_lucro(3, quantiaApostada, &lucro,  &quantiaEmPosse);
					printf("\n\tJogador acertou a dezena do n�mero sorteado : lucrou %d Kz", lucro);
				}
				else
					if(numeroApostado == (numeroSorteado % 10 + numeroSorteado / 10))
					{          //Regra3: soma dos digitos do sorteado
						calcular_lucro(2, quantiaApostada, &lucro,  &quantiaEmPosse);
						printf("\n\tJogador acertou a soma dos d�gitos do n�mero  sorteado : lucrou %d Kz", lucro);
					}
					else
						if((numeroApostado % 2) == (numeroSorteado % 2))           //Regra4: paridades iguais
							printf("\n\tJogador acertou a paridade do n�mero sorteado : n�o lucrou, nem perdeu.");
						else
						{
							quantiaEmPosse -= quantiaApostada;
							printf("\n\tJogador n�o acertou nada : perdeu %d Kz", quantiaApostada);
						}

			if(quantiaEmPosse < 0)
				printf("\n\tAt� agora o jogador teve uma perda de %d Kz", -quantiaEmPosse); //se a quantia for negativa ent�o houve perda
			else
				if(quantiaEmPosse > 0)
					printf("\n\tAt� agora o jogador teve um ganho de %d Kz", quantiaEmPosse); //se for positiva houve ganho
				else
					printf("\n\tAt� agora o jogador n�o perdeu, nem ganhou nada!");
			printf("\n\t------------------------------------------------------------------------------------\n\n");
		}
	}while(quantiaApostada != SENTINELA && numeroApostado != SENTINELA && numeroSorteado != SENTINELA);

	printf("\n\n\t\tT E R M I N A N D O. . .\n\n\n");
	system ("PAUSE");
	return 0;
}
