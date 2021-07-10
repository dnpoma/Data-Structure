#include "Person.h"
std::string Person::get_id() {
	return id;
}
void Person::set_id(std::string _id) {
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
void Person::set_direction(std::string _direction) {
	this->direction = _direction;
}
std::string Person::get_encryption() {
	return encryption;
}
void Person::set_encryption(std::string _encryption) {
	this->encryption = _encryption;
}