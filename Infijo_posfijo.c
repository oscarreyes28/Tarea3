

#include <ctype.h>
#include <stdio.h>
#define MAX 50  // Tama�o de nuestra pila

char expre[MAX];
int top = -1; // Variables globales, ya que varias funciones las usar�n

/* Funci�n para eliminar los espacios en blanco en la expresion  */
void espacios(char* fuente) {
	char* i = fuente;
	char* j = fuente;
	while(*j != 0) {
		*i = *j++;
		if(*i != ' ')
			i++;
	}
	*i = 0;
}
