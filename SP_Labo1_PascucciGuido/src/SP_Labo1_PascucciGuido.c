/*
 ============================================================================
 Name        : SP_Labo1_PascucciGuido.c
 Author      : Pascucci, Guido 1-D
 ============================================================================
*/

/// 1. Leer de un archivo .csv los datos de los perritos y guardarlos de manera dinámica en un LinkedList. Para ello se deberá crear la entidad:
/// 2. Listar a todos los perritos ordenados de manera ascendente por nombre. NOTA: Utilizar constructores, getters y setters.

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

