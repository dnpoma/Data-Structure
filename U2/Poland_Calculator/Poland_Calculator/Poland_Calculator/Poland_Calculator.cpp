
#include <iostream>
#include "Operation.h"
#include "Stack.h"
#include "Utils.h"
#include "mystring.h"
int main()
{
    do {
        try
        {
            Operation op;
   
            mystring str;
            string num = "12.36";
            Stack<string> datos;

            datos = op.ingresar_datos();

            if (!datos.empty_stack()) {
                cout << "INFIJA         :   ";
                datos.mostrar_expresion();
                Stack<string> prefija;
                Stack<string> postfija;


                prefija = op.infix_to_prefix1(datos);
                cout << "PREFIJA        :   ";
                prefija.mostrar_expresion();

                postfija = op.infix_to_postfix1(datos);
                cout << "POSTFIJA       :   ";
                postfija.mostrar_expresion();
                cout << "RESULTADO      :   ";
                cout << op.calculate(prefija) << endl;
            }
            system("pause");
        }
        catch (const std::exception&)
        {
            cout << "Error" << endl;

        }
    } while (1);
}

