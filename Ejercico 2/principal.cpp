//Alexa Salcedo Arellano
#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"
#include "lexico.cpp"
#include "pila.cpp"

using namespace std;


int main(int argc, char *argv[]){ 
    int contador = 0;
    int idReglas[2] = {3,3}; 
    int IonReglas[2] = {3,0};
    int idE = 3; 
    int E;
    int tablaLR[5][4]={// E = <id> + E |<id>
        2, 0, 0, 1,
        0, 0, -1, 0,
        0, 3, -2, 0,
        2, 0, 0, 4,
        0, 0, -3, 0
    };
    Pila pila;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("a + b + c + d + e + f ");//cadena a analizar

    pila.push( TipoSimbolo::PESOS); //Entra signo de pesos que inicializa la cadena
    pila.push( 0 );                 
    lexico.sigSimbolo();    //analizamos el primer simbolo de la cadena

    fila= pila.top();   //para la fila tomamos en cuenta en top de la pila
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
            if (accion == -3){ //si es -3 aplicamos la regla 1(E = <id> + E)
                contador = 0;
                E = idReglas[contador]  + IonReglas[contador];//(3,3)
            }
            if (accion == -2){//si es -2 aplicamos la regla 2(E = <id>)
                contador = 1;
                E = idReglas[contador];//(3)
            }

            for(int i=0; i<E; i++){//reducimos la pila el numero de veces que nos indica la regla
                pila.pop();
            }

            pila.muestra();
            fila= pila.top();
            columna= 3;//el 3 es el entero que representa el no terminal E*
            cout << "fila: " << fila << endl;
            cout << "Columna" << columna << endl;
            accion= tablaLR[fila][columna];

            pila.push( 3 ); //el 3 es el entero que representa el no terminal E*
            pila.push( accion );
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;
        }
        if(accion == 0)break;
    }
    cout << "Automata terminado" << endl;
    aceptacion= accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;
    else cout << "No aceptacion" << endl;
}
