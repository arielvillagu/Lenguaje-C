#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
void inicializarMovie(eMovie* movieptr,int cantidadMovie)
{
        (movieptr+cantidadMovie)->duracion=0;
}
int aumentarespacio(int cantidadMovie,eMovie* movieptr)
{
    int auxcantidadMovie;
    eMovie* auxmovieptr;
    cantidadMovie++;
    auxcantidadMovie = sizeof(eMovie) * (cantidadMovie+1);
    auxmovieptr = realloc( movieptr, auxcantidadMovie);
    if (auxmovieptr == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
    }
    else
    {
        movieptr=auxmovieptr;
        inicializarMovie(movieptr,cantidadMovie);
    }
    return cantidadMovie;
}
int buscarLibre(eMovie* movieptr,int cantidadMovie)
{
    int index=-1;
    int i;
    for( i=0; i < cantidadMovie; i++)
        if((*(movieptr+i)).duracion==0)
        {
            index=i;
            break;
        }
    return index;
}
int validarNum(char num[])
{
    int ok=1;
    for (int i = 0; i < strlen(num); i++)
    {
        if(!isdigit(num[i]) )
        {
            ok=0;
            break;
        }
    }
    return ok;
}
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
void altaMovie(eMovie* movieptr,int cantidadMovie)
{
    int index, i;
    char titulo[20];
    int encontro=0;
    int flag=0;
    char duracion[256];
    char puntaje[256];
    int esNum;
    index=buscarLibre(movieptr,cantidadMovie);
    if(index!=-1)
    {

        printf("INGRESO DE DATOS:\n");
        printf("Ingrese titulo: ");
        fflush(stdin);
        gets(titulo);
        for(i=0; i<5; i++)
        {
            if(titulo==(*(movieptr+i)).titulo)
            {
                encontro=1;
                break;
            }
        }
        if(encontro!=1)
        {
            strcpy((*(movieptr+index)).titulo,titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets((*(movieptr+index)).genero);
            printf("Ingrese Duracion en minutos: ");
            gets(duracion);
            esNum=validarNum(duracion);
            (movieptr+index)->duracion=atoi(duracion);
            do
            {
                if((movieptr+index)->duracion>0 && esNum==1)
                {
                    flag=1;
                }
                else
                {
                    printf("DURACION INCORRECTA.    *No puede durar 0 o menos\n\nReingrese duracion: ");
                    gets(duracion);
                    esNum=validarNum(duracion);
                    (movieptr+index)->duracion=atoi(duracion);
                    flag=0;
                }
            }
            while(flag==0);
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets((*(movieptr+index)).descripcion);
            printf("Ingrese puntaje entre 1 y 10: ");
            gets(puntaje);
            esNum=validarFloat(puntaje);
            (movieptr+index)->puntaje=atof(puntaje);
            do
            {
                if(esNum==1 && (movieptr+index)->puntaje>=1 && (movieptr+index)->puntaje<=10)
                {
                    flag=1;
                }
                else
                {
                    printf("puntaje INCORRECTO.    *El puntaje debe ser entre 1 y 10\n\nReingrese duracion: ");
                    gets(puntaje);
                    esNum=validarFloat(puntaje);
                    (movieptr+index)->puntaje=atof(puntaje);
                    flag=0;
                }
            }
            while(flag==0);
            printf("Ingrese Link de Imagen: ");
            fflush(stdin);
            gets((movieptr+index)->linkImagen);
        }
        else
        {
            printf("­­El titulo: %s ya existe!!",titulo);
        }
    }
    else
    {
        printf("No queda espacio!!!!\n");
    }
}
int buscarMovie(char titulo[20],eMovie* movieptr,int cantidadMovie)
{
    int indice=-1;
    for(int i=0; i<cantidadMovie; i++)
    {
        if(strcmp((movieptr+i)->titulo,titulo)==0&&(movieptr+i)->duracion>0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void mostrarMovie(eMovie* movieptr)
{
    printf("\nTitulo: %s----Genero: %s----Duracion: %d----Descripcion: %s-----puntaje: %f\n",movieptr->titulo,movieptr->genero,movieptr->duracion,movieptr->descripcion,movieptr->puntaje);
}
void bajaMovie(eMovie* movieptr,int cantidadMovie)
{
    char titulo[20];
    int indice;
    char confirma;
    printf("\nIngrese Titulo de la Pelicula a Eliminar: ");
    fflush(stdin);
    gets(titulo);
    indice=buscarMovie(titulo,movieptr,cantidadMovie);
    if(indice!=-1)
    {
        mostrarMovie(movieptr+indice);
        printf("\nConfirma la baja? s/n: ");
        fflush(stdin);
        confirma=getchar();
        if(confirma=='s')
        {
            (movieptr+indice)->duracion=0;
            printf("\nPelicula Eliminada\n");
        }
        else
        {
            printf("\nBaja cancelada por el usuario\n");
        }
    }
    else
    {
        printf("\nPelicula no encontrada.\n");
    }
}
void modificarMovie(eMovie* movieptr,int cantidadMovie)
{
    char titulo[20];
    int indice;
    char confirma;
    int opcion;
    int flag=0;
    printf("\nIngrese Titulo de la Pelicula a Modificar: ");
    fflush(stdin);
    gets(titulo);
    indice=buscarMovie(titulo,movieptr,cantidadMovie);
    if(indice!=-1)
    {
        mostrarMovie(movieptr+indice);
        printf("\nEsta seguro que desea modificar la Pelicula? s/n: ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            while(confirma=='s')
            {
                printf("--PELICULA A MODIFICAR: %s\n\n",(movieptr+indice)->titulo);
                printf("1- Modificar Genero: %s\n",(movieptr+indice)->genero);
                printf("2- Modificar Duracion: %d\n",(movieptr+indice)->duracion);
                printf("3- Modificar Descripcion: %s\n",(movieptr+indice)->descripcion);
                printf("4- Modificar puntaje: %f\n",(movieptr+indice)->puntaje);
                printf("5- Modificar Link Imagen\n");
                printf("6- Terminar Modificaciones!\n");
                scanf("%d",&opcion);
                system("cls");
                switch(opcion)
                {
                case 1:
                    printf("\nIngrese Genero: ");
                    fflush(stdin);
                    gets((movieptr+indice)->genero);
                    printf("\nGenero modificado con exito!\n");
                    break;
                case 2:
                    printf("\nIngrese Duracion: ");
                    scanf("%d",&(movieptr+indice)->duracion);
                    do
                    {
                        if((movieptr+indice)->duracion>0)
                        {
                            flag=1;
                        }
                        else
                        {
                            printf("DURACION INCORRECTA NO PUEDE DURAR 0 O MENOS\n\nReingrese duracion: ");
                            scanf("%d",&(movieptr+indice)->duracion);
                            flag=0;
                        }
                    }
                    while(flag==0);
                    printf("\nDuracion modificada con exito!\n");
                    break;
                case 3:
                    printf("\nIngrese Descripcion: ");
                    fflush(stdin);
                    gets((movieptr+indice)->descripcion);
                    printf("\nDescripcion modificada con exito!\n");
                    break;
                case 4:
                    printf("\nIngrese Puntaje: ");
                    scanf("%f",&(movieptr+indice)->puntaje);
                    printf("\nPuntaje modificado con exito!\n");
                    break;
                case 5:
                    printf("\nIngrese Link Imagen: ");
                    fflush(stdin);
                    gets((movieptr+indice)->linkImagen);
                    printf("\nLink Imagen modificado con exito!\n");
                    break;
                case 6:
                    confirma = 'n';
                    break;
                default:
                    printf("No existe esa opcion!!!\n");
                    break;
                }
            }
        }
        else
        {
            printf("\naccion cancelada.\n");
        }

    }
    else
    {
        printf("\nPelicula no encontrada.\n");
    }
}
void generarPagina(eMovie* movieptr,int cantidadMovie)
{
    FILE* html;
        if((html=fopen("Web.html","w"))==NULL)
        {
            printf("\nLa pagina no pudo ser creada");
            exit (1);
        }
        else
        {
            for(int i=0;i<cantidadMovie;i++)
            {
                if((movieptr+i)->duracion!=0)
                {
                fprintf(html,"<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s' alt=''>\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Género:%s</li>\n<li>Puntaje:%f</li>\n<li>Duración:%d</li>\n</ul>\n <p>%s</p>\n</article>",(movieptr+i)->linkImagen,(movieptr+i)->titulo,(movieptr+i)->genero,(movieptr+i)->puntaje,(movieptr+i)->duracion,(movieptr+i)->descripcion);
                }
            }
            printf("Pagina creada con exito!\n");
        }
        fclose(html);
}
