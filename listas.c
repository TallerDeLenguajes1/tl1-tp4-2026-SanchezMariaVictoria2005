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
Nodo *buscarTarea(Nodo ** startTareasPendientes, int id) ;
void trasferirTarea(Nodo ** startTareasRealizadas, Nodo *tarea);
void mostrarListas(Nodo ** startTareasPendientes, Nodo ** startTareasRealizadas);

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

    int id ; //id de la tarea a ingresar

    do
    {
        puts ("1-mover tarea pendiente a realizada");
        puts("2- finalizar");
        scanf("%d", &opcion);

        if (opcion == 1){
            puts("ingrese id de la tareas");
            scanf("%d", &id); //guardo el id ingresado
            tarea = buscarTarea(&startTareasPendientes, id);
            if (tarea){
               
                trasferirTarea(&starttareasRealizadas,tarea); 
                
            }else{
                puts("el id ingresado es incorrecto");
            }
            
        }

    }while(opcion == 1);

     mostrarListas(&startTareasPendientes, &starttareasRealizadas);

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

Nodo *buscarTarea(Nodo **startTareasPendientes, int id) 
{
    Nodo *aux = *startTareasPendientes;
    Nodo *anterior = *startTareasPendientes;
    
    while(aux != NULL && aux->T.TareaID != id){
        anterior = aux ;
        aux = aux->Siguiente; //me muevo en las listas hasta encontrar la que tiene el mismo id ingresado o hasta que apunte al final de la lista
    }

    if (aux){
        anterior->Siguiente = anterior->Siguiente->Siguiente;
    }
    
    return aux;
}

void trasferirTarea(Nodo **startTareasRealizadas, Nodo *tarea)
{
    
    tarea->Siguiente = *startTareasRealizadas;
    *startTareasRealizadas = tarea;
}

void mostrarListas(Nodo **startTareasPendientes, Nodo **startTareasRealizadas)
{
    Nodo *auxPendientes = *startTareasPendientes;
    Nodo *auxRealizadas = * startTareasRealizadas;

    puts("tareas pendientes:");
    while (auxPendientes != NULL){
        printf("ID: %d", auxPendientes->T.TareaID);
        puts("descripcion:");
        puts(auxPendientes->T.Descripcion);
        printf("duracion: %d", auxPendientes->T.Duracion);
        auxPendientes = auxPendientes->Siguiente;
    }

    puts("tareas Realizadas");
    while (auxRealizadas != NULL){
        printf("ID:%d", auxRealizadas->T.TareaID);
        puts("descripcion:");
        puts(auxRealizadas->T.Descripcion);
        printf("duracion: %d", auxRealizadas->T.Duracion);
        auxRealizadas = auxRealizadas->Siguiente;
    }
}