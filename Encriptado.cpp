#include<iostream>

using namespace std;
/* 12. Escribir .....
alfabeto = {a,b,c...x,y,z}

Ingrese Palabra: arroz
Ingrese Numero: 5
Su palabra encriptada es: fwwte */

int main(){
    string abc = "abcdefghijklmnopqrstuvwxyz";//Declaramos el alfabeto
    string palabra;//Declaramos la palabra a encriptar
    int cifra;//Declaramos la cifra a recorrer
    
    cout<<"\nIngrese Palabra:";getline(cin, palabra);
    cout<<"Ingrese Numero de cifrado: ";cin>>cifra;

    int longitud = palabra.length();//tamaño de la palabra
    for(int i=0;i<longitud;i++){//Iteramos la cantidad de letras de a palabra 
        for(int k=0;k<26;k++){//Iteramos cada letra del alfabeto y cada letra de la palabra 
            if(palabra[i]==abc[k]){//Si l aposicio'n de las letras coinciden                
                if((k+cifra) > 25){//si la posicion coincidida mas la cifra de encriptacion es mayor a 25                    
                    cout<<abc[k+cifra-26];//imprimimos el caracter del alfabeto con la la posicion de menos 26
                }else{                    
                    cout<<abc[k+cifra];//caso contrario se imprime esa posicion.
                }
            }
        }
    }cout<<"\n\n";//Salto de Linea para visualizacion
    return 0;
}