#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Inputs.h"
#include "Perritos.h"



/**
 * @fn void controlador_menuPrincipal(LinkedList*)
 * @brief el controlador donde se ubican todas las acciones disponibles del programa.
 *
 * @param listaPerris
 */
void controlador_menuPrincipal(LinkedList* this) {

	int fileIsOpen = 0;
	int flag = 0;
	int flagSort = 0;
	int option;

    do{
    	option = mostrarMenuPrincipal();

        switch(option) {

            case 1:
            	cargarArchivoDeTexto(this, &fileIsOpen, &flag);
                break;

            case 2:
            	if(!flagSort) {
            		ordenarPerritos(this, flag);
        			flagSort = 1;
            	}
            		mostrarListaPerritos(this, flag);
            	break;

            case 3:
            	mostrarMensajeDespedida();
            	break;

        }

    } while(option != 3);
}



/**
 * @fn int mostrarMenuPrincipal(void)
 * @brief muestra el menu principal con todas las acciones disponibles
 *
 * @return retorna un numero que sera la opcion que haya elegido el usuario
 */
int mostrarMenuPrincipal(void) {

	int option;

	getIntInMinMaxRange(&option, "\n===================================================================================================================\n\n"
								 "MENU\n\n"
								 "===================================================================================================================\n"
								 "1. Cargar los datos de los perritos desde el archivo perritos.csv (modo texto).\n"
								 "2. Ordenar Perritos & Mostrar Lista\n\n"
								 "3. Salir\n"
								 "===================================================================================================================\n\n"
								 "Ingrese una opcion: ",


								 "\n\n\nERROR! <<La opcion ingresada no es correcta>>\n"
								 "===================================================================================================================\n"
								 "MENU\n\n"
								 "===================================================================================================================\n"
								 "1. Cargar los datos de los perritos desde el archivo perritos.csv (modo texto).\n"
								 "2. Ordenar Perritos & Mostrar Lista\n\n"
								 "3. Salir\n"
								 "===================================================================================================================\n\n"
								 "Reingrese una opcion: ", 1, 3);


	return option;
}



/**
 * @fn void cargarArchivoDeTexto(LinkedList*, int*, int*)
 * @brief carga el archivo de texto "perritos.csv" al sistema.
 *
 * @param listaPerris
 * @param fileIsOpen
 * @param flag
 */
void cargarArchivoDeTexto(LinkedList* this, int* fileIsOpen, int* flag) {

	if(!(*fileIsOpen)) {
		if(controlador_cargarArchivoTexto("src/perritos.csv", this)) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se ha cargado el archivo de texto exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");

			*flag = 1;
			*fileIsOpen = 1;
		}
		else {
			printf("\n\n\nError al abrir el archivo\n\n");
		}

	}
	else {
		printf("\n\nERROR. <<Operacion no valida>>\n"
				"Ya has cargado los datos del archivo .csv al sistema!\n\n\n");
	}

	system("pause");
}



/**
 * @fn int controlador_cargarArchivoTexto(char*, LinkedList*)
 * @brief Carga los datos de los perritos desde el archivo "perritos.csv" (modo texto).
 *
 * @param path
 * @param this
 * @return lo que retorna la función del parser
 */
int controlador_cargarArchivoTexto(char* path , LinkedList* this) {

	int retorno = 0;
	FILE *pFile = fopen(path, "r");
	retorno = parser_PerritosFromText(pFile, this);
	fclose(pFile);

    return retorno;
}




/**
 * @fn int ordenarPerritos(LinkedList*, int)
 * @brief ordena los perritos por nombre ascendente.
 *
 * @param this
 * @param flag
 * @return
 */
int ordenarPerritos(LinkedList* this, int flag) {

	int ret = 0;

	if(flag) {

		ret = controlador_ordenarPerritos(this);

		if(ret) {

			printf("\n\n\n*******************************************************************************************************************\n\n"
					"Se han ordenado los datos exitosamente!\n\n"
					"*******************************************************************************************************************\n\n");
		}
		else {
			printf("\n\nHa ocurrido un error...\n\n");
		}

	}
	else {
		printf("\n\n\nERROR! <<No hay perritos cargados en el sistema>>\n");
	}

	system("pause");

	return ret;
}




/**
 * @fn int controlador_ordenarPerritos(LinkedList*)
 * @brief ordena los perritos por nombre ascendente.
 *
 * @param this
 * @return [0] si ERROR / [1] si OK
 */
int controlador_ordenarPerritos(LinkedList* this) {

	int retorno = 0;
	int criterioDeOrdenamiento = 1;
	int (*pSortByName)() = sortByName;

	if(this != NULL) {
		ll_sort(this, pSortByName, criterioDeOrdenamiento);
		retorno = 1;
	}


	return retorno;
}




/**
 * @fn void mostrarListaPerritos(LinkedList*, int)
 * @brief muestra un listado de los perritos cargados en el sistema.
 *
 * @param this
 * @param flag
 */
void mostrarListaPerritos(LinkedList* this, int flag) {

	if(flag) {
		controlador_listaPerritos(this);
	}
	else {
		printf("\n\n\nERROR! <<No hay perritos cargados en el sistema>>\n\n");
	}

	printf("\n\n");
	system("pause");
}




/**
 * @fn int controlador_listaPerritos(LinkedList*)
 * @brief Trae cada perrito cargado en la lista y lo muestra en pantalla.
 *
 * @param this
 * @return
 */
int controlador_listaPerritos(LinkedList* this) {

	ePerrito *pPerrito = NULL;
	int retorno = 0;

	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];

	if(this != NULL)
	{
		printf("\n\n\n\nLISTA DE PERRITOS\n"
				"-------------------------------------------------------------------------------------------------------------------\n"
				"%-20s %-30s %-20s %-20s %-20s", "ID", "Nombre", "Peso", "Edad", "Raza\n"
				"-------------------------------------------------------------------------------------------------------------------\n" );

		for (int i = 0; i < ll_len(this); ++i) {

			pPerrito = (ePerrito*) ll_get(this, i);

			perrito_getId(pPerrito, &id);
			perrito_getNombre(pPerrito, nombre);
			perrito_getPeso(pPerrito, &peso);
			perrito_getEdad(pPerrito, &edad);
			perrito_getRaza(pPerrito, raza);

			pPerrito = NULL;
			printf("%-20d %-30s %-20.2f %-20d %-20s\n", id, nombre, peso, edad, raza);
		}

		retorno = 1;
	}


    return retorno;
}




/**
 * @fn void mostrarMensajeDespedida(void)
 * @brief muestra el mensaje de finalizacion del programa
 *
 */
void mostrarMensajeDespedida(void) {

	printf("\n\n\n"
			"===================================================================================================================\n"
			"Programa finalizado!\n"
			"===================================================================================================================");
}




