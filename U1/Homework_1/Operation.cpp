#include<iostream>
#include "Operation.h"


template <typename data_type>
Operation<data_type>::Operation(){
}

template <typename data_type>
data_type Operation<data_type>::addition(data_type value1, data_type value2){
	return value1 + value2;
}

template <typename data_type> 
data_type Operation<data_type>::subtraction(data_type value1, data_type value2){
	return value1 - value2;
}

template <typename data_type> 
data_type Operation<data_type>::multiplication(data_type value1, data_type value2){
	return value1 * value2;
}

template <typename data_type> 
data_type Operation<data_type>::division(data_type value1, data_type value2){
//	try{
//		return value1 / value2;
//	}catch(value2==0){
//		cout<<"Division para cero"<<endl;
//	}
	return value1/value2;
}


