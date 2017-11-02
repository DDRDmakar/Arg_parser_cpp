
#include <iostream>
#include <string>

#include "arg_parser.h"

int main()
{
	Arg_parser parser("arg1 arg2 arg\\ 3   -key1 'Value 1' arg4 -Ключ2 \"Значение 2\" -singlequotes 'раз newline1 ->\nдва, двойная кавычка \"\"\"' -doublequotes \"двойная кавычка \\\" newline2 ->\\n++\" --some_array раз два три 'ч е т ы р е' -key3 value3 😄😄 😄😄😄😄");
	
	std::vector<std::string> unnamed_arguments = parser.get_array_unnamed();
	
	std::vector<std::string> all_arguments = parser.get_all_args();
	
	std::vector<std::string> named_argument_keys = parser.get_keys_of_single();
	
	std::vector<std::string> named_array_keys = parser.get_keys_of_arrays();
	
	std::cout << "\n\nArguments line: " << parser.get_all_args_line() << "\n\n";
	
	std::cout << "All arguments:\n";
	for (const auto &e : all_arguments) std::cout << '	' << e << std::endl;
	
	std::cout << "Unnamed arguments:\n";
	for (const auto &e : unnamed_arguments) std::cout << '	' << e << std::endl;
	
	std::cout << "Named arguments:\n";
	for (const auto &e : named_argument_keys) std::cout << '	' << e << " => " << parser.get_arg_named(e) << std::endl;
	
	std::cout << "Named arrays:\n";
	for (const auto &e : named_array_keys)
	{
		std::vector<std::string> current_array = parser.get_array_named(e);
		
		std::cout << '	' << e << " => \n";
		for (const auto &e2 : current_array) std::cout << "		" << e2 << std::endl;
	}
	
	return 0;
}
