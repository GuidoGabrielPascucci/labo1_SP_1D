
#ifndef PERRITOS_H_
#define PERRITOS_H_
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[21];
    float peso;
    int edad;
    char raza[21];
    float cantidadComidaRacion;
}ePerrito;



/// Builders & Destruct
ePerrito* perrito_new();
ePerrito* perrito_newParametros(char* idStr, char* nombreStr, char* pesoStr, char* edadStr, char* razaStr);
void perrito_delete(ePerrito* this);


/// Setters & Getters
int perrito_setId(ePerrito* this, int id);
int perrito_getId(ePerrito* this, int* id);

int perrito_setNombre(ePerrito* this, char* nombre);
int perrito_getNombre(ePerrito* this, char* nombre);

int perrito_setPeso(ePerrito* this, float peso);
int perrito_getPeso(ePerrito* this, float* peso);

int perrito_setEdad(ePerrito* this, int edad);
int perrito_getEdad(ePerrito* this, int* edad);

int perrito_setRaza(ePerrito* this, char* raza);
int perrito_getRaza(ePerrito* this, char* raza);

int perrito_setCantidadComidaRacion(ePerrito* this, float cantidadComidaRacion);
int perrito_getCantidadComidaRacion(ePerrito* this, float* cantidadComidaRacion);


/// Sort
int sortByName(ePerrito* pPerritoA, ePerrito* pPerritoB);


/// La que mapea
int ePerrito_laQueMapea(void* pElement);





#endif
