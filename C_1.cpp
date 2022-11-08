#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pessoa 
{
	int idade;
	float altura;
	char sexo;
};

typedef struct pessoa Pessoa;

/*
int *p;
int val =5;
*/

struct ponto 
{
	float x;
	float y;
	struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos;

void add(float x, float y) {
	Ponto *p = (Ponto*)malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	p->prox = listaPontos;
	listaPontos = p;
}

int main() {
	Pessoa p1;
	p1.idade = 5;
	p1.altura = 1.65;
	p1.sexo = 'M';
	printf("A idade da pessoa eh: %d", p1.idade);
	printf("\nA altura da pessoa eh: %.2f", p1.altura);
	printf("\nO genero da pessoa eh: %c", p1.sexo);
	
/*	p = &val;
	printf("\nO valor apontado por 'p' eh: %d", *p); */
	
	Ponto *p = (Ponto*)malloc(sizeof(Ponto));
	p->x = 1;
	p->y = 5;
	printf("\nPonto = (%.2f, %.2f)", p->x, p->y);
	
	add(1,5);
	add(3,7);
	add(5,3);
	
	
	printf("\n%.0f", listaPontos->x);
	printf("\n%.0f", listaPontos->prox->x);
	printf("\n%.0f", listaPontos->prox->prox->x);
	
	return 0;
}
