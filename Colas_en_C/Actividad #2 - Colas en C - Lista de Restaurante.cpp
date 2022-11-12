#include <stdlib.h> 
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <locale.h>

void creacion();
void EnCola();
void MostrarElementos();
void FueraDeCola();

struct nodo {
    int data;
    struct nodo* sig;
}; 

struct  nodo *crearNodo (int  data){
    struct nodo * nuevo =  (struct nodo*) malloc( sizeof (struct  nodo));
    nuevo->data = data;
    nuevo->sig  = NULL;
    return nuevo;
};

struct cola{
	struct nodo *primero, *ultimo;
	char nombre[50];
	char apellido[50];
	char comanda[50]; 		/*Nombre de quien tomó la orden*/
	char platos[50];
	char bebida[50];
	int ID; 			   	/*ID del pedido*/
	char costo [50]; 		/*Para el valor decimal expresado con "."*/
	struct cola *sig;
}*Inicio, *final;
	
	int j=0;

int main(){
	setlocale(LC_ALL, "spanish");
	int opc;
		do{
			printf("\tBienvenido, este programa que creará una cola de espera en un restaurante, seleccioné una opción del menú.\n\n");
			printf("1. Ingresar los datos de un nuevo pedido.\n2. Mostrar elementos de los datos almacenados en la cola\n3. Retirar datos de la cola\n4. Salir del programa.\n\n");
			scanf("%d", &opc);
			system("cls");
		switch (opc){
			case 1:
				EnCola();
				system("cls");
			break;
			case 2:
				MostrarElementos();
				getch();
				system("cls");
			break;
			case 3:
				FueraDeCola();
			break;	
			default: printf("\n\n\t\t--|\20Presioné 4. para salir del programa.\21|--\n\n");
			break;
		}
			}while(opc!=4);
}

void EnCola(){							//Crear e ingresar datos del nodo en la cola
	struct cola *nuevo;
		nuevo=(struct cola *)malloc(sizeof(struct cola));
		printf("Introduzca el nombre del cliente: \n");
		scanf("%s",&nuevo->nombre);
		printf("Introduzca el apellido del cliente: \n");
		scanf("%s",&nuevo->apellido);
		printf("Introduzca el nombre de quien tomó el pedido: \n");
		scanf("%s",&nuevo->comanda);
		printf("Introducir el ID del pedido: \n");
		scanf("%d",&nuevo->ID);
		printf("Introduzca el plato ordenado: \n");			/*Un plato por cola y separado con "_"*/
		scanf("%s",&nuevo->platos);
		printf("Introduzca la bebida ordenada: \n");			/*Una bebida por cola*/
		scanf("%s",&nuevo->bebida);
		printf("Introduzca el precio total a pagar: \n");
		scanf("%s",&nuevo->costo);
	nuevo->sig=NULL;
	
	if(Inicio==NULL){
		Inicio=nuevo;
		final=nuevo;
	}else{
		final->sig=nuevo;
		final=nuevo;
	}
	j++;
}

void MostrarElementos(){					//Mostrar el recorrido de la cola
	struct cola *aux;
		aux=Inicio;
	if(aux==NULL){
		printf("Cola vacía, ingrese datos a la cola...\n");
	}else{
		while(aux!=NULL){
			printf("Nombre y apellido del cliente: %s %s\nPedido a: %s\nPedido número: %d\nPlatos ordenados: %s\nBebidas ordenadas: %s\n\nTotal a pagar: %s\n \n", aux->nombre,aux->apellido,aux->comanda,aux->ID,aux->platos,aux->bebida,aux->costo);
			aux=aux->sig;
		}
	}
	getch();
}

void FueraDeCola(){					//Eliminar siguiendo los conceptos del FIFO
	struct cola *aux;
	struct cola *aux1;
		int cont;
		aux=Inicio;
		aux1=Inicio;
	cont=0;
		while(aux!=NULL){
			if(aux->ID==aux1->ID){
				if(cont==0){
				Inicio=Inicio->sig;
				}
			}
			aux=aux->sig;
			aux1=aux;
			cont=1;
		}
}

 
