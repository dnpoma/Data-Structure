
#include "./Data.h" 
#include "./Operations.h"
#include <iostream>

int main()
{
    int option;
    Data<int> data_1;
    data_1.set_Data1(8);
    data_1.set_Data2(2);
    data_1.set_Data3(4);

    Data<float> data_2;
    data_2.set_Data1(8);
    data_2.set_Data2(5.3F);
    data_2.set_Data3(5.2F);


    Operations<float> op;
    Operations<int> op2;

    do
    {
        system("cls");
        std::cout << "1 Raices" << std::endl;
        std::cout << "2 Potencia" << std::endl;
        std::cout << "3 Factorial" << std::endl;
        std::cout << "4 Ecuaciones de primer grado" << std::endl;
        std::cout << "5 Promedio de notas" << std::endl;
        std::cout << "6 Para salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "Ingresa una opcion: ";
            scanf_s("%d", &option);
        } while (option < 1 || option > 6);

        switch (option) {
        case 1: {
            std::cout << "\t\t\n Raices " << std::endl;

            std::cout << "\nLa raiz de " << data_2.get_Data1() << " es: " << op.operator+(data_2);
            std::cout << "\nLa raiz de " << data_1.get_Data2() << " es: " << op2.operator-(data_1);
            std::cout << "\nLa raiz de " << data_2.get_Data3() << " es: " << op.operator/(data_2);
            std::cout << std::endl;
            break;
        }
        case 2: {
            std::cout << "\t\t\n Potencias " << std::endl;
            std::cout << "\nLa Potencia de " << data_2.get_Data1() << "^" << data_2.get_Data3() << " = " << op.operator*(data_2);
            std::cout << "\nLa Potencia de " << data_1.get_Data1() << "^" << data_1.get_Data3() << " = " << op2.operator&(data_1);
            std::cout << "\nLa Potencia de" << data_2.get_Data2() << "^" << data_2.get_Data1() << " = " << op.operator^(data_2);
            std::cout << std::endl;
            break;
        }
              
        case 3: {
            std::cout << "\t\t\n Factorial" << std::endl;
            std::cout << "El factorial " << data_1.get_Data1() <<"! = " << op2.operator%(data_1) << std::endl;
            std::cout << "El factorial (" << data_1.get_Data1()<<" - "<< data_1.get_Data2() << ")! = " << op2.operator>(data_1) << std::endl;
            std::cout << "El factorial (" << data_1.get_Data1() << " + " << data_1.get_Data3() << ")! = " << op2.operator<(data_1) << std::endl;
            std::cout << std::endl;
            break;
        }
        case 4: {
            std::cout << "\t\t\n Ecuaciones de Primer Grado " << std::endl;
            std::cout << "x = " << data_1.get_Data1() << "\ny = " << data_1.get_Data2() << "\nz = " << data_1.get_Data3() << std::endl;
            std::cout << "Ecuacion 1:  t = x + y - z  :" << op2.operator&&(data_1)<< std::endl;
            std::cout << "Ecuacion 2:  t = x + (yz)   :" << op2.operator|=(data_1)<< std::endl;
            std::cout << "Ecuacion 3:  t = (x/y)*z    :" << op2.operator||(data_1)<< std::endl;
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::cout << "\t\t\n Promedio de Notas " << std::endl;
            std::cout << "Nota 1 ="<< data_2.get_Data1() <<"\nNota 2 ="<< data_2.get_Data2() <<"\nNota 3 ="<< data_2.get_Data3() << std::endl;
            std::cout << "El Promedio de N1 + N2 es: " << op.operator+=(data_2) << std::endl;
            std::cout << "El Promedio es N1 + N2 + N3 es: " << op.operator!=(data_2) << std::endl;
            std::cout << "El Promedio es N2 + N3 es: " << op.operator&=(data_2) << std::endl;
            std::cout << std::endl;
            break;
        }
        }
        if (option != 6) {
            system("pause");
        }
    } while (option != 6);
    

}
