#include <iostream>
#include <memory.h>
#include <queue>

const int INF = 987654321;

int island[100][100] = {0};
bool check[100][100] = { false };

int N = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isInBox(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void dfs(int x, int y, int i_island)
{
	check[x][y] = true;
	island[x][y] = i_island;

	for (size_t i = 0; i < 4; i++)
	{
		int xn = x + dx[i];
		int yn = y + dy[i];
		if (isInBox(xn, yn) && island[xn][yn] > 0 && check[xn][yn] == false)
			dfs(xn, yn, i_island);
	}
}

int bfs(int i_island)
{
	std::queue<std::pair<int, int>> q;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (island[i][j] == i_island) {
				q.push(std::make_pair(i, j));
				check[i][j] = true;
			}
		}
	}

	int result = 0;
	while (!q.empty())
	{
		int q_size = q.size();
		for (size_t i = 0; i < q_size; i++)
		{
			int x_now = q.front().first;
			int y_now = q.front().second;

			q.pop();

			for (size_t j = 0; j < 4; j++)
			{
				int x_next = x_now + dx[j];
				int y_next = y_now + dy[j];
				if (isInBox(x_next, y_next) && check[x_next][y_next] == false)
				{
					check[x_next][y_next] = true;

					if (island[x_next][y_next] > 0) {
						return result;
					}
					else
					{
						q.push(std::make_pair(x_next, y_next));
					}
				}
			}
		}
		
		result++;
	}
}

int main()
{
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cin >> island[i][j];
		}
	}

	int cnt = 1;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (island[i][j] > 0 && check[i][j] == false)
			{
				dfs(i, j, cnt++);
			}
		}
	}

	int min_dist = INF;
	for (size_t i = 1; i < cnt; i++)
	{
		memset(check, 0, sizeof(check));
		int dist = bfs(i);
		min_dist = min_dist > dist ? dist: min_dist;
	}

	std::cout << min_dist;

	return 0;
}