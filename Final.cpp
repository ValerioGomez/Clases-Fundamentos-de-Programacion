#include <iostream>
#include <string>

using namespace std;

struct Nodo{
	int codigo;
	string nombre;
	string apellido;
    char genero;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int c, string n, string a, char g, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->codigo = c;
	nuevo_nodo->nombre = n;
	nuevo_nodo->apellido = a;
    nuevo_nodo->genero = g;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int c, string n, string a, char g, Nodo *padre){
	if (arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(c, n, a, g, padre);
		arbol = nuevo_nodo;
	}else{
		int valorRaiz = arbol->codigo; 
		if(c < valorRaiz){
			insertarNodo(arbol->izq, c, n, a, g, arbol);
		}else{
			insertarNodo(arbol->der, c, n, a, g, arbol);
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
			cout << "       ";
		}
		cout << arbol->codigo << "," << arbol->nombre << endl;
		mostrarArbol(arbol->izq, contador + 1);
	}
}

float sumarcodigos(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}
	else{
		float subarbolizq = sumarcodigos(arbol->izq); 
		float subarbolder = sumarcodigos(arbol->der);
		return  arbol->codigo + subarbolizq + subarbolder;
	}
}

// Buscar mujer con mayor codigo
void mujer_mayor_codigo(Nodo *arbol, char gene){
	if (arbol == NULL){
		return;
	}else if (arbol->genero == gene){
		cout << " Alumno Encontrado" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Apellidos: " << arbol->apellido << endl;
		return;
	}else if (gene > arbol->codigo){
		mujer_mayor_codigo(arbol->der, gene);
	}else{
		mujer_mayor_codigo(arbol->izq, gene);
	}
}

void varon_mayor_codigo(Nodo *arbol, char gene){
	if (arbol == NULL){
		return;
	}else if (arbol->genero == gene){
		cout << " Alumno Encontrado" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Apellidos: " << arbol->apellido << endl;
		return;
	}else if (gene > arbol->codigo){
		varon_mayor_codigo(arbol->der, gene);
	}else{
		varon_mayor_codigo(arbol->izq, gene);
	}
}

void mostrar_estudiantes(Nodo *arbol, int total_nodos){
	if (arbol == NULL){
		return;
	}else {
		cout << "*Estudiante"<< ":" << endl;
		cout << "  -Codigo: " << arbol->codigo << endl;
		cout << "  -Apellido: " << arbol->apellido << endl;
		cout << "  -Nombre: " << arbol->nombre << endl;
		cout << "  -Genero: " << arbol->genero << endl;
        
		mostrar_estudiantes(arbol->izq,total_nodos);
		mostrar_estudiantes(arbol->der, total_nodos);
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
		return  arbol->codigo + subarbolizq + subarbolder;
	}
}

int totalestudiantes(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}else{
		return 1 + totalestudiantes(arbol->izq) + totalestudiantes(arbol->der);
	}
}

int femenino(Nodo * arbol){
	if(arbol->genero == 'F'){
		return 1;
	}else{
		return 0;
	}
}

int totalmujeres(Nodo *arbol){
	if (arbol == NULL){
		return 0;
	}
	else{
		return femenino(arbol)+ totalmujeres(arbol->der) + totalmujeres(arbol->izq);
	}
}

void menu(){
	int opcion;
	int codigo[] = {10,21,2,30,41,52};
	string apellidos[] = {"PEREZ", "QUISPE", "LOPEZ", "ALVAREZ", "ZEA", "VILCA"};
	string nombres[] = {"JUAN", "LUISA", "MILENA", "PABLO", "PEPE", "ALBERTO"};
	char genero[] = {'M','F','F','M','M','M'};    

	do{
		cout << "1. Agregar Alumnos       \n";
		cout << "2. Mostrar Nodos         \n";
		cout << "3. Mostrar Alumnos       \n";
		cout << "4. Sumatoria de Codigos  \n";
		cout << "5. Cantidad F/M          \n";
		cout << "6. Señorita Mayor codigo \n";
		cout << "7. Joven Mayor codigo    \n";
		cout << "10. Salir                \n";
		cout << "\nOpcion: ";
		cin >> opcion;

		switch (opcion){
		case 1:
				for (int i = 0; i < 6; i++){
					insertarNodo(arbol, codigo[i], nombres[i], apellidos[i], genero[i], NULL);
				}
			cout << "Se Agregaron Correctamente"<<endl;
			break;
		case 2:
				cout << "Mostrando el Arbol\n";
				mostrarArbol(arbol, 0);
			break;
		case 3:
                cout << "Detalle de Estudiantes\n\n";
                mostrar_estudiantes(arbol, totalestudiantes(arbol));
                cout<<"Total "<<totalestudiantes(arbol)<<" Estudiantes"<<endl;
                break;
		case 4:
                cout << "La sumatoria de los Codigos es: "<<sumarcodigos(arbol)<<endl;
                break;
		case 5:
                cout<<"El Total de Mujeres es :"<<totalmujeres(arbol)<<endl;
                cout<<"El Total de Varones es :"<<totalestudiantes(arbol) - totalmujeres(arbol)<<endl;
                break;
        case 6: 
                cout<<"La señorita con Mayor Codigo es: \n";
                mujer_mayor_codigo(arbol,'F');
                cout<<"\n";        
        case 7: 
                cout<<"el Joven con Mayor Codigo es: \n";
                varon_mayor_codigo(arbol,'M');
                cout<<"\n";
        }
    	system("pause");
		system("cls");
	} while (opcion != 10);
}

int main(){
	menu();

	return 0;
}
