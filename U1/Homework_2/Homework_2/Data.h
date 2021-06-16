
#pragma once
//#include "Data.h"
#include <iostream>

template<typename T>
class Data
{
private:
	T data1;
	T data2;
	T data3;
public:
	Data() = default;

	void set_Data1(T);
	T get_Data1();
	void to_String1();
	
	void set_Data2(T);
	T get_Data2();
	void to_String2();

	void set_Data3(T);
	T get_Data3();
	void to_String3();

};

/**
* @brief set_Data1
*
* @param T _data
*
* @return 
*/
template<typename T>
void Data<T>::set_Data1(T _data) {
	data1 = _data;
}

/**
* @brief get_Data1
*
* @param 
*
* @return data1
*/
template<typename T>
T Data<T>::get_Data1() {
	return data1;
}

/**
* @brief to_String1
*
* @param
*
* @return 
*/
template<typename T>
void Data<T>::to_String1() {
	std::cout << data1;
}

/**
* @brief set_Data2
*
* @param T _data
*
* @return
*/
template<typename T>
void Data<T>::set_Data2(T _data) {
	data2 = _data;
}

/**
* @brief get_Data2
*
* @param
*
* @return data2
*/
template<typename T>
T Data<T>::get_Data2() {
	return data2;
}

/**
* @brief to_String2
*
* @param
*
* @return
*/
template<typename T>
void Data<T>::to_String2() {
	std::cout << data2;
}

/**
* @brief set_Data3
*
* @param T _data
*
* @return
*/
template<typename T>
void Data<T>::set_Data3(T _data) {
	data3 = _data;
}

/**
* @brief get_Data3
*
* @param
*
* @return data3
*/
template<typename T>
T Data<T>::get_Data3() {
	return data3;
}

/**
* @brief to_String3
*
* @param
*
* @return
*/
template<typename T>
void Data<T>::to_String3() {
	std::cout << data3;
}