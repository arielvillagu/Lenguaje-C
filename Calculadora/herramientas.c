#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validarFloat(char num[])
{
    int ok=1;
    int coma=0;
    for (int i = 0; i < strlen(num); i++)
    {
        if(!isdigit(num[i]) )
        {
            if(num[i]=='.')
            {
                if(coma==1)
                {
                    ok=0;
                    break;
                }
                coma=1;
            }
            else
            {
                ok=0;
                break;
            }
        }
    }
    return ok;
}

float pedirnumero(char mensaje[])
{
    char numeroChar[256];
    float numero;
    int ok;
    printf("%s",mensaje);
    do
    {

        scanf("%s",&numeroChar[0]);
        ok=validarFloat(numeroChar);
        if(ok==1)
        {
            numero=atof(numeroChar);
        }
        else
        {
            printf("Numero Incorrecto. Reingrese: \n");
        }
    }while(ok==0);

    fflush(stdin);
    return numero;
}

int suma(float a, float b)
{
    printf("La suma es: %f\n\n",a+b);
    return 0;
}

int resta(float a, float b)
{
    printf("La resta es: %f\n\n",a-b);
    return 0;
}

int division(float a, float b)
{
    if (a==0 || b==0)
    {
        printf("No se puede dividir por cero\n\n");
    }
    else
    {
        printf("La division es: %f\n\n",(float)a/b);
    }
    return 0;
}

int multiplicacion(float a, float b)
{
    printf("La multiplicacion es: %f\n\n",a*b);
    return 0;
}

int factor(float a)
{
    int b;
    float factoreo=1;
    for(b=a; b>1; b--)
    {
        factoreo=factoreo*b;
    }
    printf("El factorial es: %f\n\n",factoreo);
    return 0;
}
