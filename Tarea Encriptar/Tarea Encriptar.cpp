#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void ingresar_contenido_archivo(string conte){
    ofstream archivo;//declaramos variable tipo archivo
    string contenido;//contenido del string
    archivo.open("archivo.txt",ios::out);
    if(archivo.fail()){//si el archivo fallo, tanto crear o leer, retorna un true o false
        cout<<"No se Pudo Abrir el Archivo\n";
        exit(1);
    }
    getline(cin,conte);
    archivo<<conte;
    archivo.close();
}
int longitud_archivo(){
    string linea,contenido;
    int longitud;
    ifstream archivo("archivo.txt");//declaramos la variable archivo pasando como parametro la direccion del archivo
    while (getline(archivo,linea)){//imprimimos el contenido
        contenido = contenido + linea +"\n";//añadimos un salto de linea
    }
    archivo.close();//cerramos el archivo
    // cout<<contenido<<endl;
    longitud = contenido.length();
    return longitud;
}
void lectura_archivo(){
    string lin,texto;
    int longitud;
    ifstream archivo("archivo.txt");//declaramos la variable archivo pasando como parametro la direccion del archivo
    while (getline(archivo,lin)){//imprimimos el texto
        texto = texto + lin +"\n";//añadimos un salto de linea
    }
    archivo.close();//cerramos el archivo
    cout<<texto<<endl;
}
void llenar_alfabeto(string alfabeto){
    for(int i=32;i<127;i++){
        alfabeto[i]=char(i);//Rellenamos conCodigo Acsii desde el 32 hasta el 127
    }
}
void imprimir_alfabeto(string alfabeto){
    int longitud;
    longitud = alfabeto.length();
    for(int i=0;i<longitud;i++){
        cout<<i<<".- "<<alfabeto[i]<<endl;
    }
    cout<<"la longitud es: "<<longitud;
}
void cifrar(string alfabeto,int cifra){
            string contenido,texto;
            ifstream archivo("archivo.txt");//declaramos la variable archivo pasando como parametro la direccion del archivo
            getline(archivo,contenido);
            archivo.close();
            int longitud = longitud_archivo()-1;
            for(int i=0;i<longitud;i++){//Iteramos la cantidad de letras de a linea 
                for(int k=0;k<95;k++){//Iteramos cada letra del alfabeto y cada letra de la linea 
                    if(contenido[i]==alfabeto[k]){//Si l aposicio'n de las letras coinciden                
                        if((k+cifra) > 94){//si la posicion coincidida mas la cifra de encriptacion es mayor a 25                    
                            texto[i]=alfabeto[k+cifra-95];//imprimimos el caracter del alfabeto con la la posicion de menos 26
                        }else{                    
                            texto[i]=alfabeto[k+cifra];//caso contrario se imprime esa posicion.xit
                            
                        }
                    }
                }
            }cout<<"\n\n";//Salto de Linea para visualizacion
            string aux;
            for (int i = 0; i < longitud; i++){
                aux=aux + texto[i];
            }          
            
            string texto_encriptado(aux);
            cout<<"Texto: "<<aux<<endl;
            ofstream archivo2;//declaramos variable tipo archivo2
            archivo2.open("archivo.txt",ios::out);
            if(archivo2.fail()){//si el archivo2 fallo, tanto crear o leer, retorna un true o false
                cout<<"No se Pudo Abrir el archivo2\n";
                exit(1);
            }
            archivo2<<aux;
            archivo2.close();
}
void descifrar(string alfabeto,int cifra){
            string contenido,texto;
            ifstream archivo("archivo.txt");//declaramos la variable archivo pasando como parametro la direccion del archivo
            getline(archivo,contenido);
            archivo.close();
            int longitud = longitud_archivo()-1;
            for(int i=0;i<longitud;i++){//Iteramos la cantidad de letras de a linea 
                for(int k=0;k<95;k++){//Iteramos cada letra del alfabeto y cada letra de la linea 
                    if(contenido[i]==alfabeto[k]){//Si l aposicio'n de las letras coinciden                
                        if((k+cifra) > 94){//si la posicion coincidida mas la cifra de encriptacion es mayor a 25                    
                            texto[i]=alfabeto[k+cifra-95];//imprimimos el caracter del alfabeto con la la posicion de menos 26
                        }else{                    
                            texto[i]=alfabeto[k+cifra];//caso contrario se imprime esa posicion.xit
                            
                        }
                    }
                }
            }cout<<"\n\n";//Salto de Linea para visualizacion
            string aux;
            for (int i = 0; i < longitud; i++){
                aux=aux + texto[i];
            }          
            
            string texto_encriptado(aux);
            cout<<"Texto: "<<aux<<endl;
            ofstream archivo2;//declaramos variable tipo archivo2
            archivo2.open("archivo.txt",ios::out);
            if(archivo2.fail()){//si el archivo2 fallo, tanto crear o leer, retorna un true o false
                cout<<"No se Pudo Abrir el archivo2\n";
                exit(1);
            }
            archivo2<<aux;
            archivo2.close();
}
void menu(){
	int opcion,longitud,clave;
    string contenido,texto;
    char alfa[100],aux[200];
    for(int i=0;i<95;i++){
        alfa[i]=char(i+32);//Rellenamos conCodigo Acsii desde el 32 hasta el 127
    }
    strcat(aux,alfa);
    string alfabeto(aux);

	do{
		cout << "\n ************************\n";
		cout << "| 0. Ingresar Contenido  |\n";
		cout << "| 1. Imprimir Archivo    |\n";
		cout << "| 2. Rellenar Alfabeto   |\n";
		cout << "| 3. Ver Alfabeto        |\n";
		cout << "| 4. Encriptar           |\n";
		cout << "| 5. Desencriptar        |\n";
		cout << "| 9. Salir              |\n";
		cout << " ************************\n";
		cout << "\nOpcion: ";
		cin >> opcion;

		switch(opcion){
		case 0:
            cout<<"Ingrese Contenido: ";
            getline(cin,contenido);
            ingresar_contenido_archivo(contenido);
            cout<<"Contenido Ingresado en el Archivo\n";
            break;
		case 1:
            lectura_archivo();
			break;
		case 2:
            for(int i=0;i<95;i++){
                alfa[i]=char(i+32);//Rellenamos conCodigo Acsii desde el 32 hasta el 127
            }
            cout<<"Alfabeto rellenado con Exito\n";
			break;
		case 3:         
            for(int i=0;i<95;i++){
                cout<<i<<" : "<<alfa[i]<<endl;
            }
            break;
        case 4:
            cout<<"Ingrese Clave de Cifrado: ";
            cin>>clave;
            cifrar(alfabeto,clave);
            cout<<"Cifrado!!\n";
            break;
        case 5:
            cout<<"Ingrese Llave de Cifrado: ";
            cin>>clave;
            descifrar(alfabeto,-clave);
            cout<<"Descifrado!\n";
            break;
        } 
    }while (opcion != 9);
}

main(){
    menu();
    return 0;
}