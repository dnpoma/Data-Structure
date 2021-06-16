#ifndef _NUMBER_H_
#define	_NUMBER_H_

template<typename data_type>
class Number{	
	private:
		data_type value1;
		
	public:
		Number();
		void set_value1(data_type value);
		data_type get_value1();
		void to_string();

};


//#include "Number.cpp"
#endif
