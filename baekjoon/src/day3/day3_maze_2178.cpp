#include <iostream>
#include <queue>

const int MAX = 101;
int N, M;

char graph[MAX][MAX];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInBox(int x, int y)
{
	return (x >= 1 && x <= N&& y >= 1 && y <= M);
}

struct Maze
{
	int step, x, y;
	Maze(int _x, int _y, int _step) : step(_step), x(_x), y(_y) {}
};

int bfs(int x, int y)
{
	std::queue<Maze> q;
	Maze maze(x, y, 1);
	q.push(maze);
	graph[x][y] = '0';

	while (!q.empty())
	{
		Maze now = q.front();
		q.pop();

		if (now.x == N && now.y == M) {
			return now.step;
		}

		for (size_t i = 0; i < 4; i++)
		{
			int next_x = now.x + dx[i];
			int next_y = now.y + dy[i];

			if (isInBox(next_x, next_y) && graph[next_x][next_y] == '1')
			{
				graph[next_x][next_y] = '0';
				Maze next(next_x, next_y, now.step + 1);
				q.push(next);
				if (next_x == N && next_y == M) {
					return next.step;
				}
			}
		}
	}
}

int main()
{
	std::cin >> N >> M;

	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= M; j++)
		{
			std::cin >> graph[i][j];
		}
	}

	std::cout << bfs(1, 1);

	return 0;
}