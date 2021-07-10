#pragma once
#include <iostream>
#include <conio.h>
#include <string>
namespace Utils{
	class Validation
	{
	public:
		static void integer(char*, int);
		static void natural_numbers(char*, int);
		static void letters(char*, int);
		static std::string upper(std::string);
        static std::string lower(std::string);
        static int random_numbers(int, int);
        static int input_number(int);
        static int lenght(int);
        static std::string input_phone(int);
        static bool phone_validation(int, int);
        static int* data_expand(int, int[]);
		static int comprobation_values(int, int, int);
		static std::string* split(std::string, std::string []);
	};

}
