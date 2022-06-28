#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;


void ingresar_archivo(string conte){
    ofstream archivo;
    string contenido;
    archivo.open("archivo.txt",ios::out);
    if(archivo.fail()){//si el archivo fallo, tanto crear o leer, retorna un true o false
        cout<<"No se Pudo Abrir el Archivo\n";
        exit(1);
    }
    getline(cin,conte);
    archivo<<conte;
    archivo.close();
}
void llenar(string encripto){
        for(int i=32;i<127;i++){
        cin>>encripto[i];        
    }
}
void lectura(){
    ifstream archivo;
    string texto;
    archivo.open("archivo.txt",ios::in);
    
    if(archivo.fail()){
        cout<<"Error en abrir el archivo";
        exit(1);    
    }
    
    while(!archivo.eof()){//mientras no sea el fin del archivo, 
        getline(cin,texto);
        cout<<texto<<endl;
    }
    archivo.close();//cerramos el archivo
}
void encriptar(string cadena,int cifra){
    int longitud = cadena.length();//tamaño de la cadena
    for(int i=0;i<longitud;i++){//Iteramos la cantidad de letras de a cadena 
        for(int k=0;k<26;k++){//Iteramos cada letra del alfabeto y cada letra de la cadena 
            if(cadena[i]==cadena[k]){//Si l aposicio'n de las letras coinciden                
                if((k+cifra) > 25){//si la posicion coincidida mas la cifra de encriptacion es mayor a 25                    
                    cout<<cadena[k+cifra-26];//imprimimos el caracter del alfabeto con la la posicion de menos 26
                }else{                    
                    cout<<cadena[k+cifra];//caso contrario se imprime esa posicion.
                }
            }
        }
    }cout<<"\n\n";//Salto de Linea para visualizacion
}
void desencriptar(string cadena,string alfabeto,int cifra){
    int longitud = cadena.length();//tamaño de la cadena
    for(int i=0;i<longitud;i++){//Iteramos la cantidad de letras de a cadena 
        for(int k=0;k<26;k++){//Iteramos cada letra del alfabeto y cada letra de la cadena 
            if(cadena[i]==alfabeto[k]){//Si l aposicio'n de las letras coinciden                
                if((k+cifra) > 25){//si la posicion coincidida mas la cifra de encriptacion es mayor a 25                    
                    cout<<alfabeto[k-cifra-26];//imprimimos el caracter del alfabeto con la la posicion de menos 26
                }else{                    
                    cout<<alfabeto[k-cifra];//caso contrario se imprime esa posicion.
                }
            }
        }
    }cout<<"\n\n";//Salto de Linea para visualizacion
}

void menu(){
	int opcion,nivel; 
    string contenido;

	do{
		cout << "\n ************************\n";
		cout << "| 0. Ingresar Contenido  |\n";
		cout << "| 1. Imprimir Archivo    |\n";
		cout << "| 2. Mostrar Nodos       |\n";
		cout << "| 3. Rellenar Alfabeto   |\n";
		cout << "| 4. Encriptar           |\n";
		cout << "| 5. Desencriptar        |\n";
		cout << "| 6. Nro de Aprobados y  |\n";
		cout << "|    Desaprobados        |\n";
		cout << "| 7. Promedio General    |\n";
		cout << "| 10. Salir              |\n";
		cout << " ************************\n";
		cout << "\nOpcion: ";
		cin >> opcion;

		switch(opcion){
		case 0:cout<<"Ingrese Contenido: ";
            getline(cin,contenido);
            ingresar_archivo(contenido);
            cout<<"Contenido Ingresado!"<<endl;
			break;
		case 1:
			break;
		case 2:
            fstream archivo;
            string texto;
            archivo.open("archivo.txt",ios::in);
            if(archivo.fail()){
            cout<<"Error en abrir el archivo";
            exit(1);    
            }
            while(!archivo.eof()){//mientras no sea el fin del archivo, 
            getline(cin,texto);
            cout<<texto<<endl;
            }
            archivo.close();//cerramos el archivo

			break;
		case 3:
		
        } 
    }while (opcion != 10);
}
int main(){
    string abecedario;
    menu();
    

    return 0;
}