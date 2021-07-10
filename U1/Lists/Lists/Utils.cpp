#include "Utils.h"
using namespace Utils;

int Validation::random_numbers(int min, int max) {
    int random = rand() % (max - min + 1) + min;
    return random;
}


// Valor a ingresar, number hasta cuantos valores puedes ingresar
void Validation::natural_numbers(char* character, int number) {
    int i = 0, number_character = number;
    char key;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            std::cout << "\b \b";
            character[--i] = '\0';
        }
        else {
            if ((key >= 48 && key <= 57)) {
                std::cout << key;
                character[i++] = key;
            }
        }
    } while ((key != 13 || character[0] == '\0') && i < number_character);
    character[i] = '\0';
    return;
}
// Valor a ingresar, number hasta cuantos valores puedes ingresar
void Validation::integer(char* character, int number) {
    int i = 0, number_character = number;
    char key;
    char key_ = 45;
    character[0] = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            std::cout << "\b \b";
            character[--i] = '\0';
        }
        else {
            if ((key >= 48 && key <= 57) || (key >= 45 && key <= 45)) {
                std::cout << key;
                character[i++] = key;
            }
        }
    } while ((key != 13 || character[0] == '\0') && i < number_character);
    character[i] = '\0';
    return;
}

//Ingresa una cadena de caracteres
void Validation::letters(char* character, int number) {
    setlocale(LC_ALL, "");
    int i = 0, number_character = number;
    char key;
    *(character + 0) = '\0';
    do {
        key = _getch();
        if (i > 0 && key == 8) {
            std::cout << "\b \b";
            *(character + --i) = '\0';
        }
        else {
            if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || key == 'ñ' || key == 'Ñ' || (key == 32)) {
                std::cout << key;
                *(character + i++) = key;
            }
        }
    } while ((key != 13 || *(character + 0) == '\0') && i < number_character);
    *(character + i) = '\0';
    return;
}

//String a convertir en mayuscula
std::string Validation::upper(std::string cadena) {

    for (int i = 0; i < cadena.length(); i++) {
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}

// String a convertir en minuscula
std::string Validation::lower(std::string cadena) {

    for (int i = 0; i < cadena.length(); i++) {
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

int Validation::lenght(int number) {
    int contador = 1;
    while (number / 10 > 0)
    {
        number = number / 10;
        contador++;
    }
    return contador;
}

//De un valor 123456
// retorna una cadena de datos enteros
int* Validation::data_expand(int value, int data[]) {
    int i = 0;
    while (value > 0) {
        data[i] = value % 10;
        value = value / 10;
        i++;
    }
    return data;
}

//Permite ingresar un dato entero con una dimención definida 1,2,4,6
int Validation::input_number(int value) {
    char dimension[5];
    int operation = 0, len = 0, number = 0;
    std::cout << "Ingrese un numero con " << value << " digitos: ";
    do {
        integer(dimension, value);
        number = atoi(dimension);
        len = lenght(number);
        if (len != value) {
            std::cout << "\nEl numero ingresado solo tiene " << len << " digitos" << std::endl;
            std::cout << "Ingrese otro numero: ";
        }
    } while (len != value);
    return number;
}

//Valida de un numero telefonico corresponde
bool Validation::phone_validation(int phone, int lenght) {
    int value[10];
    int* data = data_expand(phone, value);
    //int lenght = (sizeof(data) / sizeof(data[0])) + 1;
    int condition[] = { 2,3,4,5,6,7 };
    bool repeat = true;

    if (data[lenght - 1] == lenght && lenght == 9) {
        std::cout << "\nEl numero ingresado corresponde a un numero de telefono mobil\n ";
        repeat = false;
    }
    if (lenght == 8) {
        for (int i = 0; i < 8; i++)
        {
            if (data[lenght - 1] == condition[i]) {
                std::cout << "\nEl numero ingresando corresponde a un numero convencional 0" << data[lenght - 1] << "\n";
                repeat = false;
            }
        }
    }
    return repeat;
}

//ingresa un numero telefonico  y devuelve el str
// value es el numero de digitos 
std::string Validation::input_phone(int value) {
    char dimension[11];
    bool repeat = true;
    int operation = 0, len = 0, number = 0;
    do {
        integer(dimension, value);
        number = atoi(dimension);
        len = lenght(number);
        try {
            if (len == value - 1 || len == value - 2) {
                repeat = phone_validation(number, len);
                //std::cout << "\n\nrepeat" << repeat;
            }
            else {
                throw "\n El numero ingresado es incorrecto\nIngrese otro numero: ";
            }
        }
        catch (const char* dato) {
            std::cout << dato;
        }
    } while (repeat);
    return (dimension);
}

// Retorna un valor que esta entre dos numeros
int Validation::comprobation_values(int limit1, int limit2, int value) {
    char dimension[5];
    bool repeat = true;
    int operation = 0, lenght = 0, number = 0;
    do {

        integer(dimension, value);
        number = atoi(dimension);
        try {
            if (number<limit1 || number>limit2) {
                throw "\n El numero ingresado es incorrecto: \nIngrese otro numero: ";
            }
        }
        catch (const char* dato) {
            std::cout << dato;
        }
    } while (number<limit1 || number>limit2);
    return number;
}

//   std::string name[2];
//   std::string* array_name = lower_separate(persona->get_name(), name);
std::string* Validation::split(std::string information, std::string array_name[2]) {
    information += " ";
    //Coloca los caracteres en letra minusculas :)
    //for (int i = 0; i < information.length(); i++)
    //{
    //    information[i] = tolower(information[i]);
    //}
    information = lower(information);
    //Separa el string por los espacios " "
    std::string delimiter = " ", token;
    size_t pos = 0;
    int i = 0;
    while ((pos = information.find(delimiter)) != std::string::npos) {
        token = information.substr(0, pos);
        array_name[i] = token; // guardo cada valor en un array de string
        information.erase(0, pos + delimiter.length());
        i++;
    }
    return array_name;
}