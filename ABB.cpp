#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
/*
Jóvenes Buenos días, para hoy la siguiente practica:
1. Según el número de orden de la lista de estudiantes resolver el ejercicio que se les indica a continuación.
Nro de             Trabajo a Desarrollar
Orden
1-3                   Al recorrer el árbol cuantas llanadas recursivas
////////////////////////////////4-6                   Encontrar el nivel del árbol
////////////////////////////////7-9                   Encontrar el mayor elemento
////////////////////////////////10-12               Encontrar el menor elemento
////////////////////////////////13-15               Sumar y Hallar el Promedio
////////////////////////////////16-18               Mostrar de mayor a menor
////////////////////////////////19-21               Mostrar de menor a mayor
22-24               Al recorrer el árbol cuantas paradas hay
////////////////////////////////Nota: No utilice variables globales, utilice recursividad////////////////////////////////
2. Además del ejercicio anterior, si le alcanza tiempo resuelva un ejercicio más que no se le asigno de la lista
Subir su practica en el trabajo con el mismo nombre del foro en el sistema hasta las 11:00am
*/
using namespace std;

struct Nodo{
int dato;
Nodo *der;
Nodo *izq;
};
//inicio global el puntero arbol como NULL
Nodo *arbol =NULL;
//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato =n;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	return nuevo_nodo;
}
//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol==NULL){ //Si est vacio el arbol o subarbolcreamos un nuevo nodo
	Nodo *nuevo_nodo = crearNodo(n);
	arbol=nuevo_nodo;
	}else{//sino el arbol tiene 1 o mas de un nodos
	int valorRaiz = arbol->dato; //se obtiene el valor de la raiz
		if(n<valorRaiz){ //Si el elemento es menor a la raiz se inserta en la izquierda
		insertarNodo(arbol->izq,n);
		}else{ ////Si el elemento es mayor a la raiz se inserta en la derecha
			insertarNodo(arbol->der,n);
			}
		}
}
//Funcion par mstrar arbolcompleto
void mostrarArbol(Nodo *arbol,int contador){
	if(arbol==NULL){
	return;
	}else{
		mostrarArbol(arbol->der,contador+1);
		for(int i=0;i<contador;i++){
		cout<<"    ";
		}
	cout<<arbol->dato<<"|"<<endl;
	mostrarArbol(arbol->izq,contador+1);
	}
}

void mostrar(Nodo *arbol,string arista){
	if(arbol == NULL){
		return;
	}else{
		cout<<arbol->dato;
		if(arbol->izq!=NULL)
			if(arbol->izq!=NULL){
				cout<<arista<<"+----\n";
			}else{
				cout<<"+----\n";
			}
		return mostrar(arbol->izq,"|    ");
		}
		if(arbol->der!=NULL){
			cout<<arista<<"+----";
			return mostrar(arbol->der,"|    ");
		}
}
//Funcion Para buscar
//funcion de tipo bool para que retorne si el dato exsiste en el arbol;
int buscar(Nodo *arbol, int n){
	if(arbol == NULL){//caso de parada, si el arbol esta vacio,retornamos falso,
	return false;
	}else if(arbol->dato == n){
		return true;//sino si el dato es igual al numeor ingreso como parametro retornamos verdadero
		}else if(n<arbol->dato){//si el dato ingresado es menos que el dato del arbol
		return buscar(arbol->izq,n);//buscamos a la izquierda, pasando como parametro lavariable
		}else{//si n es mayor buscamos a la derecha
		return buscar(arbol->der,n);
		}
}
//Funcion para recorrido en profundidad - PreOrden
void preOrden(Nodo *arbol){//le pasamos el dato como parametro
	if(arbol == NULL){//si esta vacio, retornamos el caso base
	return;
	}else{//se imprimira el datocomenzando de la razin
		cout<<arbol->dato<<" - ";//recorremos la raiz
		preOrden(arbol->izq);//le decimos que recorra el arbo, izquierdo
		preOrden(arbol->der);//recorra el subarbol a la derecha
	}
}
//Funcion para recorrido en profundidad - inOrden
void inOrden(Nodo *arbol){//si esta vacio, retornamos el caso base
	if(arbol == NULL){
		return;
	}else{
		inOrden(arbol->izq);//le decimos que recorra el arbo, izquierdo
		cout<<arbol->dato<<" - ";//recorremos la raiz
		inOrden(arbol->der);//recorra el subarbol a la derecha
	}
}
//Funcion para recorrido en profundidad - PostOrden
void postOrden(Nodo *arbol){//si esta vacio, retornamos el caso base
	if(arbol == NULL){
		return;
	}else{
		inOrden(arbol->izq);//le decimos que recorra el arbo, izquierdo
		inOrden(arbol->der);//recorra el subarbol a la derecha
		cout<<arbol->dato<<" - ";//recorremos la raiz
	}
}
//MEno a mayor
void menorAmayor(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		menorAmayor(arbol->izq);
		cout<<arbol->dato<<" - ";
		menorAmayor(arbol->der);
	}
}

// mayor a menor
void mayorAmenor(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		mayorAmenor(arbol->der);
		cout<<arbol->dato<<" - ";
		mayorAmenor(arbol->izq);
	}
}
// Llamadas recursivas
int llarec(Nodo *arbol,int menor,int rec){
	if(arbol == NULL){
		return rec;
	}else if(arbol->dato < menor){
		menor = arbol->dato;
		return llarec(arbol->izq,menor,rec+1);
	}
}
// Llamadas parada
int nroparada(Nodo *arbol,int menor,int parada){
	if(arbol == NULL){
		parada ++;
		return parada;
	}else if(arbol->dato < menor){
		menor = arbol->dato;
		return nroparada(arbol->izq,menor,parada);
	}
}

//Funcion que muestra el elemento menor del arbol
int MenorArbol(Nodo *arbol,int menor){
	if(arbol == NULL){
		return menor;
	}else if(arbol->dato < menor){
		menor = arbol->dato;
		return MenorArbol(arbol->izq,menor);
	}
}

//Funcion que muestra el elemento mayor del arbol
int MayorArbol(Nodo *arbol,int mayor){
	if(arbol == NULL){
		return mayor;
	}else if(arbol->dato > mayor){
		mayor = arbol->dato;
		return MayorArbol(arbol->der,mayor);
	}
}
//funcion suma de elementos delaraobol
int sumar(Nodo *arbol){
	if(arbol == NULL){
		return 0;
	}else{
		int subarbolizq = sumar(arbol->izq); 
		int subarbolder = sumar(arbol->der);
		return arbol->dato + subarbolizq + subarbolder;
	}
}
//funcion cantidad de Nodos para el promeido
int nro_nodos(Nodo *arbol){
	if(arbol == NULL){
		return 0;
	}else{
		return 1 + nro_nodos(arbol->izq) + nro_nodos(arbol->der);
		}
}
/*Funcion par halla la profundidad del arbol es el niel
caso base: si le nodo es una hoja (arbol->iz,der == NULL) sin hijos
*/
int Nivel(Nodo *arbol){
	if(arbol->der == NULL & arbol->izq == NULL){ //nos encontramos en una hoja o un unico nodo padre
		return 0;
	}else{
		int subarbolizq = -1;
		int subarbolder = -1;
		if(arbol->izq != NULL){
			subarbolizq = Nivel(arbol->izq);
			}
		if(arbol->der!=NULL){
			subarbolder = Nivel(arbol->der);
			}
		return 1 + max(subarbolizq,subarbolder);
		}
}
//menu
void menu(){
	int dato, opcion, contador = 0;
	int lista2[]={10,5,20,6,12,7,4,15,11,16,8,27,-6,9};
	int a = sizeof lista2/ 4;
	char sino;

	do{
		cout<<"**********************************************\n";
		cout<<"| 0. Agregar Elementos Predeterminados       |\n";
		cout<<"| 1. Agregar elementos al arbol.             |\n";
		cout<<"| 2. Mostrar Arbol                           |\n";
		cout<<"| 3. Buscar en Arbol                         |\n";
		cout<<"| 4. Mostrar por PreOrden, InOrden y Post    |\n";
		cout<<"| 5. Mostrar de Menor a Mayor                |\n";
		cout<<"| 6. Mostrar de Mayor a Menor                |\n";
		cout<<"| 7. Mostrar el Menor                        |\n";
		cout<<"| 8. Mostrar el Mayor                        |\n";
		cout<<"| 9. Mostrar el Nivel del Arbol              |\n";
		cout<<"| 10. Mostrar el Promedio                    |\n";
		cout<<"| 20. Salir                                  |\n";
        	cout<<"**********************************************\n";
		cout<<"\nOpcion: ";
		cin>>opcion;

		switch(opcion){
			case 0: cout<<"Se Agregaran los Siguientes nodos : 10,5,20,6,12,7,4,15,11,16,8,27,-6,9"<<endl<<"Desea Continuar? Y/N :\n";
					cin>>sino;
					if(sino == 'Y' || sino == 'y'){
						for(int i=0;i<a;i++){
						insertarNodo(arbol,lista2[i]); //Insertamos un nuevo nodo con los elementos del vector lista2[i]
						}
						cout<<"Succesfull!\n";
					}
					break;
			case 1:	cout<<"Numero a agregar: ";
					cin>>dato;
					insertarNodo(arbol,dato);
					break;
			case 2:	if(arbol == NULL){
						cout<< "El arbol esta vacio\n";
					}else{
						cout<< "Mostrando el Arbol\n";
						mostrarArbol(arbol,contador);
					}					
					break;
			case 3: cout<<"\nNumero a Buscar: ";
					cin>>dato;
					if(buscar(arbol,dato) == true){
						cout<<"El elemento '"<<dato<<"' SI fue encontrado.";
					}else{
						cout<<"El elemento '"<<dato<<"' NO fue encontrado.";
					}
					break;
			case 4: cout<<"\nRecorrido en InOrden: ";
					inOrden(arbol);	
					cout<<"\n";
					cout<<"\nRecorrido en Preorden: ";
					preOrden(arbol);	
					cout<<"\n";
					cout<<"\nRecorrido en PostOrden: ";
					postOrden(arbol);	
					cout<<"\n";
					break;
			case 5: cout<<endl<<"Mostrando de menor a mayor: ";
					menorAmayor(arbol);
					cout<<"\n";
					break;
			case 6: cout<<"\nMostrando de mayoy a menor: ";
					mayorAmenor(arbol);
					cout<<"\n";
					break;
        	case 7: cout<<endl<<"El Menor Elemento del arbol es: "<<MenorArbol(arbol,999)<<endl;
					break;
			case 8: cout<<endl<<"El Mayor Elemento del arbol es: "<<MayorArbol(arbol,0)<<endl;
					break;
			case 9: cout<<endl<<"El arbol tiene "<<Nivel(arbol)<<" niveles"<<endl;
					break;
			case 10: float suma_arbol = sumar(arbol);
					float Nro_elementos = nro_nodos(arbol);
					float promedio = suma_arbol / Nro_elementos;
					cout<<endl<<"El promedio de elementos del arbol es: "<<promedio<<endl;
					cout<<"Dese mas detalles? Y/N: \n";
					cin>>sino;		
					if(sino == 'Y' || sino == 'y'){
						cout<<"La suma es: "<<suma_arbol<<endl;;
						cout<<"El Numero de Nodos es: "<<Nro_elementos<<endl<<endl;
					}
					break;
		}
		system("pause");
		system("cls");
	}while(opcion != 20);
}

int main(){
	menu();
	/*
		
	int a,b;
	//paradas
	a = nroparada(arbol,999,0);
	cout<<a;
				
	//recursivas
	b=llarec(arbol,0,0)	
	cout<<b;
	
	*/
	
	return 0;
	getch();
}
