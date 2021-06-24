#include "Person.h"
#include <string>
int Person::get_id() {
	return id;
}
void Person::set_id(int _id) {
	this->id = _id;
}

std::string  Person::get_name() {
	return name;
}
std::string  Person::get_last_name() {
	return last_name;
}

void Person::set_name(std::string  _name) {
	this->name = _name;
}
void Person::set_last_name(std::string  _last_name) {
	this->last_name = _last_name;
}

//Date Person::get_date() {
//	return date;
//}
//void Person::set_date(Date _date) {
//	this->date = _date;
//}

std::string  Person::get_phone() {
	return phone;
}
void Person::set_phone(std::string  _phone) {
	this->phone = _phone;
}
std::string Person::get_email() {
	return email;
}
void Person::set_email(std::string _email) {
	this->email = _email;
}
std::string Person::get_direction() {
	return direction;
}
void Person::set_cifrado(std::string _cifrado) {
	this->cifrado = _cifrado;
}
std::string Person::get_cifrado() {
	return cifrado;
}
void Person::set_direction(std::string _direction) {
	this->direction = _direction;
}

std::string Person::toString()
{
	return (name + " " + last_name + " " + std::to_string(id) + " " + email + " " + cifrado);
}