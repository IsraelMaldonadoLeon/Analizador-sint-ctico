#ifndef _LEXICO
#define _LEXICO

#include <iostream>
#include <string>
using namespace std;

class TipoSimbolo{
      public:
            static const int ERROR= -1;       
            static const int IDENTIFICADOR= 0;
            static const int OPADIC= 1;
            static const int OPMULT= 26;
            static const int PESOS= 2;
            static const int E= 3;       
            static const int ENTERO= 4;
            static const int REAL= 6;
            static const int OPRELAC= 7;
            static const int OPOR= 8;
            static const int OPAND= 9;
            static const int OPNOT= 10;
            static const int OPIGUALDAD= 11;
            static const int PUNTOYCOMA= 12;
            static const int COMA= 13;
            static const int PARENABI= 14;//parentesis abierto "("
            static const int PARENCER= 15;//parentesis cerrado ")"
            static const int CORCHETEABI= 16;//corchete abierto "{"
            static const int CORCHETECER= 17;//corchete cerrado "}"
            static const int IGUAL= 18;
            static const int IF= 19;
            static const int WHILE= 20;
            static const int RETURN= 21;
            static const int ELSE= 22;
            static const int CADENA= 23;
            static const int TIPO= 24;
            static const int ESPACIO= 25;
};


class Lexico{
      private:
            string fuente;

            int ind;       
            bool continua;
            string c;
            int estado;

            string sigCaracter();       
            void sigEstado(int estado);
            void aceptacion(int estado);
            bool esLetra(char c);
            bool esDigito(char c);
            bool esEspacio(char c);
            void retroceso();

      public:
            string simbolo;
            int tipo;
            
            Lexico(string fuente);             
            Lexico();
      
            void entrada(string fuente);              
            string tipoAcad(int tipo);

            int sigSimbolo();
            bool terminado();
      
};
#endif
