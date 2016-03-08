#include "Fibonacci.h"

#include <assert.h>
#include <array>
#include <vector>
#include <memory>
#include <cmath>
#include <list>
//----------------------------------------------------------------------------------
const int MIN_INPUT_FOR_GET = 0;
const int MAX_INPUT_FOR_GET = 40;
const int MIN_INPUT_FOR_GET_LAST_DIGIT = 1;
//----------------------------------------------------------------------------------
int Fibonacci::get(int n)
{
	assert(n >= MIN_INPUT_FOR_GET && n <= MAX_INPUT_FOR_GET);

	std::array<int, MAX_INPUT_FOR_GET + 1> arr;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];

	return arr[n];
}
//----------------------------------------------------------------------------------
int Fibonacci::get_last_digit(int n) 
{
	assert(n >= MIN_INPUT_FOR_GET_LAST_DIGIT);
	std::vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);

	for (int i = 2; i <= n; ++i)
		arr.push_back((arr[i-1] + arr[i-2])%10);
	return arr[n];
}
//----------------------------------------------------------------------------------
int Fibonacci::get_remainder(int64_t n, int m)
{
	assert(n >= 1);
	assert(m >= 2);

	if (static_cast<int64_t>(m) == n) return 0;
	if (static_cast<int64_t>(m) > n)
	{
		int *arr = new int[n+1];

		arr[0] = 0;
		arr[1] = 1;

		for (int i = 2; i <= n; ++i)
			arr[i] = arr[i - 1] + arr[i - 2];

		int res = arr[n];
		delete[] arr;
		return res;
	}

	std::vector<int64_t> arr;
	arr.push_back(0);
	arr.push_back(1);


	int64_t k = 0;
	for (int64_t i = 2; i <= n; ++i)
	{
		arr.push_back((arr[i - 1] + arr[i - 2]) % m);
		k++;
		if (arr[i] == 1 && arr[i - 1] == 0)
			break;
	}
	return arr[n%k];
}

