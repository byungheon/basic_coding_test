#include <iostream>
#include <queue>
#include <memory.h>

const int MAX = 301;

int N;

bool check[MAX][MAX] = { false };
int start[2];
int goal[2];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isInBox(int x, int y)
{
	return (x >= 0 && x < N&& y >= 0 && y < N);
}


struct Move
{
	int x, y, step;
	Move(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};

int bfs()
{
	std::queue<Move> q;
	q.push(Move(start[0], start[1], 0));
	check[start[0]][start[1]] = true;

	while (!q.empty())
	{
		Move now = q.front();
		q.pop();
		if (now.x == goal[0] && now.y == goal[1]) {
			return now.step;
		}

		for (size_t i = 0; i < sizeof(dx)/sizeof(dx[0]); i++)
		{
			int x_next = now.x + dx[i];
			int y_next = now.y + dy[i];

			if (isInBox(x_next, y_next) && check[x_next][y_next] == false) {
				q.push(Move(x_next, y_next, now.step + 1));
				check[x_next][y_next] = true;

				if(x_next == goal[0] && y_next == goal[1]){
					return now.step + 1;
				}
			}
		}
	}
}

int main()
{
	int n_trial;

	std::cin >> n_trial;

	for (size_t i = 0; i < n_trial; i++)
	{
		std::cin >> N;
		std::cin >> start[0];
		std::cin >> start[1];
		std::cin >> goal[0];
		std::cin >> goal[1];

		memset(check, 0, sizeof(check));

		std::cout << bfs() << std::endl;
	}

	return 0;
}