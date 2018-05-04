/* Verificador de números primos
 *
 * Este programa recebera valores inteiros como entrada
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de valores primos encontrados e, apos, encerrar.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>
#include <math.h>


int main() {
  
 int *primo, *k;
 
 int protection = PROT_READ | PROT_WRITE;
 int visibility = MAP_SHARED | MAP_ANON;
 
 int i, numerodivisores = 1;
 char c;
 int numeros[10000];
 
 pid_t filho1, filho2, filho3, filho4;
 
   k = (int*) mmap(NULL, sizeof(int), protection, visibility, 0, 0);
   if (k==(int*)-1) printf("Erro de alocacao!\n");
   (*k) = 0;
  
   primo = (int*) mmap(NULL, sizeof(int), protection, visibility, 0, 0);
   if (primo==(int*)-1) printf("Erro de alocacao!\n");
   (*primo) = 0;
   
while ((c = getchar()) != '\n')
{
    if (c != ' ')
        numeros[i] = numeros[i] * 10 + c - '0'; 
    else
        i++;
}

  /*Processo filho1*/
  filho1 = fork();
  
  if(filho1 == 0){
    
    if((*k) < i){
      
      if(numeros[(*k)] >= 2){ 
	numerodivisores = 0;
	  for(i = numeros[(*k)]; i >= 1; i--){
	    if(numeros[(*k)]%i == 0) numerodivisores++;    
  }
  
    if(numerodivisores == 2) (*primo)++;
 
  }
    (*k)++;
      
  }
    //printf("%d\n", (*primo));
    
    exit(0);
    
  }
  
  else {
    
    /*Processo filho2*/
    filho2 = fork();
  
  if(filho2 == 0){
    
    if((*k) < i){
      
      if(numeros[(*k)] >= 2){ 
	numerodivisores = 0;
	  for(i = numeros[(*k)]; i >= 1; i--){
	    if(numeros[(*k)]%i == 0) numerodivisores++;    
  }
  
    if(numerodivisores == 2) (*primo)++;
 
  }
    (*k)++;
      
  }
    //printf("%d\n", (*primo));
    
    exit(0);
    
  }
  else {
    
    /*Processo filho3*/
    filho3 = fork();
  
  if(filho3 == 0){
    
    if((*k) < i){
      
      if(numeros[(*k)] >= 2){ 
	numerodivisores = 0;
	  for(i = numeros[(*k)]; i >= 1; i--){
	    if(numeros[(*k)]%i == 0) numerodivisores++;    
  }
  
    if(numerodivisores == 2) (*primo)++;
 
  }
    (*k)++;
      
  }
    //printf("%d\n", (*primo));
    
    exit(0);
    
    }
    else {
    
    /*Processo filho1*/
    filho4 = fork();
  
  if(filho4 == 0){
    
    if((*k) < i){
      
      if(numeros[(*k)] >= 2){ 
	numerodivisores = 0;
	  for(i = numeros[(*k)]; i >= 1; i--){
	    if(numeros[(*k)]%i == 0) numerodivisores++;    
  }
  
    if(numerodivisores == 2) (*primo)++;
 
  }
    (*k)++;
      
  }
    //printf("%d\n", (*primo));
    
    exit(0);
    
    }
  }
  }
  }
  
 
  int status;
  
  waitpid(filho1, &status, 0);
  waitpid(filho2, &status, 0);
  waitpid(filho3, &status, 0);
  waitpid(filho4, &status, 0);
 
  printf("%d\n", (*primo));
  //printf("Indice: %d\n", (*k));
  
  return 0;
}
  