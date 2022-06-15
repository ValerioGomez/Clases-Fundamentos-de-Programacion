/* A. La modificación permitirá también desarrollar todas las operaciones del árbol que trabajan hasta ahora, con las salvedades siguientes (Todos los estudiantes desarrollaran estas funciones):

1. Cuando se haga la búsqueda del nodo se muestre los otros campos además del primer campo básico
2. Ingrese los datos de las tablas que se le indican se ingresen automáticamente.
3. Además, cuando se ingresen otros datos con la función respectiva no solo se ingrese el primer campo básico sino los otros datos más
4. Cuando se muestre el árbol con la función regular puede hacerlo solo en base al primer campo; Pero además cree otra función además de ola anterior donde se muestre el árbol, pero con todos los datos de la estructura.
Estudiantes con Nro. de orden del: 6-10

Incluir opciones en el menú que calculen:
1. Sumar las notas 1 y 2 en forma individual y determine el promedio de la nota1 y 2
2. Sacar el promedio individual y mostrarlo
3. Cuantos aprobados hay y cuantos desaprobados según el promedio individual
3. Calcule el promedio de todas las notas (incluye la Nota 1 y la Nota 2) en forma global de toda la clase */
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
		}else{
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
		cout << arbol->codigo << "-" << arbol->nombre << endl;
		mostrarArbol(arbol->izq, contador + 1);
	}
}
// Buscar en base a un elemento
void mostrar_buscar(Nodo *arbol, int cod){
	if (arbol == NULL){
		cout << ".-NO se encontro al Alumno-." << endl;
		return;
	}else if (arbol->codigo == cod){
		cout << " Alumno Encontrado" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Nota 1: " << arbol->nota1 << endl;
		cout << "  -Nota 2: " << arbol->nota2 << endl;
		return;
	}else if (cod < arbol->codigo){
		mostrar_buscar(arbol->izq, cod);
	}else{
		mostrar_buscar(arbol->der, cod);
	}
}
void mostrar_estudiantes(Nodo *arbol, int total_nodos){
	if (arbol == NULL){
		return;
	}else {
		cout << "*Estudiante"<< ":" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Nota 1: " << arbol->nota1 << endl;
		cout << "  -Nota 2: " << arbol->nota2 << endl<< endl;
		mostrar_estudiantes(arbol->izq,total_nodos);
		mostrar_estudiantes(arbol->der, total_nodos);
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
            cout<<"Se ingreso Correctamente\n";
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
		}
	} while (opcion != 10);
}

int main(){
	menu();

	return 0;
}
