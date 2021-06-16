#include "pch.h"
#include <sstream>
#include <cassert>
#include "CppUnitTest.h"
#include "../Homework_8_Pascal_Triangle/Matrix.h"
#include "../Homework_8_Pascal_Triangle/Menu.h"
#include "../Homework_8_Pascal_Triangle/Operation.h"
#include "../Homework_8_Pascal_Triangle/Validation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(matrix)
		{
			int number = 7;
			Matrix mat;
			mat.set_dimension(number);
			int test = mat.get_dimension();
			Assert::AreEqual(test, number);

		}
		TEST_METHOD(menu)
		{
			Menu menu;
			static int test = 7;
			menu.set_option(test);
			int number = menu.get_option();
			Assert::AreEqual(number, test);
		}
		TEST_METHOD(matrix)
		{
			int number = 7;
			Matrix mat;
			mat.set_dimension(number);
			int test = mat.get_dimension();
			Assert::AreEqual(test, number);

		}
		/*	

		TEST_METHOD(validation)
		{
			Validation validation;
			char opc[] = {'5'};
			int option;
			validation.validate(opc);
			option = atoi(opc);
			Assert::AreEqual(option, 5);

		}
		TEST_METHOD(menu)
		{
			Menu menu;
			menu.set_option(5);

			std::stringstream ss;
			menu.menu(ss);
			assert(ss.str() == "!Opción invalida!");
		}
	*/

	};
}
