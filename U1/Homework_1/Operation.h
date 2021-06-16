#ifndef _OPERATION_H_
#define	_OPERATION_H_

template <typename data_type>
class Operation{	
	public:
		Operation();
		data_type addition(data_type value1, data_type value2);
		data_type subtraction(data_type value1, data_type value2);
		data_type multiplication(data_type value1, data_type value2);
		data_type division(data_type value1, data_type value2);
};


//#include "Operation.cpp"
#endif
