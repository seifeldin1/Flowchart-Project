
#include "HelperFn.h"
#include <string>

bool IsValue(string input)
{
	// check that the length of string does not = 0
	if (input.length() == 0) return false; //exit if length is 0

	bool IsNegative = false, IsDecimal = false, IsDigit = false; // intializing the main 3 variables used for checking with false

	// checks if the input string is a double value
	for (int i = 0; i < input.length(); i++) {

		char latestCharacter = input[i];

		if (i == 0 && latestCharacter == '-') {	 // check if it is negtaive
			IsNegative = true;
			continue;
		}

		if (latestCharacter == '.') {		 //checks if the input string is a double value , 
			//return true if it's double value, false otherwise
			if (IsDecimal == true) return false;

			if (IsDecimal == false) IsDecimal = true;
		}

		if (latestCharacter >= '0' && latestCharacter <= '9') IsDigit = true; // check if it has digit
	}

	return IsDigit; //return either false or true according to the previous checks 
}

bool IsVariable(string input)
{
	// check that length is not 0
	if (input.length() == 0) return false; // exit if length is 0

	// checks if the input string is a variable name
	char firstChar = input[0];

	bool IsChar = false; // intializing the variable with false for the upcoming checks

	if ((int(firstChar) >= 65 && int(firstChar) <= 90) || (int(firstChar) >= 97 && int(firstChar) <= 122) || int(firstChar) == 95) {
		IsChar = true; // set IsChar variable to true if the first character was either a small or capital letter or an underscore
	}
	else {
		return false; // if not then set IsChar to false
	}

	char subsequentChar;

	for (int i = 1; i < input.length(); i++) { // checking subsequent characters
		subsequentChar = input[i];

		if (!((int(subsequentChar) >= 65 && int(subsequentChar) <= 90) ||
			(int(subsequentChar) >= 97 && int(subsequentChar) <= 122) ||
			int(subsequentChar) == 95 || (subsequentChar >= '0' && subsequentChar <= '9'))) return false;
	}
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.



	return true;
}

OpType ValueOrVariable(string input)
{
	if (IsValue(input)) return VALUE_OP;        // checks if the input string is a double value 

	if (IsVariable(input)) return VARIABLE_OP; // checks if the input string is a variable name

	else return INVALID_OP;                   // otherwise return invalid
	// chand returns enum "OpType" (the enum is declared in the .h)
}
