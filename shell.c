//LEONE DUARTE DE OLIVEIRA
#include "shell.h"
void exibir(int *vetor, int tamanho){
	int contador;	
	for(contador=0; contador < tamanho; contador++){
		printf("\n\t\t\t\tPOSICAO %d: %d",contador,vetor[contador]);
		
	}
}

void shell_sort(int *vetor, int tamanho){
	int contador,contador2,contador3,aux_troca, intervalo,final=0,inicio;

	
	printf("\n\tORDENANDO USANDO A DIVISAO POR DOIS PARA DETERMINAR OS INTERVALOS:\n");
	intervalo = tamanho/2;
	contador = 0;
	
	while(intervalo!= 1){	
		contador=0;
		final =0;			
		while(final < tamanho && contador < tamanho ){		
		//COMPARANDO AS POSIÇOES, USANDO O INTERVALO COMO DISTANCIA ENTRE AS POSIÇÕES
			if(vetor[contador] > vetor[contador + intervalo] ){		
					aux_troca = vetor[contador];
					vetor[contador] = vetor[contador + intervalo];
					vetor[contador + intervalo] = aux_troca;
				
			}
			
			contador++;
			final = contador + intervalo;
		}
		intervalo = intervalo/2;
	}
	
		//CASO JA ESTEJA NO UM NÃO E MAIS PRECISO CONTINUAR DIVIDINDO AI E FEITO O INSERTION PARA TERMINAR A ORGANIZAÇÃO
	if(intervalo == 1){
		for(contador2 = 0; contador2 < tamanho; contador2++){
			
			 	inicio = contador2+1;
				//VERIFICANDO SE O PROXIMO NUMERO E MAIOR, E TROCANDO CASO SEJA VERDADE	
				if(vetor[contador2] > vetor[contador2 + 1] && inicio < tamanho){
					aux_troca = vetor[contador2];
					vetor[contador2] = vetor[contador2 + 1];
					vetor[contador2 + 1] = aux_troca;
					
					
				
				//VEIFICANDO SE HA NUMEROS MAIORES NAS POSIÇOES ANTERIORES
				for(contador3 = contador2+1; contador3 >= 0; contador3--){
					 inicio = contador3 - 1;
			
					if(vetor[contador3] < vetor[contador3-1] && inicio >=0){
						aux_troca = vetor[contador3];
						vetor[contador3] = vetor[contador3 - 1];
						vetor[contador3 - 1] = aux_troca;
					}
				}
				
					
				}
				
		}
	}
}

void shell_knuth(int *vetor, int tamanho){
		int contador,contador2,contador3,aux_troca, intervalo,final=0,inicio;	
		
		printf("\n\tORDENANDO USANDO O METODO DE KNUTH PARA DETERMINAR OS INTERVALOS:\n");		
		intervalo = 1;
		do {//CALCULANDO O MAIOR INTERVALO POSSIVEL DE KNUTH	
			intervalo = 3 *intervalo+1;
			
			if(intervalo > tamanho){
				intervalo = (intervalo - 1) / 3;
				break;
			}
		}while(intervalo < tamanho );
			 
		while(intervalo!= 1){
			contador=0;
			final =0;
			while(contador < tamanho && final < tamanho){
									
			//COMPARANDO AS POSIÇOES, USANDO O INTERVALO COMO DISTANCIA ENTRE AS POSIÇÕES
				if(vetor[contador] > vetor[contador + intervalo]){
				
						aux_troca = vetor[contador];
						vetor[contador] = vetor[contador + intervalo];
						vetor[contador + intervalo] = aux_troca;
						
						
				}
			
			contador++;
			final = contador + intervalo;
		
			}
						
			intervalo = (intervalo - 1) / 3; //VERIFICANDO OS VALORES ANTERIORES DO INTERVALO DE KNUTH			
		}
		
			
			//CASO JA  O METODO KNUTH CHEGUE ATE O 1
		if(intervalo == 1){
			for(contador2 = 0; contador2 < tamanho; contador2++){
				
				 	inicio = contador2+1;
					//VERIFICANDO SE O PROXIMO NUMERO E MAIOR, E TROCANDO CASO SEJA VERDADE	
					if(vetor[contador2] > vetor[contador2 + 1] && inicio < tamanho){
						aux_troca = vetor[contador2];
						vetor[contador2] = vetor[contador2 + 1];
						vetor[contador2 + 1] = aux_troca;
						
						
					
					//VEIFICANDO SE HA NUMEROS MAIORES NAS POSIÇOES ANTERIORES
					for(contador3 = contador2+1; contador3 >= 0; contador3--){
						 inicio = contador3 - 1;
				
						if(vetor[contador3] < vetor[contador3-1] && inicio >=0){
							aux_troca = vetor[contador3];
							vetor[contador3] = vetor[contador3 - 1];
							vetor[contador3 - 1] = aux_troca;
						}
					}
					
						
					}
					
			}
		}
	
	
}


