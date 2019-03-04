/*-------------------------------------------------------------------------------------------------------
	Autor: EdsonGreg�rio - 1000020973
	Data: 13/06/2018;
--------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SENTINELA 0
#define VERDADEIRO 1
#define FALSO 2

/*-------------------------------------------------------------------------------------------------------
	Prot�tipo de Fun��es
--------------------------------------------------------------------------------------------------------*/
int lerNumDeJogadas();
int lerNumero();
int Fatorial(int x);
int floor(double x);
int validarAposta(int quantia, int numApostado);
double ConverterParaReal(int numero_Int);
double Potencia(double base, int expoente);
double valorAbsoluto(double x);
double Seno(double x);
double Coseno(double x);
void terminarJogo(int jogada, int quantiaEmPosse);

/*-------------------------------------------------------------------------------------------------------
Objectivo: Ler o numero de Jogadas a registar                       Recebe: Nada
Retorna: O n�mero de jogadas lido                                   Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
int lerNumDeJogadas(){
	int jogadas = 0;
	printf("\n\t>> Entre com o n�mero de jogadas: ");
	scanf("%d", &jogadas);
	if(jogadas > 0)
		return jogadas;
	else{
		printf("\n\tERRO: N�mero de jogadas inv�lido!");
		return 0;
	}
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Ler um numero inteiro com pelo menos 5 digitos              Recebe: Nada
Retorna: O n�mero de inteiro lido                                      Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
int lerNumero(){
	int numero;
	printf("\n\t>> Digite um n�mero inteiro de pelo menos 5 d�gitos: ");
	scanf("%d", &numero);
	return numero;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Converter um numero inteiro em um real               Recebe: Um numero inteiro
Retorna: Um real menor que 1 e maior que 0                      Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
double ConverterParaReal(int numero_Int){ 
	int contAlgarismos = 1, numero_Real = numero_Int;
	while(numero_Real >= 1.0)
	{
		numero_Real /= 10.0;
		contAlgarismos *= 10;
	}
	return numero_Int / contAlgarismos; 
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Calcular o fatorial de um numero               Recebe: Um numero inteiro
Retorna: O fatorial do numero                             Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
int Fatorial(int x){
	int n;
	double fatorial = 1;
    for(n = 1; n <= x; n++) 
        fatorial *= n;
    return fatorial;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Calcular o valor de uma potencia                Recebe: A base e o expoente
Retorna: o valor de base elevado ao expoente (potencia)               Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
double Potencia(double base, int expoente){
	double potencia = 1.0;		
	int n; 
	if(expoente != 0) 	
   		for (n = 1; n <= expoente; n++)
		    potencia *= base;	    
	return potencia;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Calcular o valor absoluto de um numero             Recebe: Um numero real
Retorna: o valor absoluto                                     Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
double valorAbsoluto(double x){
	if(x < 0)
		return -x;
	else
		return x;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Calcular o maior inteiro menor que um determinado real          Recebe: Um numero real
Retorna: ultimo inteiro menor que o real                                   Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
int floor(double x){
	int y = (int) x;
	return y;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Calcular o seno de um numero pela serie de Mclaurin             Recebe: Um numero real
Retorna: seno do numero real                                               Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
double Seno(double x){  
   int k;
   double senoX = 0;
   for(k = 0; k <= 100 ; k++)
      senoX += Potencia(-1, k) * Potencia(x, 2*k + 1) / Fatorial(2*k + 1); 
   return senoX;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Calcular o coseno de um numero pela serie de Mclaurin             Recebe: Um numero real
Retorna: coseno do numero real                                               Tipo: FUN��O
--------------------------------------------------------------------------------------------------------*/
double Coseno(double x){ 
   int k;
   double cosenoX = 0;
   for(k = 0; k <= 100 ; k++)
    	cosenoX += Potencia(-1, k) * Potencia(x, 2*k) / Fatorial(2*k); 
   return cosenoX;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Imprimir o numero de jogadas processadas e o lucro do jogador             Tipo: Procedimento
Retorna: Nada          Recebe: numero de jogadas e quantia em posse                                                          
--------------------------------------------------------------------------------------------------------*/
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
/*-------------------------------------------------------------------------------------------------------
Objectivo: Ler e validar a o n�mero e a quantia da aposta               Recebe: Nada 
Devolve: Quantia Apostada e Numero apostado                             Tipo: Fun��o
Retorna: Verdadeiro (aposta v�lida) ou Falso (aposta inv�lida)                                                               
--------------------------------------------------------------------------------------------------------*/
int fazerAposta(int *quantiaApostada, int *numeroApostado){	
	int quantia, numApostado;
	printf("\n\t>> Informe a quantia apostada e o N� Apostado ( de 1 a 38): "); 
	scanf("%d %d", &quantia, &numApostado);
	
	if(quantia == SENTINELA && numApostado == SENTINELA)
		return SENTINELA;
	else
		if(quantia <= 0)
		{
			printf("\n\n\t\t ERRO: Quantia inv�lida!\n\n"); 
			return FALSO;
		}
		else		
			if(numApostado < 1 || numApostado > 38)
			{
				printf("\n\n\t\t ERRO: N�mero Apostado inv�lido!\n\n"); 
				return FALSO;
			}	
			else
			{
				*quantiaApostada = quantia;
				*numeroApostado = numApostado;
				return VERDADEIRO;
			}
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Gerar um numero aleatorio de 1 a 38       Devolve: Valor de Y atualizado                                            
Retorna: Um inteiro no intervalo [1 ; 38]       Recebe: um numero real    Tipo: Fun��o                                            
--------------------------------------------------------------------------------------------------------*/
int gerarSorteado(double *Y){
	double X;
	X = 9821.0 + valorAbsoluto(Coseno(*Y)) + 0.211327;	
	*Y = X - floor(X);
	return *Y * 38 + 1;
}

/*-------------------------------------------------------------------------------------------------------
Objectivo: verificar se o jogador acertou o numero sorteado       Devolve: o lucro e a quantia em posse                                           
Retorna: Nada       Recebe: a quantia apostada, numero sorteado e numero apostado    Tipo: Procedimento                                            
--------------------------------------------------------------------------------------------------------*/
void  verificaJogada(int quantiaApostada, int numeroSorteado, int numeroApostado, int *lucro, int *quantiaEmPosse)
{	 
	if(numeroApostado == numeroSorteado)  //REGRA1: numeros iguais
	{ 
		*lucro = quantiaApostada * 5, *lucro -= quantiaApostada , *quantiaEmPosse += *lucro;
		printf("\n\tJogador acertou o n�mero sorteado : lucrou %d Kz", *lucro);
	}
	else 
		if((numeroApostado / 10) == (numeroSorteado / 10))    //Regra2: dezenas iguais
		{  										
			*lucro = quantiaApostada * 3, *lucro -= quantiaApostada , *quantiaEmPosse += *lucro;
			printf("\n\tJogador acertou a dezena do n�mero sorteado : lucrou %d Kz", *lucro);
		}
		else 
			if(numeroApostado == (numeroSorteado % 10 + numeroSorteado / 10))   //Regra3: soma dos digitos do sorteado
			{  
				*lucro = quantiaApostada * 2, *lucro -= quantiaApostada , *quantiaEmPosse += *lucro;
				printf("\n\tJogador acertou a soma dos d�gitos do n�mero  sorteado : lucrou %d Kz", *lucro);
			}
			else
				if((numeroApostado % 2) == (numeroSorteado % 2))  //Regra4: paridades iguais
					printf("\n\tJogador acertou a paridade do n�mero sorteado : n�o lucrou, nem perdeu.");
				else
				{
					*quantiaEmPosse -= quantiaApostada; 
					printf("\n\tJogador n�o acertou nada : perdeu %d Kz", quantiaApostada);
				}			
}

/*-------------------------------------------------------------------------------------------------------
	Fun��o principal
--------------------------------------------------------------------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	printf("\n\t====================================================================================");
	printf("\n\t------------------------|       JOGO DO CASINO v2.0       |-------------------------");
	printf("\n\t------------------------| Desenvolvido por EDSON_GREG�RIO |-------------------------");
	printf("\n\t====================================================================================\n");
	
	int numeroDeJogadas, quantiaApostada, numeroApostado, numeroSorteado, contJogadas, lucro, quantiaEmPosse = 0;
	double Y;
	
	numeroDeJogadas = lerNumDeJogadas();
	
	if(numeroDeJogadas != 0)
	{
		Y =	ConverterParaReal(lerNumero()); 
		
		for(contJogadas = 1; contJogadas < numeroDeJogadas; contJogadas++) 
		{
			int verificarAposta = fazerAposta(&quantiaApostada, &numeroApostado);
			
			if (verificarAposta == VERDADEIRO)
			{
				numeroSorteado = gerarSorteado(&Y);
				lucro = 0;
				printf("\t------------------------------------------------------------------------------------\n");
				printf("\n\tJOGADA %d", contJogadas);
				printf("\n\tQuantia apostada: %d Kz", quantiaApostada);
				printf("\n\tN�mero apostado: %d", numeroApostado);
				printf("\n\tN�mero sorteado: %d", numeroSorteado);
				
				verificaJogada(quantiaApostada, numeroSorteado, numeroApostado, &lucro, &quantiaEmPosse);
		
				if(quantiaEmPosse < 0)
					printf("\n\tAt� agora o jogador teve uma perda de %d Kz", -quantiaEmPosse); 
				else
					if(quantiaEmPosse > 0)
						printf("\n\tAt� agora o jogador teve um ganho de %d Kz", quantiaEmPosse);
					else
						printf("\n\tAt� agora o jogador n�o perdeu, nem ganhou nada!");
				printf("\n\t------------------------------------------------------------------------------------\n\n\n");
			}
			else
				if(verificarAposta == FALSO)
					contJogadas--;
				else
				{
					terminarJogo(contJogadas-1, quantiaEmPosse);
					printf("\n\n\t\tT E R M I N A N D O. . .\n\n\n");
					return 0;	
				}		
		}
		terminarJogo(contJogadas-1, quantiaEmPosse);
	}
			
	printf("\n\n\t\tT E R M I N A N D O. . .\n\n\n");
	system ("PAUSE");
	return 0;	
}


