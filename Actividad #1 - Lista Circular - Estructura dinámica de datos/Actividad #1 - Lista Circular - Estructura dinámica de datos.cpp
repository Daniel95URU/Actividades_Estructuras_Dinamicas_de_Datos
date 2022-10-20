#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

char nombre [50];						//Nombre de la lista.

typedef struct nodo{					//Creación de la estructura del nodo
	int dato;
	char datos2 [];
	struct nodo* siguiente;
} nodo;
nodo* siguiente = NULL;					//Primeros datos
nodo* anterior = NULL;					//Datos posteriores

void insertarNodo(); 				//Funciones para las distintas operaciones con la lista
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void Lista();						//recorrer la lista.

int main(){
	
	setlocale(LC_ALL,"spanish");			//La función setlocale en "spanish" selecciona la porción apropiada del escenario del programa y convierte los símbolos que no tienen soporte.
	int opc = 0;
	
		printf("|Bienvenido a este programa que te permitirá crear una lista circular en C|");
		printf("\n\nColoque un nombre a la lista: ");
		gets(nombre);
		
	do{																				//Menú de selección.
		printf("\n---------------------------------------------------------¬");
		printf("\n| 1. Insertar un nuevo nodo en la lista                  |");
		printf("|\n| 2. Buscar nodos especificos en la lista.               |");       
		printf("|\n| 3. Modificar nodos de la lista.                        |");
		printf("|\n| 4. Eliminar datos de la lista.                         |");
		printf("|\n| 5. Mostrar la lista de datos.                          |");
		printf("|\n| 6. Salir del programa.                                 |");
		printf("|\n----------------------------------------------------------");
		printf("\n\n Escoja una opción: ");
		scanf("%d", &opc);
		system("cls");
		switch(opc){
			case 1:
				printf("\nInsertar un nodo en la lista '%s' \n\n", nombre);
				insertarNodo();
				break;
			case 2:
				printf("\nBuscar un nodo en la lista. ´%s´\n\n", nombre);
				buscarNodo();
				break;	
			case 3:
				printf("\nModificar un nodo de la lista ´%s´ \n\n", nombre);
				modificarNodo();
				break;
			case 4:
				printf("\nEliminar un nodo de la lista '%s' \n\n", nombre);
				eliminarNodo();
				break;
			case 5:
				printf("\nMostrar la lista creada. \n\n");
				Lista();
				break;
			case 6:
				printf("\nEl programa ha finalizado...");
				break;
			default:
				printf("\n\n La opción ingresada no existe...\n\n");				//Marca de error.
		}
	}while(opc != 6);
	return 0;
}           


void insertarNodo(){										//Permite crear e insertar nodos a una lista.
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d",&nuevo->dato);
	
	if(siguiente==NULL){
		siguiente = nuevo;
		siguiente->siguiente = siguiente;
		anterior = siguiente;
	}else{
		anterior->siguiente = nuevo;
		nuevo->siguiente = siguiente;
		anterior = nuevo;
	}
	printf("\n Nodo ingresado con éxito\n\n");
}

void buscarNodo(){												//Función que permite encontrar un nodo de la lista y determinar si existe al usuario.
	nodo* act = (nodo*)malloc(sizeof(nodo));
	act = siguiente;
	int Buscador = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo a buscar: ");
	scanf("%d",&Buscador);
	if(siguiente!=NULL){											/*Si el primer dato es diferente de NULL, se prosigue con el ciclo que determina si "encontrado" aumentará 
																	y por ende serán determinados como Nodos existentes en la lista */
		do{															
			if(act->dato == Buscador){
				printf("\n Nodo con el dato (%d) encontrado\n\n", Buscador);
				encontrado = 1;
			}
			act = act->siguiente;
		}while(act!=siguiente && encontrado!=1);
		
		if(encontrado==0){
			printf("\n Nodo no encontrado\n\n");
		}else{
			printf("\n La lista ´%s´ no se encuentra vacía\n\n", nombre);				//Mensaje que aparecerá siempre que la lista no disponga de datos.
		}	
}
}
void modificarNodo(){										//Función que permite modificar un nodo (en caso de existir dos nodos iguales se modificará el último registrado)
	nodo* act = (nodo*)malloc(sizeof(nodo));
	act = siguiente;
	int Buscador = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo a Buscar para Modificar: ");
	scanf("%d",&Buscador);
	if(siguiente!=NULL){
		do{
			if(act->dato == Buscador){
				printf("\n Nodo con el dato (%d) Encontrado", Buscador);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d",&act->dato);
				printf("\n Nodo modificado con exito\n\n");
				encontrado = 1;
			}
			act = act->siguiente;
		}while(act!=siguiente && encontrado!=1);
		
		if(encontrado==0){
			printf("\nNodo no encontrado en la lista\n\n");
		}
	}else{
		printf("\nLa lista ´%s´ se encuentra vacía\n\n", nombre);
	}	
}

void eliminarNodo(){								//Función que ejecuta la operación para eliminar el nodo introducido (en nodos similares se elimina el último de la lista)
	nodo* act = (nodo*)malloc(sizeof(nodo));
	act = siguiente;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int Buscador = 0, encontrado = 0;
	printf(" Ingrese el valor de nodo eliminará: ");
	scanf("%d",&Buscador);
	if(siguiente!=NULL){											//Si el primer nodo [x] es diferente de NULL se procede el ciclo para encontrar y eliminar (Misma operación de BuscarNodo)
		do{
			if(act->dato == Buscador){
				printf("\n Nodo con el dato (%d) encontrado", Buscador);
				if(act==siguiente){
					siguiente = siguiente->siguiente;
					anterior->siguiente = siguiente;
				}else if(act==anterior){
					anterior->siguiente  = siguiente;
					anterior = anterior;
				}else{
					anterior->siguiente = act->siguiente;
				}
				printf("\n El nodo acaba de ser eliminado\n\n");				//Para eliminar un nodo, tienen que existir mínimo 2 datos en una lista de lo contrario se eliminará la lista.		
				encontrado = 1;
			}
			anterior = act;
			act = act->siguiente;
		}while(act!=siguiente && encontrado!=1);
		
		if(encontrado==0){
			printf("\nNodo no encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("La lista ´%s´ se encuentra vacía\n\n", nombre);
	}
}

void Lista(){													//Visualización de los datos introducidos.
	nodo* act = (nodo*)malloc(sizeof(nodo));					//Nodo asignado a un bloque de memoria size (recurrente en el programa)
	act = siguiente;
	if(siguiente!=NULL){
		printf("La lista ´%s´ se encuentra conformado por: \n", nombre);
		do{
			printf(" %d -", act->dato);
			act = act->siguiente;
		}while(act!=siguiente);
	}else{
		printf("\n La lista %s se encuentra vacía\n\n", nombre);
	}	
}
