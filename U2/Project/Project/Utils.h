
#pragma once
#include <iostream>
#include <conio.h>
#include<cstring>
#include <math.h>
#include <string>
#include <vector>
#include <random>

namespace Utils {
	class Validation
	{
	public:
		/*
		* @brief isNumericChar (Comprueba que un char sea un numero)
		* @param char x
		* @return true or false
		*/
		static bool isNumericChar(char);

		/*
		* @brief atoi
		* @param char str
		* @return sign * res
		*/
		static int atoi(char*);

		/*
		* @brief data_expand
		* @param int value, int* data
		* @return data
		*/
		static int* data_expand(int, int*);

		/*
		* @brief lenght (Para saber la longitud de un numero 500 = 3)
		* @param int number
		* @return contador
		*/
		static int lenght(int);

		/*
		* @brief random_numbers
		* @param int min, int max
		* @return random
		*/
		static int random_numbers(int, int);

		/*
		* @brief lenght_array
		* @param int* array
		* @return len
		*/
		static int lenght_array(int*);

		/*
		* @brief summation_array (sumatoria de un array)
		* @param int* array
		* @return sum
		*/
		static int summation_array(int*);

		//template <typename T>
		//static T summation_array(T*);



		/*
		* @brief lenght_char (retorna 4)
		* @param char* str
		* @return count
		*/
		static int lenght_char(char*);

		/*
		* @brief lenght_char (retorna 5)
		* @param string str
		* @return count
		*/
		static int lenght_str(std::string);

		/*
		* @brief split
		* @param information
		* @param array_name
		* @param delimiter
		* @return array_name
		*/
		static std::string* split(std::string, std::string[], std::string);

		/*
		* @brief upper (String a convertir en mayuscula)
		* @param string str
		* @return str
		*/
		static std::string upper(std::string);

		/*
		* @brief lower(String a convertir en minuscula)
		* @param string str
		* @return str
		*/
		static std::string lower(std::string);

		//comprobation / evalue :·)
		static void integer(char*, int);
		static void natural_numbers(char*, int);
		static void letters(char*, int);
		static int input_number(int);
		static std::string input_phone(int);
		static bool phone_validation(int, int);
		static int comprobation_values(int, int, int);



	};
	class String {
	public:
		static char* strcpy(char*, const char*);
		static char* strcat(char*, const char*);
		static char* strncpy(char*, const char*, size_t);
	};

	class Math {
	public:
		//Funciones
		static double factorial(double);
		static double pow(double, int);
		static double pi(int number = 99);
		static double radians(double);
		static double sqrt(float);


		//min max
		template <typename T>
		static T max(T, T);

		template <typename T>
		static T min(T, T);

		//float owo
		static float avarage(int[]);
	};

	template<typename T>
	T Math::max(T num1, T num2) {
		return (num1 > num2 ? num1 : num2);
	}

	template<typename T>
	T Math::min(T num1, T num2) {
		return (num1 < num2 ? num1 : num2);
	}

}