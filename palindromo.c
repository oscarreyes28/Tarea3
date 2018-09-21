    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> // Incluyo biblioteca de string para dividir su longitud
    #define MAX 50 // dimension de pila[]



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
 //Funcion principal
 void main()

{

    int i;
    char arr[MAX], b;

    printf("Ingrese su palabra:");
    scanf("%s", arr);


    for (i = 0;arr[i] != '\0';i++){
        b = arr[i];
        apilar(b);
    }

    for (i = 0;i < (strlen(arr) / 2);i++){

        if (pila[top] == pila[elem]){

            desapilar();
            elem++;

        }
        else{
            printf("%s No es palindromo\n", arr);
            }

    }

    if ((strlen(arr) / 2)  ==  elem){

        printf("%s es palindromo\n",  arr);
        elem =  0;
        top  =  -1;


           }

    }
