

#include <ctype.h>
#include <stdio.h>
#define MAX 50  // Tamaño de nuestra pila

char expre[MAX];
int top = -1; // Variables globales, ya que varias funciones las usarán

/* Función para eliminar los espacios en blanco en la expresion  */
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
