#include <iostream>
#include <memory.h>
#include <cmath>

const int MAX = 10;

long long number[MAX] = {0};

long long max_numbers[MAX] = { 0 };
long long min_numbers[MAX] = { 0 };

bool check[MAX] = { false };

bool inequality[MAX - 1] = { false };

int n;

long long max = -1, min = 99999999999;

void dfs(int depth)
{
	if (depth == n + 1) {
		long long x = 0;
		for (long long i = 0; i <= n; i++)
		{
			x += number[n - i] * std::pow(10, i);
		}
		if (x > max) {
			max = x;
			memcpy(max_numbers, number, sizeof(long long) * (n + 1));
		}
		if (x < min) {
			min = x;
			memcpy(min_numbers, number, sizeof(long long) * (n + 1));
		}

		return;
	}

	for (long long i = 0; i < MAX; i++)
	{
		if (check[i] == false)
		{
			if (depth != 0) {
				if (inequality[depth - 1]) { // '<'
					if (number[depth - 1] >= i){
						continue;
					}
				}
				else
				{
					if (number[depth - 1] <= i) {
						continue;
					}
				}
			}

			number[depth] = i;
			check[i] = true;
			dfs(depth + 1);
			check[i] = false;
		}
	}
}

int main()
{
	char s;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> s;
		if (s == '<')
			inequality[i] = true;
		else
			inequality[i] = false;
	}

	dfs(0);


	for (size_t i = 0; i <= n; i++)
	{
		std::cout << max_numbers[i];
	}
	std::cout << std::endl;

	for (size_t i = 0; i <= n; i++)
	{
		std::cout << min_numbers[i];
	}
	return 0;
}