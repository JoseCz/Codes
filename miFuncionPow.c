#include <stdio.h>
#include <math.h> //Se incluye para poder utilizar la funcion fabs(n), que retorna el valor absoluto de n.

/*
Instrucciones: Utiliza este programa para conocer la potencia de x numero elevado a la n, en donde x y n
son de la familia de los enteros (positivos y negativos, no se toma en cuenta el 0).

Este programa funciona para la forma x^n, no para la forma (x)^n
- Ejem: -3^2 = -(3)(3) = -9    FUNCIONA PARA ESTE PROGRAMA
- Ejem: (-3)^2 = (-3)(-3) = 9  NO FUNCIONA PARA ESTE PROGRAMA

Conclusion este programa no toma en cuenta los parentesis, de tenerlos el resultado cambiaria en algunos casos.
*/


//Variables globales.
int x, n;    //Guarda la base y exponente que ingrese el usuario.
int result; //Guarda el resultado de realizar la operacion x^n
int before; //Sirve para que funcione el algoritmo.

//Algoritmo: para conocer la potencia de un numero.
int algorithmPow()
{
    int before = x; //la variable "before", Vale lo mismo que la base que ingreso el usuario.

    for (int i = 1; i < fabs(n); i++)
    {
        result = before *= x; //multiplicate por ti mismo cuantas veces diga n.
        before = result; //Guarda el resultado de la primera multiplicacion, luego de la segunda ...
    }
}


int power()
{
    printf("Ingresa la base: ");
    scanf("%d", &x); //Guarda en la variable "x", la base que ingrese el usuario.

    int before = x; //la variable "before", Vale lo mismo que la base que ingreso el usuario.

    printf("Ingresa el exponente: ");
    scanf("%d", &n); //Guarda en la variable "n", el exponente que ingrese el usuario.
    
    //Para todo numero entero diferente de 0 elevado a la 1 o a la -1 (da como resultado el mismo numero).
        //Casos especiales: x^1, x^-1, -x^-1
    if(x != 0 && n == 1)
    {
        result = x;
        printf("El resultado es: %i \n", result);
    }
    else if (x > 0 && n == -1)
    {
        result = x;
        printf("El resultado es: 1/%i \n", result);
    }
    else if (x < 0 && n == -1)
    {
        result = x * -1; //Multiplo por -1 para anular el simbolo de menos, ejem: -3 (-3 * -1 = 3).
        printf("El resultado es: -1/%i \n", result);
    }

    //Para todo numero entero diferente de 0 elevado a la 0 es igual a la unidad "1".
    //Caso: x^0
    else if (x > 0 && n == 0)
    {
        result = 1;
        printf("El resultado es: %i \n", result);
    }
    else if (x < 0 && n == 0) //Caso: -x^0
    {
        result = 1;
        printf("El resultado es: %i \n", -result);
    }
    

    //Se evaluan todos los demas casos donde x es diferente de 0 y n es diferente de 1, -1 y 0.
    else if (x != 0)
    {
        if (x > 0 && n > 0) //Para el caso: x^2
        {
            algorithmPow();   
            printf("El resultado es: %i \n", result);
        }
        else if (x < 0 && n > 0) //Para el caso: -x^2
        {  
            algorithmPow();   
            printf("El resultado es: %i \n", -result);    
        }   
        else if (x > 0 && n < 0 && n != -1) //Para el caso: x^-2 donde n nunca va ser -1.
        { 
            algorithmPow();   
            printf("El resultado es: 1/%i \n", result);         
        }
        else if (x < 0 && n < 0 && n != -1) //Para el caso: -x^-2 donde n nunca va ser -1.
        {
            algorithmPow();   
            printf("El resultado es: -1/%i \n", result);  
        }
    }
    else
    {
        printf("Este programa solo trabaja con la familia de los numeros enteros \n");
    }
}


int main ()
{
    power(); //Ejecuto mi funcion Power (que realiza la operacion de potencia de un numero).
}

