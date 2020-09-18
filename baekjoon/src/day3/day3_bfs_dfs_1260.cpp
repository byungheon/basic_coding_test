#include <iostream>
#include <memory.h>
#include <queue>

const int MAX = 1001;

bool check[MAX] = { false };
bool neighbor[MAX][MAX] = { false };

int N, M, start;

void dfs(int x)
{
	std::cout << x << " ";
	check[x] = true;
	for (size_t i = 1; i <= N; i++)
	{
		if (neighbor[x][i] == true && check[i] == false)
			dfs(i);
	}
}

void bfs(int x)
{
	std::queue<int> q;
	q.push(x);
	check[x] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		std::cout << now << " ";

		for (size_t i = 1; i <= N; i++)
		{
			if (neighbor[now][i] == true && check[i] == false)
			{
				check[i] = true;
				q.push(i);
			}
		}
	}

}

int main()
{
	std::cin >> N >> M >> start;

	int first, second;
	for (size_t i = 0; i < M; i++)
	{
		std::cin >> first >> second;
		neighbor[first][second] = true;
		neighbor[second][first] = true;
	}

	dfs(start);
	std::cout << std::endl;

	memset(check, 0, sizeof(check));

	bfs(start);

	return 0;
}