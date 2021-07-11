#include <iostream>
#include "Operation.h"
int main()
{
	Operation op;
	std::string result;
	//infija retorna una postfija
	//std::string exp = "a + b * ( c ^ d - e ) ^ ( f + g * h ) - i";
	std::string exp = "5 + 4 * ( 3 ^ 2 - 1 ) - ( 7 + 8 * 3 ) - 5";
	result = op.infix_to_postfix(exp);

	//prefija a postfija

	
	//prefija retorna el resultado
	//std::cout << "Prefija" << std::endl;
	////std::string post1 = "+ 9 * 12 6";
	//std::string post1 = "+ - 20 * 3 4 1";
	//op.prefix_evaluation(post1);


	//postfija a infija

	//postfija retorna el resultado
	//char post[] = "100 200 + 2 / 5 * 7 +";
	std::cout<<"Postfija" << std::endl;
	//std::string post = "5 5 / 10 30 - *";
	op.postfix_evaluation(result);

}