#include <iostream>
#include <queue>

int n_com, n_neighbor;

int check[101];
int neighbor[101][101];

//#define DFS_SOL
#define BFS_SOL

void dfs(int x) {
	check[x] = 1;
	for (size_t i = 1; i <= n_com; i++)
	{
		if (neighbor[x][i] == 1 && check[i] != 1)
			dfs(i);
	}
}

void bfs(int x) {
	std::queue<int> q;
	q.push(x);
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (size_t i = 1; i <= n_com; i++)
		{
			if (neighbor[now][i] == 1 && check[i] != 1) {
				check[i] = 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	std::cin >> n_com >> n_neighbor;

	int head, tail;
	for (size_t i = 0; i < n_neighbor; i++)
	{
		std::cin >> head >> tail;

		neighbor[head][tail] = 1;
		neighbor[tail][head] = 1;
	}
#ifdef DFS_SOL
	dfs(1);
#endif
#ifdef BFS_SOL
	bfs(1);
#endif BFS_SOL
	int n_defect = 0;
	for (size_t i = 2; i <= n_com; i++)
	{
		if (check[i] == 1)
			n_defect++;
	}

	std::cout << n_defect << std::endl;

	return 0;
}

