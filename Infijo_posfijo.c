

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
// Función para apilar en nuestra pila
void apilar(char elem) {
	expre[++top] = elem;
}
//Función para "desapilar" en nuestra pila
char desapilar() {
	return (expre[top--]);
}

// Funcion que define la prioridad en nuestro conjunto de operaciones
int priori(char elem) {
	switch (elem) {
		case '#':
			return 0;
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	}
}

/*
// Funcion que convierte de infijo a posfijo
*/
void infijo_posfijo(char *infijo, char *posfijo) {
	char ch, elem;
	int i = 0, k = 0;

	espacios(infijo);
	apilar('#');

	while ((ch = infijo[i++]) != '\n') {
		if (ch == '(')
			apilar(ch);
		else if (isalnum(ch))
			posfijo[k++] = ch;
		else if (ch == ')') {
			while (expre[top] != '(')
				posfijo[k++] = desapilar();
			elem = desapilar();
		} else {
			while (priori(expre[top]) >= priori(ch))
				posfijo[k++] = desapilar();
			apilar(ch);
		}
	}

	while (expre[top] != '#')
	posfijo[k++] = desapilar();

	posfijo[k] = 0;
}

// Funcion que evalua la operacion posfija

int evaluar(char *posfijo) {
	char ch;
	int i = 0, op1, op2;
	while((ch = posfijo[i++]) != 0) {
		if(isdigit(ch))
			apilar(ch-'0');
		else {
			op2 = desapilar();
			op1 = desapilar();
			switch(ch) {
				case '+' : apilar(op1+op2);
				break;
				case '-' : apilar(op1-op2);
				break;
				case '*' : apilar(op1*op2);
				break;
				case '/' : apilar(op1/op2);
				break;
			}
		}
	}
	return expre[top];
}

void main() {

	char inf[50], pos[50];
	printf("Ingrse su operacion:");
	fgets(inf, 50, stdin);

	infijo_posfijo(inf, pos);

	printf("Expresion infija: %s" ,inf);
	printf("Expresion posfija: %s \n" ,pos);
	top = -1;
printf("Resultado : %d", evaluar(pos));
}
