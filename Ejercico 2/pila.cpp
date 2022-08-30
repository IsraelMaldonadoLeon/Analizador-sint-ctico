#include "pila.h"
//#include "lexico.h"
#include <sstream>

//Ingresa el elemento a la pila
void Pila::push(int x){
   lista.push_front(x);
}

//Saca el elemento de la pila y lo regresa
int Pila::pop(){
   int x = *lista.begin();
   lista.erase(lista.begin());
   return x;
};

//regresa el ultimo elemento de la pila
int Pila::top(){
   return *lista.begin();     
};

//Imprime toda la pila
void Pila::muestra(){
   list <int>::reverse_iterator  it;
   cout << "Pila: ";   
   for (it= lista.rbegin(); it != lista.rend(); it++){
      cout << (*it) << " ";         
   } 
   cout << endl;
};
