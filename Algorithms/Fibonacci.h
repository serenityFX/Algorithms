#ifndef __FIBONACCI__
#define __FIBONACCI__
//----------------------------------------------------------------------------------
#include <iostream>
#include <cstdint>
//----------------------------------------------------------------------------------
class Fibonacci
{
public:
	static int get				(int n);				// get Fibonacci number for 1 <= n <= 40
	static int get_last_digit	(int n);				// get last digit Fibonacci number for 1 <= n <= 10^7
	static int get_remainder	(int64_t n, int m);		// input 1 <= n <= 10^18, 2 <= m <= 10^5 return remainder of division Fibonacci(n)/Fibonacci(m)
};
//----------------------------------------------------------------------------------
#endif // __FIBONACCI__
