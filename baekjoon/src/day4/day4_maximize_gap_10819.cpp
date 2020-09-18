#include <iostream>

const int MAX = 8;

int numbers[MAX];

int sorted[MAX];

int N;

int max_sum = 0;

bool check[MAX] = {false};

int calcSum()
{
	int sum = 0;
	for (size_t i = 0; i < N-1; i++)
	{
		sum += std::abs(sorted[i + 1] - sorted[i]);
	}

	return sum;
}

void dfs(int depth)
{
	if (depth == N) {
		int sum = calcSum();
		if (sum > max_sum)
			max_sum = sum;

		return;
	}

	for (size_t i = 0; i < N; i++)
	{
		if (check[i] == false) {
			check[i] = true;
			sorted[depth] = numbers[i];
			dfs(depth + 1);
			check[i] = false;
		}
	}
}

int main()
{
	std::cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
	}

	dfs(0);

	std::cout << max_sum;

	return 0;
}