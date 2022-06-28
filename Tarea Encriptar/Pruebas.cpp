#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;
void escribir(){
    ofstream archivo;
    string archi,contenido;

    // cout<<"Ingrese Nombre de archivo: ";
    // getline(cin,archi);

    archivo.open("archivo.txt",ios::out);//abre el archivo, sino existe lo crea, si existe lo reemplaza
    // archivo.open(archi.c_str(),ios::out);//Ingresando con el nombre del archivo convertiendo string a cadena c
    if(archivo.fail()){//si el archivo fallo, tanto crear o leer, retorna un true o false
        cout<<"No se Pudo Abrir el Archivo\n";
        exit(1);
    }
    // archivo<<"Encriptando... Programa para \nencriptar con El Encriptado Cesar\nXD";
    getline(cin,contenido);
    archivo<<contenido;
    archivo.close();
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
void agregar(){
    ofstream archivo;
    string texto;
    archivo.open("",ios::app);//crear out, leer in, añadir up

    if(archivo.fail()){
        cout<<"Error en abrir el archivo";
        exit(1);    
    }
    /* cout<<"Agrega texto a añadir";
    getline(cin,texto);
    archivo<<texto; 
    con.getline(texto,20,'\n');
    longitud = strlen(texto); //char
    longitud = palabra.length();//string

    */
    archivo<<"\nAgregando mas cadenas";
    archivo.close();
}


int main(){

/* 
    string palabra;
    int longitud,contador=0;
    getline(cin,palabra);
    // auto cad = palabra.c_str(); 
    longitud = palabra.length();
    for(int i=0;i<longitud;i++){
        if(palabra[i]!='\0'){
            contador++;
        }
    }
    
    cout<<"Palabra: "<<palabra;
    cout<<"Cantidad de Letras: "<<contador;
 */
/*     new = reserva el numero de bytes solicitado por la declaracion
    delete = libera el bloque de bytes reservado con anterioridad
    int *textos; //global
    cin>>total_texto;
    //funcion para cambiar a minusculas
    strlwr(palabra);
    cout<<<palabra;

    texto = new int[total_texto];

    delete[] texto;  */
    char alfa[100];
    char abcd[200];
    for(int i=0;i<95;i++){
        alfa[i]=char(i+32);//Rellenamos conCodigo Acsii desde el 32 hasta el 127

    }
    strcat(abcd,alfa);
    string alfabeto(abcd);
    cout<<alfabeto;
    
    return 0;
}