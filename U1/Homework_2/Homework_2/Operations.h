#pragma once
#include"Data.h"
#include <iostream>

template<typename T>
class Operations
{
private: 
	Data<T> data;
	//Data data2;
public:
	Operations() = default;
	void set_Data(Data<T>);
	Data<T> get_Data();


	T operator +=(Data<T>&);
	T operator !=(Data<T>&);
	T operator &=(Data<T>&);

	T operator *(Data<T>&);
	T operator &(Data<T>&);
	T operator ^(Data<T>&);

	T operator %(Data<T>&);
	T operator >(Data<T>&);
	T operator <(Data<T>&);

	T operator +(Data<T>&);
	T operator -(Data<T>&);
	T operator /(Data<T>&);

	T operator &&(Data<T>&);
	T operator |=(Data<T>&);
	T operator ||(Data<T>&);

};

/**
* @brief set_Data
*
* @param Data<T> data_1
*
* @return 
*/

template<typename T>
void Operations<T>::set_Data(Data<T> data_1) {
	this->data1 = data_1;
}

/**
* @brief get_Data
*
* @param 
*
* @return data
*/


template<typename T>
Data<T> Operations<T>::get_Data() {
	return data;
}


/**
* @brief promedio
*
* @param Data<T> &data1
*
* @return typename
*/

template<typename T>
T Operations<T>::operator+=(Data<T> &data1)
{
	return ((data1.get_Data1() + data1.get_Data2()) / 2);
}

template<typename T>
T Operations<T>::operator!=(Data<T>& data1) {
	return ((data1.get_Data1() + data1.get_Data2() + data1.get_Data3()) / 3);
}

template<typename T>
T Operations<T>::operator &=(Data<T>& data1) {
	return ((data1.get_Data2() + data1.get_Data3()) / 2);
}

/**
* @brief potencia
*
* @param Data<T> &data1
*
* @return typename
*/

template<typename T>
T Operations<T>::operator*(Data<T>& data1) {

	return pow(data1.get_Data2(), data1.get_Data3());
}
template<typename T>
T Operations<T>::operator&(Data<T>& data1) {
	return pow(data1.get_Data1(), data1.get_Data3());
}
template<typename T>
T Operations<T>::operator^(Data<T>& data1) {

	return pow(data1.get_Data2(), data1.get_Data1());
}

/**
* @brief factorial
*
* @param Data<T> &data1
*
* @return typename
*/

template<typename T>
T Operations<T>::operator%(Data<T>& data1)
{
	int factorial = 1;
	int n = data1.get_Data1();
	for (int i = 1; i <= n; i++)
		factorial = factorial * i;
	return factorial;
}

template <typename T>
T Operations<T>::operator>(Data<T>& data1)
{
	int factorial = 1;
	int n = (data1.get_Data1() - data1.get_Data2());
	for (int i = 1; i <= n; i++)
		factorial = factorial * i;
	return factorial;
}

template<typename T>
T Operations<T>::operator<(Data<T>& data1)
{
	int factorial = 1;
	int n = (data1.get_Data1() + data1.get_Data3());
	for (int i = 1; i <= n; i++)
		factorial = factorial * i;
	return factorial;
}

/**
* @brief radical
*
* @param Data<T> &data1
*
* @return typename
*/

template<typename T>
T Operations<T>::operator +(Data<T>& data1) {
	return sqrt(data1.get_Data1());
}

template<typename T>
T Operations<T>::operator -(Data<T>& data1) {
	return sqrt(data1.get_Data2());
}

template<typename T>
T Operations<T>::operator /(Data<T>& data1) {
	return sqrt(data1.get_Data3());
}

/**
* @brief ecuaciones
*
* @param Data<T> &data1
*
* @return typename
*/

template<typename T>
T Operations<T>::operator &&(Data<T>& data1) {
	return (data1.get_Data1() + data1.get_Data2() - data1.get_Data3());
}

template<typename T>
T Operations<T>::operator |=(Data<T>& data1) {
	return (data1.get_Data1() + (data1.get_Data2() * data1.get_Data3()));
}

template<typename T>
T Operations<T>::operator ||(Data<T>& data1) {
	return ((data1.get_Data1() / data1.get_Data2()) * data1.get_Data3());
}