#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Funcion para obtener numero
*
*   \param  Se muestra el mensaje
*   \param  El numero que se quiere obtener
*   \return El numero obtenido
*
*/
float pedirnumero(char mensaje[]);

/** \brief Funcion "sumar"
*
*   \param  El primer numero a sumar
*   \param  El segundo numero a sumar
*   \return El resultado de la suma
*
*/
int suma(float a,float b);


/** \brief Funcion "restar"
*
*   \param  El primer numero a restar
*   \param  El segundo numero a restar
*   \return El resultado de la resta
*
*/
int resta(float a,float b);

/** \brief Funcion "dividir"
*
*   \param Los numeros a dividir no deben ser cero
*   \param Se muestra el mensaje con el error
*
*   \param  Numero a dividir
*   \param  Divisor
*   \return El resultado de la division
*
*/
int division(float a,float b);

/** \brief Funcion "multiplicar"
*
*   \param  El primer numero a multiplicar
*   \param  El segundo numero a multiplicar
*   \return El resultado de la multiplicacion
*
*/
int multiplicacion(float a, float b);

/** \brief Funcion "Factorial"
*
*   \param  Numero al que se le calcula factor
*   \return El factor final del numero
*
*/
int factor(float a);

int validarFloat(char []);
#endif // FUNCIONES_H_INCLUDED
