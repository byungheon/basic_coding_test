#include <iostream>
#include <queue>

const int MAX = 1001;

bool check[MAX][MAX] = { false };
bool check_break[MAX][MAX] = { false };
char graph[MAX][MAX];

int N, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInBox(int x, int y)
{
	return (x >= 1 && x <= N && y >= 1 && y <= M);
}

struct Move
{
	int x, y, step;
	bool use_breaker;

	Move(int _x, int _y, int _step, bool _use_breaker) :
		x(_x), y(_y), step(_step), use_breaker(_use_breaker) {}
};

int bfs(int x, int y)
{
	std::queue<Move> q;
	check[x][y] = true;
	q.push(Move(x, y, 1, false));

	while (!q.empty())
	{
		Move now = q.front();
		q.pop();

		if (now.x == N && now.y == M)
			return now.step;

		for (size_t i = 0; i < 4; i++)
		{
			int x_next = now.x + dx[i];
			int y_next = now.y + dy[i];

			if (isInBox(x_next, y_next))
			{
				if (now.use_breaker == false && check[x_next][y_next] == false)
				{
					if (graph[x_next][y_next] == '0')
					{
						check[x_next][y_next] = true;
						q.push(Move(x_next, y_next, now.step + 1, now.use_breaker));
					}
					else if (now.use_breaker == false)
					{
						check[x_next][y_next] = true;
						q.push(Move(x_next, y_next, now.step + 1, true));
					}
				}
				else if (now.use_breaker == true && check_break[x_next][y_next] == false) {
					if (graph[x_next][y_next] == '0')
					{
						check_break[x_next][y_next] = true;
						q.push(Move(x_next, y_next, now.step + 1, now.use_breaker));
					}
				}
			}
		}
	}

	return -1;
}

int main()
{
	std::cin >> N >> M;

	for (size_t i = 1; i <= N; i++)
	{
		std::cin >> &(graph[i][1]);
	}

	std::cout << bfs(1, 1);

	return 0;
}
