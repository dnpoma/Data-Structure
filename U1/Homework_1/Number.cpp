#include <string>
#include "Number.h"

//template <typename data_type>
//Number<data_type>::Number(data_type value_1) : value1(value_1){
////	value1 = value_1;
//}



template <typename data_type>
Number <data_type>::Number(){
}

template <typename data_type>
void Number <data_type>::set_value1(data_type value){
	value1 = value;
}

template <typename data_type>
data_type Number <data_type>::get_value1(){
	return value1;
}

template <typename data_type>
void Number <data_type>::to_string(){
//	std::cout << value1 << std::endl;	
}


