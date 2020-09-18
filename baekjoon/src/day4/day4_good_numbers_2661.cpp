#include <iostream>

const int MAX = 81;

int cand[3] = { 1, 2, 3 };

int numbers[MAX];

int N;

bool isGooldNumbers(int n_numbers)
{
	if (n_numbers <= 1)
		return true;

	for (int i = 1; i <= n_numbers / 2; i++)
	{
		bool repeat = true;
		int idx1 = n_numbers - i;
		int idx2 = n_numbers - 2 * i;
		for (int j = 0; j < i; j++)
		{
			if (numbers[idx1 + j] != numbers[idx2 + j]) {
				repeat = false;
			}
		}

		if (repeat == true)
			return false;
	}

	return true;
}

bool dfs(int depth)
{
	if (depth == N) {
		for (size_t i = 0; i < N; i++)
		{
			std::cout << numbers[i];
		}
		return true;
	}

	for (size_t i = 0; i < 3; i++)
	{
		numbers[depth] = cand[i];
		if (isGooldNumbers(depth + 1)) {
			bool find = dfs(depth + 1);
			if (find) {
				return true;
			}
		}
	}

	return false;
}

int main()
{
	std::cin >> N;

	dfs(0);

	return 0;
}