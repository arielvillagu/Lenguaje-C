#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[100];
    float puntaje;
    char linkImagen[200];
}eMovie;
//void creararchivo(FILE*);
void inicializarMovie(eMovie*,int cantidadMovie);
int aumentarespacio(int cantidadMovie,eMovie*);
void altaMovie(eMovie*,int cantidadMovie);
void bajaMovie(eMovie*,int cantidadMovie);
void modificarMovie(eMovie*,int cantidadMovie);
void generarPagina(eMovie*,int cantidadMovie);
int validarNum(char num[]);
int validarFloat(char num[]);
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(eMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
