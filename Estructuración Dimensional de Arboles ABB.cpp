#include <iostream>
#include <string>

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

Nodo *arbol = NULL;

Nodo *crearNodo(int c, string n, float n1, float n2, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->codigo = c;
	nuevo_nodo->nombre = n;
	nuevo_nodo->nota1 = n1;
	nuevo_nodo->nota2 = n2;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int c, string n, float n1, float n2, Nodo *padre){
	if (arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(c, n, n1, n2, padre);
		arbol = nuevo_nodo;
	}else{
		int valorRaiz = arbol->codigo; 
		if(c < valorRaiz){
			insertarNodo(arbol->izq, c, n, n1, n2, arbol);
		}else{ ////Si el elemento es mayor a la raiz se inserta en la derecha
			insertarNodo(arbol->der, c, n, n1, n2, arbol);
		}
	}
}
// Funcion para mostrar nodos
void mostrarArbol(Nodo *arbol, int contador){
	if (arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der, contador + 1);
		for (int i = 0; i < contador; i++){
			cout << "         ";
		}
		cout << arbol->codigo << endl;
		mostrarArbol(arbol->izq, contador + 1);
	}
}
// Buscar en base a un elemento
void mostrar_buscar(Nodo *arbol, int n){
	if (arbol == NULL){
		cout << ".-NO se encontro al Alumno-." << endl;
		return;
	}else if (arbol->codigo == n){
		cout << " Alumno Encontrado" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Nota 1: " << arbol->nota1 << endl;
		cout << "  -Nota 2: " << arbol->nota2 << endl;
		return;
	}else if (n < arbol->codigo){
		mostrar_buscar(arbol->izq, n);
	}else{
		mostrar_buscar(arbol->der, n);
	}
}
void mostrar_estudiantes(Nodo *arbol, int n){
	if (arbol == NULL){
		return;
	}else {
		cout << "*Estudiante"<< ":" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Nota 1: " << arbol->nota1 << endl;
		cout << "  -Nota 2: " << arbol->nota2 << endl<< endl;
		mostrar_estudiantes(arbol->izq,n);
		mostrar_estudiantes(arbol->der, n);
	}
}
float promedio_alumno(Nodo *arbol, int codi){
	if (arbol == NULL){
		return 0;
	}else if (arbol->codigo == codi){
		float n1 = arbol->nota1;
		float n2 = arbol->nota2;
		float promedio = (n1 + n2) / 2;
		cout << "El estudiante " << arbol->nombre << " Tiene Como Promedio: ";
		return promedio;
	}else if (codi < arbol->codigo){
		return promedio_alumno(arbol->izq, codi);
	}else{
		return promedio_alumno(arbol->der, codi);
	}
}
/* float suma_total(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}
	else{
		float subarbolizq = suma_total(arbol->izq); 
		float subarbolder = suma_total(arbol->der);
		float nota1 = arbol->nota1;
		float nota2 = arbol->nota2;
		return  nota1 + nota2 + subarbolizq + subarbolder;
	}
} */
bool buscar(Nodo *arbol, int bus){
	if (arbol == NULL){
		return false;
	}else if (arbol->codigo == bus){
		return true;
	}else if (bus < arbol->codigo){
		buscar(arbol->izq, bus);
	}else{
		buscar(arbol->der, bus);
	}
}

float suma_nota1(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}
	else{
		float subarbolizq = suma_nota1(arbol->izq); 
		float subarbolder = suma_nota1(arbol->der);
		return  arbol->nota1 + subarbolizq + subarbolder;
	}
}
float suma_nota2(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}
	else{
		float subarbolizq = suma_nota2(arbol->izq); 
		float subarbolder = suma_nota2(arbol->der);
		return  arbol->nota2 + subarbolizq + subarbolder;
	}
}
Nodo *minimo(Nodo *arbol){
	if (arbol == NULL){
		return NULL;
	}
	if (arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}
// Reemplazar un nodos por le otro un solo hijo
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	// si tiene padre
	if (arbol->padre){
		// arbolpadre asgnamos su nuevo hijo
		if (arbol->codigo == arbol->padre->izq->codigo){
			arbol->padre->izq = nuevoNodo;
		}
		// le asignamos al nodo su nuevo padre
		else if (arbol->codigo == arbol->padre->der->codigo){
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo){
		// Le aseignamos su nueov padre
		nuevoNodo->padre = arbol->padre;
	}
}
// Destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}
// eliminar un nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	// si el nodo tiene ambos hijos
	if (nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->codigo = menor->codigo;
		eliminarNodo(menor); // si el nodo tiene Dos hijos
	}
	else if (nodoEliminar->izq){ // si el nodo tiene un solo hijoizquiedo
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar->der){ // si el nodo tiene un solo hijo derrecho
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{ // si el nodo es una hoja
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}
// Eliminar Nodos de arbol
void eliminar(Nodo *arbol, int n){
	if (arbol == NULL){
		return;
	}
	else if (n < arbol->codigo){
		// busca por la izquierda
		eliminar(arbol->izq, n);
	}else if (n > arbol->codigo){
		// busca por la derecha
		eliminar(arbol->der, n);
	}else{ // si ya lo encontraste eliminamos con otra funcion
		eliminarNodo(arbol);
	}
}
int cantidad_estudiantes(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}else{
		return 1 + cantidad_estudiantes(arbol->izq) + cantidad_estudiantes(arbol->der);
	}
}

float aprobado(float n,float m){
	float prom = (n+m)/2;
	if(prom >10){
		return 1;
	}else{
		return 0;
	}
}
//probar nodos 9 13 10
int aprobados(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}
	else{
		int n1 = arbol->nota1;
		int n2 = arbol->nota2;
		return aprobado(n1,n2)+ aprobados(arbol->der) + aprobados(arbol->izq);
	}
}

void menu(){
	int codigo, opcion, contador = 0;
	string nombre[] = {"JUAN", "LUIS", "MILENA", "PABLO", "PEPE", "ALBERTO"},nom;
	float nota1[] = {11, 15, 20, 12, 5, 12},not1,not2;
	float nota2[] = {11.5, 12.65, 16, 17, 8, 17.5};

	do{
		cout << "\n ************************\n";
		cout << "| 0. Agregar Estudiante  |\n";
		cout << "| 1. Agregar Lista       |\n";
		cout << "| 2. Mostrar Nodos       |\n";
		cout << "| 3. Buscar Nodo         |\n";
		cout << "| 4. Mostrar Estudiantes |\n";
		cout << "| 5. Promedio Individual |\n";
		cout << "| 6. Nro de Aprobados y  |\n";
		cout << "|    Desaprobados        |\n";
		cout << "| 7. Promedio General    |\n";
		cout << "| 10. Salir              |\n";
		cout << " ************************\n";
		cout << "\nOpcion: ";
		cin >> opcion;

		switch (opcion){
		case 0:
			cout<<"Ingrese Codigo: ";cin>>codigo;
			if(buscar(arbol,codigo) == true){
				cout<<"\nEstudiante ya Existe! Intente de Nuevo"<<endl;
				break;
			}
			cout<<"Ingrese Nombre: ";cin>>nom;
			cout<<"Ingrese Nota 1: ";cin>>not1;
			cout<<"Ingrese Nota 2: ";cin>>not2;
			insertarNodo(arbol, codigo, nom, not1, not2, NULL);
			break;
		case 1:
				for (int i = 0; i < 6; i++){
					insertarNodo(arbol, i, nombre[i], nota1[i], nota2[i], NULL);
				}
			cout << "Se Agregaron Correctamente"<<endl;
			break;
		case 2:
			if (arbol == NULL){
				cout << "No hay Estudiantes\n";
			break;
			}
				cout << "Mostrando el Arbol\n";
				mostrarArbol(arbol, contador);
			break;
		case 3:
			if(arbol == NULL){
				cout<<"No hay estudiantes Registrados\n";
				break;
			}
			cout << "Ingrese Codigo: ";
			cin >> codigo;
			mostrar_buscar(arbol, codigo);
			break;
		case 4:
			if(arbol == NULL){
				cout<<"No hay estudiantes Registrados\n";
				break;
			}
			cout << "Detalle de Estudiantes\n\n";
			mostrar_estudiantes(arbol, cantidad_estudiantes(arbol));
			cout<<"Total "<<cantidad_estudiantes(arbol)<<" Estudiantes"<<endl;
			break;
		case 5:
			if(arbol == NULL){
				cout<<"No hay estudiantes Registrados\n";
				break;
			}
			cout << "Ingrese codigo del alumno: ";
			cin >> codigo;
			if(buscar(arbol,codigo) != true){
				cout<<"\nEl Estudiante no Existe! Intente de Nuevo"<<endl;
				break;
			}
			cout << promedio_alumno(arbol, codigo) << endl;
			break;
		case 6:
			if(arbol == NULL){
				cout<<"No hay estudiantes Registrados\n";
				break;
			}
			cout<<"Alumnos Aprobados son: "<<aprobados(arbol)<<endl;
			cout<<"Alumnos Desaprobados son: "<<cantidad_estudiantes(arbol)-aprobados(arbol)<<endl;
			break;
		case 7:	
			if(arbol == NULL){
				cout<<"No hay estudiantes Registrados\n";
				break;
			}
			cout << "El Promedio General de la Nota 1 es: "<<suma_nota1(arbol)/(cantidad_estudiantes(arbol));
			cout << "\nEl Promedio General de la Nota 2 es: "<<suma_nota2(arbol)/(cantidad_estudiantes(arbol));
			cout << "\nEl Promedio General de la Clase es: "<<(suma_nota1(arbol)+suma_nota2(arbol))/(cantidad_estudiantes(arbol)*2)<<endl;
			break;
		case 8: 
			cout<<"Ingrese Codigo de Alumno a Eliminar :";cin>>codigo;
			eliminar(arbol,codigo);
		}
	} while (opcion != 10);
}

int main(){
	menu();

	return 0;
}
