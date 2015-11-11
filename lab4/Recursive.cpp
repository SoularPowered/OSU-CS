/*********************************************************************
** Program Filename: Recursive.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             10/15/2015
** Description:      Class for running static recursive functions.
** Input:            Only the arguments required for method calls
** Output:           Returns values depending on which static method is called
********************************************************************/

#include "Recursive.hpp"

/*********************************************************************
** Function:         reverse_string() : static method
** Description:      Recurisvely reverses a string by concatenating
**                   the reverse of the substring from [1] to end, adding
**                   the first character to the end of this new string each time
** Parameters:       One std::string object or string literal (ok because of
**                   auto type conversion from char[] to std::string)
** Pre-Conditions:   None. This is a STATIC method. Call with full scope
**                   Recursive::reverse_string(your_string);
** Post-Conditions:  Base case Returns string to caller. Discarded if not
**                   assigned to a variable.
**                   Also prints the characters in reverse order.
********************************************************************/
std::string Recursive::reverse_string(const std::string str)
{
	/* Base case - if str is empty or it's the last character, return the str */
	if (str.length() == 0 || str.length() == 1) // Base case
	{
		std::cout << str << "\n";
		return str;
	}
	/* recursive case */
	else
	{
		// save the first character to append after the recursive chain
		std::string first_char = str.substr(0,1);
		// grab the rest of the string so we can send it up recursively
		// recursively goes to end of string, appends last character, adds first_Char
		std::string new_str = reverse_string(str.substr(1, str.length()-1)) + first_char;
		std::cout << first_char << "\n";
		return new_str;
	}
}


/*********************************************************************
** Function:         sum_array()
** Description:      Recursively calculates the sum of all values in
**                   an array by adding the value of each node to the
**                   sum_array() of the rest of the array
** NOTE**            I have this algorithm publiclly posted
**                   on my OWN personal github.com/soularpower. I
**                   did this exercise as part of chapter 14 in the
**                   Gaddis text several months ago. The problem
**                   was completed independently at the time.
** Parameters:       An array of double and the int size which indicates
**                   the number
** Pre-Conditions:   size must be >=1. Method is static. Call with full scope:
**                   Recusrive::sum_array(arr, size);
** Post-Conditions:  Base case returns double which is sum of all
**                   values stored in the array. Each recursive call
**                   will evaluate the sum of the rest of the array by
**                   passing the array + 1 (next element) & size-1, then
**                   adds the value at each position as the recursive call
**                   cascades back through the stack on its way back "down"
********************************************************************/
double Recursive::sum_array(const double array[], const int size)
{
	if (size == 1)         // base case
		return array[0];     // returns value of last element of array
	// else return the value of the subset of the array; each time, size is -1
	// and use pointer arithmetic to move forward 1 element from current first element
	else
		return array[0] + sum_array(array + 1, size - 1);
}


/*********************************************************************
** Function:         triangle_number()
** Description:      Calculates the triangular number x for x-sub-n,
**                   where n is the sequence and x is the result. The
**                   result can be confirmed with n(n+1)/2. Each call
**                   adds the number of "dots" in the current row to the
**                   triangular number for the prior value of n.
** Parameters:       Pass an an int for sequence in triangular to Calculate
** Pre-Conditions:   None. Static method. Use full scope to call:
**                   Recursive::triangle_number
** Post-Conditions:  Returns an int which is the value x, where x is
**                   the triangular number for x-sub-n (n is num of sequence)
********************************************************************/
int Recursive::triangle_number(const int num)
{
	/* base case / handle invalid input < 1 */
	if (num < 1)
		return 0;
	/* base case is n = 1 */
	if (num == 1)
		return 1;
	/* recursive case */
	else
		return triangle_number(num-1) + num;
}
