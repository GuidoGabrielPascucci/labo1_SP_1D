/*
 ============================================================================
 Name        : SP_Labo1_PascucciGuido.c
 Author      : Pascucci, Guido 1-D
 ============================================================================
*/

/// 1. Leer de un archivo .csv los datos de los perritos y guardarlos de manera dinámica en un LinkedList. Para ello se deberá crear la entidad:
/// 2. Listar a todos los perritos ordenados de manera ascendente por nombre. NOTA: Utilizar constructores, getters y setters.

/// 3. Calcular en un nuevo campo (de ePerrito) la “cantidadComidaRacion” (flotante) de cada uno de los perritos leídos.
/// El criterio para calcularlo es: peso * 23
/// Para hacer este cálculo, se deberá desarrollar la función ll_map en la biblioteca LinkedList, la cual recibe la lista y una función.
/// int ll_map(LinkedList* this, int (*pFunc)(void*));
/// La función ll_map ejecutará la función recibida como parámetro por cada ítem de la lista, y le pasará, en cada llamada, uno de los ítems.
/// int ePerrito_laQueMapea(void*);
/// De esta manera, la función pasada como parámetro podrá realizar un cálculo con el ítem recibido, en este caso, calcular la ración de comida.

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

