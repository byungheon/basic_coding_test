#include <iostream>

int N, M;
int check[1001];
int neighbor[1001][1001];

void dfs(int x)
{
	check[x] = 1;
	for (size_t i = 1; i <= N; i++)
	{
		if (neighbor[x][i] == 1 && check[i] != 1)
		{
			dfs(i);
		}
	}
}

int main()
{
	std::cin >> N >> M;

	int head, tail;
	for (size_t i = 0; i < M; i++)
	{
		std::cin >> head >> tail;

		neighbor[head][tail] = 1;
		neighbor[tail][head] = 1;
	}

	int n_connected= 0;
	for (size_t i = 1; i <= N; i++)
	{
		if (check[i] != 1) {
			n_connected++;
			dfs(i);
		}
	}

	std::cout << n_connected << std::endl;

	return 0;
}