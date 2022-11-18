#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define True 1
#define False 0

	typedef struct Arbol{
		int info;
		struct Arbol* izq;
		struct Arbol* der;
}	arbol;

	void inicializar(arbol ** a);
	int vacio(arbol* a);
	void insertar(arbol ** a, int e);
	void borrar(arbol ** a, int c);
	void buscar(arbol * a, int c, int * encontrado);
	void recorreras(arbol * a);
	void recorrerdes(arbol * a);
	arbol* construir(arbol * a, int e, arbol * b);
	void menor(arbol* a, int * e);
	void eliminar( arbol ** a);
	void inicializar(arbol ** a){
		*a = NULL;
	};
	int vacio(arbol* a){
		return a == NULL;
	}
	void buscar(arbol * a, int c, int * encontrado){
		if (vacio(a))
			* encontrado = False;
		else
		if (a->info == c)
			*encontrado = True;
		else
		if (a->info > c)
			buscar(a->izq, c, encontrado);
		else
			buscar(a->der, c, encontrado);
	}

	arbol* construir(arbol * a, int e, arbol * b){
		arbol* nuevo;
		nuevo = (arbol*)malloc(sizeof(arbol));
		nuevo->info = e;
		nuevo->izq = a;
		nuevo->der = b;
	return nuevo;
	}
	void insertar(arbol ** a, int e){
		if (vacio(*a))
			*a = construir(NULL, e, NULL);
		else
		if ((*a)->info > e)
			insertar(& (*a)->izq, e);
		else
		if ((*a)->info < e)
			insertar(& (*a)->der, e);
	}
	void menor(arbol* a, int* e){
		if (a->izq == NULL)
			*e = a->info;
		else
			menor(a->izq, e);
	}

	void eliminar( arbol ** a){
		arbol* auxi;
		int e;
		if ((*a)->izq == NULL){
			auxi = *a; *a = (*a)->der;
			free (auxi);
		}
		else
		if ((*a)->der == NULL){
			auxi = *a; *a = (*a)->izq;
			free (auxi);
		}
		else{
			menor((*a)->der, & e); (*a)->info = e;
			borrar(&(*a)->der, e);
		}
	}

	void borrar(arbol ** a, int c){
		if (*a != NULL )
			if ((*a)->info == c)
				eliminar(a);
			else
		if ((*a)->info > c)
			borrar(&(*a)->izq, c);
		else
			borrar(&(*a)->der, c);
	}

	void recorreras(arbol * a){
		if (! vacio(a)){
			recorreras(a->izq);
			printf(" %d ", a->info);
			recorreras(a->der);
		}
	}

	void recorrerdes(arbol * a){
		if (! vacio(a)){
			recorrerdes(a->der);
			printf(" %d ", a->info);
			recorrerdes(a->izq);
		}
	}

int main(){
	setlocale(LC_ALL, "spanish");
	int nm;
	arbol* a;
	char pausa;
		inicializar (&a);
		printf("Ingrese un número (0 -> Fin): ");
		scanf("%d*c ", &nm);
	while (nm !=0){
		insertar(&a,nm);
		printf("Ingrese un número (0 -> Fin): ");
		scanf("%d*c ", &nm);
	}
	recorrerdes(a);
	puts("");
	recorreras(a);
	printf("\n Pulse cualquier tecla para continuar ... ");
	scanf("%c%*c",&pausa);
	
return 0;
}
