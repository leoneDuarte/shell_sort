#include"shell.h"

main(){
	setlocale(LC_ALL, "Portuguese");
	int escolha_menu,*vetor,*vetor_knuth,tamanho_vetor,contador,metodo_escolha,fim=1,final=1,auxiliar;
	int ordenado=0,ordenadok=0;
	
	while(fim!=0){
		printf("\n\t\t\t----------------------------\n");
		printf("\n\t\t\t--SHELL SORT--\n");
		printf("\t\t\t[1]-GERAR UM NOVO VETOR E ORDENA-LO\n\t\t\t[2]-SAIR");
		printf("\n\t\t\t----------------------------\n\n>>");
		scanf("%d",&escolha_menu);
		system("cls");
		final=1;
		switch(escolha_menu){
			case 1:
				
				printf("\n\t\t-----------------------------------------\n");
				printf("\n\t\tDIGITE O TAMANHO DO VETOR A SER ORDENADO\n");
				printf("\n\t\t-----------------------------------------\n\n>>>");
				scanf("%d",&tamanho_vetor);	
				system("cls");
				
				ordenado = 0;
				ordenadok = 0;
				
				vetor = malloc (sizeof(int) * (tamanho_vetor));
				vetor_knuth = malloc (sizeof(int) * (tamanho_vetor));		

				srand(time(NULL));
				
				for(contador = 0; contador < tamanho_vetor; contador++){
					auxiliar = rand()%1000;
					vetor[contador] = auxiliar;
					vetor_knuth [contador]= auxiliar;
				
				}
							
				//definindo qual metodo sera usado para descobrir os intervalos
				while(final!=0){
					printf("\n\t------------------------------------------------------------------\n");
					printf("\n\tPORFAVOR INSIRA O MÉTODO PARA DESCOBRIR OS INTERVALOS DE COMPARAÇÃO:\n");
					printf("\n\t\t[1]-METODO DE KNUTH \n\t\t[2]-DIVIDINDO TAMANHO POR 2\n\t\t[3]-SAIR");
					printf("\n\t------------------------------------------------------------------\n\n>>>");
					scanf("%d",&metodo_escolha);
					system("cls");
					//calculando o tempo dos metodos escolhidos
					switch(metodo_escolha){
						case 1:									
							if(ordenadok == 1){
								system("cls");
								printf("\n\n\t\t\tESTE VETOR JA ESTA ORDENADO\n");
								break;
								
							}	
							ordenadok++;			
							printf("\n\t\t\tEXIBINDO VETOR DESORDENADO\n %\n\n");
							exibir(vetor_knuth,tamanho_vetor);
							printf("\n\n");
							system("pause");
														
						 	clock_t hora_inicial = clock();
							shell_knuth(vetor_knuth, tamanho_vetor);
							clock_t hora_final = clock();
												
							printf("\n\t\t\tEXIBINDO VETOR ORDENADO\n");
							exibir(vetor_knuth,tamanho_vetor);
							double tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
			   				printf("\n\n\n\t\tTEMPO GASTO USANDO KNUTH: %lf s\n", tempo_gasto);
							printf("\n\n");
							system("pause");
							system("cls");							
							break;
						
						case 2:
							
							if(ordenado == 1 ){
								system("cls");
								printf("\n\t\t\tESTE VETOR JA ESTA ORDENADO\n");
								break;
							}
							ordenado++;
							printf("\n\t\t\tEXIBINDO VETOR DESORDENADO\n");
							exibir(vetor,tamanho_vetor);
							printf("\n\n");
							system("pause");
							
						    hora_inicial = clock();
							shell_sort(vetor, tamanho_vetor);
							hora_final = clock();
						
							printf("\n\t\t\tEXIBINDO VETOR ORDENADO\n");
							exibir(vetor,tamanho_vetor);
							tempo_gasto = ( (double) (hora_final - hora_inicial) ) / CLOCKS_PER_SEC;
			   				printf("\n\n\n\t\tTEMPO GASTO USANDO METODO DE DIVISÃO POR DOIS: %lf s\n", tempo_gasto);
							printf("\n\n");
							system("pause");
							system("cls");
							break;
							
						case 3:
							final=0;
							break;
					}
				}
					
					break;				
			
			case 2:
				
				printf("\n\t\t\t-----------------------------------\n");
				printf("\n\t\t\t\tENCERRADO COM SUCESSO\n");
				printf("\n\t\t\t-----------------------------------\n");
				fim=0;
				
				break;
		
		}
	}
}
