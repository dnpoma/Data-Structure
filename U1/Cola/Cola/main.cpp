#include <iostream>
#include "Process.h"


#include "Utils.h"
#include <string>
using namespace Utils;


int main() {
	/*std::cout << Utils::Validation::summation_array(num)<<std::endl;
	std::cout << Utils::Validation::lenght_array(num);
	std::cout <<"hi" << (*(&num + 1) - num);
	*/


	Process process;
	process.calculate_all(30);
	process.print_table(30);
	process.print_total();
}
