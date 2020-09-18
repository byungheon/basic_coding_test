#include <iostream>
#include <vector>

bool isFelindrom(int n) {
	std::vector<int> numbers;
	int n_tmp = n;
	while (n_tmp > 0) {
		int remainder = n_tmp % 10;
		numbers.push_back(remainder);
		n_tmp = n_tmp / 10;
	}

	bool is_felin = true;
	for (size_t i = 0; i < numbers.size() / 2; i++)
	{
		if (numbers[i] != numbers[numbers.size() - i - 1])
		{
			is_felin = false;
			break;
		}
	}

	return is_felin;
}

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	else {
		for (int j = 2; j <= sqrt(n); j++)
		{
			if (n % j == 0) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int n = 1;
	int answer = 1;
	std::cin >> n;

	for (int i = n; i < INT32_MAX; i++)
	{
		if (isFelindrom(i) && isPrime(i)) {
			std::cout << i << std::endl;
			break;
		}
	}

	return 0;
}