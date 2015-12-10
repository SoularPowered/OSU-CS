/*********************************************************************
** Program Filename: TestSuite.cpp		[IMPLEMENTATION]
** Author:           Shawn Hillyer
** Date:             11/27/2015
** Description:      A collection of functions to test and compare
**                   runtime performance.
** Input:            User input at keyboard
** Output:           Prints results to screen and logs to file
********************************************************************/
#include "Logger.hpp"
#include "TestSuite.hpp"

/*********************************************************************
** Function:         rfactorial() - no tail recursion
** Description:      Recursively calculates the nth factorial
** Parameters:       integer n
** Pre-Conditions:   None
** Post-Conditions:  returns the result
** Source:           Lab10 Description of non-tail-recursive factorial
********************************************************************/
long TestSuite::rfactorial(int n) // static
{
  if (n == 1)
    return 1;
  else {
    int result = rfactorial(n -1);
    return n * result;
  }
}


/*********************************************************************
** Function:         factorial() - with tail recursion
** Description:      Recursively calculates the nth factorial
** Parameters:       integer n
** Pre-Conditions:   None
** Post-Conditions:  returns the result
** Source:           Lab10 Description of tail-recursive factorial
********************************************************************/
long TestSuite::factorialHelper(int n, int result) // static
{
  if (n == 1)
    return result;
  else
    return factorialHelper(n-1,n*result);
}

long TestSuite::factorial(int n)  // static
{
  return factorialHelper(n, 1);
}


/*********************************************************************
** Function:         fib_rec()
** Description:      Calculates nth Fibonacci recursively
** Parameters:       integer n
** Pre-Conditions:   None
** Post-Conditions:  Returns the result
** Source:           Adapted from Gaddis C++ text page 910
********************************************************************/
long TestSuite::fib_rec(int n) // recursive - static
{
  if (n <= 0) // base case
    return 0;
  else if (n == 1) // base case
    return 1;
  else
    return fib_rec(n - 1) + fib_rec(n - 2);
}


/*********************************************************************
** Function:         fib_iter()
** Description:      Calculates the nth Fibonacci number iteratively
** Parameters:       integer n
** Pre-Conditions:   None
** Post-Conditions:  Returns the result
** Source: adapted from a Python algorithm @
** stackoverflow/com/questions/15047116/a-iterative-algorithm-for-fibonacci-numbers
********************************************************************/
long TestSuite::fib_iter(int n) // iterative - static
{
  if (n <= 0)
    return 0;
  else if (n == 1)
    return 1;
  else {
    long a = 0, b = 1, current;
    for (int i = 1; i < n; i++) {
      current = a + b;
      a = b;
      b = current;
    }
    return b;
  }
}


/*********************************************************************
** Function:         test_fib()
** Description:      Tests both versions of Fibonacci functions
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Files will be logged with results
********************************************************************/
void TestSuite::test_fib() // static
{
  std::string filename;
  std::cout << "Enter a filename to log the results to:\n >";
  std::getline(std::cin, filename);

  int n;
  std::cout << "Testing Recursive & iterative Fibonacci.\nEnter a value to calculate the nth Fib number:\n >";
  std::cin >> n;

  // Recursive test
  Logger::log(filename, "Start:\t fib_rec()", "");
  int result = fib_rec(n);
  Logger::log(filename, "End: \t fib_rec()", "");
  std::cout << "Result of fib_rec(n) = " << result << "\n";

  // Iterative test
  Logger::log(filename, "Call:\t fib_iter()", "");
  result = fib_iter(n);
  Logger::log(filename, "End: \t fib_iter()", "");
  std::cout << "Result of fib_iter(n) = " << result << "\n";
}


/*********************************************************************
** Function:         test_fact()
** Description:      Tests both versions of Factorial functions
** Parameters:       None
** Pre-Conditions:   None
** Post-Conditions:  Files will be logged with results
********************************************************************/
void TestSuite::test_fact() // static
{
  std::string filename;
  std::cout << "Enter a filename to log the results to:\n >";
  std::getline(std::cin, filename);

  int n;
  std::cout << "Testing Recursive Factorial - with and without tail recursion.\nEnter a value to calculate the nth Factorial number:\n >";
  std::cin >> n;

  // No tail
  int result;
  Logger::log(filename, "Start:\t rfactorial()", "");
  // for (int i = 0; i < 10000; i++)
    result = rfactorial(n);
  Logger::log(filename, "End: \t rfactorial()", "");
  std::cout << "Result of rfactorial(n) = " << result << "\n";

  // With tail
  Logger::log(filename, "Call:\t factorial()", "");
  // for (int i = 0; i < 10000; i++)
    result = factorial(n);
  Logger::log(filename, "End: \t factorial()", "");
  std::cout << "Result of factorial(n) = " << result << "\n";
}
