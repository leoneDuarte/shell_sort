#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<locale.h>


void shell_sort(int *vetor, int tamanho);
                                            /*ORDENANDO O VETOR ESSA FUN��O RECEBE O VETOR O 
										       TAMANHO E UM NUMERO QUE INDICA O METODO PARA 
										        SE DESCOBRIR OS INTERVALOS DE COMPARA��O 
										     */
void shell_knuth(int *vetor, int tamanho);

void exibir(int *vetor, int tamanho);//RESPONSAVEL SOMENTE PELA EXIBI��O
