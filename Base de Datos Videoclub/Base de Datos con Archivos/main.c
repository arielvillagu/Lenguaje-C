#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    int cantidadMovie=0;
    //eMovie movie;
    eMovie* movieptr;
    char seguir='s';
    int opcion=0;
    movieptr = malloc(sizeof(eMovie));
    if (movieptr == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    inicializarMovie(movieptr,cantidadMovie);
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            cantidadMovie=aumentarespacio(cantidadMovie,movieptr);
            altaMovie(movieptr,cantidadMovie);
            break;
        case 2:
            bajaMovie(movieptr,cantidadMovie);
            break;
        case 3:
            modificarMovie(movieptr,cantidadMovie);
            break;
        case 4:
            generarPagina(movieptr,cantidadMovie);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("No existe esa opcion!!!\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
