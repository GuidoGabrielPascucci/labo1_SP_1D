/*
 ============================================================================
 Name        : SP_Labo1_PascucciGuido.c
 Author      : Pascucci, Guido 1-D
 ============================================================================
*/

/// 1. Leer de un archivo .csv los datos de los perritos y guardarlos de manera din�mica en un LinkedList. Para ello se deber� crear la entidad:
/// 2. Listar a todos los perritos ordenados de manera ascendente por nombre. NOTA: Utilizar constructores, getters y setters.

/// 3. Calcular en un nuevo campo (de ePerrito) la �cantidadComidaRacion� (flotante) de cada uno de los perritos le�dos.
/// El criterio para calcularlo es: peso * 23
/// Para hacer este c�lculo, se deber� desarrollar la funci�n ll_map en la biblioteca LinkedList, la cual recibe la lista y una funci�n.
/// int ll_map(LinkedList* this, int (*pFunc)(void*));
/// La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem de la lista, y le pasar�, en cada llamada, uno de los �tems.
/// int ePerrito_laQueMapea(void*);
/// De esta manera, la funci�n pasada como par�metro podr� realizar un c�lculo con el �tem recibido, en este caso, calcular la raci�n de comida.

/// 4. Listar los perritos con sus raciones de comida.





#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);

    LinkedList* listaPerris = ll_newLinkedList();
    controlador_menuPrincipal(listaPerris);
    ll_deleteLinkedList(listaPerris);

	return EXIT_SUCCESS;
}

