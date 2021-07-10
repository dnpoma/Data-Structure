#pragma once
//#include "Date.h"
#include <iostream>
class Person
{
private:
	std::string id;
	std::string name;
	std::string last_name;
	std::string phone;
	std::string email;
	std::string direction;
	std::string encryption;
	std::string username;
	std::string clave;
	//Date date;//fecha de nacimiento, edad uwu
public:
	Person() = default;
	std::string get_id();
	void set_id(std::string);
	std::string get_name();
	void set_name(std::string);
	std::string get_last_name();
	void set_last_name(std::string);
	std::string get_phone();
	void set_phone(std::string);
	std::string get_clave();
	void set_clave(std::string);
	std::string get_userame();
	void set_username(std::string);
	std::string get_email();
	void set_email(std::string);
	//Date get_date();
	//void set_date(Date);
	std::string get_direction();
	void set_direction(std::string);
	std::string get_encryption();
	void set_encryption(std::string);
};

