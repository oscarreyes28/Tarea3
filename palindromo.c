    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 50



    int top = -1, elem = 0;
    int pila[MAX];
    void apilar(char);
    void desapilar();




    // Funcion que agrega elemntos a la pila

    void apilar(char a)
{

    top++;
    pila[top]  =  a;

}

    //Funcion para deaspilar

    void desapilar()
{

    top--;
}
