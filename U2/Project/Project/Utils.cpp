#include "Utils.h"
using namespace Utils;


bool Validation::isNumericChar(char x)
{
    return (x >= '0' && x <= '9') ? true : false;
}


int Validation::atoi(char* str) {
    if (*str == '\0')
        return 0;

    int res = 0;
    int sign = 1;
    int i = 0;
    //si el numero es negativo
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }

    for (; *(str + i) != '\0'; ++i)
    {
        if (isNumericChar(*(str + i)) == false)
            return 0;
        res = res * 10 + str[i] - '0';
    }
    return sign * res;
}


int* Validation::data_expand(int value, int* data) {
    int i = 0;
    while (value > 0) {
        *(data + i) = value % 10;
        value = value / 10;
        i++;
    }
    return data;
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



int Validation::random_numbers(int min, int max) {
    std::random_device rdm;
    std::mt19937 mt(rdm());
    std::uniform_real_distribution<double> motor(min, max);
    int random = int(motor(mt));
    return random;
}



int Validation::lenght_array(int* array) {
    //int count = 0;
    //for (int i = 0; array[i] != '\0'; i++) {
    //    count++;
    //}
    //return count;
    int len = *(&array + 1) - array;
    return len;
}



int Validation::summation_array(int* array) {
    int sum = 0;
    for (int i = 0; *(array + i) != '\0'; i++) {
        sum += *(array + i);
        std::cout << sum << std::endl;
    }
    return sum;
}

//sumatoria de sumation array
//template <typename T>
//T Validation::summation_array(T* array) {
//    T sum = 0;
//    for (int i = 0; array[i] != '\0'; i++) {
//        sum += array[i];
//    }
//    return sum;
//}



//  ---------------- string uwu

int Validation::lenght_char(char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}


int Validation::lenght_str(std::string str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

std::string* Validation::split(std::string information, std::string array_name[2], std::string delimiter) {
    information += " ";
    information = lower(information);
    //Separa el string por los espacios " "
    //std::string delimiter = " ", token;
    std::string token;
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



std::string Validation::upper(std::string str) {
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}



std::string Validation::lower(std::string str) {

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}


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

// 
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



bool Validation::phone_validation(int phone, int lenght) {
    int value[10];
    int* data = data_expand(phone, value);
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



char* String::strcpy(char* destination, const char* source)
{
    if (destination == NULL) {
        return NULL;
    }

    char* ptr = destination;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

char* String::strcat(char* destination, const char* value)
{
    char* p = destination;

    while (*p != '\0') ++p;

    while (*p++ = *value++);

    return destination;
}

char* String::strncpy(char* destination, const char* source, size_t num)
{
    if (destination == NULL) {
        return NULL;
    }
    char* ptr = destination;

    while (*source && num--)
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return ptr;
}


double Math::factorial(double factorial)
{
    int f = 1;
    for (int i = 1; i <= factorial; i++)
    {
        f = f * i;
    }
    return f;
}


double Math::pow(double base, int exponent) {
    double temp;

    if (exponent == 0) {
        return 1;
    }

    temp = pow(base, exponent / 2);

    if ((exponent % 2) == 0) {
        return temp * temp;
    }
    else {
        if (exponent > 0) {
            return base * temp * temp;
        }
        else {
            return (temp * temp) / base;
        }
    }
}

double Math::pi(int terms) {
    double sum = 0.0;
    int sign = 1;

    for (int i = 0; i < terms; ++i) {
        sum += sign / (2.0 * i + 1.0);
        sign *= -1;
    }

    return 4.0 * sum;
}

double Math::radians(double angle) {
    return (angle * pi()) / 180;
}


double Math::sqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    if (number < 0) {
        throw std::invalid_argument("El número ingresado no pertenece a los números reales");
    }

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;
    i = 0x5f3759df - (i >> 1); // Aproximacion de Newton
    y = *(float*)&i;

    for (int j = 0; j < 3; j++) {
        y = y * (threehalfs - (x2 * y * y));
    }

    return 1 / y;
}


float Math::avarage(int list[]) {
    int len = Utils::Validation::lenght_array(list);
    float avarage = 0;
    for (int i = 0; list[i] != '\0'; i++) {
        avarage += list[i];
    }
    return avarage / len;
}