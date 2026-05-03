#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo * Siguiente;
} Nodo;


Nodo *crearListas();
Nodo *crearTarea();

int main ()
{
    srand(time(NULL));

    Nodo *startTareasPendientes = crearListas(); //creo lista de tareas pendientes
    Nodo *starttareasRealizadas = crearListas(); //creo lista de tareas realizadas
    Nodo *tarea; //tarea a ingresar
    int ID = 1000;
    int *p_id = &ID; 
    //hasta aqui cree los punteros de listas pendientes y realizadas ademas de los nodos (tareas)
    int opcion; //opcion 1 continua cargando tareas, opcion 2 finaliza
    do {
        puts("ingresar opcion");
        puts ("1- cargar tarea");
        puts("2-finalizar");
        scanf("%d", &opcion);
       
          if (opcion == 1){
            tarea = crearTarea();
            tarea->T.TareaID = (*p_id)++;
            if (startTareasPendientes == NULL){ //guarda la tarea al final de la lista (hacer funcion)
                startTareasPendientes = tarea;
            }else{
                Nodo *aux = startTareasPendientes;
                while(aux->Siguiente){
                    aux = aux->Siguiente;
                }
                aux->Siguiente = tarea;
            }
            ////
        }
        
    }while(opcion == 1);

    return 0 ;
}

Nodo *crearListas() 
{
    return NULL;
}

Nodo *crearTarea()
{
    Nodo *tarea = (Nodo *)malloc(sizeof(Nodo));
    tarea->Siguiente = NULL; //apunta a nulo
    char *buffer = (char *)malloc(100 * sizeof(char)); //variable auxiliar para la asignacion dinamica de memoria de la variable "descripcion"
    //agrego informacion al nodo tarea
    puts("escribir informacion de la tarea: ");
    fflush(stdin);
    gets(buffer);
    tarea->T.Descripcion = (char *)malloc((strlen(buffer) + 1) * sizeof(char)); //asignacion dinamica de memoria
    strcpy(tarea->T.Descripcion, buffer); //guardo la descripcion 
    tarea->T.Duracion = rand()% 100 + 10 ; //duracion de la tarea

    return tarea;
}