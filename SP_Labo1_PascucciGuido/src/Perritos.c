#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perritos.h"
#include "Inputs.h"
#include "Controller.h"



/**
 * @fn ePerrito perrito_new*()
 * @brief reserva espacio en memoria y lo asigna a un puntero tipo struct.
 *
 * @return un puntero a struct ePerrito
 */
ePerrito* perrito_new() {

	ePerrito *pPerrito = NULL;
	pPerrito = (ePerrito*) malloc(sizeof(ePerrito));

	return pPerrito;
}



/**
 * @fn ePerrito perrito_newParametros*(char*, char*, char*, char*, char*)
 * @brief ademas de reservar espacio en memoria para un puntero de tipo struct, guarda datos en los campos de la misma.
 *
 * @param idStr
 * @param nombreStr
 * @param pesoStr
 * @param edadStr
 * @param razaStr
 * @return un puntero a struct ePerrito.
 */
ePerrito* perrito_newParametros(char* idStr, char* nombreStr, char* pesoStr, char* edadStr, char* razaStr) {

	ePerrito *pPerrito = NULL;
	pPerrito = perrito_new();

	if(pPerrito != NULL && idStr != NULL && nombreStr != NULL && pesoStr != NULL && edadStr != NULL && razaStr != NULL) {
		perrito_setId(pPerrito, atoi(idStr));
		perrito_setNombre(pPerrito, nombreStr);
		perrito_setPeso(pPerrito, atoi(pesoStr));
		perrito_setEdad(pPerrito, atoi(edadStr));
		perrito_setRaza(pPerrito, razaStr);
	}

	return pPerrito;
}


/**
 * @fn void perrito_delete(ePerrito*)
 * @brief libera memoria y fija el puntero a struct en NULL - borra perrito de la lista
 *
 * @param this
 */
void perrito_delete(ePerrito* this) {

	if(this != NULL) {
		free(this);
		this = NULL;
	}

}


/**
 * @fn int perrito_setId(ePerrito*, int)
 * @brief guarda en la struct ePerrito un dato de tipo ID
 *
 * @param this
 * @param id
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_setId(ePerrito* this, int id) {

	int retorno = 0;

	if(this != NULL) {
		this->id = id;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int perrito_getId(ePerrito*, int*)
 * @brief trae un elemento de la struct de tipo ID.
 *
 * @param this
 * @param id
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_getId(ePerrito* this, int* id) {

	int retorno = 0;
	if(this != NULL) {
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int perrito_setNombre(ePerrito*, char*)
 * @brief guarda en la struct un dato de tipo nombre.
 *
 * @param this
 * @param nombre
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_setNombre(ePerrito* this, char* nombre) {

	int retorno = 0;

	if(this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}


/**
 * @fn int perrito_getNombre(ePerrito*, char*)
 * @brief trae un elemento de la struct de tipo nombre.
 *
 * @param this
 * @param nombre
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_getNombre(ePerrito* this, char* nombre) {

	int retorno = 0;
	if(this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_setPeso(ePerrito*, float)
 * @brief guarda en la struct un dato de tipo peso.
 *
 * @param this
 * @param peso
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_setPeso(ePerrito* this, float peso) {

	int retorno = 0;
	if(this != NULL) {
		this->peso = peso;
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_getPeso(ePerrito*, float*)
 * @brief trae un elemento de la struct de tipo peso.
 *
 * @param this
 * @param peso
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_getPeso(ePerrito* this, float* peso) {

	int retorno = 0;
	if(this != NULL) {
		*peso = this->peso;
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_setEdad(ePerrito*, int)
 * @brief guarda en la struct un dato de tipo edad.
 *
 * @param this
 * @param edad
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_setEdad(ePerrito* this, int edad) {

	int retorno = 0;

	if(this != NULL) {
		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_getEdad(ePerrito*, int*)
 * @brief trae un elemento de la struct de tipo edad.
 *
 * @param this
 * @param edad
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_getEdad(ePerrito* this, int* edad) {

	int retorno = 0;
	if(this != NULL) {
		*edad = this->edad;
		retorno = 1;
	}

	return retorno;
}




/**
 * @fn int perrito_setRaza(ePerrito*, char*)
 * @brief guarda en la struct un dato de tipo raza.
 *
 * @param this
 * @param raza
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_setRaza(ePerrito* this, char* raza) {

	int retorno = 0;

	if(this != NULL) {
		strcpy(this->raza, raza);
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_getRaza(ePerrito*, char*)
 * @brief trae un elemento de la struct de tipo raza.
 *
 * @param this
 * @param raza
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_getRaza(ePerrito* this, char* raza) {

	int retorno = 0;
	if(this != NULL) {
		strcpy(raza, this->raza);
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_setCantidadComidaRacion(ePerrito*, float)
 * @brief guarda en la struct un dato de tipo cantidadComidaRacion.
 *
 * @param this
 * @param cantidadComidaRacion
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_setCantidadComidaRacion(ePerrito* this, float cantidadComidaRacion) {

	int retorno = 0;
	if(this != NULL) {
		this->cantidadComidaRacion = cantidadComidaRacion;
		retorno = 1;
	}

	return retorno;
}



/**
 * @fn int perrito_getCantidadComidaRacion(ePerrito*, float*)
 * @brief trae un elemento de la struct de tipo cantidadComidaRacion.
 *
 * @param this
 * @param cantidadComidaRacion
 * @return [0] si el puntero es NULL / [1] si OK
 */
int perrito_getCantidadComidaRacion(ePerrito* this, float* cantidadComidaRacion) {

	int retorno = 0;
	if(this != NULL) {
		*cantidadComidaRacion = this->cantidadComidaRacion;
		retorno = 1;
	}

	return retorno;
}




/**
 * @fn int sortByName(ePerrito*, ePerrito*)
 * @brief ordena la lista de perritos segun nombre.
 *
 * @param pPerritoA
 * @param pPerritoB
 * @return retorna el resultado de la comparacion de dos cadenas de caracteres.
 */
int sortByName(ePerrito* pPerritoA, ePerrito* pPerritoB) {

	char perritoA[128];
	char perritoB[128];
	int resultCmp;

	perrito_getNombre(pPerritoA, perritoA);
	perrito_getNombre(pPerritoB, perritoB);

	resultCmp = strcmp(perritoA, perritoB);


	return resultCmp;
}




int ePerrito_laQueMapea(void* pElement) {

	int ret = 0;
	float peso;
	float cantidadComidaRacion;

	ePerrito *pPerrito = (ePerrito*) pElement;


	if(pElement != NULL) {
		perrito_getPeso(pPerrito, &peso);
		cantidadComidaRacion = peso * 23;
		perrito_setCantidadComidaRacion(pPerrito, cantidadComidaRacion);

		ret = 1;
	}


	return ret;
}





