#pragma once
//#include "Date.h"
#include <iostream>
class Person
{
private:
	int id;
	std::string name;
	std::string last_name;
	std::string phone;
	std::string email;
	std::string direction;
	std::string cifrado;
	//Date date;//fecha de nacimiento, edad uwu
public:
	Person() = default;
	int get_id();
	void set_id(int);
	std::string get_name();
	void set_name(std::string);
	std::string get_last_name();
	void set_last_name(std::string);
	std::string get_phone();
	void set_phone(std::string);
	std::string get_email();
	void set_email(std::string);
	std::string get_cifrado();
	void set_cifrado(std::string);
	//Date get_date();
	//void set_date(Date);
	std::string get_direction();
	void set_direction(std::string);
	std::string toString();

};