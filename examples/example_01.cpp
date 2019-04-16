/*
 **************************************************************
 *         C++ Mathematical Expression Toolkit Library        *
 *                                                            *
 * Simple Example 1                                           *
 * Author: Arash Partow (1999-2019)                           *
 * URL: http://www.partow.net/programming/exprtk/index.html   *
 *                                                            *
 * Copyright notice:                                          *
 * Free use of the Mathematical Expression Toolkit Library is *
 * permitted under the guidelines and in accordance with the  *
 * most current version of the MIT License.                   *
 * http://www.opensource.org/licenses/MIT                     *
 *                                                            *
 **************************************************************
*/


#include <cstdio>
#include <string>

#define POSIT_THROW_ARITHMETIC_EXCEPTION 1
#include <posit>

#include "exprtk_posit_adaptor.hpp"
//#include "exprtk_posit_forward.hpp"
//#include "exprtk.hpp"



template <typename T>
void trig_function()
{
	using namespace std;

	using symbol_table_t = exprtk::symbol_table<T>;
	using expression_t   = exprtk::expression<T>;
	using parser_t       = exprtk::parser<T>;

	string expression_string = "clamp(-1.0,sin(2 * pi * x) + cos(x / 2 * pi),+1.0)";

	T x;

	symbol_table_t symbol_table;
	symbol_table.add_variable("x",x);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string,expression);

	cout << "Expression: " << expression_string << endl;
	for (x = T(-0.01); x <= T(+0.01); x += T(0.001)) {
		T y = expression.value();
		cout << x << " = " << y << endl;
	}
}

int main()
{
   trig_function<double>();
   trig_function<posit_32_2>();
   return 0;
}
