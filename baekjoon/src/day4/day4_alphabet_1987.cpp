#include <iostream>

const int MAX = 20;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int R, C;

bool isInBox(int x, int y)
{
	return (x >= 0 && x < R && y >= 0 && y < C);
}

bool check[30] = { false };
char graph[MAX][MAX] = {};

int max_length = 1;

void dfs(int x, int y, int depth)
{
	if (depth > max_length)
		max_length = depth;

	for (size_t i = 0; i < 4; i++)
	{
		int x_n = x + dx[i];
		int y_n = y + dy[i];

		int delta = static_cast<int> (graph[x_n][y_n] - 'A');
		if (isInBox(x_n, y_n) && check[delta] == false)
		{
			check[delta] = true;
			dfs(x_n, y_n, depth + 1);
			check[delta] = false;
		}
	}
}

int main() {

	std::cin >> R >> C;
	for (size_t i = 0; i < R; i++)
	{
		std::cin >> graph[i];
	}

	int delta = static_cast<int> (graph[0][0] - 'A');
	check[delta] = true;
	dfs(0, 0, 1);

	std::cout << max_length;

	return 0;
}