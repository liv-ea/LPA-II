/* Bibliotecas */

#include <stdio.h>
#include <windows.h>

/* Struct que armazena dados dos alunos */

typedef struct aluno {

  int matricula;

  float nota1,
        nota2,
        nota3;

} Aluno;

typedef struct lista{

  Aluno infor;

  struct Lista* prox;

} Lista;

/* Protótipos de funções */

 Lista* criarlista();

int tamanholista();
int inseriraluno();

void liberarlista();

/* Variáveis Globais */



int main(){

  system("color f0");

  printf("ok\n");

}

/* struct Lista* criarlista(){

} */

int tamanholista(){

}

int inseriraluno(){

}

void liberarlista(){

}
