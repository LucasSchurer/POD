#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no{
    int num; // elemento
    int i;   // indice do elemento
};

typedef struct no No;

FILE * input (char * arquivo, char * modo) {
    FILE * input_file = fopen(arquivo, modo);
    if(input_file == NULL){
        puts("Erro ao abrir o arquivo '%s.txt'.\n");
        exit(EXIT_FAILURE);
    } return input_file;
}

No * troca (No * x, No * y) {
    No temp = *x;
    *x = *y;
    *y = temp;
}

void main (){
    int caminhos = 10;
    int tam_particao = 1000; 

    char * entrada = "input.txt";
    char * saida = "output.txt";
    FILE * arq = input(entrada, "wb"); 
  
    srand(time(NULL)); 
    for (int i = 0; i < caminhos * tam_particao; i++) 
        fprintf(arq, "%d ", (rand() % 1000)); 

    fclose(arq); 
}