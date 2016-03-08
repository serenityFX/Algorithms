#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
	assert(a > 0 && b > 0);
	
	if (a == 0) return b;
	if (b == 0) return a;

	if (a >= b) return gcd(a%b,b);
	if (b >= a) return gcd(a,b%a);
}