#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    fflush(stdin);
    char seguir='s';
    int opcion=0;
    float numero1=0;
    float numero2=0;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",numero1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
        {
            numero1=pedirnumero("Ingrese el primer numero: ");
            system("cls");
            break;
        }
        case 2:
        {
            numero2=pedirnumero("Ingrese el segundo numero: ");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            suma(numero1,numero2);
            break;
        }
        case 4:
        {
            system("cls");
            resta(numero1,numero2);
            break;
        }
        case 5:
        {
            system("cls");
            division(numero1, numero2);
            break;
        }
        case 6:
        {
            system("cls");
            multiplicacion(numero1, numero2);
            break;
        }
        case 7:
        {
            system("cls");
            factor(numero1);
            break;
        }
        case 8:
        {
            system("cls");
            suma(numero1,numero2);
            resta(numero1,numero2);
            division(numero1, numero2);
            multiplicacion(numero1,numero2);
            factor(numero1);
            break;
        }
        case 9:
        {
            seguir = 'n';
            break;
        }
        default:
        {
            system("cls");
            printf("\nOPCION INVALIDA REINGRESE\n\n");
        }
        }
    }
    return 0;
}
