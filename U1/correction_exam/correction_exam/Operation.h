#pragma once
#include "Person.h"
#include "Validation.h"
class Operation
{
private:
	Validation val;
public:
	void validate_email(Person*);
	std::string* lower_separate(std::string, std::string[]);
	void generate_email(Person* persona, int value);
	void generate_encryption(Person* persona, int value);
	std::string input();
	int input_number(int);
	int date_comprobation(int limit1, int limit2, int value);
	std::string input_numbers(int);
	bool phone_validation(int, int);
	int* data_expand(int, int[]);
	int digits(int number);
	void enter_ID(char*);
	int plus_id(Person* persona, int[]);
};
