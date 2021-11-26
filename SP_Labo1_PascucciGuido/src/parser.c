#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Inputs.h"
#include "Perritos.h"



/**
 * @fn int parser_PerritosFromText(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los perritos desde el archivo "perritos.csv" (modo texto).
 *
 * @param pFile
 * @param this
 * @return 0 si ERROR / 1 si OK
 */
int parser_PerritosFromText(FILE* pFile , LinkedList* this) {

	int retorno = 0;

	char id[11];
	char nombre[21];
	char peso[11];
	char edad[11];
	char raza[21];


	if(pFile != NULL && this != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);

		while(!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);

			if(feof(pFile)) {
				break;
			}

			ePerrito *pPerrito = perrito_newParametros(id, nombre, peso, edad, raza);
			ll_add(this, pPerrito);
		}

		retorno = 1;
	}


	return retorno;
}




/**
 * @fn int parser_PerritosFromBinary(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los perritos desde el archivo "perritos.csv" (modo binario).
 *
 * @param pFile
 * @param this
 * @return 0 si ERROR / 1 si OK
 */
int parser_PerritosFromBinary(FILE* pFile , LinkedList* this) {

	int retorno = 0;
	ePerrito *pPerrito = NULL;

	if(pFile != NULL && this != NULL) {

		while(!feof(pFile)) {
			pPerrito = perrito_new();
			fread(pPerrito, sizeof(ePerrito), 1, pFile);

			if(feof(pFile)) {
				break;
			}

			ll_add(this, pPerrito);
			pPerrito = NULL;
		}

		retorno = 1;
	}


    return retorno;
}




