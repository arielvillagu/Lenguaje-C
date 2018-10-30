#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define CANTIDADMOVIE 5
int main()
{
    FILE *movies;
    eMovie movie[CANTIDADMOVIE];
    eMovie* movieptr;
    movieptr=&movie[0];
    if((movies=fopen("movies.bin","rb"))==NULL)
    {
        if((movies=fopen("movies.bin","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        else
        {
            inicializarMovie(movieptr,CANTIDADMOVIE);
            printf("Archivo creado con exito!\n");
            system("pause");
            system("cls");
        }
        fclose(movies);
    }
    else
    {
        fread(movieptr,sizeof(eMovie),CANTIDADMOVIE,movies);
        printf("Archivo abierto con exito!\n");
        fclose(movies);
        system("pause");
        system("cls");
    }
    char seguir='s';
    int opcion=0;
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
            altaMovie(movieptr,CANTIDADMOVIE);
            break;
        case 2:
            bajaMovie(movieptr,CANTIDADMOVIE);
            break;
        case 3:
            modificarMovie(movieptr,CANTIDADMOVIE);
            break;
        case 4:
            generarPagina(movieptr,CANTIDADMOVIE);
            break;
        case 5:
            seguir = 'n';
            movies=fopen("movies.bin","wb");
            fwrite(movieptr,sizeof(eMovie),CANTIDADMOVIE,movies);
            fclose(movies);
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
