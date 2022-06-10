/*
Jóvenes Buenos días para el día de hoy se desarrollara una práctica, la práctica se subirá en el trabajo asignado para este fin, 
con la debida descripción para la siguiente clase el día Lunes de las 9:00 am a 11am y se revisará la sub siguiente clase síncrona, 
en esta práctica se deberá:

Modificar el código definido de los Árboles ABB de manera que en la estructura Nodo el dato sea reemplazado por el primer campo de 
la tabla y además contemple los otros campos indicados para cada caso.

struct Nodo{
	int dato;//primer campo de búsqueda reemplazarlo por el primero de las tablas
	//...
	//campos con nuevos datos de las tablas
	//….
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
	};
struct Nodo{
	int codigo;
	string nombre;
	int nota1;
	int nota2;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

A. La modificación permitirá también desarrollar todas las operaciones del árbol que trabajan hasta ahora, con las salvedades 
siguientes (Todos los estudiantes desarrollaran estas funciones):

1. Cuando se haga la búsqueda del nodo se muestre los otros campos además del primer campo básico. | void mostrar();
2. Ingrese los datos de las tablas que se le indican se ingresen automáticamente. | void ingresar_todos_datos_automaticamente();
3. Además, cuando se ingresen otros datos con la función respectiva no solo se ingrese el primer campo básico sino los otros datos más.
4. Cuando se muestre el árbol con la función regular puede hacerlo solo en base al primer campo; 
Cree otra función además de ola anterior donde se muestre el árbol, pero con todos los datos de la estructura.

Código = {0,1,2,3,4,5}
Nombre = {JUAN,LUIS,MILENA,PABLO,PEPE,ALBERTO}
Nota 1 = {11,15,20,12,5,12}
Nota 2 = {11.5,12.65,16,17,08,17.5}

Incluir opciones en el menú que calculen:

1. Sumar las notas 1 y 2 en forma individual y determine el promedio de la nota 1 y 2.
2. Sacar el promedio individual y mostrarlo.
3. Cuantos aprobados hay y cuantos desaprobados según el promedio individual.
3. Calcule el promedio de todas las notas (incluye la Nota 1 y la Nota 2) en forma global de toda la clase.
 */
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

struct Nodo{
	int codigo;
	string nombre;
	float nota1;
	float nota2;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

Nodo *arbol =NULL;

Nodo *crearNodo(int c,string n,float n1,float n2,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->codigo = c;
	nuevo_nodo->nombre = n;
	nuevo_nodo->nota1 = n1;
	nuevo_nodo->nota2 =n2;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}
//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int c,string n,float n1,float n2,Nodo *padre){
	if(arbol==NULL){
	Nodo *nuevo_nodo = crearNodo(c,n,n1,n2,padre);
	arbol=nuevo_nodo;
	}else{//sino el arbol tiene 1 o mas de un nodos
	int valorRaiz = arbol->codigo; //se obtiene el valor de la raiz
		if(c<valorRaiz){ //Si el elemento es menor a la raiz se inserta en la izquierda
		insertarNodo(arbol->izq,c,n,n1,n2,arbol);
		}else{ ////Si el elemento es mayor a la raiz se inserta en la derecha
			insertarNodo(arbol->der,c,n,n1,n2,arbol);
			}
		}
}
void mostrar_regular(Nodo *arbol,int n){
    if(arbol == NULL){
        return;
    }else if(arbol->codigo == n){
        mostrar_regular(arbol->der,n);
        cout<<arbol->codigo<<endl;
        cout<<arbol->nombre<<endl;
        cout<<arbol->nota1<<endl;
        cout<<arbol->nota2<<endl;
    }
}
//Funcion para mostrar nodos
void mostrarArbol(Nodo *arbol,int contador){
	if(arbol==NULL){
	return;
	}else{
		mostrarArbol(arbol->der,contador+1);
		for(int i=0;i<contador;i++){
		cout<<"         ";
		}
	cout<<arbol->codigo<<endl;
	mostrarArbol(arbol->izq,contador+1);
	}
}
//Buscar en base a un elemento
void mostrar_buscar(Nodo *arbol, int n){
	if(arbol == NULL){
		cout<<".-NO se encontro al Alumno-."<<endl;
	return;
	}else if(arbol->codigo == n){
		cout<<" Alumno Encontrado"<<endl;
        cout<<"  -Codigo: "<<arbol->codigo<<endl;
        cout<<"  -Nombre: "<<arbol->nombre<<endl;
        cout<<"  -Nota 1: "<<arbol->nota1<<endl;
        cout<<"  -Nota 2: "<<arbol->nota2<<endl;
		return;
		}else if(n < arbol->codigo){
		mostrar_buscar(arbol->izq,n);
		}else{
		mostrar_buscar(arbol->der,n);
		}
}

//Mostrar Todos los estudiantes
void mostrar_estudiantes(Nodo *arbol, int n){
	if(arbol == NULL){
        cout<<"\nNo hay nada que Mostrar\n";
	return;
	}else{
		cout<<arbol->codigo +1<<"º Estudiante"<<":"<<endl;
        cout<<"  -Codigo: "<<arbol->codigo<<endl;
        cout<<"  -Nombre: "<<arbol->nombre<<endl;
        cout<<"  -Nota 1: "<<arbol->nota1<<endl;
        cout<<"  -Nota 2: "<<arbol->nota2<<endl<<endl;
        mostrar_estudiantes(arbol->der,n);
		}
}

//determinar el nodo mas izquierdo posible
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}if(arbol->izq){
		//buscamos el hijo mas izquierdo del arbol
		return minimo(arbol->izq);
	}else{
		//retornamos el mismo nodo
		return arbol;
	}
}
//Reemplazar un nodos por le otro un solo hijo
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	//si tiene padre
	if(arbol->padre){
		//arbolpadre asgnamos su nuevo hijo
		if(arbol->codigo == arbol->padre->izq->codigo){
			arbol->padre->izq = nuevoNodo;
		}
		//le asignamos al nodo su nuevo padre
        else if(arbol->codigo == arbol->padre->der->codigo){
			arbol->padre->der = nuevoNodo;
		}
	}if(nuevoNodo){
		//Le aseignamos su nueov padre
		nuevoNodo->padre = arbol->padre;
	}
}
//Destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}
//eliminar un nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	//si el nodo tiene ambos hijos
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->codigo = menor->codigo;
		eliminarNodo(menor);//si el nodo tiene Dos hijos
	}else if(nodoEliminar->izq){//si el nodo tiene un solo hijoizquiedo
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}else if(nodoEliminar->der){//si el nodo tiene un solo hijo derrecho
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}else{//si el nodo es una hoja
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}
//Eliminar Nodos de arbol
void eliminar(Nodo *arbol,int n){
	if(arbol == NULL){
		return;
	}else if(n < arbol->codigo){
		//busca por la izquierda
		eliminar(arbol->izq,n);
	}else if(n > arbol->codigo){
		//busca por la derecha
		eliminar(arbol->der,n);
	}else{ //si ya lo encontraste eliminamos con otra funcion
		eliminarNodo(arbol);
	}
}
//menu
void menu(){
	int codigo, opcion,opcion2, contador = 0;
	char sino;

string nombre[] = {"JUAN","LUIS","MILENA","PABLO","PEPE","ALBERTO"};
float nota1[] = {11,15,20,12,5,12};
float nota2[] = {11.5,12.65,16,17,8,17.5};

	do{
		cout<<" ************************\n";
		cout<<"| 1. Agregar Estudiantes |\n";
		cout<<"| 2. Mostrar Nodos       |\n";
		cout<<"| 3. Buscar Nodo         |\n";
		cout<<"| 4. Mostrar Estudiantes |\n";
		cout<<"| 5. Promedio Individual |\n";
		cout<<"| 6. Nro de Aprobados y  |\n";
		cout<<"|    Desaprobados        |\n";
		cout<<"| 7. Promedio General    |\n";
		cout<<"| 10. Salir              |\n";
        cout<<" ************************\n";
		cout<<"\nOpcion: ";
		cin>>opcion;

		switch(opcion){
			case 0:	cout<<"Ingrese Codigo: ";
                    cout<<"Ingrese Nombre: ";
                    cout<<"Ingrese Nota 1: ";
                    cout<<"Ingrese Nota 2: ";
					break;
			case 1: cout<<"Se Agregaran los Estudiantes"<<endl<<"Desea Continuar? Y/N :\n";
					cin>>sino;
					if(sino == 'Y' || sino == 'y'){
						for(int i=0;i<6;i++){
						insertarNodo(arbol,i,nombre[i],nota1[i],nota2[i],NULL); //Insertamos automaticamente
						}
						cout<<"Add Successfully!\n";
					}
					break;
			case 2:	if(arbol == NULL){
						cout<< "El arbol esta vacio\n";
					}else{
						cout<< "Mostrando el Arbol\n";
						mostrarArbol(arbol,contador);
					}					
					break;
			case 3: do{
						cout<<"	 *********************\n";
						cout<<"	| 1.Buscar por Codigo |\n";
						cout<<"	| 2.Buscar por Nombre |\n";
						cout<<"	| 3.Salir             |\n";
						cout<<"	 *********************\n";
						cout<<"\nOpcion: ";
						cin>>opcion2;
					switch(opcion2){
						case 1:	cout<<"Buscar Codigo: ";
						cin>>codigo;
						mostrar_buscar(arbol,codigo);
								break;
						case 2: 
								break;
					}
					}while(opcion != 3);					
						break;
            case 4: cout<<"Detalle de Estudiantes\n\n";
					mostrar_estudiantes(arbol,5);					
					break;
		}
		system("pause");
		system("cls");
	}while(opcion != 10);
}

int main(){
	menu();
	
	return 0;
}
