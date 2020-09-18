#include <iostream>
#include <queue>
#include <memory.h>
// 그냥 각 점별로 bfs돌면서 최대거리 뽑으면 됨..
const int MAX = 50;

bool check[MAX][MAX] = { false };
char graph[MAX][MAX];

int M, N;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInBox(int x, int y)
{
	return (x >= 0 && x < M && y >= 0 && y < N);
}

struct Move
{
	int x, y, step;
	Move(int _x, int _y, int _step): x(_x), y(_y), step(_step) {}
};

int bfs(int x, int y)
{
	std::queue<Move> q;
	q.push(Move(x, y, 0));
	check[x][y] = true;

	int last_step = 0;
	while (!q.empty())
	{
		Move now = q.front();
		q.pop();

		for (size_t i = 0; i < 4; i++)
		{
			int x_next = now.x + dx[i];
			int y_next = now.y + dy[i];

			if (isInBox(x_next, y_next) && check[x_next][y_next] == false &&
				graph[x_next][y_next] == 'L') {
				q.push(Move(x_next, y_next, now.step + 1));
				check[x_next][y_next] = true;
				last_step = now.step + 1;
			}
		}
	}

	return last_step;
}

int main()
{
	std::cin >> M >> N;
	for (size_t i = 0; i < M; i++)
	{
		std::cin >> graph[i];
	}

	int dist = 0;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			memset(check, 0, sizeof(check));
			if (graph[i][j] == 'L') {
				int dist_loc = bfs(i, j);
				dist = dist < dist_loc? dist_loc: dist;
			}
		}
	}

	std::cout << dist;

	return 0;
}