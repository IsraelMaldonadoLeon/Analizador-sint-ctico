//Salcedo Arellano Alexa
#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"
#include "lexico.cpp"
#include "pila.cpp"

using namespace std;


int main(int argc, char *argv[]){ 
    int idE = 3; 
    int E;
    int tablaLR[5][4]={// E = <id> + E |<id>
        2, 0, 0, 1,
        0, 0, -1, 0,
        0, 3, -2, 0,
        4, 0, -3, 0,
        0, 0, -4, 0
    };

    Pila pila;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("hola + mundo ");//cadena a analizar

    pila.push( TipoSimbolo::PESOS );//Entra signo de pesos que inicializa la cadena
    pila.push( 0 );
    lexico.sigSimbolo();//analizamos el rimer simbolo de la cadena

    fila= pila.top();//para la fila tomamos en cuenta en top de la pila
    columna= lexico.tipo;//para la columna tomamos en el id del siguente simbolo en la cadena
    cout << "fila: " << fila << endl;
    cout << "Columna" << columna << endl;
    accion= tablaLR[fila][columna];//la accion es el valor que se encuentre etre la fila y la columna

    pila.muestra();//mostramos la pila
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl;

    while(accion != -1){//mientras la accion sea diferente de aceptacion repetimos el proceso
        if(accion > 0){//si la accion es mayor a 0 hacemos un desplazo
            pila.push( lexico.tipo );
            pila.push( accion );
            lexico.sigSimbolo();

            fila= pila.top();
            columna= lexico.tipo;
            cout << "fila: " << fila << endl;
            cout << "Columna" << columna << endl;
            accion= tablaLR[fila][columna];

            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl;
        }
        if(accion < 0){//Si la accion es menor a 0 hacemos una reduccion
            if (accion == -1)break;//si es -1 es aceptacion
            E = idE + idE;//Aplicamos la regla E = <id> + <id>
            for(int i=0; i<E; i++){
                pila.pop();
            }
            fila= pila.top();
            columna= idE; //el 3 es el entero que representa el no terminal E
            cout << "fila: " << fila << endl;
            cout << "Columna" << columna << endl;
            accion= tablaLR[fila][columna];

            pila.push( 3 ); //el 3 es el entero que representa el no terminal E
            pila.push( accion );
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;
        }
        if(accion == 0)break;//Estado de no aceptacion
    }
    cout << "Salio while" << endl;
    aceptacion= accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;
}
