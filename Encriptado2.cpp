#include<iostream>
using namespace std;

int main(){//Declaramos el alfabeto
    char alfabeto[100] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char cadena[100];//Declaramos la cadena a encriptar
    int longitud_cadena;
    cout<<"\nIngrese Palabra: ";cin>>cadena;
    longitud_cadena = (sizeof(&cadena));//tamaño de la cadena
    char cadena_cifrada[longitud_cadena];//Cadena Cifrada
    for(int i=0;i<(longitud_cadena);i++){//Convertimos todo a Mayuscula
        cadena[i] = toupper(cadena[i]);//To Up Per,funcion a mayusculas
    }//iteramos la cadena a encriptar
    for(int i=0;i<(longitud_cadena);i++){
        for(int j=0;j<26;j++){//buscamos coincidencias con el alfabeto
            if(cadena[i]==alfabeto[j]){
                if(cadena[i]!='\0'){//si la letra es diferente al fin de linea de la palabra a cifrar
                    cadena_cifrada[i]=alfabeto[j+3];//ingresamos la cadena cifrada con la posicion +3 del alfabeto
                }
            }
        }
    }
    //Imprimimos la cadena cifrada
    cout<<"Palabra Encriptada: ";
    for(int i=0;i<longitud_cadena;i++){
        cout<<cadena_cifrada[i];
    }cout<<"\n\n";



    return 0;
}