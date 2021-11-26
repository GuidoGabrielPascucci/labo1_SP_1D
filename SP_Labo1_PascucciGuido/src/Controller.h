

void controlador_menuPrincipal(LinkedList* this);
int mostrarMenuPrincipal(void);
void cargarArchivoDeTexto(LinkedList* this, int* fileIsOpen, int* flag);
int controlador_cargarArchivoTexto(char* path , LinkedList* this);

/// Ordenar Perritos
int ordenarPerritos(LinkedList* this, int flag);
int controlador_ordenarPerritos(LinkedList* this);
/// Mostrar Lista Perritos
void mostrarListaPerritos(LinkedList* this, int flag);
int controlador_listaPerritos(LinkedList* this);


/// Exit program
void mostrarMensajeDespedida(void);














