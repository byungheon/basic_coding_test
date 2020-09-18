#include <iostream>

int pluscycle(int n) {
	int out = 0;

	int first = n % 10;
	int second = n / 10;
	
	int temp = first + second;
	int out_first = temp % 10;

	return out_first + first * 10;
}

int main()
{
	int n = 0;

	std::cin >> n;

	int next = n;
	int cnt = 0;
	while (1)
	{
		next = pluscycle(next);

		cnt++;
		if (next == n)
			break;
	}

	std::cout << cnt << std::endl;

	return 0;
}