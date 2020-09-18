#include <iostream>
#include <vector>
#include <queue>

int degree[32001] = {0};
std::vector<int> topology[32001];

int N, M;

void bfs()
{
	std::queue<int> q;
	for (size_t i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		std::cout << now << " ";

		for (size_t i = 0; i < topology[now].size(); i++)
		{
			degree[topology[now][i]]--;
			if (degree[topology[now][i]] == 0)
				q.push(topology[now][i]);
		}
	}
}

int main()
{
	std::cin >> N >> M;

	int a, b;
	for (size_t i = 0; i < M; i++)
	{
		std::cin >> a >> b;
		topology[a].push_back(b);
		degree[b]++;
	}

	bfs();

	return 0;
}