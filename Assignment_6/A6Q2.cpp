
/*Q2. Write a user defined function factorial() that calculates factorial of given number and it throws 
exception if number entered by user is negative. */
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n < 0)
    {
        throw 0;
        cout << "Factorial of a negative number is not defined.";
    }
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}
int main()
{
    int number;

    cout << "Enter a number to calculate its factorial: ";
    cin >> number;

    try
    {
        int fact = factorial(number);
        cout << "Factorial of " << number << " is " << fact << endl;
    }
    catch (int e)
    {
        cout << "Error:(can't enter a negative no)";
    }

    return 0;
}
