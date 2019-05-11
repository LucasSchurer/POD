#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAM 5
#define NUM_NUMS 16
#define NUM_CAMINHOS 3

// Cria um arquivo temporario chamado nome com tam numeros aleatorios. 
// Os numeros gerados sÃ£o mostrados na tela. 
void cria_arq_rand(char *nome, int tam){
  FILE *arq;
  int num,j=0;
  arq = fopen(nome,"wb"); 

  for (int i = 0; i < tam; i++) {
    num = random()%100;
    fwrite(&num, sizeof(num), 1, arq);
    printf("%d:%d\t",j++,num);
    if (j%RAM==0) 
      printf("\n");
  }
  printf("\n");
  printf("\n");
//  fflush(arq); // garante que tudo foi gravado antes de fechar
  fclose(arq);
}

// Le um aquivo com numeros inteiros e mostra-os na tela.
void le_arq(char *nome){
  FILE *arq;
  int num;
  int i=0;

  arq = fopen(nome,"rb"); 

  while( 1 == fread(&num,sizeof(num),1,arq)){
    printf("%d:%d\t",i++,num);
    if (i%RAM==0) 
      printf("\n");
  }
  printf("\n");
  if (!feof(arq)) 
    printf("Houston!\n\n"); // teoricamente nunca devemos ver isso!
}

int main () {
    cria_arq_rand("input", 100);
    le_arq("input");
}